#pragma once

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Engine.h"

int main()
{
    std::srand(time(NULL));

    Engine engine;

    if (engine.ready())
        engine.Run();

    return 0;
}
