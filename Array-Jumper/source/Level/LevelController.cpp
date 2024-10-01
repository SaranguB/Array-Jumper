#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelModel.h"
#include "../../header/Level/LevelView.h"

namespace Level
{
	LevelController::LevelController()
	{
		levelModel = new LevelModel();
		levelView = new LevelView(this);
	}
	LevelController::~LevelController()
	{
		delete(levelModel);
		delete(levelView);
	}

	void LevelController::Initialize()
	{
		levelView->Initialize();
	}
	void LevelController::Update()
	{
		levelView->Update();
	}
	void LevelController::Render()
	{
		levelView->Render();
	}

	BlockType LevelController::GetCurrentBoxValue(int currentPosition)
	{
		return levelModel->GetCurrentBoxValue(currentPosition);
	}

	BoxDimensions LevelController::GetBoxDimensions()
	{
		return levelView->GetBoxDimesnion();
	}
	bool LevelController::IsLastLevel()
	{
		return levelModel->IsLastlevel();;
	}
	void LevelController::LoadLastLevel()
	{
		levelModel->LoadNextLevel();
	}
	int LevelController::GetCurrentLevelNumber()
	{
		return levelModel->GetCurrentLevelNumber();;
	}
}