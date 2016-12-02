#pragma once
#define MAX_NAME 20
#define SUBJECTS 3
#define STUDENTS 3

typedef struct grade
{
	char name[MAX_NAME];
	int score[SUBJECTS];
	int total;
	double average;
}Grade;