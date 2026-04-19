# Common-Plus-Plus
Commonly used Std Extensions Library for C++

I've found the std library is lacking features or is generally slow, so this attempts to consolidate common solutions I use in one place.

## To Use
Copy src/common headers to your external or vendor library

## Features
- Application Looper
- Bidirectional Map
- Threadsafe Queue
- Counter Accumulator
- CPP Version Checker
- String Utilities
- Aliasing commonly used c/c++ and std library features in a single include
- Log wrapper for spdlog
- GLM single include and extensions to work with reflect-cpp (TODO, previously using CEREAL)
- Bitmask Type

## Dependencies
Relies on vcpkg to install: spdlog, toml++, reflect-cpp, glm

