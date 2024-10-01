#pragma once
#include "../../header/Level/LevelData.h"
#include "LevelConfig.h"


namespace Level
{

	struct BoxDimensions
	{
		float boxWidth;
		float boxHeight;
		float boxSpacing;

		float boxSpacingPercentage = .3f;
		float bottomOffset = 200.f;
	};

	class LevelModel
	{
	private:
		const int numberOfLevels = LevelConfig::numberOfLevels;
		LevelConfig levelConfig;
		int currentLevelIndex = 0;


	public:
		LevelModel();
		~LevelModel();

		BlockType GetCurrentBoxValue(int currentPosition);

		void LoadNextLevel();
		int GetCurrentLevelNumber();
		bool IsLastlevel();

		void Reset();
	};
}