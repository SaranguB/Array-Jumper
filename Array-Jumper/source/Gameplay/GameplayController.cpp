#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Gameplay/GameplayModel.h"
#include "../../header/Gameplay/GameplayView.h"
#include "../../header/Global/ServiceLocator.h"


namespace Gameplay
{
	using namespace Global;
	using namespace Level;;
	GameplayController::GameplayController()
	{
		gameplayView = new GameplayView(this);
		gameplayModel = new GameplayModel();
	}
	GameplayController::~GameplayController()
	{
		delete(gameplayView);
		delete(gameplayModel);
	}
	void GameplayController::Initialize()
	{
		gameplayModel->Initialize();
		gameplayView->Initialize();
	}
	void GameplayController::Update()
	{
		gameplayView->Update();
	}
	void GameplayController::Render()
	{
		gameplayView->Render();
	}

	bool GameplayController::IsObsatcle(Level::BlockType value)
	{
		if (value == BlockType::OBSTACLE_ONE || value == BlockType::OBSTACLE_TWO)
			return true;
		return false;
	}

	void GameplayController::OnPositionChanged(int poisition)
	{
		BlockType boxValue = ServiceLocator::getInstance()->GetLevelService()->GetCurrentBoxValue(poisition);

		if (IsObsatcle(boxValue))
		{
			ProcessObstacle();
		}
	}

	void GameplayController::ProcessObstacle()
	{
		ServiceLocator::getInstance()->GetPlayerService()->TakeDamage();
		ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DEATH);
	}
}