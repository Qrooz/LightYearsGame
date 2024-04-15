#pragma once
#include "framework/World.h"
namespace ly {
	class MainMenuHUD;
	class MainMenuLevel : public World{
	public:
		MainMenuLevel(Application* owningApp);
		virtual void BeginPlay() override;

		void StartGame();
		void QuitGame();
	private:
		weak<MainMenuHUD> mMainMenuHUD;
	};

}