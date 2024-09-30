#pragma once
#include "../../header/UI/UIElement/ImageView.h"
#include "LevelModel.h"


namespace Level
{
	class LevelController;
	class LevelView
	{

	private:
		sf::RenderWindow* gameWindow;
		LevelController* levelController;
		BoxDimensions boxDimensions;

		UI::UIElement::ImageView* backgroundImage;
		UI::UIElement::ImageView* boxImage;

		UI::UIElement::ImageView* target_overlay_image;
		UI::UIElement::ImageView* letter_one_overlay_image;
		UI::UIElement::ImageView* letter_two_overlay_image;
		UI::UIElement::ImageView* letter_three_overlay_image;
		UI::UIElement::ImageView* obstacle_one_overlay_image;
		UI::UIElement::ImageView* obstacle_two_overlay_image;

		UI::UIElement::ImageView* GetBoxOverlayImage(BlockType type);


		void DrawBoxValue(sf::Vector2f position, BlockType type);
		void DrawBox(sf::Vector2f position);


		const float backgroundAlpha = 110.f;
		
		void CreateImages();
		void InitializeImages();
		void UpdateImages();
		void DrawLevel();
		void DeleteImages();

		void CalculateBoxDimensions();
		void CalculateBoxWidthHeight();
		void CalculateBoxSpacing();
		
		sf::Vector2f calculateBoxPosition(int index);


	public:
		LevelView(LevelController* controller);
		~LevelView();

		void Initialize();
		void Update();
		void Render();

		BoxDimensions GetBoxDimesnion();	

	};
}