#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"

namespace game_framework {
	Map::Map() 
	{
	}

	void Map::LoadBitmap()
	{
		map01.LoadBitmap(IDB_01);
		fg01.LoadBitmap(IDB_FG01, RGB(0, 0, 0));

		map02.LoadBitmap(IDB_02);
		fg02.LoadBitmap(IDB_FG02, RGB(0, 0, 0));
	}

	void Map::Map01()
	{
		fg01.ShowBitmap(map01);
		map01.ShowBitmap(2);
		matrix01 = { {}, 
					 {},
					 {}
				   };
	}

	void Map::Map02()
	{
		fg02.ShowBitmap(map02);
		map02.ShowBitmap(2);
	}

	void Map::ShowBitmap()
	{
		Map01();
	}
}