#pragma once
#include "BlockType.h"
#include "LevelData.h"

namespace Level
{
	class LevelConfig
	{
	private:
		BlockType level1[LevelData::numberOfBoxes] =
		{
			 ONE, TWO, OBSTACLE_ONE, TWO, THREE, ONE, OBSTACLE_TWO, TWO, ONE, TARGET
		};
		BlockType level2[LevelData::numberOfBoxes] =
		{
			 ONE, TWO, OBSTACLE_TWO, ONE, TWO, OBSTACLE_ONE, THREE, OBSTACLE_ONE, ONE, TARGET

		};
		BlockType level3[LevelData::numberOfBoxes] =
		{
			 ONE, THREE, OBSTACLE_ONE, OBSTACLE_TWO, ONE, TWO, OBSTACLE_ONE, TWO, ONE, TARGET

		};
	public:

		static const int numberOfLevels = 3;
		LevelData levels[numberOfLevels];
		LevelConfig()
		{
			for (int i = 0; i < LevelData::numberOfBoxes; i++)
			{
				levels[0].levelBoxes[i] = level1[i];
			}
			for (int i = 0;i < LevelData::numberOfBoxes;i++)
			{
				levels[1].levelBoxes[i] = level2[i];
			}
			for (int i = 0;i < LevelData::numberOfBoxes;i++)
			{
				levels[2].levelBoxes[i] = level2[i];
			}
		}


	};
}
