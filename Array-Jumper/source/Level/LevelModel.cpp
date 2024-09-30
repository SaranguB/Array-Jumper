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
        return currentLevelData.levelBoxes[currentPosition];
    }
}   