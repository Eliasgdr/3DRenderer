#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL.h>
#include <string>

class Renderer {
public:
    Renderer(int width, int height, const std::string& title);
    ~Renderer();

    void clear();
    void present();
    void drawLine(int x1, int y1, int x2, int y2);
    void drawPoint(int x, int y);

private:
    SDL_Window* window;
    SDL_Renderer* sdlRenderer;
};

#endif // RENDERER_HPP
