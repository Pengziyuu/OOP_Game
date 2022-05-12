#pragma once
namespace game_framework {

	class Map
	{
	public:
		Map();
		~Map();
		void LoadBitmap();
		void ShowBitmap();
		void ChangeMap(int n);
		int IsEmpty(int x, int y);
		void Map01();
		void Map02();
	protected:
		int **matrix;
		int nowMap;

		CMovingBitmap map01;
		CMovingBitmap fg01;

		CMovingBitmap map02;
		CMovingBitmap fg02;

	};
}
