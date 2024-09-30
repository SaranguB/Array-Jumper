#include "../../header/Player/PlayerModel.h"

namespace Player
{
	PlayerModel::PlayerModel()
	{
		playerState = PlayerState::ALIVE;
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
}