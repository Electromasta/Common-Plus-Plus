#pragma once
#include "common/core.types.h"
#include <fstream>
#include <toml++/toml.hpp>
#include <rfl.hpp>
#include <rfl/toml.hpp>

namespace Common::File    {
    template<typename T>
    class Config  {
        public:
            Config(const std::filesystem::path & path, const T & fallback) : path(path) {
                if (!load()) {
                    config = fallback;
                    save();
                }
            };
            ~Config() {};
            Config(const Config&) = delete;
            Config& operator=(const Config&) = delete;

            T* operator->() { return &config; }
            T & get() { return config; }

            bool save() {
                const String toml = rfl::toml::write(config);
                std::filesystem::create_directories(path.parent_path());
                std::ofstream file(path);
                if (!file.is_open()) return false;
                file << toml;
                file.close();
                return true;
            }

            bool load() {
                std::ifstream file(path);
                if (!file.is_open()) return false;
                std::stringstream buffer;
                buffer << file.rdbuf();
                rfl::Result<T> result = rfl::toml::read<T>(buffer.str());
                if (!result) return false;
                config = result.value();
                return true;
            }
        private:
            std::filesystem::path path;
            T config;
    };
}