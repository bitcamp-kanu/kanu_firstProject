#include<stdio.h>

void main()
{
	FILE*fp = fopen("mystory.txt", "wt");
	fputs("�̸�:ȫ�浿\n", fp);
	fputs("����:31\n", fp);
	fputs("��ȭ��ȣ:010-1111-2222\n", fp);
	fputs("����:31\n", fp);
	fputs("��ȭ��ȣ:010-1111-2222\n", fp);
	fputs("��ܸԴ� ���� : «��, ������\n", fp);
	fputs("��� : �౸\n", fp);
	fclose(fp);
}