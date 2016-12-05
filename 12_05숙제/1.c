#include<stdio.h>

void main()
{
	FILE*fp = fopen("mystory.txt","wt");
	fputs("이름:홍길동\n", fp);
	fputs("나이:31\n", fp);
	fputs("전화번호:010-1111-2222\n", fp);
	fclose(fp);
}