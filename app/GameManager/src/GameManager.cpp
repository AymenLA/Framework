#include <SDL.h>
#include <stdio.h>
#include "GameManager.h"
#include "Graphics.h"

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
}


//---------------------------------------------------------------------------------------------//
GameManager::~GameManager(){

    Graphics::Release();
    mGraphics = nullptr;
}


//---------------------------------------------------------------------------------------------//
void GameManager::Release(){

    delete sInstance;
    sInstance = nullptr;
}

//---------------------------------------------------------------------------------------------//
void GameManager::Run(void){

    while(false == mQuit){

        while(SDL_PollEvent(&mEvents) != 0){
            if(mEvents.type == SDL_QUIT){

                mQuit = true;
            }

            mGraphics->Render();
        }
    }
}