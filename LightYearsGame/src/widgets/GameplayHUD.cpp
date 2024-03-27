#include "widgets/GameplayHUD.h"
#include "player/PlayerManager.h"
#include "player/PlayerSpaceship.h"
#include "player/player.h"
#include "framework/Actor.h"

namespace ly {
	GameplayHUD::GameplayHUD()
		:mFramerateText{"Frame Rate:"},
		mPlayerHealthBar{},
		mHealthyHealthBarColor{128,255,128,255},
		mCriticalHealthBarColor{255,0,0,255},
		mCriticalThreshold{0.3}
	{
		mFramerateText.SetTextSize(30);
	}
	
	void GameplayHUD::Draw(sf::RenderWindow& windowRef)
	{
		mFramerateText.NativeDraw(windowRef);
		mPlayerHealthBar.NativeDraw(windowRef);
	}
	void GameplayHUD::Tick(float deltaTime)
	{
		int frameRate = int(1 / deltaTime);
		std::string frameRateText = "Frame Rate: " + std::to_string(frameRate);
		mFramerateText.SetString(frameRateText);
	}
	
	void GameplayHUD::Init(const sf::RenderWindow& windowRef)
	{
		auto windowSize = windowRef.getSize();
		mPlayerHealthBar.SetWidgetLocation(sf::Vector2f{20.f, windowSize.y - 50.f});
		RefreshHealthBar();
	}
	
	void GameplayHUD::PlayerHealthUpdated(float amt, float currentHealth, float maxHealth)
	{
		mPlayerHealthBar.UpdateValue(currentHealth, maxHealth);
		if (currentHealth/maxHealth <= mCriticalThreshold) {
			mPlayerHealthBar.SetForeGroundColor(mCriticalHealthBarColor);
		}
		else {
			mPlayerHealthBar.SetForeGroundColor(mHealthyHealthBarColor);
		}
	}
	
	void GameplayHUD::RefreshHealthBar()
	{
		Player* player = PlayerManager::Get().GetPlayer();
		if (player && !player->GetCurrentSpaceship().expired()) {
			weak<PlayerSpaceship> playerSpaceship = player->GetCurrentSpaceship();
			playerSpaceship.lock()->onActorDestroyed.BindAction(GetWeakRef(), &GameplayHUD::PlayerSpaceshipDestroyed);
			HealthComponent& healthComp = player->GetCurrentSpaceship().lock()->GetHealthComp();
			healthComp.onHealthChanged.BindAction(GetWeakRef(), &GameplayHUD::PlayerHealthUpdated);
			mPlayerHealthBar.UpdateValue(healthComp.GetHealth(), healthComp.GetMaxHealth());
		}
	}
	
	void GameplayHUD::PlayerSpaceshipDestroyed(Actor* actor)
	{
		RefreshHealthBar();
	}
}