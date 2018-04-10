//
// Created by Adam on 4/10/2018.
//

#ifndef SDL_TEMPLATE_SPRITE_H
#define SDL_TEMPLATE_SPRITE_H


#include <SDL_surface.h>

class Sprite {
private:
    SDL_Surface *image;
    SDL_Rect rect;
    int origin_x;
    int origin_y;
public:
    Sprite(Uint32 color, int x, int y, int width = 48, int height = 64);

    void update();

    void draw(SDL_Surface *destination);
};


#endif //SDL_TEMPLATE_SPRITE_H
