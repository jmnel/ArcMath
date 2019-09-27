#pragma once

#include <sstream>
#include <string>
#include <type_traits>
#include <variant>

//#include <Math/Vec.hpp>

#include <Debug/Assert.hpp>
//#include <Utility/IDebugPrintable.hpp>
#include <Debug/SourceLocation.hpp>
#include <Utility/PatternMatch.hpp>
#include <Utility/StringUtility.hpp>
#include <Utility/TypeUtility.hpp>

namespace arc {

    template <typename T>
    class Ok {
    private:
        //    public:
        T m_value;

    public:
        Ok( T& value )
            : m_value( value ) {
        }

        Ok( T&& value )
            : m_value( std::move( value ) ) {
        }

        T& getValue() {
            return m_value;
        }
        T const& getValue() const {
            return m_value;
        }
    };

    template <typename E>
    class Error {
    private:
        E m_error;

    public:
        Error( E& error )
            : m_error( error ) {
        }

        Error( E&& error )
            : m_error( std::move( error ) ) {
        }

        E& getError() {
            return m_error;
        }

        E const& getError() const {
            return m_error;
        }
    };

    template <typename T, typename E = string>
    class Result : is_matching_type {
    private:
    public:
        std::variant<Ok<T>, Error<E>> m_value;

    public:
        Result()
            : m_value( Error<E>{E{}} ){};

        Result( Ok<T>&& ok )
            : m_value( std::move( ok ) ) {
        }

        Result( Error<E>&& error )
            : m_value( std::move( error ) ) {
        }

        Result<T, E>& operator=( Ok<T>&& ok ) {
            m_value = std::move( ok );
            return *this;
        }

        Result<T, E>& operator=( Error<E>&& error ) {
            m_value = std::move( error );
            return *this;
        }

        bool isOk() const {
            return std::holds_alternative<Ok<T>>( m_value );
        }

        bool isError() const {
            return std::holds_alternative<Error<E>>( m_value );
        }

#define unwrap() _unwrap( SourceLocation::current( __FILE__, __func__, __LINE__ ) )

        inline T&& _unwrap( const SourceLocation sourceLocation ) {
            // Panic if result doesn't contain ok.
            if( !isOk() ) {
                std::cerr << "Panic: Tried to dereference `Result` type with invalid state!" << endl;
                assertf( isError() );
                const auto e = std::get<Error<E>>( m_value );
                std::cerr << "    " << e << endl;
                std::cerr << "    -> in function " << sourceLocation.m_function << " in file ";
                std::cerr << sourceLocation.m_file << " @ line " << sourceLocation.m_line << endl;
                abort();
            }

            return std::move( std::get<Ok<T>>( m_value ).getValue() );
        }

#define expect( message ) _expect( SourceLocation::current( __FILE__, __func__, __LINE__ ), message )

        inline T&& _expect( const SourceLocation sourceLocation, std::string const& message ) {
            if( !isOk() ) {
                std::cerr << "Panic: expect on result type failed!" << endl;
                std::cerr << message << endl;
                std::cerr << "    -> in function " << sourceLocation.m_function << " in file ";
                std::cerr << sourceLocation.m_file << " @ line " << sourceLocation.m_line << endl;
                abort();
            }

            return std::move( std::get<Ok<T>>( m_value ).getValue() );
        }
    };

    template <typename T, typename E>
    inline std::ostream& operator<<( std::ostream& os, Result<T, E>& result ) {
        os << "Result<" << types::getTypeName<T>() << ", ";
        os << types::getTypeName<E>() << ">"
           << "{" << endl;

        os << match(
            result,
            []( Ok<T> ok ) { return makeStringFrom( "  Ok<", types::getTypeName<T>(), "> { ", ok.getValue(), " }" ); },
            []( Error<E> error ) {
                return makeStringFrom( "  Error<", types::getTypeName<T>(), "> { ", error.getError(), " }" );
            } );

        os << "\n}";

        return os;
    }

    template <typename E>
    inline std::ostream& operator<<( std::ostream& os, Error<E> error ) {
        os << "Error<" << types::getTypeName<E>() << ">{ ";
        os << error.getError() << " }";
        return os;
    }

    template <typename T>
    inline std::ostream& operator<<( std::ostream& os, Ok<T> ok ) {
        os << "Ok<" << types::getTypeName<T>() << ">{ ";
        os << ok.getValue() << " }";
        return os;
    }

}  // namespace arc
