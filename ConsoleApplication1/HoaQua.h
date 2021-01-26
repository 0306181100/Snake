#pragma once
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "point.h"
#include "console.h"
class HoaQua
{
private:
	point hq;
public:

	HoaQua(){
		srand(time(NULL));
		point kq((rand() % 38), (rand() % 22));
		this->hq = kq;
	}
	HoaQua(int xx,int yy){
		point kq(xx, yy);
		this->hq = kq;
	}
	~HoaQua(){
	}
	point Get_Hq(){
		return hq;
	}

	void HienThiHoaQua(){
		hq.hienthi('x');
	}
};

