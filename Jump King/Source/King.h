namespace game_framework {

	class King
	{
	public:
		King();
		void Initialize();					// �]�w���
		void LoadBitmap();					// ���J�Ϥ�
		void OnMove();						// ����
		void OnShow();						// �K�ϫ�
		int  GetX1();						// ���⥪�W��X�y��	0
		int  GetY1();						// ���⥪�W��Y�y��	0 
		int  GetX2();						// ���⥪�U��X�y��	0
		int  GetY2();						// ���⥪�U��Y�y��	0
		void SetMovingLeft(bool flag);		// �]�w�O�_��������
		void SetMovingRight(bool flag);		// �]�w�O�_���k����
		void FaceDirection();				// �]�w��e���¤�V
		void addJumpForce();				// �]�w�O�_�W�[���D�O	
		void doJump();						// �]�w�O�_�������D
		//------------------------------����------------------------------//

	protected:
		CAnimation animationRUNL;			// �V���]�B�ʵe
		CAnimation animationRUNR;			// �V�k�]�B�ʵe
		CMovingBitmap jumpReady;			// �ۤU�Ϥ�
		CMovingBitmap jumpUpL;				// �V�����D�W�ɹϤ�
		CMovingBitmap jumpUpR;				// �V�k���D�W�ɹϤ�
		CMovingBitmap jumpDownL;			// �V�����D�U���Ϥ�
		CMovingBitmap jumpDownR;			// �V�k���D�U���Ϥ�
		enum FACE_DIRECTION { LEFT, RIGHT }; 
		FACE_DIRECTION faceDirection;		// ��e���¤�V
		enum JUMP_DIRECTION { NONE, JLEFT, JRIGHT }; 
		JUMP_DIRECTION jumpDirection;		// ���X�h��V
		int x, y;							// �H�����W���y��
		int velocity;						// �H�����D�O
		bool isMovingLeft;					// �O�_��������
		bool isMovingRight;					// �O�_���k����
		bool applyForce;					// �O�_�W�[���D�O
		bool isJumpING;						// �O�_���b���D
		
		int floor;
		//------------------------------����------------------------------//

	};
}