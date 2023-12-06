#include "Texture.h"
#include <string.h>
#include "iostream"

//---------------------------------------------------------------------------//
Texture::Texture(std::string filename){

    mGraphics = Graphics::Instance();

    mTexture = AssetManager::Instance()->GetTexture(filename);

    SDL_QueryTexture(mTexture, NULL, NULL, &mWidth, &mHeight);
}


//---------------------------------------------------------------------------//
Texture::~Texture(){

    mTexture = nullptr;
    mGraphics = nullptr;
}

//---------------------------------------------------------------------------//
void Texture::Render(void){

    mGraphics->DrawTexture(mTexture);
}