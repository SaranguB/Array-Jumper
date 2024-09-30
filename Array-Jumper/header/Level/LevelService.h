#pragma once


namespace Level
{
	class LevelController;
	struct BoxDimensions;
	class LevelService
	{
	private:
		LevelController* levelController;

	public:
		LevelService();
		~LevelService();

		void Destroy();

		void Initialize();
		void Update();
		void Render();

		BoxDimensions GetBoxDimension();
	};
}
