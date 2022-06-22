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
		void Map09();
		void Map10();
		void Map11();
		void Map12();
		void Map13();
		void Map14();
		void Map15();
		void Map16();
		void Map17();
		void Map18();
		void Map19();
		void Map20();
		void Map21();
		void Map22();
		void Map23();
		void Map24();
		void Map25();
		void Map26();
		void Map27();
		void Map28();
		void Map29();
		void Map30();
		void Map31();
		void Map32();
		void Map33();
		void Map34();
		void Map35();
		void Map36();
		void Map37();
		void Map38();
		void Map39();
		void Map40();
		void Map41();
		void Map42();
		void Map43();

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

		CMovingBitmap map09;
		CMovingBitmap fg09;

		CMovingBitmap map10;
		CMovingBitmap fg10;

		CMovingBitmap map11;

		CMovingBitmap map12;

		CMovingBitmap map13;

		CMovingBitmap bg14;
		CMovingBitmap map14;

		CMovingBitmap bg15;
		CMovingBitmap map15;

		CMovingBitmap bg16;
		CMovingBitmap map16;
		CMovingBitmap fg16;

		CMovingBitmap bg17;
		CMovingBitmap map17;
		CMovingBitmap fg17;

		CMovingBitmap bg18;
		CMovingBitmap map18;
		CMovingBitmap fg18;

		CMovingBitmap bg19;
		CMovingBitmap map19;

		CMovingBitmap bg20;
		CMovingBitmap map20;

		CMovingBitmap bg21;
		CMovingBitmap map21;
		CMovingBitmap fg21;

		CMovingBitmap bg22;
		CMovingBitmap map22;
		CMovingBitmap fg22;

		CMovingBitmap bg23;
		CMovingBitmap map23;

		CMovingBitmap bg24;
		CMovingBitmap map24;

		CMovingBitmap bg25;
		CMovingBitmap map25;
		CMovingBitmap fg25;

		CMovingBitmap bg26;
		CMovingBitmap map26;
		CMovingBitmap fg26;

		CMovingBitmap bg27;
		CMovingBitmap map27;
		CMovingBitmap fg27;

		CMovingBitmap bg28;
		CMovingBitmap map28;
		CMovingBitmap fg28;

		CMovingBitmap bg29;
		CMovingBitmap map29;
		CMovingBitmap fg29;

		CMovingBitmap bg30;
		CMovingBitmap map30;
		CMovingBitmap fg30;

		CMovingBitmap bg31;
		CMovingBitmap map31;
		CMovingBitmap fg31;

		CMovingBitmap bg32;
		CMovingBitmap map32;
		CMovingBitmap fg32;

		CMovingBitmap map33;

		CMovingBitmap map34;

		CMovingBitmap map35;

		CMovingBitmap bg36;
		CMovingBitmap map36;
		CMovingBitmap fg36;

		CMovingBitmap bg37;
		CMovingBitmap map37;
		CMovingBitmap fg37;

		CMovingBitmap bg38;
		CMovingBitmap map38;
		CMovingBitmap fg38;

		CMovingBitmap bg39;
		CMovingBitmap map39;
		CMovingBitmap fg39;

		CMovingBitmap bg40;
		CMovingBitmap map40;
		CMovingBitmap fg40;

		CMovingBitmap bg41;
		CMovingBitmap map41;

		CMovingBitmap bg42;
		CMovingBitmap map42;

		CMovingBitmap bg43;
		CMovingBitmap map43;
		CMovingBitmap fg43;
	};
}