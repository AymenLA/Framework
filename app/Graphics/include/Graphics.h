#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <SDL.h>
#include <stdio.h>

class Graphics {

public:
    static const uint32_t SCREEN_WIDTH = 800U;
    static const uint32_t SCREEN_HEIGHT = 600U;

private:

    static Graphics* sInstance;
    static bool sInitialized;

    SDL_Window* mWindow;
    SDL_Surface* mBackBuffer;

public:

    static Graphics* Instance(void);
    static void Release(void);
    static bool Initialized(void);

    void Render(void);

private:

    Graphics();
    ~Graphics();

    bool Init();
};

#endif