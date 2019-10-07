#include <iterator>
#pragma once

namespace jmnel::algorithm {

    template <typename InputIt>
    class range {
        const InputIt m_begin;
        const InputIt m_end;

        InputIt begin() { return m_begin; }
        InputIt end() { return m_end; }
    };

    //    template <typename

}  // namespace jmnel::algorithm
