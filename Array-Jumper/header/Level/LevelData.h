#pragma once
#include "../../header/Level/BlockType.h"

namespace Level
{
	struct LevelData
	{
		static const int numberOfBoxes = 10;
		BlockType levelBoxes[numberOfBoxes] = {
			BlockType::ONE,
			BlockType::TWO,
			BlockType::OBSTACLE_ONE,
			BlockType::TWO,
			BlockType::THREE,
			BlockType::ONE,
			BlockType::OBSTACLE_TWO,
			BlockType::TWO,
			BlockType::ONE,
			BlockType::TARGET };
		
		
	};
}