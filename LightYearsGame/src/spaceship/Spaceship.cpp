#include "spaceship/Spaceship.h"
#include "framework/MathUtility.h"

namespace ly {
    Spaceship::Spaceship(World* owningWorld, const std::string& texturePath)
        : Actor{owningWorld,texturePath},
        mVelocity{},
        mHealthComp{100.f,100.f},
        mBlinkTime{ 0.f },
        mBlinkDuration{0.2f},
        mBlinkColorOffset{255,0,0, 255}
    {

    }
    void Spaceship::Tick(float deltaTime)
    {
        Actor::Tick(deltaTime);
        AddActorLocationOffset(GetVelocity() * deltaTime);
        UpdateBlink(deltaTime);
    }
    void Spaceship::SetVelocity(sf::Vector2f& newVel)
    {
        mVelocity = newVel;
    }
    void Spaceship::Shoot()
    {

    }
    void Spaceship::BeginPlay()
    {
        Actor::BeginPlay();
        SetEnablePhysics(true);
        mHealthComp.onHealthChanged.BindAction(GetWeakRef(), &Spaceship::OnHealthChanged);
        mHealthComp.onTakenDamage.BindAction(GetWeakRef(), &Spaceship::OnTakenDamage);
        mHealthComp.onHealthEmpty.BindAction(GetWeakRef(), &Spaceship::Blow);

    }
    void Spaceship::ApplyDamage(float amt)
    {
        mHealthComp.ChangeHealth(-amt);
    }
    void Spaceship::Blink()
    {
        if (mBlinkTime == 0.f) {
            mBlinkTime = mBlinkDuration;
        }
    }
    void Spaceship::UpdateBlink(float deltaTime)
    {
        if (mBlinkTime > 0) {
            mBlinkTime -= deltaTime;
            mBlinkTime = mBlinkTime > 0 ? mBlinkTime : 0.f;

            GetSprite().setColor(LerpColor(sf::Color::White, mBlinkColorOffset, mBlinkTime));
        }
    }
    void Spaceship::OnHealthChanged(float amt, float health, float maxHealth)
    {
        LOG("Health Changed by: %f, and is now: %f/%f", amt, health, maxHealth);
    }
    void Spaceship::OnTakenDamage(float amt, float health, float maxHealth)
    {
        Blink();
    }
    void Spaceship::Blow()
    {
        Destroy();
    }
}