#include "Texture.h"
#include <string.h>

//---------------------------------------------------------------------------------------------//
Texture::Texture(std::string path){

    mGraphics = Graphics::Instance();

    mTexture = mGraphics->LoadTexture(path);
}


//---------------------------------------------------------------------------------------------//
Texture::~Texture(){

    SDL_DestroyTexture(mTexture);
    mTexture = nullptr;
    mGraphics = nullptr;
}

//---------------------------------------------------------------------------------------------//
void Texture::Render(void){

    mGraphics->DrawTexture(mTexture);
}