#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly {
	Actor::Actor(World* owningWorld)
		: mOwningWorld{owningWorld},
		mHasBeganPlay{false}
	{

	}

	void Actor::BeginPlayInternal()
	{
		if (!mHasBeganPlay) {
			mHasBeganPlay = true;
			BeginPlay();
		}
	}

	void Actor::BeginPlay()
	{
		LOG("Actor Begin Play");
	}

	void Actor::Tick(float deltaTime)
	{
		LOG("Actor Ticking")
	}
}