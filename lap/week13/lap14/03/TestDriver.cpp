#include <iostream>
#include "Student.h"
#include "SelectionSort.h"

using namespace std;

int main(void)
{
    Student *stu[10];
    for (int i = 0; i < 10; ++i)
    {
        stu[i] = new Student();
    }
    (*stu[0]).InitValue(2003220101, "123", 3.0);
    (*stu[1]).InitValue(2003220131, "Sranfo", 3.9);
    (*stu[2]).InitValue(2003220501, "DOa", 4.3);
    (*stu[3]).InitValue(2033220501, "AVD", 2.3);
    (*stu[4]).InitValue(2013220501, "David", 1.3);
    SelectionSortPointer(stu, 5);
    PrintByPointer(cout, stu, 5);
}