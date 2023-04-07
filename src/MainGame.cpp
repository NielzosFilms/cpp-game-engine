#include "MainGame.h"

#include <iostream>
#include <string>

void fatalError(std::string error) {
    std::cout << error << std::endl;
    std::cout << "Enter any key to quit..." << std::endl;
    int tmp;
    std::cin >> tmp;
    SDL_Quit();
}

MainGame::MainGame() {
    _window = nullptr;
    _screenWidth = 600;
    _screenHeight = 400;
    _gameState = GameState::PLAY;
}

void MainGame::run() {
    initSystems();
    gameLoop();
}

void MainGame::initSystems() {
    SDL_Init(SDL_INIT_EVERYTHING);

    _window = SDL_CreateWindow("cpp-game-engine",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               _screenWidth,
                               _screenHeight,
                               SDL_WINDOW_OPENGL);
    if (_window == nullptr) {
        fatalError("SDL Window failed to create");
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(_window);
    if (glContext == nullptr) {
        fatalError("SDL_GL context failed to create");
    }

    // Optional for wierd crashes
    glewExperimental = true;
    GLenum error = glewInit();
    if (error != GLEW_OK) {
        fatalError("Glew initialization failed");
    }

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void MainGame::gameLoop() {
    while (_gameState != GameState::EXIT) {
        processInput();
        draw();
    }
}

void MainGame::processInput() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                _gameState = GameState::EXIT;
                break;
            case SDL_MOUSEMOTION:

                break;
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                    glViewport(0, 0, (GLsizei)event.window.data1, (GLsizei)event.window.data2);
                }
                break;
            default:
                break;
        }
    }
}

void MainGame::draw() {
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0, 0);
    glVertex2f(0, 0.5);
    glVertex2f(0.5, 0.5);

    glEnd();

    SDL_GL_SwapWindow(_window);
}
