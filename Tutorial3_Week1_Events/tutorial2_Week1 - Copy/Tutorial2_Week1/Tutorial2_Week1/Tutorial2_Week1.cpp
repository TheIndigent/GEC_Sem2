#include <iostream>
#include <SDL.h>
#undef main
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "constants.h"
using namespace std;

//globals
SDL_Window* g_window = nullptr;

//function prototypes
bool InitSDL();
void CloseSDL();

//Setup SDL
bool InitSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL did not initialise. Error. " << SDL_GetError();
        return false;
    }
    else {
        //creates window if setup is passed
        g_window = SDL_CreateWindow("Budget Mario",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);
        //did window get created?
        if (g_window == nullptr) {
            //window failed
            cout << "window was not created. Error. " << SDL_GetError();
            return false;
        }
    }
}

void CloseSDL() {
    SDL_DestroyWindow(g_window);
    g_window = nullptr;
    IMG_Quit();
    SDL_Quit();
}

int main()
{
    if (InitSDL()) {
        bool quit = false;

        while (!quit)
        {
            quit = Update();
        }
    }

    CloseSDL();
}

int Update() 
{
    SDL_Event e;
    SDL_PollEvent(&e);

    switch (e.type)
    {
        //click the "X" to quit
    case SDL_QUIT:
        return true;
        break;
    }

    return false;
}