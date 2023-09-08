#include "header/GameService.h"

int main()
{
    GameService* game_service = new GameService();
    game_service->ignite();

    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    }

    delete(game_service);
    return 0;
}