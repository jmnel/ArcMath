#pragma once

namespace arc::detail {

    // Storage options.
    static constexpr int ColMajor = 0x0;
    static constexpr int RowMajor = 0x1;

    static constexpr int RowMajorBit = 0x1;

    static constexpr int AccessorsBit = 0x2;
    static constexpr int AccessorsEnabled = 0x2;
    static constexpr int AccessorsDisabled = 0x0;

    static constexpr int NamedMemberRefsBit = 0x4;
    static constexpr int NamedMemberRefsEnabled = 0x4;
    static constexpr int NamedMemberRefsDisabled = 0x0;

    static constexpr int DefaultMatrixStorageOrder = RowMajor;

}  // namespace arc::detail
