// exam8.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int num = 0;
	int num2;
	printf_s("정수값을 입력하세요 : ");
	scanf_s("%d,%d", &num,&num2);
	printf_s("%d, %d을 입력하셨습니다.\n", num,num2);
	printf_s("두 수의 합은 %d", num + num2);
    return 0;
}

