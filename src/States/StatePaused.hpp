#ifndef STATE_PAUSED_HPP
#define STATE_PAUSED_HPP

#include <ME/GameStateManager.hpp>
#include <ME/Space.hpp>

namespace tg
{
	class StatePlaying;

	class StatePaused : public me::IGameState
	{
	private:
		me::Space *m_space;
		StatePlaying *m_statePlaying;

	public:
		void loadSpace(me::Space *space);
		inline void registerStatePlaying(StatePlaying *state) { m_statePlaying = state; }
		
		// update loops
		virtual void continuousUpdate(const sf::Time &timeElapsed);
		virtual void fixedUpdate();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		StatePaused();
		~StatePaused();
	};
}



#endif //STATE_PAUSED_HPP
