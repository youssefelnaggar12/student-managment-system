#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void choice1(struct student* mystudents, int count1, int maxacademicyrs)//add
{

	printf("enter student name and between first and last names '.' : ");
	scanf_s("%s", mystudents[count1].name, sizeof(mystudents[count1].name));
	int dots=0;
	for (int k = 0; k < strlen(mystudents[count1].name); k++)
	{
		if (mystudents[count1].name[k] == '.')
		{
			dots++;
		}
	}
	if (dots > 1)
	{
		printf("\nenter only two names separted by '.' : ");
		scanf_s("%s", mystudents[count1].name, sizeof(mystudents[count1].name));
	}
	/*gets(mystudents[count1].name);*/
	printf("\nenter student id : ");
	scanf_s("%d", &mystudents[count1].id);
	while (mystudents[count1].id < 1000000 || mystudents[count1].id>9999999)
	{
		printf("\nplease enter an valid id : ");
		scanf_s("%d", &mystudents[count1].id);
	}
    for (int i = 0; i < count1; i++)
	{
		if (count1 == 0)
		{
			break;
		}
		else if (mystudents[count1].id == mystudents[i].id)
		{
			printf("\nid is already used please enter an new id : ");
			scanf_s("%d", &mystudents[count1].id);
		}
	}
	getchar();
	printf("\nenter student gender : ");
	scanf("%c",&mystudents[count1].gender); 
	while (mystudents[count1].gender != 'm' && mystudents[count1].gender != 'f')
	{
		getchar();
		printf("\nplease enter right gender m or f : ");
		scanf("%c",&mystudents[count1].gender);
	}
	printf("\nenter student academic year : ");
	scanf_s("%d", &mystudents[count1].academicyear);
	while (mystudents[count1].academicyear < 1 || mystudents[count1].academicyear > maxacademicyrs)
	{
		printf("\nplease enter valid student academic year : ");
		scanf_s("%d", &mystudents[count1].academicyear);

	}

	printf("\nenter student gpa : ");
	scanf_s("%f", &mystudents[count1].gpa);
	while (mystudents[count1].gpa < 0 || mystudents[count1].gpa > 4.0)
	{
		printf("\nenter valid student gpa : ");
		scanf_s("%f", &mystudents[count1].gpa);
	}

	printf("student added successfully\nname: %s, id: %d, gender: %c, year: %d, gpa: %f\n", mystudents[count1].name, mystudents[count1].id, mystudents[count1].gender, mystudents[count1].academicyear, mystudents[count1].gpa);
}
void choice2(struct student* mystudents, int count1)//delete
{

	int studentidop2=0;
	int i,avail=0;
	int c1 = 0;
	printf("\nplease enter student's id : ");
	scanf_s("%d",&studentidop2);
	for (i = 0; i <= count1; i++)
	{
		if (mystudents[i].id == studentidop2)
		{
			avail = 1;
			printf("student details:\nname: %s, id: %d, gender: %c, year: %d, gpa: %f\ndo you confirm please press 1 else press 0\n", mystudents[i].name, mystudents[i].id, mystudents[i].gender, mystudents[i].academicyear, mystudents[i].gpa);
			scanf_s("%d", &c1);
			break;
		}
	}
	if (avail == 0)
	{
		printf("\nid is not available please enter an available one : ");
		scanf_s("%d",&studentidop2);
		for (i = 0; i <= count1; i++)
		{
			if (mystudents[i].id == studentidop2)
			{
				avail = 1;
				printf("student details:\nname: %s, id: %d, gender: %c, year: %d, gpa: %f\ndo you confirm please press 1 else press 0\n", mystudents[i].name, mystudents[i].id, mystudents[i].gender, mystudents[i].academicyear, mystudents[i].gpa);
				scanf_s("%d", &c1);
				break;
			}
		}
		
	}
	if (c1 == 1)
	{
		for (int j = i; j < count1; j++)
		{
			strcpy(mystudents[j].name, mystudents[j + 1].name);
			mystudents[j].id = mystudents[j + 1].id;
			mystudents[j].gender = mystudents[j + 1].gender;
			mystudents[j].academicyear = mystudents[j + 1].academicyear;
			mystudents[j].gpa = mystudents[j + 1].gpa;
		}
		printf("student deleted successfully\n");
	}
	else
	{
		return;
	}
}
void choice3(struct student* mystudents, int count1)//retrive
{
	int option3=0;
	printf("please choose option :\n1)Search by name\n2)Search by id\n");
	scanf_s("%d", &option3);

	if (option3 == 1)
	{
		char search[50];
		int avail = 0;
		printf("please enter student full name : ");
		scanf("%s",search);
		for (int i = 0; search[i] != '\0'; i++)
		{
			if (strcmp(mystudents[i].name, search) == 0)
			{
				printf("\nname: % s, id : % d, gender : % c, year : % d, gpa : % f\n", mystudents[i].name, mystudents[i].id, mystudents[i].gender, mystudents[i].academicyear, mystudents[i].gpa);
				avail++;
			}
		}

		if (avail == 0)
		{
			printf("name not available\n");

		}
	}
	else if (option3 == 2)
	{
		int reqid;
		int available = 0;
		printf("please enter id : ");
		scanf_s("%d", &reqid);
		for (int i = 0; i <= count1; i++)
		{
			if (mystudents[i].id == reqid)
			{
				printf("\nname: % s, id : % d, gender : % c, year : % d, gpa : % f\n", mystudents[i].name, mystudents[i].id, mystudents[i].gender, mystudents[i].academicyear, mystudents[i].gpa);
				available = 1;
			}
		}
		if (available == 0)
		{
			printf("id not available\n");
		}
	}
}
void choice4(struct student* mystudents, int count1)//update
{
	int studentidop4=0;
	int option4=0;
	int i;
	printf("\nplease enter student's id : ");
	scanf_s("%d", &studentidop4);
	printf("\nchoose what to update :\n1)academic year\n2)gpa\n");
	scanf_s("%d", &option4);
	for (i = 0; i <= count1; i++)
	{
		if (mystudents[i].id == studentidop4)
		{
			break;
		}
	}
	if (option4 == 1)
	{
		int academicyr=0;
		printf("\nplease enter new academic year :");
		scanf_s("%d", &academicyr);
		mystudents[i].academicyear = academicyr;
		printf("student's academic year updated :\n");
		printf("student updated successfully\nname: %s, id: %d, gender: %c, year: %d, gpa: %f\n", mystudents[i].name, mystudents[i].id, mystudents[i].gender, mystudents[i].academicyear, mystudents[i].gpa);

	}
	else if (option4 == 2)
	{
		float newgpa;
		printf("\nplease enter new gpa :");
		scanf_s("%f", &newgpa);
		mystudents[i].gpa = newgpa;

		printf("\nstudent's gpa updated :\n");
		printf("student updated successfully\nname: %s, id: %d, gender: %c, year: %d, gpa: %f\n", mystudents[i].name, mystudents[i].id, mystudents[i].gender, mystudents[i].academicyear, mystudents[i].gpa);
	}
}