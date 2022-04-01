namespace game_framework {

	class Map
	{
	public:
		Map();
		void LoadBitmap();
		void ShowBitmap();
		void Map01();
		void Map02();
	protected:
		CMovingBitmap map01;
		CMovingBitmap fg01;
		vector<vector<int>> matrix01;

		CMovingBitmap map02;
		CMovingBitmap fg02;
	};
}
