#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"
#include "../../header/Level/LevelData.h"
#include "../../header/Global/ServiceLocator.h"

namespace Player
{
	using namespace Level;
	using namespace Global;
	using namespace Event;
	PlayerController::PlayerController()
	{
		playerModel = new PlayerModel();
		playerView = new PlayerView(this);

	}

	PlayerController::~PlayerController()
	{
	}

	void PlayerController::Destroy()
	{
		delete(playerView);
		delete(playerModel);
	}


	void PlayerController::Initialize()
	{
		playerView->Initialize();
		eventService = ServiceLocator::getInstance()->getEventService();
	}


	void PlayerController::Update()
	{
		playerView->Update();
		ReadInput();
		//printf("CurrentPosition = %d\n", GetCurrentPosition());

	}

	void PlayerController::ReadInput()
	{
		if (eventService->pressedDKey() || eventService->pressedRightArrowKey())
		{
			if (eventService->heldSpaceKey())
			{
				Jump(MovementDirection::FORWARD);
			}
			else
			{

				Move(MovementDirection::FORWARD);
			}
		}
		if (eventService->pressedLeftArrowKey() || eventService->pressedAKey())
		{
			if (eventService->heldSpaceKey())
			{
				Jump(MovementDirection::BACKWARD);
			}
			else
			{
				Move(MovementDirection::BACKWARD);
			}

		}
	}

	void PlayerController::Move(MovementDirection direction)
	{
		int steps = 0, targetPosition;

		switch (direction)
		{
		case MovementDirection::FORWARD:
			//printf("forward");
			steps = 1;
			break;

		case MovementDirection::BACKWARD:
			//printf("Backward");
			steps = -1;
			break;
		default:
			steps = 0;
			break;
		}
		targetPosition = playerModel->GetCurrentPosition() + steps;
		//printf("targetPosiiton %d\n", targetPosition);

		if (!IsPositionInBound(targetPosition))
		{
			return;
		}
		playerModel->SetCurrentPosition(targetPosition);

		ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::MOVE);
		ServiceLocator::getInstance()->GetGameplayService()->OnPositionChanged(targetPosition);
	}

	bool PlayerController::IsPositionInBound(int targetPosition)
	{
		//printf("numberOfBoxes %d\n", LevelData::numberOfBoxes);

		if (targetPosition >= 0 && targetPosition < LevelData::numberOfBoxes)
		{
			return true;
		}

		return false;
	}

	void PlayerController::Jump(MovementDirection direction)
	{
		int currentPosition = playerModel->GetCurrentPosition();
		BlockType boxValue = ServiceLocator::getInstance()->GetLevelService()->GetCurrentBoxValue(currentPosition);

		int steps, targetPosition;
		switch (direction)
		{
		case MovementDirection::FORWARD:
			//printf("forward");
			steps = boxValue;
			break;

		case MovementDirection::BACKWARD:
			//printf("Backward");
			steps = -boxValue;
			break;
		default:
			steps = 0;
			break;
		}

		targetPosition = currentPosition + steps;

		if (!IsPositionInBound(targetPosition))
		{
			return;
		}
		playerModel->SetCurrentPosition(targetPosition);
		ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::JUMP);
		ServiceLocator::getInstance()->GetGameplayService()->OnPositionChanged(targetPosition);

	}

	void PlayerController::Render()
	{
		playerView->Render();
	}

	PlayerState PlayerController::getPlayerState()
	{
		return playerModel->GetPlayerState();
	}
	void PlayerController::setPlayerState(PlayerState state)
	{
		playerModel->SetPlayerState(state);
	}

	int PlayerController::GetCurrentPosition()
	{
		return playerModel->GetCurrentPosition();;
	}
	void PlayerController::TakeDamage()
	{
		playerModel->DecrementLives();

		if (playerModel->GetCurrentLives() <= 0)
		{
			OnDeath();

		}
		else
		{
			playerModel->ResetPosition();
		}
	}
	void PlayerController::Reset()
	{
		playerModel->ResetPlayer();
	}
	int PlayerController::GetCurrentLives()
	{
		return playerModel->GetCurrentLives();;
	}
	void PlayerController::OnDeath()
	{
		ServiceLocator::getInstance()->GetGameplayService()->OnDeath();
		playerModel->ResetPlayer();
	}
}