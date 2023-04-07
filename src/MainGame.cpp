#include "MainGame.h"

#include <iostream>
#include <string>

MainGame::MainGame()
    : _window("Game engine", 1920, 1080) {
    _gameState = GameState::PLAY;
}

void MainGame::run() {
    initSystems();
    gameLoop();
}

void MainGame::initSystems() {
    _window.initWindowAndContexts();
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

    SDL_GL_SwapWindow(_window.getWindow());
}
