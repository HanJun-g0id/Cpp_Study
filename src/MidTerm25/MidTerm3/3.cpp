#include "3.h"

void printStudents(const Student students[], int size) {

    for (int i = 0; i < size; ++i) {
        printf("%s\t%s\t%d\t%s\n",
            students[i].name,
            students[i].gender,
            students[i].age,
            students[i].phone);
    }
}
