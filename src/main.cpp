#include <SDL.h>
#include <iostream>

#include "../include/renderer.hpp"
#include "../include/vector3.hpp"

int main(int argc, char* argv[]) {
    std::cout << "aaaaaaa" << std::endl;
    /*
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
    */
    Vec3 v1 = Vec3(1.0f,1.0f,1.0f);
    Vec3 v2 = Vec3(3.0f,4.0f,5.0f);
    Vec3 v3 = v1 + v2;
    v3.print();
    v3 = v1 - v2;
    v3.print();
    v3 = v1 * 2.0f;
    v3.print();
    v3 = v1 ^ v2;
    v3.print();
    float t = v1*v2;
    std::cout << t << std::endl;
    v3 = v3.normalize();
    v3.print();

    return 0;
}
