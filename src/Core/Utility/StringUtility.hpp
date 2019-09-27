#pragma once

#include <array>
#include <sstream>
#include <string>
#include <vector>

using std::array;
using std::endl;
using std::string;
using std::vector;

namespace arc {

    template <typename Arg, typename... Args>
    void makeStringFromHelper( std::string &output, Arg arg, Args... args ) {
        std::stringstream ss;
        ss << arg;
        output.append( ss.str() );
    }

    template <typename... Args>
    std::string makeStringFrom( Args... args ) {
        std::string result{""};
        ( ( makeStringFromHelper<Args>( result, args ) ), ... );
        return result;
    }

    void split( string const &s, const char delim, vector<string> &tokens );
    string trimLeft( string const &s );
    string trimRight( string const &s );
    string trim( string const &s );

    template <class T>
    string toString( vector<T> const &v, const bool multiline = false ) {
        std::stringstream ss;
        for( auto it = v.begin(); it != v.end(); ++it ) {
            ss << *it;
            const auto dist = std::distance( v.begin(), it );
            if( dist + 1 < v.size() ) {
                if( multiline ) {
                    ss << endl;
                } else {
                    ss << ", ";
                }
            }
        }
    }

    template <class T, size_t N>
    string toString( array<T, N> const &a, const bool multiline = false ) {
        std::stringstream ss;
        for( auto it = a.begin(); it != a.end(); ++it ) {
            ss << *it;
            const auto dist = std::distance( a.begin(), it );
            if( dist + 1 < a.size() ) {
                if( multiline ) {
                    ss << endl;
                } else {
                    ss << ", ";
                }
            }
        }
    }

}  // namespace arc
