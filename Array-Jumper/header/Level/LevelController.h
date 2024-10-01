#pragma once
#include "BlockType.h"
#include "LevelModel.h"

namespace Level
{
	class LevelModel;
	class LevelView;

	class LevelController
	{
	private:
		LevelModel* levelModel;
		LevelView* levelView;

	public:
		LevelController();
		~LevelController();


		void Initialize();
		void Update();
		void Render();

		BlockType GetCurrentBoxValue(int currentPosition);
		BoxDimensions GetBoxDimensions();

		bool IsLastLevel();
		void LoadLastLevel();
		int GetCurrentLevelNumber();
	};
}
