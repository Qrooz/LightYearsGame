#include "framework/Application.h"
#include "framework/Core.h"

namespace ly {
	Application::Application() 
		: mWindow{sf::VideoMode(1024, 1440), "Light Years" },
		mTargetFrameRate{60.f},
		mTickClock{}
	{
		
	}

	void Application::Run()
	{
		mTickClock.restart();
		float accumulatedTime = 0.f;
		float targetDeltaTime = 1.f / mTargetFrameRate;
		while (mWindow.isOpen()) {
			sf::Event windowEvent;
			while (mWindow.pollEvent(windowEvent)) {
				if (windowEvent.type == sf::Event::EventType::Closed) {
					mWindow.close();
				}
			}

			float frameDeltaTime = mTickClock.restart().asSeconds();
			accumulatedTime += frameDeltaTime;
			while (accumulatedTime > targetDeltaTime) {
				accumulatedTime -= targetDeltaTime;
				TickInternal(targetDeltaTime);
				RenderInternal();
			}
			LOG("Ticking at framerate: %f", 1.f / frameDeltaTime);
		}
	}
	void Application::TickInternal(float deltaTime)
	{
		Tick(deltaTime);
	}
	void Application::Tick(float deltaTime)
	{
		//std::cout << "Ticking at framerate: " << 1.f / deltaTime << std::endl;
	}
	void Application::RenderInternal() //template (programming part not lang feature) function, sets up before and after a task
	{
		mWindow.clear();
		Render();
		mWindow.display();
	}
	void Application::Render()
	{
		sf::CircleShape rect{ 50 };
		rect.setFillColor(sf::Color::Green);
		rect.setOrigin(50, 50);
		rect.setPosition(mWindow.getSize().x / 2.f, mWindow.getSize().y / 2.f);
		mWindow.draw(rect);	
	}
}