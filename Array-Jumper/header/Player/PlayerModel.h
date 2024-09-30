#pragma once

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD,
	};

	class PlayerModel
	{
	private:
		int currentPosition;
		PlayerState playerState;

	public:
		PlayerModel();
		~PlayerModel();

		void SetPlayerState(PlayerState state);
		PlayerState GetPlayerState();

		void SetCurrentPosition(int position);
		int GetCurrentPosition();

	};
}
