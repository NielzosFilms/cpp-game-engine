#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>

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
    SDL_Window* _window;
    int _screenWidth;
    int _screenHeight;
    GameState _gameState;
};
