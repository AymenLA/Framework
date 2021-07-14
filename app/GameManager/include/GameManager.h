#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include <SDL.h>
#include <stdio.h>
#include "Graphics.h"
#include "Timer.h"
#include "GameEntity.h"

class GameManager {

public:

    static GameManager* Instance();
    static void Release();

    void Run(void);

    
private:
    GameManager();
    ~GameManager();

private:
    static GameManager* sInstance;
    bool mQuit;
    Graphics* mGraphics;

    Timer* mTimer;

    GameEntity* mParent;
    GameEntity* mChild;

    SDL_Event mEvents;

    const uint32_t FRAME_RATE = 60U;
  
};

#endif