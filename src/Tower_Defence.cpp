#include <iostream>
#include <allegro.h>
#include <allegro_primitives.h>

#include <Player.hpp>
#include <Board.hpp>
#include <Tower.hpp>
#include <Ammunition.hpp>
#include <Enemy.hpp>
#include <Rules.hpp>
#include <Engine.hpp>
#include <UI.hpp>
using namespace std;





const unsigned int ScreenW = 1280;
const unsigned int ScreenH = 720;





int main()
{
  ALLEGRO_DISPLAY *Display = NULL;
  ALLEGRO_BITMAP *EnemyPH = NULL;
  ALLEGRO_BITMAP *TowerPH = NULL;






  if (!al_init())
    {
      cout << "failed to initialize Allegro!\n";
      return 1;
    }





  if (!al_init_primitives_addon())
    {
      cout << "failed to initialize primitives addon!\n";
      return 1;
    }





  Display = al_create_display (ScreenW, ScreenH);
  if (!Display)
    {
      cout << "failed to create display!\n";
      return 1;
    }




  // ALLEGRO_COLOR ColorBlue = al_map_rgb (0, 0, 255);






  Player *pPlayer = new Player();

  Board *pBoard = new Board();

  Tower *pTower = new Tower();

  Ammunition *pAmmunition = new Ammunition();

  Enemy *pEnemy = new Enemy();

  Engine *pEngine = new Engine();





  EnemyPH = pEnemy->getBitmap();

  al_set_target_bitmap(EnemyPH);

  al_clear_to_color (al_map_rgb(255, 0, 0));





  TowerPH = pTower->getBitmap();

  al_set_target_bitmap(TowerPH);

  al_clear_to_color (al_map_rgb(0, 255, 0));





  al_set_target_bitmap(al_get_backbuffer(Display));

  al_draw_bitmap(EnemyPH, 50, 50, 0);

  al_draw_bitmap(TowerPH, 10, 10, 0);

  al_draw_line (0, ScreenH - 80, ScreenW, ScreenH - 80, al_map_rgb(0, 255, 0), 1);

  al_flip_display();





  if (pPlayer != NULL) pPlayer->debugPrint();

  if (pBoard != NULL) pBoard->debugPrint();

  if (pTower != NULL) pTower->debugPrint();

  if (pAmmunition != NULL) pAmmunition->debugPrint();

  if (pEnemy != NULL) pEnemy->debugPrint();

  if (pEngine != NULL) pEngine->debugPrint();





  while(1)
    {
      //stuff
    }
}
