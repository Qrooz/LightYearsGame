#pragma once
#include <SFML/Graphics.hpp>

namespace ly
{
	class Application {
	public:
		Application();
		void Run();
	private:
		void TickInternal(float deltaTime);
		virtual void Tick(float deltaTime);
		void RenderInternal();
		virtual void Render();
		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;
	};
}