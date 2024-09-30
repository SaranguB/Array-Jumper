#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"

namespace Player
{

	PlayerController::PlayerController()
	{
		playerModel = new PlayerModel();
		playerView = new PlayerView(this);
	}

	PlayerController::~PlayerController()
	{
	}

	void PlayerController::Destroy()
	{
		delete(playerView);
		delete(playerModel);
	}

	void PlayerController::Initialize()
	{
		//playerModel->SetPlayerState(PlayerState::ALIVE);
		playerView->Initialize();
	}

	void PlayerController::Update()
	{
		playerView->Update();
	}

	void PlayerController::Render()
	{
		playerView->Render();
	}

	PlayerState PlayerController::getPlayerState()
	{
		return playerModel->GetPlayerState();
	}
	void PlayerController::setPlayerState(PlayerState state)
	{
		playerModel->SetPlayerState(state);
	}

	int PlayerController::GetCurrentPosition()
	{
		return playerModel->GetCurrentPosition();;
	}
}