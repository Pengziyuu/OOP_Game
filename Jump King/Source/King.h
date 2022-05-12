#include "Map.h"
#pragma once
namespace game_framework {

	class King
	{
	public:
		King();
		void Initialize();					// �]�w���
		void LoadBitmap();					// ���J�Ϥ�
		void OnMove(Map *m);				// ����
		void OnShow();						// �K�ϫ�
		int  GetX1();						// ���⥪�W��X�y��	0
		int  GetY1();						// ���⥪�W��Y�y��	0 
		int  GetX();						// ���⤤���IX�y��	0
		int  GetY();						// ���⤤���IY�y��	0
		void SetMovingLeft(bool flag);		// �]�w�O�_��������
		void SetMovingRight(bool flag);		// �]�w�O�_���k����
		void SetFloor(Map *m);				// �]�w��e�a�OY��
		void FaceDirection();				// �]�w��e���¤�V
		void addJumpForce();				// �]�w�O�_�W�[���D�O	
		void doJump();						// �]�w�O�_�������D

		//------------------------------����------------------------------//
		void TestMove(int d, Map *m);

	protected:
		CAnimation animationRUNL;			// �V���]�B�ʵe
		CAnimation animationRUNR;			// �V�k�]�B�ʵe
		CMovingBitmap jumpReady;			// �ۤU�Ϥ�
		CMovingBitmap jumpUpL;				// �V�����D�W�ɹϤ�
		CMovingBitmap jumpUpR;				// �V�k���D�W�ɹϤ�
		CMovingBitmap jumpDownL;			// �V�����D�U���Ϥ�
		CMovingBitmap jumpDownR;			// �V�k���D�U���Ϥ�
		CMovingBitmap reboundL;				// �V���ϼu�Ϥ�
		CMovingBitmap reboundR;				// �V�k�ϼu�Ϥ�

		enum FACE_DIRECTION { LEFT, RIGHT, REBOUND}; 
		FACE_DIRECTION faceDirection;		// ��e���¤�V
		enum JUMP_DIRECTION { NONE, JLEFT, JRIGHT, JREBOUND}; 
		JUMP_DIRECTION jumpDirection;		// ���X�h��V

		int floor;							// �a�OY��
		int x, y;							// �H�����W���y��
		int velocityX;						// �H�����k�첾��
		int velocityY;						// �H���W�U�첾��
		bool isMovingLeft;					// �O�_��������
		bool isMovingRight;					// �O�_���k����
		bool applyForce;					// �O�_�W�[���D�O
		bool isJumpING;						// �O�_���b���D
		bool falling;						// �O�_Y�ȥ��b�U��
		//------------------------------����------------------------------//
	};
}