#include "Graphics.h"
#include <SDL.h>

Graphics* Graphics::sInstance = nullptr;
bool Graphics::sInitialized = false;

//---------------------------------------------------------------------------------------------//
Graphics* Graphics::Instance(void){

    if(sInstance == nullptr){
        sInstance = new Graphics();
    }

    return sInstance;
}


//---------------------------------------------------------------------------------------------//
void Graphics::Release(void){

    delete sInstance;
    sInstance = nullptr;

    sInitialized = false;
}


//---------------------------------------------------------------------------------------------//
bool Graphics::Initialized(void){

    return sInitialized;
}


//---------------------------------------------------------------------------------------------//
Graphics::Graphics() : mBackBuffer(nullptr) {

    sInitialized = Init();
}


//---------------------------------------------------------------------------------------------//
Graphics::~Graphics(){

    SDL_DestroyWindow(mWindow);
    mWindow = nullptr;

    SDL_Quit();
}


//---------------------------------------------------------------------------------------------//
bool Graphics::Init(void){

    bool status = false;
    int32_t sdl_status = SDL_Init(SDL_INIT_VIDEO);
    if(0 == sdl_status){
        mWindow = SDL_CreateWindow("SDL Tutorial", 
                                    SDL_WINDOWPOS_UNDEFINED, 
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH ,
                                    SCREEN_HEIGHT ,
                                    SDL_WINDOW_SHOWN
                                    );

        if(nullptr != mWindow){
            mBackBuffer = SDL_GetWindowSurface(mWindow);
            status = true;
        }else {
            printf("SDL windoCreation Error : %s\n", SDL_GetError());
        }
    }else{
        printf("SDL Initialization Error : %s\n", SDL_GetError());
    }

    return status;
}


//---------------------------------------------------------------------------------------------//
void Graphics::Render(void){

    SDL_UpdateWindowSurface(mWindow);
}