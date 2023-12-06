#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "GameEntity.h"
#include "AssetManager.h"
#include <string.h>

class Texture : public GameEntity{

public: 

    Texture(std::string filename);
    ~Texture();

    virtual void Render();
private:

    SDL_Texture* mTexture;
    Graphics* mGraphics;

    int mHeight;
    int mWidth;
};

#endif 