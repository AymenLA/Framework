#include "GameManager.h"

int32_t main(int argc, char* argv[]){

    GameManager* game = GameManager::Instance();

    game->Run();

    GameManager::Release();
    game = nullptr;
    
    return 0;
}