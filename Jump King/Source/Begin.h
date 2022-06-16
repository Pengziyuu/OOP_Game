#pragma once
namespace game_framework {

	class Begin
	{
	public:
		Begin();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		int logoStop;
	protected:
		CMovingBitmap logo;					
		CMovingBitmap logoEnter;
		CMovingBitmap logoKing;
		int x, y;
		int x2, y2;
		int x3, y3;
		int delay;
		bool show;
	};
}
