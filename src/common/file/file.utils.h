#pragma once
#include "common/core.types.h"
#include <filesystem>

namespace Common::File  {
    bool exists(const std::filesystem::path & path)    {
        return std::filesystem::exists(path);
    }

    String getFileNameSansExtension(const std::filesystem::path & path)   {
        return path.stem().string();
    }

    ArrayList<String> getAllFilePaths(const std::filesystem::path & path) {
        ArrayList<String> files;

        std::error_code ec;
        if (!std::filesystem::exists(path, ec) || ec) {
            return files;
        }

        for (const auto & entry : std::filesystem::recursive_directory_iterator(path)) {
            if (entry.is_regular_file() && !ec) {
                files.push_back(entry.path().string());
            }
        }

        return files;
    }
}