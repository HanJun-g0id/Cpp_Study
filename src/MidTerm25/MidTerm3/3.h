#define MAX_NAME 20
#define MAX_GENDER 4
#define MAX_PHONE 20

#include <stdio.h>

typedef struct {
    char name[MAX_NAME];
    char gender[MAX_GENDER];
    int age;
    char phone[MAX_PHONE];
} Student;

void printStudents(const Student students[], int size);
