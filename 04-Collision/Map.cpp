#include "Map.h"

void CMap::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}

void CMap::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + CELL_SIZE;
	b = y - CELL_SIZE;
}