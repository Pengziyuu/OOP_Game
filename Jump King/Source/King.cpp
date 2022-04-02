#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "King.h"
#include "GameAudio.h"

namespace game_framework {
	King::King()
	{
		Initialize();
	}

	void King::Initialize()
	{
		// �H���]�w
		const int X_POS = 480; 
		const int Y_POS = 602;
		x = X_POS;
		y = Y_POS;
		velocity = 0;							
		isMovingLeft = isMovingRight = false;	
		applyForce = false;						
		isJumpING = false;						
		jumpDirection = NONE;					
		faceDirection = RIGHT;			

		const int FLOOR = 602;
		floor = FLOOR;
	}

	void King::LoadBitmap()
	{
		// RightRun
		animationRUNR.AddBitmap(IDB_KING01, RGB(0, 0, 0));
		animationRUNR.AddBitmap(IDB_KING02, RGB(0, 0, 0));
		animationRUNR.AddBitmap(IDB_KING03, RGB(0, 0, 0));
		animationRUNR.AddBitmap(IDB_KING04, RGB(0, 0, 0));
		// LeftRun
		animationRUNL.AddBitmap(IDB_KING01L, RGB(0, 0, 0));
		animationRUNL.AddBitmap(IDB_KING02L, RGB(0, 0, 0));
		animationRUNL.AddBitmap(IDB_KING03L, RGB(0, 0, 0));
		animationRUNL.AddBitmap(IDB_KING04L, RGB(0, 0, 0));
		// ReadyJump
		jumpReady.LoadBitmap(IDB_KING11, RGB(0, 0, 0));
		// RightJump
		jumpUpR.LoadBitmap(IDB_KING12, RGB(0, 0, 0));
		jumpDownR.LoadBitmap(IDB_KING13, RGB(0, 0, 0));
		// LeftJump
		jumpUpL.LoadBitmap(IDB_KING12L, RGB(0, 0, 0));
		jumpDownL.LoadBitmap(IDB_KING13L, RGB(0, 0, 0));
	}

	int King::GetX1()
	{
		return x;
	}

	int King::GetY1()
	{
		return y;
	}

	int King::GetX2()
	{
		return x + animationRUNR.Width();
	}

	int King::GetY2()
	{
		return y + animationRUNR.Height();
	}

	void King::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void King::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void King::FaceDirection()
	{
		if (applyForce == false && isJumpING == false) // ���b�W�O�M���D����ʤ�V
		{
			if (isMovingLeft == true && isMovingRight == true) // ���k�����ɤ�V����
			{
				return;
			}
			else if (isMovingLeft)
			{
				faceDirection = LEFT;
			}
			else if (isMovingRight)
			{
				faceDirection = RIGHT;
			}
		}
	}

	void King::addJumpForce() // �D���D�ɬO�_�W�[���D�O
	{
		if (isJumpING == false)
		{
			applyForce = true;
		}
	}

	void King::doJump()
	{
		applyForce = false; // �����W�O
		isJumpING = true;	// �}�l���D

		// �]�w���X�h��V
		if (isMovingLeft == isMovingRight) jumpDirection = NONE;
		else
		{
			if (isMovingLeft)  jumpDirection = JLEFT;
			if (isMovingRight)  jumpDirection = JRIGHT;
		}

	}

	void King::OnMove()
	{
		// �W�O
		if (applyForce)
		{
			velocity++;
			if (velocity >= 17)
			{
				doJump();
			}
		}

		// ���D
		if (isJumpING)
		{
			y -= velocity;
			if (y <= floor - 1) // the king not touch the ground
			{
				y -= velocity;
				velocity--;
				if (jumpDirection == JRIGHT) {
					x += 13;
				}
				else if (jumpDirection == JLEFT) 
				{
					x -= 13;
				}
			}
			else 
			{
				CAudio::Instance()->Play(AUDIO_Fall, false);
				y = floor;
				velocity = 0;
				isJumpING = false;
				jumpDirection = NONE;
				FaceDirection();

			}
		}

		// �]�B
		if (applyForce == false && isJumpING == false)
		{
			const int STEP_SIZE = 5;
			if (isMovingLeft != isMovingRight) // ����@��V�~��
			{
				switch (faceDirection)
				{
				case LEFT:
					x -= STEP_SIZE;
					break;
				case RIGHT:
					x += STEP_SIZE;
					break;
				default:
					break;
				}
			}
		}
	}
	 
	void King::OnShow()
	{
		// �W�O
		if (applyForce) 
		{
			jumpReady.SetTopLeft(x, y+jumpReady.Height());
			jumpReady.ShowBitmap(2);
		}

		//���D
		if (isJumpING)
		{
			switch (jumpDirection)
			{
			case JRIGHT:
				if (velocity >= 0) 
				{
					jumpUpR.SetTopLeft(x, y);
					jumpUpR.ShowBitmap(2);
				}
				else
				{
					jumpDownR.SetTopLeft(x, y);
					jumpDownR.ShowBitmap(2);
				}
				break;
			case JLEFT:
				if (velocity >= 0) 
				{
					jumpUpL.SetTopLeft(x, y);
					jumpUpL.ShowBitmap(2);
				}
				else
				{
					jumpDownL.SetTopLeft(x, y);
					jumpDownL.ShowBitmap(2);
				}
				break;
			case NONE:
				switch (faceDirection)
				{
				case LEFT:
					if (velocity >= 0)
					{
						jumpUpL.SetTopLeft(x, y);
						jumpUpL.ShowBitmap(2);
					}
					else
					{
						jumpDownL.SetTopLeft(x, y);
						jumpDownL.ShowBitmap(2);
					}
					break;
				case RIGHT:
					if (velocity >= 0)
					{
						jumpUpR.SetTopLeft(x, y);
						jumpUpR.ShowBitmap(2);
					}
					else
					{
						jumpDownR.SetTopLeft(x, y);
						jumpDownR.ShowBitmap(2);
					}
					break;
				default:
					break;
				}
			default:
				break;
			}
		}

		// �]�B
		if (applyForce == false && isJumpING == false) {
			animationRUNL.SetTopLeft(x, y); // �]�w�����ʵe��m
			animationRUNR.SetTopLeft(x, y); // �]�w���k�ʵe��m
			if (isMovingLeft == isMovingRight) // ���k��}/�����A����
			{
				switch (faceDirection)
				{
				case LEFT:
					animationRUNL.Reset();
					animationRUNL.OnShow();
					break;
				case RIGHT:
					animationRUNR.Reset();
					animationRUNR.OnShow();
					break;
				default:
					break;
				}
			}
			else
			{
				switch (faceDirection)
				{
				case LEFT:
					animationRUNL.OnMove();
					animationRUNL.OnShow();
					break;
				case RIGHT:
					animationRUNR.OnMove();
					animationRUNR.OnShow();
					break;
				default:
					break;
				}
			}
		}
	}
}