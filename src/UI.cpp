#include <UI.hpp>
#include <iostream>

#include <allegro.h>
#include <allegro_font.h>
#include <allegro_ttf.h>

UI::UI()
{
  al_init();
  al_init_font_addon();
  al_init_ttf_addon();

  resolutionText_ = al_load_ttf_font ("pirulen.ttf", 18, 0);

  Unselected_ = al_map_rgb (255, 255, 255);
  Selected_ = al_map_rgb (0, 50, 0);
}


void UI::Draw()
{
  drawResolutionTexts();
  drawResolutionSelector();
}

 
void UI::drawResolutionTexts()
{

  al_draw_text (resolutionText_, Unselected_, (1280 / 2), (720 / 2), ALLEGRO_ALIGN_CENTRE, "TEST");
  al_draw_text (resolutionText_, Unselected_, (1280 / 2), (720 / 2) + 20, ALLEGRO_ALIGN_CENTRE, "Test+20");
  al_draw_text (resolutionText_, Unselected_, (1280 / 2), (720 / 2) + 40, ALLEGRO_ALIGN_CENTRE, "Test+40");
  al_draw_text (resolutionText_, Unselected_, (1280 / 2), (720 / 2) + 60, ALLEGRO_ALIGN_CENTRE, "Test+60");

}


void UI::drawResolutionSelector()
{

}
