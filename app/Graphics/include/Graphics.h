#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <SDL.h>
#include <SDL_image.h>
#include <string>
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

    SDL_Renderer* mRenderer;

public:

    static Graphics* Instance(void);
    static void Release(void);
    static bool Initialized(void);

    SDL_Texture* LoadTexture(std::string path);

    void ClearBackBuffer(void);

    void DrawTexture(SDL_Texture* texture);

    void Render(void);

private:

    Graphics();
    ~Graphics();

    bool Init();
};

#endif