#ifndef STATE_PLAYING_HPP
#define STATE_PLAYING_HPP

#include <ME/GameStateManager.hpp>
#include <ME/Space.hpp>

namespace tg
{
	class StatePlaying : public me::GameState
	{
	private:
		std::shared_ptr<me::Space> m_space;
		sf::View m_view;

	public:
		void loadSpace(std::shared_ptr<me::Space> space);

		virtual void onTransitionIn();
		virtual void onTransitionOut();

		virtual void continuousUpdate(const sf::Time &timeElapsed);
		virtual void fixedUpdate();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		StatePlaying();
		~StatePlaying();
	};
}


#endif //STATE_PLAYING_HPP
