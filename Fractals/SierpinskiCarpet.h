#include "AllegroWindow.h"
#include "Allegro5\allegro_primitives.h"

class SierpinskiCarpet : public AllegroWindow
{
private:
	SierpinskiCarpet(Point hook, int width, int heigth, int level, bool filled);
	void DrawCarpet(bool filled);
public:
	static void CreateNew(int width, int height, int level);
	int Level;
	SierpinskiCarpet* children[9];

	Point p1;
	Point p2;
};