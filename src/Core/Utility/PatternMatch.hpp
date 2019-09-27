#pragma once

#include <functional>
#include <iostream>
#include <type_traits>
#include <variant>

using std::cout;
using std::endl;

namespace arc {

    class is_matching_type {};

    template <class... Ts>
    struct overloaded : Ts... {
        using Ts::operator()...;
    };
    template <class... Ts>
    overloaded( Ts... )->overloaded<Ts...>;

    template <typename Variant,
              typename... Handlers,
              typename std::enable_if<!std::is_base_of<is_matching_type, Variant>::value, Variant>::type* = nullptr>
    auto match( Variant& v, Handlers&&... handlers ) {
        //        cout << "std::variant version called." << endl;

        return std::visit( overloaded{std::forward<Handlers>( handlers )...}, std::forward<Variant>( v ) );
    }

    template <typename Variant,
              typename... Handlers,
              typename std::enable_if<std::is_base_of<is_matching_type, Variant>::value, Variant>::type* = nullptr>
    auto match( Variant& v, Handlers&&... handlers ) {
        //        cout << "non variant version called." << endl;

        return std::visit( overloaded{std::forward<Handlers>( handlers )...},
                           std::forward<decltype( v.m_value )>( v.m_value ) );
    }

    // -- CONST NON STD::VARIANT VERSION --
    template <typename Variant,
              typename... Handlers,
              typename std::enable_if<std::is_base_of<is_matching_type, Variant>::value, Variant>::type* = nullptr>
    auto match( const Variant& v, Handlers&&... handlers ) {
        //        cout << "non variant version called." << endl;

        return std::visit( overloaded{std::forward<Handlers>( handlers )...},
                           std::forward<const decltype( v.m_value )>( v.m_value ) );
    }

    //    template <typename Variant,
    //              typename... Handlers,
    //              typename std::enable_if<std::is_base_of<is_matching_type, Variant>::value, Variant>::type* =
    //              nullptr>
    //    auto match( Variant const& v, Handlers&&... handlers ) {
    //                cout << "non variant version called." << endl;

    //        return std::visit( overloaded{std::forward<Handlers>( handlers )...},
    //                           std::forward<decltype( v.m_value )>( v.m_value ) );
    //    }

}  // namespace arc
