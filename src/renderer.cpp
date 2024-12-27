#ifndef RENDERER_CPP
#define RENDERER_CPP

#include "../include/renderer.hpp"
#include <stdexcept>

Renderer::Renderer(int width, int height, const std::string& title){ // Constructor definition
    // SDL Initialisation
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error("Failed to initialize SDL: " + std::string(SDL_GetError()));
    }

    // Window creation
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        throw std::runtime_error("Failed to create SDL window: " + std::string(SDL_GetError()));
    }

    // Renderer creation
    sdlRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!sdlRenderer) {
        throw std::runtime_error("Failed to create SDL renderer: " + std::string(SDL_GetError()));
    }

}

Renderer::~Renderer() {// Destructor definition
	if (sdlRenderer) SDL_DestroyRenderer(sdlRenderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
} 

void Renderer::clear() {
    SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255); // Couleur noire
    SDL_RenderClear(sdlRenderer);
}

void Renderer::present() {
    SDL_RenderPresent(sdlRenderer);
}

void Renderer::drawLine(int x1, int y1, int x2, int y2) {
    SDL_SetRenderDrawColor(sdlRenderer, 255, 255, 255, 255); // Couleur blanche
    SDL_RenderDrawLine(sdlRenderer, x1, y1, x2, y2);
}

void Renderer::drawPoint(int x, int y) {
    SDL_SetRenderDrawColor(sdlRenderer, 255, 0, 0, 255); // Couleur rouge
    SDL_RenderDrawPoint(sdlRenderer, x, y);
}
#endif // RENDERER_CPP
