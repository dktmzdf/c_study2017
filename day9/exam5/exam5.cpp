// exam5.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

void input_ary(int *ap)
{
	ap[0] = 10;
	*(ap + 1) = 20;

}

int main()
{
	int ary[2];
	input_ary(ary);

	printf("%d %d \n",ary[0],ary[1]);

	int ary2[5] = { 10,20,30,40,50 };
	int *ap = ary2 + 2;//기준을 뒤로 2칸 미룸
	printf("%d %d \n",*(ap +1), *(ap + 2));
    return 0;
}

