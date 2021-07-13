#ifndef _TIMER_H_
#define _TIMER_H_

#include <SDL.h>
#include <stdio.h>
#include <stdint.h>

class Timer{

public:

    static Timer* Instance(void);
    static void Release(void);

    void Reset(void);
    float DeltaTime(void);

    void SetTimeScale(float scale);
    float GetTimeScale(void);

    void Update(void);

private:

    Timer();
    ~Timer();

private:

    static Timer* sInstance;
    uint32_t mStartTicks;
    uint32_t mElapsedTicks;
    float mDeltaTime;
    float mTimeScale;

};

#endif