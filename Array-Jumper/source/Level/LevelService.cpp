#include "../../header/Level/LevelService.h"
#include "../../header/Level/LevelController.h"


namespace Level
{
	LevelService::LevelService()
	{
		levelController = new LevelController();
	}

	LevelService::~LevelService()
	{
		Destroy();
	}
	void LevelService::Destroy()
	{
		delete(levelController);

	}
	void LevelService::Initialize()
	{
		levelController->Initialize();
	}
	void LevelService::Update()
	{
		levelController->Update();
	}
	void LevelService::Render()
	{
		levelController->Render();
	}

	BoxDimensions LevelService::GetBoxDimension()
	{
		return levelController->GetBoxDimensions();
	}
}