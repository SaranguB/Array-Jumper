#include "../../header/Level/LevelView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include "../../header/Level/LevelController.h"


namespace Level
{
	using namespace Global;
	using namespace UI::UIElement;

	LevelView::LevelView(LevelController* controller)
	{
		gameWindow = nullptr;
		levelController = controller;
		CreateImages();
	}

	LevelView::~LevelView()
	{
		DeleteImages();
	}
	void LevelView::Initialize()
	{
		gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		CalculateBoxDimensions();
		InitializeImages();
	}
	void LevelView::Update()
	{
		UpdateImages();
	}
	void LevelView::Render()
	{
		DrawLevel();
	}

	BoxDimensions LevelView::GetBoxDimesnion()
	{
		return boxDimensions;
	}

	void LevelView::CreateImages()
	{
		backgroundImage = new ImageView();
		boxImage = new ImageView();
		target_overlay_image = new ImageView();
		letter_one_overlay_image = new ImageView();
		letter_two_overlay_image = new ImageView();
		letter_three_overlay_image = new ImageView();
		obstacle_one_overlay_image = new ImageView();
		obstacle_two_overlay_image = new ImageView();
	}
	void LevelView::InitializeImages()
	{
		backgroundImage->initialize(Config::array_jumper_bg_texture_path, gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0, 0));
		backgroundImage->setImageAlpha(backgroundAlpha);

		boxImage->initialize(Config::box_texture_path, boxDimensions.boxWidth, boxDimensions.boxHeight, sf::Vector2f(0, 0));

		target_overlay_image->initialize(Config::target_texture_path, boxDimensions.boxWidth, boxDimensions.boxHeight, sf::Vector2f(0, 0));
		letter_one_overlay_image->initialize(Config::letter_one_texture_path, boxDimensions.boxWidth, boxDimensions.boxHeight, sf::Vector2f(0, 0));
		letter_two_overlay_image->initialize(Config::letter_two_texture_path, boxDimensions.boxWidth, boxDimensions.boxHeight, sf::Vector2f(0, 0));
		letter_three_overlay_image->initialize(Config::letter_three_texture_path, boxDimensions.boxWidth, boxDimensions.boxHeight, sf::Vector2f(0, 0));
		obstacle_one_overlay_image->initialize(Config::obstacle_01_texture_path, boxDimensions.boxWidth, boxDimensions.boxHeight, sf::Vector2f(0, 0));
		obstacle_two_overlay_image->initialize(Config::obstacle_02_texture_path, boxDimensions.boxWidth, boxDimensions.boxHeight, sf::Vector2f(0, 0));

	}
	void LevelView::UpdateImages()
	{
		backgroundImage->update();
		boxImage->update();
		target_overlay_image->update();
		letter_one_overlay_image->update();
		letter_two_overlay_image->update();
		letter_three_overlay_image->update();
		obstacle_one_overlay_image->update();
		obstacle_two_overlay_image->update();
	}

	void LevelView::DeleteImages()
	{
		delete(backgroundImage);
		delete(boxImage);
		delete(target_overlay_image);
		delete(letter_one_overlay_image);
		delete(letter_two_overlay_image);
		delete(letter_three_overlay_image);
		delete(obstacle_one_overlay_image);
		delete(obstacle_two_overlay_image);
	}

	void LevelView::DrawLevel()
	{
		backgroundImage->render();

		for (int i = 0;i < LevelData::numberOfBoxes;i++)
		{
			sf::Vector2f position = calculateBoxPosition(i);
			BlockType blockTypeToDraw = levelController->GetCurrentBoxValue(i);
			DrawBox(position);
			DrawBoxValue(position, blockTypeToDraw);
		}


	}
	void LevelView::CalculateBoxDimensions()
	{
		if (gameWindow == nullptr)return;

		CalculateBoxWidthHeight();
		CalculateBoxSpacing();
	}

	void LevelView::CalculateBoxWidthHeight()
	{
		float screenWidth = static_cast<float>(gameWindow->getSize().x);

		int numBoxes = LevelData::numberOfBoxes;

		int numGaps = numBoxes + 1;

		float totalSpaceByGaps = boxDimensions.boxSpacingPercentage * static_cast<float>(numGaps);

		float totalSpace = numBoxes + totalSpaceByGaps;

		boxDimensions.boxWidth = screenWidth / (totalSpace);
		boxDimensions.boxHeight = boxDimensions.boxWidth;
	}

	void LevelView::CalculateBoxSpacing()
	{
		boxDimensions.boxSpacing = boxDimensions.boxSpacingPercentage * boxDimensions.boxWidth;
	}

	sf::Vector2f LevelView::calculateBoxPosition(int index)
	{
		float xPosition = boxDimensions.boxSpacing + static_cast<float>(index) * (boxDimensions.boxWidth + boxDimensions.boxSpacing);
		float yPosition = static_cast<float>(gameWindow->getSize().y) - boxDimensions.boxHeight - boxDimensions.bottomOffset;

		return sf::Vector2f(xPosition, yPosition);
	}

	ImageView* LevelView::GetBoxOverlayImage(BlockType type)
	{
		switch (type)
		{
		case BlockType::OBSTACLE_ONE:
			return obstacle_one_overlay_image;

		case BlockType::OBSTACLE_TWO:
			return obstacle_two_overlay_image;

		case BlockType::ONE:
			return letter_one_overlay_image;

		case BlockType::TWO:
			return letter_two_overlay_image;

		case BlockType::THREE:
			return letter_three_overlay_image;

		case BlockType::TARGET:
			return target_overlay_image;
		}
		return nullptr;

	}



	void LevelView::DrawBox(sf::Vector2f position)
	{
		boxImage->setPosition(position);
		boxImage->render();


	}

	void LevelView::DrawBoxValue(sf::Vector2f position, BlockType type)
	{
		ImageView* image = GetBoxOverlayImage(type);
		image->setPosition(position);
		image->render();
	}
}