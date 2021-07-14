#ifndef _GAMEENTITY_H
#define _GAMEENTITY_H

#include <SDL.h>
#include <stdio.h>
#include "MathHelper.h"

class GameEntity {

public:

    enum SPACE {local = 0, world = 1};

public:

    GameEntity(float x = 0.0f, float y = 0.0f);
    ~GameEntity();

    void SetPos(Vector2 pos);
    Vector2 Pos(SPACE space = world);

    void SetRotation(float rotation);
    float Rotation( SPACE space = world);

    void SetActive(bool active);
    bool Active(void);

    void SetParent(GameEntity* parent);
    GameEntity* Parent(void);

    virtual void Update(void);
    virtual void Render(void);

private:

    Vector2 mPos;
    float mRotation;

    bool mActive;
    GameEntity* mParent;


};


#endif