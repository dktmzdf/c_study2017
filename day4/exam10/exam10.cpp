// exam10.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	printf("%d %c %d \n", 65, 65 , 'A');
	printf("%d %d %d %d %d \n", 'H', 'e','l','l','o');
	printf("%c%c%c%c%c \n", 65, 66, 67, 68, 69);
	printf("%c%c%c%c%c \n", 72, 101, 108, 108, 111);

	char blood_type;
	scanf_s("%c",&blood_type);
	printf_s("당신의 혈액형은 : %c 입니다. \n", blood_type);



    return 0;
}

