#pragma once
#include "widgets/HUD.h"
#include "widgets/TextWidget.h"
#include "widgets/ValueGauge.h"
#include "widgets/ImageWidget.h"

namespace ly {
	class Actor;
	class GameplayHUD : public HUD {
	public:
		GameplayHUD();

		virtual void Draw(sf::RenderWindow& windowRef) override;
		virtual void Tick(float deltaTime) override;

	private:
		virtual void Init(const sf::RenderWindow& windowRef) override;
		void PlayerHealthUpdated(float amt, float currentHealth, float maxHealth);
		void PlayerSpaceshipDestroyed(Actor* actor);
		void RefreshHealthBar();
		void PlayerLifeCountUpdated(int amt);
		void ConnectPlayerLifeCount();
		TextWidget mFramerateText;
		ValueGauge mPlayerHealthBar;
		ImageWidget mPlayerLifeIcon;
		TextWidget mPlayerLifeText;
		sf::Color mHealthyHealthBarColor;
		sf::Color mCriticalHealthBarColor;
		float mCriticalThreshold;
		float mWidgetSpacing;
	};

}
