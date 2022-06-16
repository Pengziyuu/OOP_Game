#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Begin.h"

namespace game_framework {
	Begin::Begin()
	{
		show = false;
		x = (SIZE_X - 392 * 2) / 2;
		y = SIZE_Y / 5;
		x2 = 430;
		y2 = 440;
		x3 = 480;
		y3 = 600;
		logoStop = 0;
		delay = 0;
	}

	void Begin::LoadBitmap()
	{
		logo.LoadBitmap(IDB_LOGO);
		logoEnter.LoadBitmap(IDB_LOGOENTER);
		logoKing.LoadBitmap(IDB_KING14);
	}

	void Begin::OnMove()
	{
		if (logoStop < 4)
		{
			if (y > SIZE_Y / 6) {
				y -= 3;
			}
			else if (y > SIZE_Y / 10) {
				y -= 30;
			}
			else if (y <= SIZE_Y / 10) {
				y += 30;
				logoStop++;
			}
		}
		else if (logoStop == 4) logoStop++;

		if (delay % 10 > 4)
		{
			show = false;
			Sleep(100);
		}
		else 
		{
			show = true;
			Sleep(100);
		}
		delay++;
	}

	void Begin::OnShow()
	{
		logo.SetTopLeft(x, y);
		logo.ShowBitmap(2);
		
		if (show && logoStop >= 4)
		{	
			logoEnter.SetTopLeft(x2, y2);
			logoEnter.ShowBitmap();
		}
	
		logoKing.SetTopLeft(x3, y3);
		logoKing.ShowBitmap(2);
	}
}