#include "SierpinskiCarpet.h"

AllegroWindow* AllegroWindow::Instance;
ALLEGRO_DISPLAY* AllegroWindow::display;
ALLEGRO_EVENT_QUEUE* AllegroWindow::event_queue;

AllegroWindow::AllegroWindow()
{
}

AllegroWindow::AllegroWindow(int width, int height)
{
	display = NULL;

	if (!al_init())
	{
		al_show_native_message_box(NULL, NULL, NULL,
			"Failed to initialize allegro!", NULL, NULL);
	}

	display = al_create_display(width + 20, height + 20);
	al_set_window_title(display, "Sierpinski's carpet");

	if (!display)
	{
		al_show_native_message_box(NULL, NULL, NULL,
			"Failed to create display!", NULL, NULL);
	}

	al_init_primitives_addon();
	al_clear_to_color(al_map_rgb(255, 255, 255));
	//al_destroy_display(display);
	//al_destroy_event_queue(event_queue);
}

void AllegroWindow::CreateDisplay(int width, int height)
{
	if(Instance == NULL)
	Instance = new AllegroWindow(width, height);
};
