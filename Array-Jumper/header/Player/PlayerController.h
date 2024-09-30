#pragma once
#include "MovementDirection.h"
#include "../../header/Event/EventService.h"


namespace Player
{
	class PlayerView;
	class PlayerModel;
	
	enum class PlayerState;
	class PlayerController
	{
	private:
		PlayerModel* playerModel;
		PlayerView* playerView;
		Event::EventService* eventService;

		void Destroy();

		void Move(MovementDirection direction);

		bool IsPositionInBound(int targetPosition);

		void ReadInput();
	public:
		PlayerController();
		~PlayerController();

		void Initialize();
		void Update();
		void Render();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState state);

		int GetCurrentPosition();
	};
}
