#pragma once
#include "common/core.types.h"

namespace Common  {
    struct Specification  {
        String name;
        String version;
    };

    class Application   {
        public:
            Application(Specification specification);
            ~Application();

            void run();
            void quit();

            const String & getName()    const;
            const String & getVersion() const;
        protected:
            virtual void setup() = 0;
            virtual void loop() = 0;
            virtual void shutdown() = 0;
        private:
            Specification specification;
            bool running;
    };
};
