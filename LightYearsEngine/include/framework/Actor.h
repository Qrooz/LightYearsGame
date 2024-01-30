#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"
#include "framework/Object.h"

namespace ly
{
	class World;
	class Actor : public Object{
	public:
		Actor(World* owningWorld, const std::string& texturePath = "");

		void BeginPlayInternal();
		void TickInternal(float deltaTime);
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		virtual ~Actor();
		void SetTexture(const std::string& texturePath);
		void Render(sf::RenderWindow& window);
	private:
		World* mOwningWorld;
		bool mHasBeganPlay;

		sf::Sprite mSprite;
		shared<sf::Texture> mTexture;

	};

}