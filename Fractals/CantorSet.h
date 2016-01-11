#include "AllegroWindow.h"
#include "Allegro5\allegro_primitives.h"

class CantorSet : public AllegroWindow
{
private:
	CantorSet(Point hook, int width, int level, bool filled);
	void DrawSet(bool filled);
public:
	static void CreateNew(int width, int height, int level);
	int Level;
	CantorSet* children[3];

	Point p1;
	Point p2;
};
