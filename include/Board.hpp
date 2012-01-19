//! Spelplanen

//! Spelplanen, sedd uppifrån, är där allting utspelar sig. Här placeras Tower som skjuter på Enemy på @ref generatePath() "gången".
//! Här finns också ingången och utgången placerade.

#ifndef BOARD_HPP
#define BOARD_HPP

#include <allegro.h>
#include <vector>
#include <definitions.hpp>
#include <list>

#include <Enemy.hpp>
#include <Tower.hpp>

class Board
{
public:
   Board();
   void Draw() const;

   //! Går igenom (iterator) en lista på Tower och anropar Tower::Draw()
   void drawTowers() const;

   //! Går igenom (iterator) en lista på Enemy och anropar Enemy::Draw()
   void drawEnemies() const; 

   //! En lista på ett par
   typedef std::list<std::pair<Enemy *, unsigned int> > EnemiesList_t;

   //! En lista på Tower
   typedef std::list<Tower *> TowersList_t;

   //! Kollar var på Board användaren klickat, i pixelkoordinater
   void mouseClick(pixelPosition x, pixelPosition y);

   //! Omvandlar pixelkoordinater till rutnätkoordinater
   bool getTileCoordinates(pixelPosition x, pixelPosition y, gridPosition &gridX, gridPosition &gridY) const;

   //! Hittar @ref entranceTile_ "ingångens" position
   unsigned int getEntranceTile() const;

   //! Hittar @ref exitTile_ "utgångens" position
   unsigned int getExitTile() const;

   //! Kollar om en specifik ruta är en del av @ref generatePath() "gångvägen"
   bool onEnemyPath(gridPosition gridX, gridPosition gridY) const;

   //! Enemys position
   //! @param stepNumber antal steg fienden har tagit från @ref entranceTile_ "ingången"
   void getEnemyPosition (unsigned int stepNumber, gridPosition &gridX, gridPosition &gridY);

   //! Lägger till en Enemy, som ägs av Board, i en lista av par
   //! @param pEnemy Den Enemy som ska läggas till
   //! @param enemyStartStep Det "tick" timern är ställd på när Enemy skickas ut.
   void addEnemy(Enemy * pEnemy, unsigned int enemyStartStep);

   //! Lägger till Tower, som ägs av Board, i en lista
   void addTower(Tower *pTower);

   //! Kollar om ett Tower är placerat på en given ruta
   bool tileHasTower(unsigned int gridX, unsigned int gridY) const;

   //! Tar bort ett Tower från en specifik ruta
   void removeTower(unsigned int gridX, unsigned int gridY);

   //! Tar bort en Enemy
   void removeEnemy();

   //! @return en lista på Enemy
   EnemiesList_t & getEnemies();

   //! @return en lista på Tower
   TowersList_t & getTowers();

   private:
   Board(const Board&);
   Board & operator = (const Board&);

   //! En lista på Enemy
   EnemiesList_t Enemies;

   //! En lista på Tower
   TowersList_t Towers;

   //! Generarar ett slumpmässigt tal med time seed
   unsigned int getRand(unsigned int Min, unsigned int Max);

   //! Genererar vägen fienden kan gå på

   //! Vägen genereras slumpmässigt, men har vissa punkter som den
   //! ska gå förbi innan den slutligen når @ref exitTile_
   //! "utgången". Dessa punkter definieras i kontruktorn
   //! @param gridXEnd x-position för en punkt
   //! @param gridYEnd y-position för en punkt
   void generatePath (gridPosition gridXEnd, gridPosition gridYEnd);

   //! Genererar @ref entranceTile_ "ingångens" och @ref exitTile_ "utgångens" positioner.
   
   //! Endast Y-axeln genereras; X-axeln är alltid samma
   void generateEntranceExitPositions();

   void drawBackground() const;
   void drawGrid() const;
   void drawExit() const;
   void drawEntrance() const;
   void drawEnemyPath() const;

   //! Alla rutor på @ref generatePath() "gången"

   //! Vektorn innehåller ett par med X och Y
   std::vector<std::pair<gridPosition, gridPosition> > enemyPath_;

   gridPosition entranceTile_;
   gridPosition exitTile_;
   gridPosition enemyPathX_;
   gridPosition enemyPathY_;
   const unsigned int tileSize_;
   const unsigned int boardWidth_;
   const unsigned int boardHeight_;

   ALLEGRO_BITMAP *Entrance_;
   ALLEGRO_BITMAP *Exit_;
   ALLEGRO_BITMAP *enemyPathBitmap_;
   ALLEGRO_BITMAP *targetBitmapHolder_;
   ALLEGRO_COLOR gridColor_;
   ALLEGRO_COLOR blackBackground_;
};


#endif //BOARD_HPP
