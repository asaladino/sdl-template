#include "SDL2/SDL.h"
#include "Sprite.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

#define fps 60
#define window_width 640
#define window_height 480

using namespace std;

void capFrameRate(Uint32 starting_tick) {
    if ((1000 / fps) > SDL_GetTicks() - starting_tick) {
        SDL_Delay(1000 / fps - (SDL_GetTicks() - starting_tick));
    }
}

int main(int argc, char **argv) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("Just a Test",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          window_width,
                                          window_height,
                                          SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        cout << "Error loading window!" << endl << SDL_GetError() << endl;
        return 1;
    }

    SDL_Surface *screen = SDL_GetWindowSurface(window);
    Uint32 colorCyan = SDL_MapRGB(screen->format, 155, 200, 205);
    SDL_FillRect(screen, nullptr, colorCyan);

    int x = 0, y = 0;

    SDL_GetWindowPosition(window, &x, &y);
    string str = to_string(x) + ", " + to_string(y);
    SDL_SetWindowTitle(window, str.c_str());

    Uint32 startingTick;

    SDL_Event event;
    bool running = true;

    Uint32 colorGray = SDL_MapRGB(screen->format, 200, 200, 200);
    Sprite sprite(colorGray, 100, 200);
    sprite.draw(screen);

    SDL_UpdateWindowSurface(window);

    while (running) {
        startingTick = SDL_GetTicks();
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
        }
        capFrameRate(startingTick);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
