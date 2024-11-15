#pragma once

#include <iostream>
#include "Engine.h"

int main()
{
    Engine engine;

    if (engine.ready())
        engine.Run();

    return 0;
}
