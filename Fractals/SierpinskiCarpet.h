#include "AllegroWindow.h"
#include "Allegro5\allegro_primitives.h"
#include "Fractal.h"

class SierpinskiCarpet : public Fractal, public AllegroWindow
{
private:
	SierpinskiCarpet(Point hook, int width, int heigth, int level, bool filled);
	void DrawCarpet(bool filled);
public:
	static void CreateNew(int width, int height, int level);
	SierpinskiCarpet* children[9];
};