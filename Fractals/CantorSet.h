#include "AllegroWindow.h"
#include "Allegro5\allegro_primitives.h"
#include "Fractal.h"

class CantorSet : public Fractal, public AllegroWindow
{
private:
	CantorSet(Point hook, int width, int level);
	void DrawSet();
public:
	static void CreateNew(int width, int level);
	CantorSet* Children[3];
};
