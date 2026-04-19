#pragma once
#include "common/core.types.h"

namespace Common  {
    struct Specification  {
        String name;
        String version;
    };

    class Application   {
        public:
            Application(Specification specification)    : specification(std::move(specification)), running(true) {}
            ~Application() {};

            void run() {
                setup();
                while (running) {
                    loop();
                }
                shutdown();
            }
            void quit() {
                running = false;
            }

            const String& getName() const {
                return specification.name;
            }

            const String& getVersion() const {
                return specification.version;
            }
        protected:
            virtual void setup() = 0;
            virtual void loop() = 0;
            virtual void shutdown() = 0;
        private:
            Specification specification;
            bool running;
    };
};
