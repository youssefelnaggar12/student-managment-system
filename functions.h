#ifndef functions
#define functions
typedef struct student
{
	char name[50];
	int id;
	char gender;
	int academicyear;
	float gpa;
}record;
void choice1(struct student* mystudents, int count1, int maxacademicyrs);
void choice2(struct student* mystudents, int count1);
void choice3(struct student* mystudents, int count1);
void choice4(struct student* mystudents, int count1);
#endif