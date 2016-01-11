#define ALLEGRO_NO_MAGIC_MAIN
#ifndef ALLEGROWINDOW_H
#define ALLEGROWINDOW_H
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>

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
	static void HandleClose();
};

#endif
