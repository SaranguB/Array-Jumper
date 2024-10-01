#pragma once
#include "../../header/Level/BlockType.h"

namespace Gameplay
{
	class GameplayView;
	class GameplayModel;
	class GameplayController
	{
	private:
		GameplayView* gameplayView;
		GameplayModel* gameplayModel;

		void ProcessObstacle();
		void GameOver();
	public:
		GameplayController();
		~GameplayController();

		void Initialize();
		void Update();
		void Render();

		bool IsObsatcle(Level::BlockType value);
		void OnPositionChanged(int posiition);

		bool IsendBlock(Level::BlockType value);
		void processEndBlock();

		
		void OnDeath();

	};
}
