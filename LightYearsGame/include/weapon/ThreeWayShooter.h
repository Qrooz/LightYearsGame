#pragma once
#include <SFML/Graphics.hpp>
#include "weapon/BulletShooter.h"

namespace ly {
	class ThreeWayShooter : public Shooter {
	public:
		ThreeWayShooter(Actor* owner, float cooldownTime = 0.3f, const sf::Vector2f& localOffset = {0.f,0.f});

		BulletShooter mShooterLeft;
		BulletShooter mShooterRight;
		BulletShooter mShooterMiddle;

		BulletShooter mTopLevelShooterLeft;
		BulletShooter mTopLevelShooterRight;

		virtual void IncrementLevel(int amt) override;
	private:
		virtual void ShootImpl();

	};

	class ThreeWayShooterBoss : public Shooter {
	public:
		ThreeWayShooterBoss(Actor* owner, float cooldownTime = 0.3f, const sf::Vector2f& localOffset = { 0.f,0.f }, float rotationOffset = 0.f);

		BulletShooter mShooterLeft;
		BulletShooter mShooterRight;
		BulletShooter mShooterMiddle;

		BulletShooter mTopLevelShooterLeft;
		BulletShooter mTopLevelShooterRight;

		virtual void IncrementLevel(int amt) override;
		virtual void SetCurrentLevel(int level) override;
	private:
		virtual void ShootImpl();
	};

}