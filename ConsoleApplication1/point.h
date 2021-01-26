#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <random>
#include "console.h"

enum TrangThai { up, down, left, right};

class point
{
private:
	int x;
	int y;
	TrangThai tt;
public:
	point(){
		x = 0;
		y = 0;
		tt = right;
	}
	int get_tt_int(){
		if (this->tt == up)
			return 94;
		else if (this->tt == down)
			return 118;
		else if (this->tt == left)
			return 60;
		return 62;
	}
	int GetX(){
		return x;
	}
	int GetY(){
		return y;
	}
	point(int xx,int yy){
		x = xx;
		y = yy;
		tt = right;
	}

	~point(){
	}
	point SetPoint(int xx, int yy){
		x = xx;
		y = yy;
		return *this;
	}

	point move(){
		if (this->tt == up)
			this->y--;
		else if (this->tt == down)
			this->y++;
		else if (this->tt == left)
			this->x--;
		else if (this->tt == right)
			this->x++;
		return *this;
	}

	void hienthi(char c){
		gotoXY(x, y);
		putchar(c);
	}
	point GetXY(){
		point kq(this->x, this->y);
		return kq;
	}
	TrangThai Get_tt(){
		return this->tt;
	}
	point Set_tt(TrangThai ttp){
		this->tt = ttp;
		return *this;
	}
	bool operator ==(point p){
		return x == p.x&&y == p.y;
	}
};

