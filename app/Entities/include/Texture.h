#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "GameEntity.h"
#include "Graphics.h"
#include <string.h>

class Texture : public GameEntity{

public: 

    Texture(std::string path);
    ~Texture();

    virtual void Render();
private:

    SDL_Texture* mTexture;
    Graphics* mGraphics;

};

#endif 