#include <SDL.h>
#include <iostream>

#include "../include/renderer.hpp"

int main(int argc, char* argv[]) {
    try {
        Renderer renderer(1280, 720, "3D Renderer");

        bool running = true;
        SDL_Event event;

        while (running) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    running = false;
                }
            }

            renderer.clear();
            
            // Exemple de dessin
            renderer.drawLine(100, 100, 200, 200);
            renderer.drawPoint(150, 150);

            renderer.present();
        }

    } catch (const std::exception& e) {
        SDL_Log("Error: %s", e.what());
        return -1;
    }
    return 0;
}
