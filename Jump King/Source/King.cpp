#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "King.h"

namespace game_framework {
	King::King()
	{
		Initialize();
	}

	void King::Initialize()
	{
		const int X_POS = 480;
		const int Y_POS = 602;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = false;
		isRightLeft = true;


		const int FLOOR = 601;
		floor = FLOOR;
		rising = true;
		isJump = false;
		isJumpUp = false;
		isJumpING = false;
		velocity = 5;
	}

	void King::LoadBitmap()
	{
		// RightRun
		animationRRUN.AddBitmap(IDB_KING01, RGB(0, 0, 0));
		animationRRUN.AddBitmap(IDB_KING02, RGB(0, 0, 0));
		animationRRUN.AddBitmap(IDB_KING03, RGB(0, 0, 0));
		animationRRUN.AddBitmap(IDB_KING04, RGB(0, 0, 0));
		// LeftRun
		animationLRUN.AddBitmap(IDB_KING01L, RGB(0, 0, 0));
		animationLRUN.AddBitmap(IDB_KING02L, RGB(0, 0, 0));
		animationLRUN.AddBitmap(IDB_KING03L, RGB(0, 0, 0));
		animationLRUN.AddBitmap(IDB_KING04L, RGB(0, 0, 0));

		jumpReady.LoadBitmap(IDB_KING11, RGB(0, 0, 0));
		jumpUp.LoadBitmap(IDB_KING12, RGB(0, 0, 0));
		jumpDown.LoadBitmap(IDB_KING13, RGB(0, 0, 0));
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
		return x + animationRRUN.Width();
	}

	int King::GetY2()
	{
		return y + animationRRUN.Height();
	}

	void King::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void King::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void King::SetRightLeft(bool flag)
	{
		isRightLeft = flag;
	}

	void King::SetJump(bool flag)
	{
		isJump = flag;
	}

	void King::SetJumpUp(bool flag)
	{
		isJumpUp = flag;
	}

	void King::SetHeight() 
	{
		velocity+=2;
	}

	bool King::GetJumpING()
	{
		return isJumpING;
	}

	void King::OnMove()
	{
		if (isJump)
		{
			if (isJumpUp || velocity == 25)
			{ 
				isJumpUp = true;
				isJumpING = true;
				if (rising)
				{
					if (velocity > 0)
					{
						x += 10;
						y -= velocity;
						velocity--;
					}
					else
					{
						rising = false;
						velocity = 1;
					}
				}
				else
				{
					if (y < floor - 1)
					{
						x += 10;
						y += velocity;
						velocity++;
					}
					else {
						rising = true;
						isJump = false;
						isJumpUp = false;
						isJumpING = false;
						velocity = 5;
					}
				}
			}
		}
		// 跑步
		else
		{
			const int STEP_SIZE = 3;
			if (isMovingLeft == false && isMovingRight == false) // 左右放開，動畫設為後按的
			{
				if (isRightLeft)
				{
					animationRRUN.Reset();
				}
				else
				{
					animationLRUN.Reset();
				}
			}
			else if (isMovingLeft == true && isMovingRight == true) // 左右都按，動畫設為先按的
			{
				if (isRightLeft)
				{
					animationLRUN.Reset();
				}
				else
				{
					animationRRUN.Reset();
				}
			}
			else if (isMovingLeft) // 向左移動
			{
				x -= STEP_SIZE;
				animationLRUN.OnMove();
			}
			else if (isMovingRight) // 向右移動
			{
				x += STEP_SIZE;
				animationRRUN.OnMove();
			}
		}
	}
	 
	void King::OnShow()
	{
		if (isJump)
		{
			if (isJumpUp == false) 
			{
				jumpReady.SetTopLeft(x, y + jumpReady.Height());
				jumpReady.ShowBitmap(2);
			}
			else {
				if (rising)
				{
					jumpUp.SetTopLeft(x, y);
					jumpUp.ShowBitmap(2);
				}
				else
				{
					jumpDown.SetTopLeft(x, y);
					jumpDown.ShowBitmap(2);
				}
			}
		}
		// 跑步
		else
		{
			animationLRUN.SetTopLeft(x, y); // 設定往左動畫位置
			animationRRUN.SetTopLeft(x, y); // 設定往右動畫位置
			if (isMovingLeft == false && isMovingRight == false) // 左右放開，動畫設為後按的
			{
				if (isRightLeft)
				{
					animationRRUN.OnShow();
				}
				else
				{
					animationLRUN.OnShow();
				}
			}
			else if (isMovingLeft == true && isMovingRight == true) // 左右都按，動畫設為先按的
			{
				if (isRightLeft)
				{
					animationLRUN.OnShow();
				}
				else
				{
					animationRRUN.OnShow();
				}
			}
			else if (isMovingLeft) // 向左移動
			{
				animationLRUN.OnShow();
			}
			else if (isMovingRight) // 向右移動
			{
				animationRRUN.OnShow();
			}
		}
	}
}