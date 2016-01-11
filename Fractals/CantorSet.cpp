#include "CantorSet.h"

CantorSet::CantorSet(Point hook, int width, int level)
{
	p1 = hook;
	p2 = { hook.X + width, hook.Y + level * 10 };

	Point hookPoints[2] =
	{
		{ hook.X, hook.Y + 50 },
		{ hook.X + (width / 3) * 2, hook.Y + 50 },
	};

	int nextLevel = level - 1;
	if (level != 0)
		for (int i = 0; i < 2; i++)
		{
			Children[i] = new CantorSet(hookPoints[i], (width / 3), nextLevel);
		}
	DrawSet();
}

void CantorSet::DrawSet()
{
	al_draw_filled_rectangle(p1.X, p1.Y, p2.X, p2.Y, al_map_rgb(255, 0, 0));
	al_flip_display();
}

void CantorSet::CreateNew(int width, int level)
{
	CreateDisplay(width, level*100);
	CantorSet* set = new CantorSet({ 10, 10 }, 600, level);
	HandleClose();
	delete(set);
}
