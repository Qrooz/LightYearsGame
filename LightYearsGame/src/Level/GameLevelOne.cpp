#include "Level/GameLevelOne.h"
#include "Enemy/UFOStage.h"
#include "Enemy/HexagonStage.h"
#include "Enemy/TwinBladeStage.h"
#include "Enemy/VanguardStage.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "framework/AssetManager.h"
#include "framework/TimerManager.h"
#include "gameplay/GameStage.h"
#include "gameplay/WaitStage.h"
#include "player/PlayerSpaceship.h"
#include "player/PlayerManager.h"


namespace ly {
	GameLevelOne::GameLevelOne(Application* owningApp)
		:World{owningApp}
	{
		

	}
	void GameLevelOne::BeginPlay()
	{
		Player newPlayer = PlayerManager::Get().CreateNewPlayer();
		mPlayerSpaceship = newPlayer.SpawnSpaceShip(this);
		mPlayerSpaceship.lock()->onActorDestroyed.BindAction(GetWeakRef(), &GameLevelOne::PlayerSpaceshipDestroyed);
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
		AddStage(shared<UFOStage>{new UFOStage{this}});
		AddStage(shared<WaitStage>{new WaitStage{ this, 5.f }});
		AddStage(shared<VanguardStage>{new VanguardStage{this}});
		AddStage(shared<WaitStage>{new WaitStage{ this, 15.f }});
		//AddStage(shared<TwinBladeStage>{new TwinBladeStage{ this }});
		//AddStage(shared<WaitStage>{new WaitStage{ this, 15.f }});
		//AddStage(shared<HexagonStage>{new HexagonStage{ this }});
	}
	void GameLevelOne::GameOver()
	{
		LOG("Game Over! ====================================================");
	}
}