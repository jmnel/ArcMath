#pragma once

#include <cxxabi.h>
#include <memory>
#include <string>

using std::string;

namespace arc::types {

    template <class T>
    string getTypeName() {
        int status;
        const auto mangled = typeid( T ).name();
        std::unique_ptr<char[], void ( * )( void* )> result( abi::__cxa_demangle( mangled, 0, 0, &status ), std::free );

        const auto name = result.get() ? string{result.get()} : "NA";

        if( name == "std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >" ) {
            return "std::string";
        }

        return name;
    }

}  // namespace arc::types
