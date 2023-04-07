#pragma once

#include <SDL2/SDL.h>

#include <iostream>
#include <string>

class ErrorHandler {
   public:
    static void fatalErrorAndQuit(std::string error) {
        std::cout << error << std::endl;
        std::cout << "Enter any key to quit..." << std::endl;
        int tmp;
        std::cin >> tmp;
        SDL_Quit();
    };
};
