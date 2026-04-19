#pragma once
#include <spdlog/spdlog.h>

namespace Log {
    using spdlog::set_level;
    using spdlog::set_pattern;
    using spdlog::set_default_logger;

    using spdlog::info;
    using spdlog::warn;
    using spdlog::error;
    using spdlog::debug;
    using spdlog::trace;
    using spdlog::critical;
};