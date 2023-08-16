#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{
	struct student mystudents[50];
	int choice = 100;
	int count1 = 0;
	const int maxacademicyrs = 5;
	printf("**************\n        Student managment system\n**************\n");
	while (choice != 0)
	{
		printf("1-Add a new student\n2-Remove a student\n3-Retrieve student's data\n4-Update student's data\nif you want to quit press 0\n");
		scanf_s("%d", &choice);
		if (choice == 1) //add student
		{
			choice1(mystudents, count1, maxacademicyrs);
			count1++;
		}
		else if (choice == 2) //remove student
		{
			choice2(mystudents, count1);
		}
		else if (choice == 3) //retrieve student data
		{
			choice3(mystudents, count1);
		}
		else if (choice == 4) //update data
		{
			choice4(mystudents, count1);
		}
		else
		{
			printf("please enter a valid option\n");
		}
	}
}