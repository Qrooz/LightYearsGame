#pragma once
#include "Gameplay/Gamestage.h"

namespace ly {
	class Actor;
	class BossStage : public GameStage {
	public:
		BossStage(World* world);
		virtual void StartStage() override;
	private:
		void BossDestroyed(Actor* bossActor);
	};

}