#include "AssetManager.h"

AssetManager* AssetManager::sInstance = nullptr;


//---------------------------------------------------------------------------//
AssetManager* AssetManager::Instance() {
    if(sInstance == NULL) {
        sInstance = new AssetManager();
    }

    return sInstance;
}


//---------------------------------------------------------------------------//
void AssetManager::Release() {
    delete sInstance;
    sInstance = nullptr;
}

AssetManager::AssetManager() {

}


//---------------------------------------------------------------------------//
AssetManager::~AssetManager() {
    for(auto tex : mTexture) {
        if(tex.second != nullptr)
        {
            SDL_DestroyTexture(tex.second);
        }
    }

    mTexture.clear();
}


//---------------------------------------------------------------------------//
SDL_Texture* AssetManager::GetTexture(std::string filename) {
    std::string fullPath = SDL_GetBasePath();
    fullPath.append("../extra/Assets/" + filename);

    if(mTexture[fullPath] == nullptr) {
        mTexture[fullPath] = Graphics::Instance()->LoadTexture(fullPath);
    }

    return mTexture[fullPath];
}