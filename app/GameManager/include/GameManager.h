#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include <SDL.h>
#include <stdio.h>
#include "Graphics.h"

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

    SDL_Event mEvents;
  
};

#endif