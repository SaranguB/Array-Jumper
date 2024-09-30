#include "../../header/Player/PlayerModel.h"

namespace Player
{
	PlayerModel::PlayerModel()
	{
		ResetPlayer();
	}
	PlayerModel::~PlayerModel()
	{
	}
	void PlayerModel::SetPlayerState(PlayerState state)
	{
		playerState = state;
	}

	PlayerState PlayerModel::GetPlayerState()
	{
		return playerState;
	}
	void PlayerModel::SetCurrentPosition(int position)
	{
		currentPosition = position;
	}
	int PlayerModel::GetCurrentPosition()
	{
		return currentPosition;
	}
	void PlayerModel::ResetPlayer()
	{
		currentPosition = 0;
		playerState = PlayerState::ALIVE;
		currentLives = maxLives;

	}
	int PlayerModel::GetCurrentLives()
	{
		return currentLives;
	}
	void PlayerModel::DecrementLives()
	{
		currentLives--;
	}
	void PlayerModel::ResetPosition()
	{
		currentPosition = 0;
	}
}