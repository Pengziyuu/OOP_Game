namespace game_framework {

	class King
	{
	public:
		King();
		void Initialize();					//設定腳色初值
		void LoadBitmap();					//載入圖片
		void OnMove();						//移動
		void OnShow();						//貼圖型
		int  GetX1();						//角色左上角X座標
		int  GetY1();						//角色左上角Y座標
		int  GetX2();						//角色左下角X座標
		int  GetY2();						//角色左下角Y座標
		void SetMovingLeft(bool flag);		//設定是否往左移動
		void SetMovingRight(bool flag);		//設定是否往右移動
		void SetRightLeft(bool flag);		//設定結束運動後方向,true:右, false:左
		//------------------------------測試------------------------------//
		void SetJump(bool flag);
		void SetJumpUp(bool flag);
		void SetHeight();
		bool GetJumpING();
	protected:
		CAnimation animationRRUN;		//向右跑步動畫
		CAnimation animationLRUN;		//向左跑步動畫
		int x, y;						//角色左上角座標
		bool isMovingLeft;				//是否往左移動
		bool isMovingRight;				//是否往右移動
		bool isRightLeft;				//結束運動後方向,true:右, false:左
		//------------------------------測試------------------------------//
		bool isJump;
		bool isJumpUp;
		bool isJumpING;
		int floor;
		bool rising;
		// int initial_velocity;	
		int velocity;			
		CMovingBitmap jumpReady;
		CMovingBitmap jumpUp;
		CMovingBitmap jumpDown;
	};
}