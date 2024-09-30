#pragma once
#include "../../header/Level/LevelData.h"


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
		LevelData currentLevelData;
		

	public:
		LevelModel();
		~LevelModel();

		BlockType GetCurrentBoxValue(int currentPosition);
	};
}