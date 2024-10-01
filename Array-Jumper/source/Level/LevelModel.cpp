#include "../../header/Level/LevelModel.h"

namespace Level
{
	LevelModel::LevelModel()
	{
	}
	LevelModel::~LevelModel()
	{
	}
	BlockType LevelModel::GetCurrentBoxValue(int currentPosition)
	{
		return levelConfig.levels[currentLevelIndex].levelBoxes[currentPosition];
	}
	void LevelModel::LoadNextLevel()
	{
		currentLevelIndex++;
	}
	int LevelModel::GetCurrentLevelNumber()
	{
		return currentLevelIndex + 1;
	}
	bool LevelModel::IsLastlevel()
	{
		if (currentLevelIndex == LevelConfig::numberOfLevels - 1)
			return true;
		return false;
	}
	void LevelModel::Reset()
	{
		currentLevelIndex = 0;
	}
}