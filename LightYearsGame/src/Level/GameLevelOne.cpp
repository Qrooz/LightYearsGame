#include "Level/GameLevelOne.h"
#include "Enemy/BossStage.h"
#include "Enemy/ChaosStage.h"
#include "Enemy/UFOStage.h"
#include "Enemy/HexagonStage.h"
#include "Enemy/TwinBladeStage.h"
#include "Enemy/VanguardStage.h"
#include "framework/Actor.h"
#include "framework/BackdropActor.h"
#include "framework/Application.h"
#include "framework/World.h"
#include "framework/AssetManager.h"
#include "framework/TimerManager.h"
#include "gameplay/GameStage.h"
#include "gameplay/WaitStage.h"
#include "player/PlayerSpaceship.h"
#include "player/PlayerManager.h"
#include "widgets/GameplayHUD.h"

namespace ly {
	GameLevelOne::GameLevelOne(Application* owningApp)
		:World{owningApp}
	{
		

	}
	void GameLevelOne::AllStageFinished()
	{
		mGameplayHUD.lock()->GameFinished(true);
	}
	void GameLevelOne::BeginPlay()
	{
		SpawnCosmetics();
		Player& newPlayer = PlayerManager::Get().CreateNewPlayer();
		mPlayerSpaceship = newPlayer.SpawnSpaceShip(this);
		mPlayerSpaceship.lock()->onActorDestroyed.BindAction(GetWeakRef(), &GameLevelOne::PlayerSpaceshipDestroyed);
		mGameplayHUD = SpawnHUD<GameplayHUD>();
		mGameplayHUD.lock()->onQuitBtnClicked.BindAction(GetWeakRef(), &GameLevelOne::QuitGame);
		mGameplayHUD.lock()->onRestartBtnClicked.BindAction(GetWeakRef(), &GameLevelOne::Restart);
	}

	void GameLevelOne::PlayerSpaceshipDestroyed(Actor* destroyedPlayerSpaceship)
	{
		mPlayerSpaceship = PlayerManager::Get().GetPlayer()->SpawnSpaceShip(this);
		if (!mPlayerSpaceship.expired()) {
			mPlayerSpaceship.lock()->onActorDestroyed.BindAction(GetWeakRef(), &GameLevelOne::PlayerSpaceshipDestroyed);
		}
		else {
			GameOver();
		}
	}

	void GameLevelOne::InitGameStages()
	{
		
		AddStage(shared<WaitStage>{new WaitStage{ this, 5.f }});
		AddStage(shared<VanguardStage>{new VanguardStage{ this }});
		
		AddStage(shared<WaitStage>{new WaitStage{ this, 5.f }});
		AddStage(shared<TwinBladeStage>{new TwinBladeStage{ this }});
		
		AddStage(shared<WaitStage>{new WaitStage{ this, 5.f }});
		AddStage(shared<HexagonStage>{new HexagonStage{ this }});
		
		AddStage(shared<WaitStage>{new WaitStage{ this, 5.f }});
		AddStage(shared<UFOStage>{new UFOStage{this}});
		
		AddStage(shared<WaitStage>{new WaitStage{ this, 5.f }});
		AddStage(shared<ChaosStage>{new ChaosStage{ this }});

		AddStage(shared<WaitStage>{new WaitStage{ this, 5.f }});
		AddStage(shared<BossStage>{new BossStage{this}});
	}
	void GameLevelOne::QuitGame()
	{
		GetApplication()->QuitApplication();
	}
	void GameLevelOne::Restart()
	{
		PlayerManager::Get().Reset();
		GetApplication()->LoadWorld<GameLevelOne>();
	}
	void GameLevelOne::GameOver()
	{
		mGameplayHUD.lock()->GameFinished(false);
	}
	
	void GameLevelOne::SpawnCosmetics()
	{
		auto backdropActor = SpawnActor<BackdropActor>("SpaceShooterRedux/Backgrounds/darkPurple.png");
	}
}