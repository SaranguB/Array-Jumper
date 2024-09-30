#include "../../header/Player/playerService.h"
#include "../../header/Player/PlayerController.h"

namespace Player
{

	PlayerService::PlayerService()
	{
		playerController = new PlayerController();
	}

	PlayerService::~PlayerService()
	{
		Destroy();
	}

	void PlayerService::Initialize()
	{
		playerController->Initialize();
	}

	void PlayerService::Update()
	{
		playerController->Update();
	}

	void PlayerService::render()
	{
		playerController->Render();
	}

	void PlayerService::Destroy()
	{
		delete(playerController);
	}
}