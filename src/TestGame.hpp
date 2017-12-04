#ifndef TEST_GAME_HPP
#define TEST_GAME_HPP

#include <ME/Game.hpp>
#include "States/AllStates.hpp"

namespace tg
{
	class TestGame : public me::Game
	{
	private:
		StatePaused m_statePaused;
		StatePlaying m_statePlaying;

	public:
		virtual void begin();

		TestGame();
		~TestGame();

	private:
		virtual void continuousUpdate(sf::Time timeElapsed);
		virtual void fixedUpdate();
		virtual void draw();

	};
}
#endif //TEST_GAME_HPP