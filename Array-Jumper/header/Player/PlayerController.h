#pragma once


namespace Player
{
	class PlayerView;
	class PlayerModel;

	enum class PlayerState;
	class PlayerController
	{
	private:
		PlayerModel* playerModel;
		PlayerView* playerView;

		void Destroy();
	public:
		PlayerController();
		~PlayerController();

		void Initialize();
		void Update();
		void Render();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState state);

		int GetCurrentPosition();
	};
}
