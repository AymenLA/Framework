#include "Timer.h"


Timer* Timer::sInstance = nullptr;


//---------------------------------------------------------------------------//
Timer* Timer::Instance(void){

    if(nullptr == sInstance){
        sInstance = new Timer();
    }

    return sInstance;
}


//---------------------------------------------------------------------------//
void Timer::Release(void){

    delete sInstance;
    sInstance = nullptr;
}


//---------------------------------------------------------------------------//
Timer::Timer(){

    Reset();
    mTimeScale = 1.0f;
}


//---------------------------------------------------------------------------//
Timer::~Timer(){

}


//---------------------------------------------------------------------------//
void Timer::Reset(void){

    mStartTicks = SDL_GetTicks();
    mElapsedTicks = 0;
    mDeltaTime = 0.0f;
}


//---------------------------------------------------------------------------//
float Timer::DeltaTime(void){

    return mDeltaTime;
}


//---------------------------------------------------------------------------//
void Timer::SetTimeScale(float scale){

    mTimeScale = scale;
}


//---------------------------------------------------------------------------//
float Timer::GetTimeScale(void){

    return mTimeScale;
}


//---------------------------------------------------------------------------//
void Timer::Update(void){

    mElapsedTicks = SDL_GetTicks() - mStartTicks;
    mDeltaTime = mElapsedTicks * 0.001f;
}