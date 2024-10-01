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
		const int maxLives = 3;
		int currentLives;

	public:
		PlayerModel();
		~PlayerModel();

		void SetPlayerState(PlayerState state);
		PlayerState GetPlayerState();

		void SetCurrentPosition(int position);
		int GetCurrentPosition();

		void ResetPlayer();

		int GetCurrentLives();
		void DecrementLives();

		void ResetPosition();

	};
}
