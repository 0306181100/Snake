#pragma once
#include "point.h"
#include "console.h"

#define maxw 40
#define maxh 24
class snake
{
private:
	point dot[50];
	int n;
public:
	snake TangDoDai(){
		dot[++n]=dot[n-1];
		return *this;
	}
	snake(){
		n = 3;
		point Head(4, 0),Body(3, 0),Tail(2, 0);
		dot[0] = Head;
		dot[1] = Body;
		dot[2] = Tail;
	}

	~snake(){
	}


	point Get_Head(){
		return dot[0];
	}
	void HienThi_snake(){
		TextColor(2);
		dot[0].hienthi(dot[0].get_tt_int());
		TextColor(1);
		for (int i = 1; i < n; i++){
			dot[i].hienthi(dot[i].get_tt_int());
		}
	}

	snake DiChuyen(){
		for (int i = this->n - 1; i > 0; i--)
			dot[i] = dot[i - 1];
		DieuKhien();
		return *this;
	}

	snake DieuKhien(){
		if (_kbhit()){
			char key = _getch();
			if ((key == 'w' || key == 'W') && dot[0].Get_tt() != down)
				this->dot[0].Set_tt(up);
			else if ((key == 's' || key == 'S') && dot[0].Get_tt() != up)
				this->dot[0].Set_tt(down);
			else if ((key == 'd' || key == 'D') && dot[0].Get_tt() != left)
				this->dot[0].Set_tt(right);
			else if ((key == 'a' || key == 'A') && dot[0].Get_tt() != right)
				this->dot[0].Set_tt(left);

		}
		dot[0].move();
		return *this;
	}
	
	void TaoKhung(){
		TextColor(14);
		for (int i = 0; i < maxh; i++){
			gotoXY(maxw-1, i);
			putchar(186);
		}

		for (int i = 0; i < maxw; i++){
			gotoXY(i,maxh-1);
			putchar(205);
		}
		gotoXY(maxw-1, maxh-1); putchar(188);
	}

	void dichchuyen(){
		if (dot[0].GetX() < 0)
			dot[0].SetPoint(maxw - 3, dot[0].GetY());

		if (dot[0].GetX() > maxw-3)
			dot[0].SetPoint(0, dot[0].GetY());

		if (dot[0].GetY() < 0)
			dot[0].SetPoint(dot[0].GetX(), maxh - 3);

		if (dot[0].GetY() > maxh-3)
			dot[0].SetPoint(dot[0].GetX(),0);
	}

	bool EndGame(){
		for (int i = 3; i < n; i++){
			if (dot[0] == dot[i])
				return false;
		}
		return true;
	}
};

