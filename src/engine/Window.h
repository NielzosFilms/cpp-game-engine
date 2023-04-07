#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <iostream>
#include <string>

class Window {
   private:
    SDL_Window* _window;
    std::string _title;
    int _screenWidth;
    int _screenHeight;

   public:
    Window(std::string title, int width, int height);
    ~Window();

    void initWindowAndContexts();

    SDL_Window* getWindow();
};
