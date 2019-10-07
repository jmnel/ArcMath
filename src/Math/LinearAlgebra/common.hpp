#pragma once

namespace jmnel {
    enum class storage_policies { static_store, heap_store, span_store };
    enum class order_policies { row_major, col_major };
    enum class density_policies { dense, spare };

}  // namespace jmnel
