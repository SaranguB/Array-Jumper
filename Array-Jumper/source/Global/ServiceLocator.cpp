#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"
#include "../../header/Event/EventService.h"

namespace Global
{
	using namespace Graphics;
	using namespace Event;
	using namespace Sound;
	using namespace UI;
	using namespace Main;
	using namespace Player;
	using namespace Level;
	using namespace Gameplay;


	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		sound_service = nullptr;
		ui_service = nullptr;
		playerService = nullptr;
		levelService = nullptr;
		gameplayService = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator() { clearAllServices(); }

	void ServiceLocator::createServices()
	{
		graphic_service = new GraphicService();
		event_service = new EventService();
		sound_service = new SoundService();
		ui_service = new UIService();
		playerService = new PlayerService();
		levelService = new LevelService();
		gameplayService = new GameplayService();
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		event_service->initialize();
		sound_service->initialize();
		ui_service->initialize();
		levelService->Initialize();
		playerService->Initialize();
		gameplayService->Initialize();

	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		event_service->update();
		ui_service->update();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplayService->Update();
			levelService->Update();
			playerService->Update();
		}
	}
	void ServiceLocator::render()
	{
		graphic_service->render();
		ui_service->render();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplayService->Render();
			levelService->Render();
			playerService->render();
		}
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphic_service);
		delete(event_service);
		delete(sound_service);
		delete(ui_service);
		delete(playerService);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }

	EventService* ServiceLocator::getEventService() { return event_service; }

	SoundService* ServiceLocator::getSoundService() { return sound_service; }

	UIService* ServiceLocator::getUIService() { return ui_service; }
	Level::LevelService* ServiceLocator::GetLevelService()
	{
		return levelService;
	}
	Player::PlayerService* ServiceLocator::GetPlayerService()
	{
		return playerService;
	}
	Gameplay::GameplayService* ServiceLocator::GetGameplayService()
	{
		return gameplayService;
	}
}