#include <stdio.h>
#include <stdlib.h>
#include"snake.h"
#include"HoaQua.h"
#include "console.h"

void main(){
	snake snake;
	HoaQua A;
	int diem = 0;
	while (snake.EndGame()){
		clrscr();
		snake.TaoKhung();
		snake.HienThi_snake();
		gotoXY(82, 0);
		printf("Diem: %i", diem);
		A.HienThiHoaQua();
		if (A.Get_Hq().GetXY() == snake.Get_Head().GetXY()){
			HoaQua tmp;
			A = tmp;
			diem++;
			if (diem % 1 == 0 && diem != 0)
				snake.TangDoDai();
		}
		snake.dichchuyen();
		snake.DiChuyen();
		Sleep(100);
	}
	clrscr();
	gotoXY(42, 0);
	printf("DIEM: %i \n", diem);
	system("pause");
}