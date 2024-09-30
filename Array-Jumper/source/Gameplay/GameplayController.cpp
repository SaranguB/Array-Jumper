#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Gameplay/GameplayModel.h"
#include "../../header/Gameplay/GameplayView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"


namespace Gameplay
{
	using namespace Global;
	using namespace Level;
	using namespace Main;

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
		if (IsendBlock(boxValue))
		{
			processEndBlock();
		}
	}

	bool GameplayController::IsendBlock(Level::BlockType value)
	{
		if (value == BlockType::TARGET)
			return true;
		return false;

	}

	void GameplayController::processEndBlock()
	{
		ServiceLocator::getInstance()->GetPlayerService()->LevelComplete();
		ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::LEVEL_COMPLETE);
		GameService::setGameState(GameState::CREDITS);
	}

	void GameplayController::OnDeath()
	{
		GameOver();
	}

	void GameplayController::GameOver()
	{
		GameService::setGameState(GameState::CREDITS);
		ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DEATH);

	}

	void GameplayController::ProcessObstacle()
	{
		ServiceLocator::getInstance()->GetPlayerService()->TakeDamage();
		ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DEATH);
	}
}