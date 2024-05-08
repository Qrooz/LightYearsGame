#pragma once
#include "framework/Actor.h"

namespace ly {
	class BackgroundLayer : public Actor {
	public:
		BackgroundLayer(World* owningWorld, 
			const List<std::string>& assetPaths = {},
			const sf::Vector2f& minVel = sf::Vector2f{0.f,50.f},
			const sf::Vector2f& maxVel = sf::Vector2f{ 0.f,50.f },
			float sizeMin = 1.f,
			float sizeMax = 2.f,
			int spriteCount = 20,
			const sf::Color& colorTint = sf::Color{180, 180, 200, 255});

		void SetAssets(const List<std::string>& assetPaths);
		void setColorTint(const sf::Color& color);
		void setSpriteCount(int newCount);
		void setVelocities(const sf::Vector2f& min, const sf::Vector2f& max);
		void setSizes(float min, float max);

		virtual void Render(sf::RenderWindow& windowRef) override;
		virtual void Tick(float deltaTime) override;

	private:
		void RefreshSprites();
		void RandomSpriteTexture(sf::Sprite& sprite);
		void RandomSpriteTransform(sf::Sprite& sprite, bool randomY = false);
		void RandomSpritePosition(sf::Sprite& sprite, bool randomY);
		void RandomSpriteRotation(sf::Sprite& sprite);
		void RandomSpriteSize(sf::Sprite& sprite);
		bool IsSpriteOffScreen(sf::Sprite& sprite) const;
		shared<sf::Texture> GetRandomTexture() const;
		sf::Vector2f mMinVelocity;
		sf::Vector2f mMaxVelocity;
		float mSizeMin;
		float mSizeMax;
		int mSpriteCount;
		sf::Color mTintColor;

		List<shared<sf::Texture>> mTextures;
		List<sf::Sprite> mSprites;
		List<sf::Vector2f> mVelocities;
	};

}