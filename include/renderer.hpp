#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL.h>
#include <string>
#include <stdexcept>
#include "vector3.hpp"
#include "matrix4.hpp"
#include "mesh.hpp"

class Renderer {
public:
    Renderer(int width, int height, const std::string& title);
    ~Renderer();

    void clear();
    void present();

    

    void drawPoint2D(int x, int y);
    void drawLine2D(int x1, int y1, int x2, int y2);
    
private:
    SDL_Window* window;
    SDL_Renderer* sdlRenderer;
};

#endif // RENDERER_HPP
