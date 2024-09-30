#pragma once

namespace Player
{
	class PlayerController;
	class PlayerService
	{
	private:
		void Destroy();
		PlayerController* playerController;

	public:
		PlayerService();
		~PlayerService();

		void Initialize();
		void Update();
		void render();

		void TakeDamage();

		void LevelComplete();

	};

}