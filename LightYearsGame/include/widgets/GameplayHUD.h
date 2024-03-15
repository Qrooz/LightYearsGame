#pragma once
#include "widgets/HUD.h"
#include "widgets/TextWidget.h"

namespace ly {
	class GameplayHUD : public HUD {
	public:
		GameplayHUD();

		virtual void Draw(sf::RenderWindow& windowRef) override;

	private:
		TextWidget mFramerateText;
	};

}
