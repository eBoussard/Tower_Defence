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

   typedef std::list<std::pair<Enemy *, unsigned int> > EnemiesList_t;
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

   //! @ref Enemy "Fiendens" position
   //! @param stepNumber antal steg fienden har tagit från @ref entranceTile_ "ingången"
   void getEnemyPosition (unsigned int stepNumber, gridPosition &gridX, gridPosition &gridY);

   //! Enemy ägs av Board. Board lägger till alla Enemy i par (antal steg och Enemy) i en lista.
   void addEnemy(Enemy * pEnemy, unsigned int enemyStartStep);

   //! Tower ägs av Board. Board lägger till alla Tower i en lista.
   void addTower(Tower *pTower);

   EnemiesList_t & getEnemies();

   TowersList_t & getTowers();

   private:
   Board(const Board&);
   Board & operator = (const Board&);

   EnemiesList_t Enemies;
   TowersList_t Towers;

   //! Enkel metod som genererar ett slumpmässigt tal med time seed
   unsigned int getRand(unsigned int Min, unsigned int Max);

   //! Genererar vägen fienden kan gå på

   //! Vägen genereras slumpmässigt, men har vissa punkter som den
   //! ska gå förbi innan den slutligen når @ref exitTile_
   //! "utgången"
   void generatePath (gridPosition gridXEnd, gridPosition gridYEnd);

   //! Genererar @ref entranceTile_ "ingångens" och @ref exitTile_
   //! "utgångens" positioner. Endast Y-axeln genereras; X-axeln är
   //! alltid samma
   void generateEntranceExitPositions();

   void drawBackground() const;
   void drawGrid() const;
   void drawExit() const;
   void drawEntrance() const;
   void drawEnemyPath() const;

   //! Alla rutor på @ref generatePath() "gången"

   //! Vektorn innehåller ett par där den första är X-axeln och den
   //! andra är Y-axeln
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
