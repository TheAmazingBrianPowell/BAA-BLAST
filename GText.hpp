#ifndef G_TEXT_HPP
#define G_TEXT_HPP

#include <SFML/Graphics.hpp>
using namespace sf;

extern const String letters[62][20];

void text(String characters, int x, int y, double size, RenderWindow& window);
#endif
