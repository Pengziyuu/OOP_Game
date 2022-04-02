namespace game_framework {

	class King
	{
	public:
		King();
		void Initialize();					// 設定初值
		void LoadBitmap();					// 載入圖片
		void OnMove();						// 移動
		void OnShow();						// 貼圖型
		int  GetX1();						// 角色左上角X座標	0
		int  GetY1();						// 角色左上角Y座標	0 
		int  GetX2();						// 角色左下角X座標	0
		int  GetY2();						// 角色左下角Y座標	0
		void SetMovingLeft(bool flag);		// 設定是否往左移動
		void SetMovingRight(bool flag);		// 設定是否往右移動
		void FaceDirection();				// 設定當前面朝方向
		void addJumpForce();				// 設定是否增加跳躍力	
		void doJump();						// 設定是否切換跳躍
		//------------------------------測試------------------------------//

	protected:
		CAnimation animationRUNL;			// 向左跑步動畫
		CAnimation animationRUNR;			// 向右跑步動畫
		CMovingBitmap jumpReady;			// 蹲下圖片
		CMovingBitmap jumpUpL;				// 向左跳躍上升圖片
		CMovingBitmap jumpUpR;				// 向右跳躍上升圖片
		CMovingBitmap jumpDownL;			// 向左跳躍下降圖片
		CMovingBitmap jumpDownR;			// 向右跳躍下降圖片
		enum FACE_DIRECTION { LEFT, RIGHT }; 
		FACE_DIRECTION faceDirection;		// 當前面朝方向
		enum JUMP_DIRECTION { NONE, JLEFT, JRIGHT }; 
		JUMP_DIRECTION jumpDirection;		// 跳出去方向
		int x, y;							// 人物左上角座標
		int velocity;						// 人物跳躍力
		bool isMovingLeft;					// 是否往左移動
		bool isMovingRight;					// 是否往右移動
		bool applyForce;					// 是否增加跳躍力
		bool isJumpING;						// 是否正在跳躍
		
		int floor;
		//------------------------------測試------------------------------//

	};
}