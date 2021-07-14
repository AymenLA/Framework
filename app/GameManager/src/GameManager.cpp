#include <SDL.h>
#include <stdio.h>
#include "GameManager.h"
#include "Graphics.h"
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

    mParent = new GameEntity(100.0f, 400.0f);
    mChild = new GameEntity(100.0f, 500.0f);

    printf("Child local pos: (%F, %F)\n", mChild->Pos(GameEntity::local).x, 
                                          mChild->Pos(GameEntity::local).y);

    mChild->SetParent(mParent);

    printf("Child local pos: (%F, %F)\n", mChild->Pos(GameEntity::local).x, 
                                          mChild->Pos(GameEntity::local).y);
}


//---------------------------------------------------------------------------------------------//
GameManager::~GameManager(){

    Graphics::Release();
    mGraphics = nullptr;

    Timer::Release();
    mTimer = nullptr;

    delete mParent;
    delete mChild;
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

            mGraphics->Render();
            mTimer->Reset();
        }

    }
}