//! Motorn, som håller igång rörelse

//! Engine sköter saker som förflyttning och skjutning av Enemy

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <Enemy.hpp>
#include <Board.hpp>
#include <Tower.hpp>
#include <list>
#include <definitions.hpp>

class Engine
{
public:
	Engine();

	//! Placerar (flyttar på) Enemy
	//! @param enemyStepCounter använder Mains timertick för att avgöra var Enemy ska placeras
	void moveEnemy(Board & board, unsigned int enemyStepCounter);

	//! Tower skjuter Enemy
	void shootEnemy(const Board & board, Tower & tower, Enemy & enemy);

private:
	Engine(const Engine&);
	Engine & operator = (const Engine&);
};



#endif //ENGINE_HPP
