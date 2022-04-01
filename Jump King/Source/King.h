namespace game_framework {

	class King
	{
	public:
		King();
		void Initialize();					//�]�w�}����
		void LoadBitmap();					//���J�Ϥ�
		void OnMove();						//����
		void OnShow();						//�K�ϫ�
		int  GetX1();						//���⥪�W��X�y��
		int  GetY1();						//���⥪�W��Y�y��
		int  GetX2();						//���⥪�U��X�y��
		int  GetY2();						//���⥪�U��Y�y��
		void SetMovingLeft(bool flag);		//�]�w�O�_��������
		void SetMovingRight(bool flag);		//�]�w�O�_���k����
		void SetRightLeft(bool flag);		//�]�w�����B�ʫ��V,true:�k, false:��
		//------------------------------����------------------------------//
		void SetJump(bool flag);
		void SetJumpUp(bool flag);
		void SetHeight();
		bool GetJumpING();
	protected:
		CAnimation animationRRUN;		//�V�k�]�B�ʵe
		CAnimation animationLRUN;		//�V���]�B�ʵe
		int x, y;						//���⥪�W���y��
		bool isMovingLeft;				//�O�_��������
		bool isMovingRight;				//�O�_���k����
		bool isRightLeft;				//�����B�ʫ��V,true:�k, false:��
		//------------------------------����------------------------------//
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