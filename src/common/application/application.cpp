#include "application.h"

Common::Application::Application(Specification specification)   :
    specification(std::move(specification)),
    running(true)
{}

void Common::Application::run()  {
    setup();
    while (running) {
        loop();
    }
    shutdown();
}

void Common::Application::quit()    {
    running = false;
}

const String & Common::Application::getName() const {
    return specification.name;
}

const String & Common::Application::getVersion()  const {
    return specification.version;
}

Common::Application::~Application()    {}