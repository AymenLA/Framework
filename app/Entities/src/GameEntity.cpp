#include <SDL.h>
#include <stdio.h>
#include "GameEntity.h"


//---------------------------------------------------------------------------------------------//
GameEntity::GameEntity(float x, float y){

    mPos.x = x;
    mPos.y = y;

    mRotation = 0.0f;
    mActive = true;
    mParent = nullptr;
}


//---------------------------------------------------------------------------------------------//
GameEntity::~GameEntity(){

    mParent = nullptr;
}


//---------------------------------------------------------------------------------------------//
void GameEntity::SetPos(Vector2 pos){

    mPos = pos;
}


//---------------------------------------------------------------------------------------------//
Vector2 GameEntity::Pos(SPACE space){

    if((space == local) || (mParent == nullptr)){
        return mPos;
    }

    return mParent->Pos(world) + RotateVector(mPos, mParent->Rotation(local));
}


//---------------------------------------------------------------------------------------------//
void GameEntity::SetRotation(float angle){

    mRotation = angle;

    if(mRotation > 360.0f){
        mRotation -= 360.0f;
    }

    if(mRotation < 0.0f){

        mRotation += 360.0f;
    }
}


//---------------------------------------------------------------------------------------------//
float GameEntity::Rotation(SPACE space){

    if((space == local) || (mParent == nullptr)){
        return mRotation;
    }

    return mParent->Rotation(world) + mRotation;
}


//---------------------------------------------------------------------------------------------//
void GameEntity::SetActive(bool active){

    mActive = active;
}


//---------------------------------------------------------------------------------------------//
bool GameEntity::Active(void){

    return mActive;
}


//---------------------------------------------------------------------------------------------//
void GameEntity::SetParent(GameEntity* parent){

    mPos = Pos(world) - parent->Pos(world);

    mParent = parent;
}


//---------------------------------------------------------------------------------------------//
GameEntity* GameEntity::Parent(void){

    return mParent;
}


//---------------------------------------------------------------------------------------------//
void GameEntity::Update(void){


}


//---------------------------------------------------------------------------------------------//
void GameEntity::Render(void){


}