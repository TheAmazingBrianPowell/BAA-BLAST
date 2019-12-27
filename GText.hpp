#ifndef G_TEXT_HPP
#define G_TEXT_HPP

#include <SFML/Graphics.hpp>
using namespace sf;

extern const String letters[64][20];

Vector2f text(String characters, float x, float y, int size2, RenderWindow& window);

#endif
