#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include "engine/Window.cpp"
#include "engine/Window.h"

enum class GameState { PLAY,
                       EXIT };

class MainGame {
   public:
    MainGame();

    void run();
    void initSystems();
    void gameLoop();
    void processInput();
    void draw();

   private:
    Window _window;
    GameState _gameState;
};
