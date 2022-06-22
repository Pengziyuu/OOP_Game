#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "King.h"
#include "GameAudio.h"
#include "Map.h"

namespace game_framework {
	King::King()
	{
		Initialize();
	}

	void King::Initialize()
	{
		// 人物設定
		x = 480;
		//y = 600;
		y = 300;
		floor = 638;
		velocityX = 0;
		velocityY = 0;	
		trueX = 5;
		isMovingLeft = isMovingRight = false;	
		applyForce = false;						
		isJumpING = false;
		falling = false;
		jumpDirection = NONE;					
		faceDirection = RIGHT;		

		slide = false;
	}

	void King::LoadBitmap()
	{
		// LeftRun
		animationRUNL.AddBitmap(IDB_KING01L, RGB(0, 0, 0));
		animationRUNL.AddBitmap(IDB_KING02L, RGB(0, 0, 0));
		animationRUNL.AddBitmap(IDB_KING03L, RGB(0, 0, 0));
		animationRUNL.AddBitmap(IDB_KING04L, RGB(0, 0, 0));
		// RightRun
		animationRUNR.AddBitmap(IDB_KING01, RGB(0, 0, 0));
		animationRUNR.AddBitmap(IDB_KING02, RGB(0, 0, 0));
		animationRUNR.AddBitmap(IDB_KING03, RGB(0, 0, 0));
		animationRUNR.AddBitmap(IDB_KING04, RGB(0, 0, 0));
		// ReadyJump
		jumpReady.LoadBitmap(IDB_KING11, RGB(0, 0, 0));
		// LeftJump
		jumpUpL.LoadBitmap(IDB_KING12L, RGB(0, 0, 0));
		jumpDownL.LoadBitmap(IDB_KING13L, RGB(0, 0, 0));
		// RightJump
		jumpUpR.LoadBitmap(IDB_KING12, RGB(0, 0, 0));
		jumpDownR.LoadBitmap(IDB_KING13, RGB(0, 0, 0));
		// LeftReboun
		reboundR.LoadBitmap(IDB_KING31, RGB(0, 0, 0));
		// RightReboun
		reboundL.LoadBitmap(IDB_KING31L, RGB(0, 0, 0));
	}

	int King::GetX1()
	{
		return x;
	}

	int King::GetY1()
	{
		return y;
	}

	int King::GetX()
	{
		return x + 24;
	}

	int King::GetY()
	{
		return y + 30;
	}

	void King::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void King::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void King::SetFloor(Map *m) 
	{
		int temp = GetY();
		// 從當前Y值往下抓地面值
		while(m->IsEmpty(GetX(), temp) == 0)
		{
			temp++;
			if (temp > 700)
			{
				temp = 700;
				break;
			}
		}
		floor = temp;
	}

	void King::FaceDirection()
	{
		if (applyForce == false && isJumpING == false) // 不在蓄力和跳躍中改動方向
		{
			if (isMovingLeft == true && isMovingRight == true) // 左右都按時方向不變
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

	void King::addJumpForce() // 非跳躍時是否增加跳躍力
	{
		if (isJumpING == false)
		{
			applyForce = true;
		}
	}

	void King::doJump()
	{
		if (isJumpING == false) // 非跳躍期間才可改變跳躍方向
		{
			applyForce = false; // 結束蓄力
			isJumpING = true;	// 開始跳躍

			// 設定跳出去方向
			if (isMovingLeft == isMovingRight) jumpDirection = NONE;
			else
			{
				if (isMovingLeft)  jumpDirection = JLEFT;
				if (isMovingRight)  jumpDirection = JRIGHT;
			}
		}
	}

	void King::OnMove(Map *m)
	{
		// 移動前抓地板Y值
		SetFloor(m);

		// 蓄力
		if (applyForce)
		{
			velocityY+=1;
			if (velocityY >= 25)
			{
				doJump();
			}
		}

		// 跳躍，先上下判斷移動在左右判斷移動
		if (isJumpING)
		{
			if (GetY() - velocityY <= 20) // 碰到上邊界換下一張地圖，Y值回到680
			{
				m->ChangeMap(3);
				y = 670;
			}
			else if (m->IsEmpty(GetX(), GetY() - velocityY) == 1 && velocityY > 0) //往上碰到障礙物動能歸0
			{
				velocityY = 0;
			}
			else if (m->IsEmpty(GetX(), GetY() - velocityY) == 4)
			{
				slide = true;
				if (m->IsEmpty(GetX(), GetY() + trueX) != 1)
				{
					y += trueX;
					if (GetY() + trueX < 720)
					{
						if (trueX < 100) trueX++;
					}
					if (GetY() + trueX >= 700) // 碰到下邊界換上一張地圖，Y值回到30
					{
						m->ChangeMap(2);
						y = 30;
					}
					x += trueX;
					while (m->IsEmpty(GetX(), GetY()) == 1) {
						x++;
					}
				}

				falling = true;
				isJumpING = true;
				jumpDirection = JRIGHT;
		
			}
			else if (m->IsEmpty(GetX(), GetY() - velocityY) == 5)
			{
				slide = true;
				if (m->IsEmpty(GetX(), GetY() - trueX) != 1)
				{
					y += trueX;
					if (GetY() + trueX < 720)
					{
						if (trueX < 100) trueX++;
					}
					if (GetY() + trueX >= 700) // 碰到下邊界換上一張地圖，Y值回到30
					{
						m->ChangeMap(2);
						y = 30;
					}
					x -= trueX;
					while (m->IsEmpty(GetX(), GetY()) == 1) {
						x--;
					}
				}

				falling = true;
				isJumpING = true;
				jumpDirection = JLEFT;

			}
			else if (m->IsEmpty(GetX(), GetY() - velocityY) != 1) // 上下方向沒碰到障礙物動
			{
				y -= velocityY;
				if (GetY() - velocityY < 720)
				{
					if (velocityY < 300) velocityY--;
				}
				if (GetY() - velocityY >= 700) // 碰到下邊界換上一張地圖，Y值回到30
				{
					m->ChangeMap(2);
					y = 30;
				}

				if (slide == false)
				{
					if (falling) trueX = 5;
					else trueX = 9;
				}

				switch (jumpDirection)
				{
				case JLEFT:
					if (m->IsEmpty(GetX() - trueX, GetY()) == 0) 
						velocityX = -trueX;
					else if (m->IsEmpty(GetX() - trueX, GetY()) == 1)
					{
						CAudio::Instance()->Play(AUDIO_Bump, false);
						jumpDirection = JREBOUND;
						velocityX = 4;
					}
					break;
				case JRIGHT:
					if (m->IsEmpty(GetX() + trueX, GetY()) == 0)
						velocityX = trueX;
					else if (m->IsEmpty(GetX() + trueX, GetY()) == 1)
					{
						CAudio::Instance()->Play(AUDIO_Bump, false);
						jumpDirection = JREBOUND;
						velocityX = -4;
					}
					break;
				case JREBOUND:
					if (m->IsEmpty(GetX() - velocityX, GetY()) == 1 || m->IsEmpty(GetX() + velocityX, GetY()) == 1) // 若撞牆則位移反向否則不變
					{                         
  		        	 	CAudio::Instance()->Play(AUDIO_Bump, false);
						velocityX = -velocityX;
					}
					break;
				case NONE:
					velocityX = 0;
					break;
				default:
					break;
				}
				x += velocityX;
			}
			else
			{
				CAudio::Instance()->Play(AUDIO_Fall, false);
				y = floor-38;
				velocityY = 0;
				if (jumpDirection == JRIGHT)
					faceDirection = RIGHT;
				if (jumpDirection == JLEFT)
					faceDirection = LEFT;
				jumpDirection = NONE;
				isJumpING = false;
				falling = false;
				slide = false;
			}
		}

		// 跑步
		if (applyForce == false && isJumpING == false && falling == false) 
		{
			velocityX = 5;
			if (isMovingLeft != isMovingRight) // 單按一方向才動
			{
				FaceDirection();
				switch (faceDirection)
				{
				case LEFT:
					if (m->IsEmpty(GetX() - velocityX, GetY()) != 1)
						x -= velocityX;
					if (m->IsEmpty(GetX(), GetY() + 20) == 0) // 往前沒地板掉落
					{
						falling = true;
						isJumpING = true;
						jumpDirection = JLEFT;
					}
					break;
				case RIGHT:
					if (m->IsEmpty(GetX() + velocityX, GetY()) != 1)
						x += velocityX;
					if (m->IsEmpty(GetX(), GetY() + 20) == 0) // 往前沒地板掉落
					{
						falling = true;
						isJumpING = true;
						jumpDirection = JRIGHT;
					}
					break;
				default:
					velocityY = 0;
					break;
				}
			}
		}
	}
	 
	void King::OnShow()
	{
		// 蓄力
		if (applyForce) 
		{
			jumpReady.SetTopLeft(x, y+jumpReady.Height());
			jumpReady.ShowBitmap(2);
		}

		//跳躍
		if (isJumpING)
		{
			switch (jumpDirection)
			{
			case JLEFT:
				if (velocityY >= 0)
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
			case JRIGHT:
				if (velocityY >= 0) 
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
			case JREBOUND:
				if (velocityX < 0) 
				{
					reboundR.SetTopLeft(x, y);
					reboundR.ShowBitmap(2);
				}
				else
				{
					reboundL.SetTopLeft(x, y);
					reboundL.ShowBitmap(2);
				}
				break;
			case NONE:
				switch (faceDirection)
				{
				case LEFT:
					if (velocityY >= 0)
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
					if (velocityY >= 0)
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

		// 跑步
		if (applyForce == false && isJumpING == false && falling == false) {
			animationRUNL.SetTopLeft(x, y); // 設定往左動畫位置
			animationRUNR.SetTopLeft(x, y); // 設定往右動畫位置
			if (isMovingLeft == isMovingRight) // 左右放開/都按，停住
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

	void King::TestMove(int d, Map *m)
	{
		switch (d)
		{
		case 1: // right
			if (m->IsEmpty(GetX() + 5, GetY()) == 0)
			x += 5;
			break;
		case 2: // left
			if (m->IsEmpty(GetX() - 5, GetY()) == 0)
			x -= 5;
			break;
		case 3: // down
			if (m->IsEmpty(GetX(), GetY() + 5) == 0)
			y += 5;
			break;
		case 4: // up
			if (m->IsEmpty(GetX(), GetY() - 5) == 0)
			y -= 5;
			break;
		default:
			break;
		}
	}
}