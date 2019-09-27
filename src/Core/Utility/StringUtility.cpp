#include <Utility/StringUtility.hpp>

namespace arc {

    void split( string const &s, const char delim, vector<string> &tokens ) {
        size_t current;
        size_t previous = 0;
        current = s.find( delim );
        while( current != string::npos ) {
            tokens.emplace_back( s.substr( previous, current - previous ) );
            previous = current + 1;
            current = s.find( delim, previous );
        }
        tokens.emplace_back( s.substr( previous, current - previous ) );
    }

    string trimLeft( string const &s ) {
        size_t spaces = 0;
        for( auto i = s.begin(); i != s.end(); i++ ) {
            if( *i == ' ' ) {
                spaces++;
            } else {
                break;
            }
        }
        string result = s;

        if( spaces > 0 ) {
            result.erase( result.begin(), result.begin() + spaces );
        }

        return result;
    }

    string trimRight( string const &s ) {
        size_t spaces = 0;
        for( auto i = s.rbegin(); i != s.rend(); i++ ) {
            if( *i == ' ' ) {
                spaces++;
            } else {
                break;
            }
        }

        string result = s;

        if( spaces > 0 ) {
            result.erase( result.begin() + ( result.size() - spaces ), result.end() );
        }

        return result;
    }

    string trim( string const &s ) {
        auto r = trimLeft( s );
        r = trimRight( r );
        return r;
    }

}  // namespace arc
