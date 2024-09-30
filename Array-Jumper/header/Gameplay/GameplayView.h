#pragma once

namespace Gameplay
{
	class GameplayController;
	class GameplayView
	{
	private:

	public:
		GameplayView(GameplayController* controller);
		~GameplayView();

		void Initialize();
		void Update();
		void Render();
	};
}
