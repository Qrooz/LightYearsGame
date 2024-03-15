#include "widgets/GameplayHUD.h"

namespace ly {
	GameplayHUD::GameplayHUD()
		:mFramerateText{"Frame Rate:"}
	{
	}
	
	void GameplayHUD::Draw(sf::RenderWindow& windowRef)
	{
		mFramerateText.NativeDraw(windowRef);
	}
}