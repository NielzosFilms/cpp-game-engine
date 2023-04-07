#include <SDL2/SDL.h>

#include "MainGame.h"
#include "iostream"

int main(int argc, char** argv) {
    MainGame mainGame;
    mainGame.run();

    SDL_Quit();
    return 0;
}