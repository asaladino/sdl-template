//
// Created by Adam on 4/10/2018.
//

#include "Sprite.h"

Sprite::Sprite(Uint32 color, int x, int y, int width, int height) {
    image = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    SDL_FillRect(image, nullptr, color);
    rect = image->clip_rect;
    rect.x = x - origin_x;
    rect.y = y - origin_y;
}

void Sprite::update() {}

void Sprite::draw(SDL_Surface *destination) {
    SDL_BlitSurface(image, nullptr, destination, &rect);
}