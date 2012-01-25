//! Kollar om draget är tillåtet

//! Rules kollar bland annat på var Player får och inte får placera Tower

#ifndef RULES_HPP
#define RULES_HPP

#include <Board.hpp>
#include <Tower.hpp>
#include <Enemy.hpp>
#include <Engine.hpp>
#include <list>
#include <definitions.hpp>

class Rules
{
public:
   Rules();

   //! Kollar om placering av torn på den klickade rutan är tillåtet
   //! @param board för att kolla upp @ref Board::entranceTile_ "ingång", @ref Board::exitTile_ "utgång" och
   //! @ref Board::generatePath() "gången".
   //! @param Towers för att kolla upp var eventuella torn redan är placerade
   //! @return true om placeringen är tillåten
   bool towerPlacementValid (const Board & board, Tower & tower, gridPosition gridX, gridPosition gridY) const;

   //! Kollar om Enemys steg är giltigt
   //! @param board för att kolla upp @ref Board::entranceTile_ "ingång", @ref Board::exitTile_
   //! "utgång" och @ref Board::generatePath() "gången"
   bool enemyPositionValid (const Board & board, gridPosition gridX, gridPosition gridY) const;

   //! Innehåller listor på Tower och Enemy. Anropar Engine::shootEnemy()
   void isEnemyShootable(Board & board, Player & player);

private:
   Rules(const Rules&);
   Rules & operator = (const Rules&);
};

#endif //RULES_HPP
