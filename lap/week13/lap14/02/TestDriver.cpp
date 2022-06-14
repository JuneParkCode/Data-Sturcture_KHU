#include <iostream>
#include "Student.h"
#include "MergeSort.h"

using namespace std;

int main(void)
{
    Student stu[10];
    stu[2].InitValue(2003220501, "DOa", 4.3);
    stu[0].InitValue(2003220101, "123", 3.0);
    stu[3].InitValue(2033220501, "Sranfo", 2.3);
    stu[1].InitValue(2003220131, "AVD", 3.9);
    stu[4].InitValue(2013220501, "David", 1.3);
    MergeSort(stu, 0, 4);
    Print(cout, stu, 5);
}