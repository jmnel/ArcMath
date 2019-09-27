#pragma once

namespace arc {

    struct SourceLocation {
        const char* m_file;
        const char* m_function;
        const int m_line;

        inline static constexpr SourceLocation current( const char* __file, const char* __function, const int __line ) {
            return SourceLocation{__file, __function, __line};
        }
    };

}  // namespace arc
