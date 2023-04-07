#include "Window.h"

#include "ErrorHandler.h"

Window::Window(std::string title, int width, int height) {
    _window = nullptr;
    _title = title;
    _screenWidth = width;
    _screenHeight = height;
};

void Window::initWindowAndContexts() {
    SDL_Init(SDL_INIT_EVERYTHING);

    _window = SDL_CreateWindow(
        _title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        _screenWidth,
        _screenHeight,
        SDL_WINDOW_OPENGL);
    if (_window == nullptr) {
        ErrorHandler::fatalErrorAndQuit("SDL Window failed to create");
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(_window);
    if (glContext == nullptr) {
        ErrorHandler::fatalErrorAndQuit("SDL_GL context failed to create");
    }

    // Optional, enable for wierd crashes
    glewExperimental = true;
    GLenum error = glewInit();
    if (error != GLEW_OK) {
        ErrorHandler::fatalErrorAndQuit("Glew initialization failed");
    }

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
};

SDL_Window* Window::getWindow() {
    return _window;
}