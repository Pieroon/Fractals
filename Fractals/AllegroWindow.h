#define ALLEGRO_NO_MAGIC_MAIN
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>

struct Point
{
public:
	int X;
	int Y;
};

class AllegroWindow
{
protected:
	AllegroWindow();
	AllegroWindow(int width, int height);

	//static ALLEGRO_COLOR red;
	//static ALLEGRO_COLOR white;
public:
	static ALLEGRO_DISPLAY* display;
	static AllegroWindow* Instance;
	static ALLEGRO_EVENT_QUEUE* event_queue;
	static void CreateDisplay(int width, int height);
};
