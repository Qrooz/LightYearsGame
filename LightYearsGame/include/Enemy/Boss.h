#pragma once
#include "Enemy/EnemySpaceship.h"
#include "Weapon/BulletShooter.h"
#include "weapon/ThreeWayShooter.h"
#include "weapon/FrontalWiper.h"

namespace ly {
	class Boss : public EnemySpaceship {
	public:
		Boss(World* world);
		virtual void Tick(float deltaTime) override;
		virtual void BeginPlay() override;
	private:
		float mSpeed;
		float mSwitchDistanceToEdge;
		void CheckMove();

		BulletShooter mBaseShooterLeft;
		BulletShooter mBaseShooterRight;

		ThreeWayShooterBoss mThreeWayShooter;
		FrontalWiperBoss mFrontalWiperLeft;
		FrontalWiperBoss mFrontalWiperRight;

		BulletShooter mFinalStageShooterLeft;
		BulletShooter mFinalStageShooterRight;
		
		void ShootBaseShooters();
		void ShootThreeWayShooter();
		void ShootFrontalWipers();
		void HealthChanged(float amt, float currentHealth, float maxHealth);

		void SetStage(int newStage);
		int mStage;
	};
}