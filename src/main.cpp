#include "common/core.types.h"
#include "common/application/application.h"

#include "common/logging.types.h"
#include "common/utils/hello.h"
#include "common/reflect.types.h"
#include <fstream>

struct Config {
    String name;
    u8 num;
    float dot;
};

int main()  {
    Log::info("Compiled with: {}", Common::cxxversion());

    Config config = { "Hello", 30, 5.8f };
    auto toml_string = rfl::toml::write(config);

    std::ofstream file("config.toml");
    file << toml_string;
    file.close();
}
