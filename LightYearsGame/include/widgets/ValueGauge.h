#pragma once
#include "widgets/Widget.h"
namespace ly {
	class ValueGauge : public Widget{
	public:
		ValueGauge(const sf::Vector2f& size = sf::Vector2f{ 200.f, 30.f }, 
			float initialPercent = 0.75f, 
			const sf::Color& foreGroundColor = sf::Color{ 128,255,128,255 }, 
			const sf::Color& backGroundColor = sf::Color{128,128, 128,255,});
		void UpdateValue(float value, float maxValue);
		virtual sf::FloatRect GetBound() const override;
		void SetTextSize(unsigned int characterSize);
		void SetForeGroundColor(const sf::Color& color);
		void SetBackGroundColor(const sf::Color& color);
	private:
		virtual void Draw(sf::RenderWindow& windowRef) override;
		virtual void LocationUpdated(const sf::Vector2f& newLocation) override;
		virtual void RotationUpdated(float newRotation) override;
		void CenterText();
		shared<sf::Font> mTextFont;
		sf::Text mText;

		sf::RectangleShape mBarFront;
		sf::RectangleShape mBarBack;

		sf::Color mForeGroundColor;
		sf::Color mBackGroundColor;

		float mPercent;
	};

}