#ifndef UI_HPP
#define UI_HPP

#include <allegro.h>
#include <allegro_primitives.h>
#include <allegro_font.h>
#include <allegro_ttf.h>


class UI
{
public:
  UI();
  void Draw();  


  //! Width of the menu screen
  const unsigned int menuDisplayWidth;

  //! Height of the menu screen
  const unsigned int menuDisplayHeight;

  //! High resolution screen width
  const unsigned int highResWidth;
  //! High resolution screen height
  const unsigned int highResDisplayHeight;
  //! High resolution Board height
  const unsigned int highResBoardHeight;

  //! Low resolution screen width
  const unsigned int lowResWidth;
  //! Low resolution screen height
  const unsigned int lowResDisplayHeight;
  //! Low resolution Board height
  const unsigned int lowResBoardHeight;

private:
  UI(const UI&);
  UI & operator = (const UI&);

  //! To draw the text on the menu screen showing the available resolutions
  void drawResolutionTexts();

  //! To show if one of the available resolutions from
  //! drawResolutionTexts() is currently selected
  void drawResolutionSelector();

  ALLEGRO_FONT *resolutionText_;
  ALLEGRO_COLOR Unselected_;
  ALLEGRO_COLOR Selected_;
};



#endif //UI_HPP

