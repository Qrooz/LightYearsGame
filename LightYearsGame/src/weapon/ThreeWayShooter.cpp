#include "weapon/ThreeWayShooter.h"

namespace ly {
	ThreeWayShooter::ThreeWayShooter(Actor* owner, float cooldownTime, const sf::Vector2f& localOffset)
		: Shooter{ owner },
		mShooterLeft{ owner, cooldownTime, localOffset + sf::Vector2f{10,10}, -30.f, "SpaceShooterRedux/PNG/Lasers/laserRed01.png" },
		mShooterMiddle{owner, cooldownTime, localOffset, 0.f, "SpaceShooterRedux/PNG/Lasers/laserRed01.png" },
		mShooterRight{ owner, cooldownTime, localOffset + sf::Vector2f{10,-10}, 30.f , "SpaceShooterRedux/PNG/Lasers/laserRed01.png" },
		mTopLevelShooterLeft{ owner, cooldownTime, localOffset + sf::Vector2f{10, 5}, -15.f , "SpaceShooterRedux/PNG/Lasers/laserRed01.png" },
		mTopLevelShooterRight{ owner, cooldownTime, localOffset + sf::Vector2f{10, -5}, 15.f , "SpaceShooterRedux/PNG/Lasers/laserRed01.png" }
	{
		
	}
	
	void ThreeWayShooter::IncrementLevel(int amt)
	{
		Shooter::IncrementLevel(amt);
		mShooterLeft.IncrementLevel(amt);
		mShooterMiddle.IncrementLevel(amt);
		mShooterRight.IncrementLevel(amt);
		
		mTopLevelShooterLeft.IncrementLevel(amt);
		mTopLevelShooterRight.IncrementLevel(amt);
	}
	
	void ThreeWayShooter::ShootImpl()
	{
		mShooterLeft.Shoot();
		mShooterMiddle.Shoot();
		mShooterRight.Shoot();

		if (GetCurrentLevel() == GetMaxLevel()) {
			mTopLevelShooterLeft.Shoot();
			mTopLevelShooterRight.Shoot();
		}
	}
}