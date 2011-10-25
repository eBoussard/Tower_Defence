#include <UI.hpp>
#include <iostream>

#include <allegro.h>
#include <allegro_font.h>
#include <allegro_ttf.h>

UI::UI():menuWidth(640), menuHeight(480), highResWidth(1920), highResHeight(1080), lowResWidth(1280), lowResHeight(720)
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

  al_draw_text (resolutionText_, Unselected_, (menuWidth / 2), (menuHeight / 2) - 10, ALLEGRO_ALIGN_CENTRE, "1280*720");
  al_draw_text (resolutionText_, Unselected_, (menuWidth / 2), (menuHeight / 2) + 10, ALLEGRO_ALIGN_CENTRE, "1920*1080");
}


void UI::drawResolutionSelector()
{

}
