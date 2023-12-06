#ifndef _ASSET_MANAGER_
#define _ASSET_MANAGER_

#include "Graphics.h"
#include "map"

class AssetManager {

private:
    
    static AssetManager* sInstance;

    std::map<std::string, SDL_Texture*> mTexture;

public:
    
    static AssetManager* Instance();
    static void Release();

    SDL_Texture* GetTexture(std::string filename);

private:

    AssetManager();
    ~AssetManager();
};

#endif