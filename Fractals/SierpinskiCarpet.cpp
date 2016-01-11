#include "SierpinskiCarpet.h"

SierpinskiCarpet::SierpinskiCarpet(Point hook, int width, int height, int level, bool filled)
{
	p1 = hook;
	p2 = { hook.X + width, hook.Y + height };

	Point hookPoints[9] =
	{
		hook,
		{ hook.X + width / 3, hook.Y },
		{ hook.X + (width / 3) * 2, hook.Y },

		{ hook.X, hook.Y + height / 3 },
		{ hook.X + width / 3, hook.Y + height / 3 },
		{ hook.X + (width / 3) * 2, hook.Y + height / 3 },

		{ hook.X, hook.Y + (height / 3) * 2 },
		{ hook.X + width / 3, hook.Y + (height / 3) * 2 },
		{ hook.X + (width / 3) * 2, hook.Y + (height / 3) * 2 }
	};

	int nextLevel = level - 1;
	if(level != 0)
		for (int i = 0; i < 9; i++)
		{
			if (i != 4)
				children[i] = new SierpinskiCarpet(hookPoints[i], (width / 3), (height / 3), nextLevel, true);
			else 
				children[i] = new SierpinskiCarpet(hookPoints[i], width / 3, height / 3, nextLevel, false);
		}

	DrawCarpet(filled);
};


void SierpinskiCarpet::DrawCarpet(bool filled)
{
	if (filled)
		al_draw_rectangle(p1.X, p1.Y, p2.X, p2.Y, al_map_rgb(255, 255, 255), 2);
	else
		al_draw_filled_rectangle(p1.X, p1.Y, p2.X, p2.Y, al_map_rgb(255, 0, 0));
	al_flip_display();
}

void SierpinskiCarpet::CreateNew(int width, int height, int level)
{
	CreateDisplay(width, height);
	SierpinskiCarpet* carpet = new SierpinskiCarpet({ 10,10 }, width, height, level, true);
	HandleClose();
	delete(carpet);
}