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
		int currentPosition = 0;
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
