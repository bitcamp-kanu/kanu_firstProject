#include<stdio.h>

void main()
{
	FILE*fp = fopen("mystory.txt", "wt");
	fputs("이름:홍길동\n", fp);
	fputs("나이:31\n", fp);
	fputs("전화번호:010-1111-2222\n", fp);
	fputs("나이:31\n", fp);
	fputs("전화번호:010-1111-2222\n", fp);
	fputs("즐겨먹는 음식 : 짬뽕, 탕수육\n", fp);
	fputs("취미 : 축구\n", fp);
	fclose(fp);
}