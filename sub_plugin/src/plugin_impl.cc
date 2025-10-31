
#include "plugin_impl.h"
#include <iostream>

void pluginCallFunction(ILnkInterface* interface)
{
    std::cout << "hello from plugin: " << interface->getValue() << std::endl;
}
