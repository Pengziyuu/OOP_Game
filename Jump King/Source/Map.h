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
		void Map03();
		void Map04();
		void Map05();
		void Map06();
		void Map07();
		void Map08();

		void plus();
		void minus();
	protected:
		int **matrix;
		int nowMap;
		int minMap;
		int maxMap;

		CMovingBitmap map01;
		CMovingBitmap fg01;

		CMovingBitmap map02;
		CMovingBitmap fg02;

		CMovingBitmap map03;
		CMovingBitmap fg03;

		CMovingBitmap bg04;
		CMovingBitmap map04;
		CMovingBitmap fg04;

		CMovingBitmap bg05;
		CMovingBitmap map05;
		CMovingBitmap fg05;

		CMovingBitmap bg06;
		CMovingBitmap map06;
		CMovingBitmap fg06;

		CMovingBitmap map07;

		CMovingBitmap map08;
	};
}
