#include "Graphics.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>

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

    SDL_DestroyRenderer(mRenderer);
    mRenderer = nullptr;

    IMG_Quit();
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

            mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

            if(nullptr != mRenderer){

                SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0xff);

                int32_t flag = IMG_INIT_PNG;

                if(true != (IMG_Init(flag) & flag)){

                    mBackBuffer = SDL_GetWindowSurface(mWindow);
                    status = true;
                }else{

                    printf("IMG Initialization Error: %s\n", IMG_GetError());
                }

            }else{

                printf("Renderer Creation Error: %s\n", SDL_GetError());
            }

        }else {

            printf("SDL windoCreation Error : %s\n", SDL_GetError());
        }
    }else{

        printf("SDL Initialization Error : %s\n", SDL_GetError());
    }

    return status;
}


//---------------------------------------------------------------------------------------------//
SDL_Texture* Graphics::LoadTexture(std::string path){

    SDL_Texture* texture = nullptr;

    SDL_Surface* surface = IMG_Load(path.c_str());

    if(nullptr != surface){

        texture = SDL_CreateTextureFromSurface(mRenderer, surface);
        if(nullptr != texture){

            SDL_FreeSurface(surface);
        }else{

            printf("Create Texture Error: Error(%s)\n", SDL_GetError());
        }
    }else{

        printf("Image Load Error: Path(%s) - Error(%s)\n", path.c_str(), IMG_GetError());
    }

    return texture;
}


//---------------------------------------------------------------------------------------------//
void Graphics::ClearBackBuffer(void){

    SDL_RenderClear(mRenderer);
}


//---------------------------------------------------------------------------------------------//
void Graphics::DrawTexture(SDL_Texture* texture){

    SDL_RenderCopy(mRenderer, texture, NULL, NULL);
}


//---------------------------------------------------------------------------------------------//
void Graphics::Render(void){

    SDL_RenderPresent(mRenderer);
}