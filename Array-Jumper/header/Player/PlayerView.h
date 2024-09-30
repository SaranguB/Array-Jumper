#pragma once
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/Level/LevelModel.h"

namespace Player
{
	class PlayerController;

	class PlayerView
	{
	private:
		sf::RenderWindow* gameWindow;
		UI::UIElement::ImageView* playerImage;
		PlayerController* playerController;

		float playerHeight;
		float playerWidth;

		void InitializePlayerImage();
		void DrawPlayer();
		void LoadPlayer();
		void calculatePlayerDimensions();
		void UpdatePlayerPosition();
		sf::Vector2f calculatePlayerPosition();
		Level::BoxDimensions currentBoxDimensions;
		
	public:
		PlayerView(PlayerController* controller);
		~PlayerView();

		void Initialize();
		void Update();
		void Render();

		
	};
}