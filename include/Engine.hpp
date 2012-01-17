//! Sköter saker som förflyttning

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

	void moveEnemy(Board & board, unsigned int enemyStepCounter);

	void shootEnemy(const Board & board, Tower & tower, Enemy & enemy);

private:
	Engine(const Engine&);
	Engine & operator = (const Engine&);


};



#endif //ENGINE_HPP
