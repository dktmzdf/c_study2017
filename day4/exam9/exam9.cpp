// exam9.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	double pi = 3.14;
	printf("%lf \n", pi);
	double tax;

	printf("세금을 입력하세요 : ");
	scanf_s("%lf", &tax);
	printf("세금은 %lf%% 입니다 \n", tax);

	float test;
	printf("아무 실수나 입력하세요 : ");
	scanf_s("%f", &test);
	printf("%f \n",test);
    return 0;
}

