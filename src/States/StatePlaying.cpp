#include "StatePlaying.hpp"
#include <ME/Graphics/AnimatedSprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <ME/Input/Keyboard.hpp>
#include <iostream>
#include "StatePaused.hpp"
#include <ME/GameObject.hpp>
#include <SFML/System/Clock.hpp>

namespace tg
{
	void StatePlaying::loadSpace(me::Space *space)
	{
		m_space = space;
	}

	void StatePlaying::onTransitionIn()
	{
		std::cout << "Transition into StatePlaying" << std::endl;
	}

	void StatePlaying::onTransitionOut()
	{
		std::cout << "Transition out of StatePlaying" << std::endl;
	}

	void StatePlaying::continuousUpdate(const sf::Time &timeElapsed)
	{
		m_space->continuousUpdate(timeElapsed);
	}

	void StatePlaying::fixedUpdate()
	{
		if (me::Keyboard::isKeyJustPressed(me::Keyboard::Space))
			m_stateManager->transitionTo(m_statePaused);
		m_space->fixedUpdate();
	}

	void StatePlaying::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.setView(m_view);
		m_space->draw(target, states);
	}


	StatePlaying::StatePlaying() :
		frame(0)
	{
		m_view.reset(sf::FloatRect(0, 0, 800, 600));
	}

	StatePlaying::~StatePlaying()
	{
	}
}
