#include "../../header/Player/PlayerView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"

namespace Player
{
	using namespace UI::UIElement;
	using namespace Global;
	using namespace Level;

	PlayerView::PlayerView(PlayerController* controller)
	{
		playerController = controller;
		gameWindow = nullptr;
		playerImage = new ImageView();
	}

	PlayerView::~PlayerView()
	{
		delete(playerImage);
	}

	void PlayerView::Initialize()
	{
		gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		LoadPlayer();
	}

	void PlayerView::LoadPlayer()
	{
		calculatePlayerDimensions();
		InitializePlayerImage();
	}

	void PlayerView::Update()
	{
		UpdatePlayerPosition();

	}

	void PlayerView::Render()
	{
		switch (playerController->getPlayerState())
		{

		case PlayerState::ALIVE:
			DrawPlayer();
			break;
		}

	}

	void PlayerView::InitializePlayerImage()
	{
		playerImage->initialize(Config::character_texture_path, playerWidth, playerHeight, sf::Vector2f(0, 0));
	}
	void PlayerView::DrawPlayer()
	{
		//printf("player Rendered");

		playerImage->render();
	}

	void PlayerView::calculatePlayerDimensions()
	{

		currentBoxDimensions = ServiceLocator::getInstance()->GetLevelService()->GetBoxDimension();

		playerWidth = currentBoxDimensions.boxWidth;
		playerHeight = currentBoxDimensions.boxHeight;
	}

	void PlayerView::UpdatePlayerPosition()
	{
		playerImage->setPosition(calculatePlayerPosition());
	}

	sf::Vector2f PlayerView::calculatePlayerPosition()
	{
		//printf("spacing = %d", playerController->GetCurrentPosition());

		float xPosition = currentBoxDimensions.boxSpacing + static_cast<float>(playerController->GetCurrentPosition()) *
			(currentBoxDimensions.boxWidth + currentBoxDimensions.boxSpacing);
		
		float yPosition = static_cast<float>(gameWindow->getSize().y) - currentBoxDimensions.boxHeight
			- currentBoxDimensions.bottomOffset - playerHeight;

		return sf::Vector2f(xPosition, yPosition);

	}
}