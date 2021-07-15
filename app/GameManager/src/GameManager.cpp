#include <SDL.h>
#include <stdio.h>
#include "GameManager.h"
#include "Graphics.h"
#include "GameEntity.h"
#include "Texture.h"
#include "Timer.h"

GameManager* GameManager::sInstance = nullptr;


//---------------------------------------------------------------------------------------------//
GameManager* GameManager::Instance(void){

    if(nullptr == sInstance){
        sInstance = new GameManager();
    }

    return sInstance;
}


//---------------------------------------------------------------------------------------------//
GameManager::GameManager() : mQuit(false){

    mGraphics = Graphics::Instance();

    if(false == Graphics::Initialized()){
        mQuit = true;
    }

    mTimer = Timer::Instance();

    std::string path = SDL_GetBasePath();
    path.append("Assets/galaga.png");

    mTexture = new Texture(path);
}


//---------------------------------------------------------------------------------------------//
GameManager::~GameManager(){

    Graphics::Release();
    mGraphics = nullptr;

    Timer::Release();
    mTimer = nullptr;

    delete mTexture;
    mTexture = nullptr;
}


//---------------------------------------------------------------------------------------------//
void GameManager::Release(){

    delete sInstance;
    sInstance = nullptr;
}

//---------------------------------------------------------------------------------------------//
void GameManager::Run(void){

    while(false == mQuit){

        mTimer->Update();

        while(SDL_PollEvent(&mEvents) != 0){
            if(mEvents.type == SDL_QUIT){

                mQuit = true;
            }
        }

        if(mTimer->DeltaTime() >= (1.0f / FRAME_RATE)){

            mGraphics->ClearBackBuffer();

            mTexture->Render();

            mGraphics->Render();

            mTimer->Reset();
        }

    }
}