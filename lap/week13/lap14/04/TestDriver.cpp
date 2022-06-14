#include <iostream>
#include "Student.h"
#include "Hash.h"

using namespace std;

int main(void)
{
    Student stu[10];
    stu[0].InitValue(2003220101, "123", 3.0);
    stu[1].InitValue(2003220131, "AVD", 3.9);
    stu[2].InitValue(2003220501, "DOa", 4.3);
    stu[3].InitValue(2033220501, "Sranfo", 2.3);
    stu[4].InitValue(2013220501, "David", 1.3);
    HashTable<Student> h(stu[0].emptyItem());
    for (int i = 0; i < 3; ++i)
        h.InsertItem(stu[i]);
    for (int i = 0; i < 5; ++i)
    {
        bool found = false;
        h.RetrieveItem(stu[i], found);
        cout << stu[i].getName() << " : FOUND ? " << (found ? "found" : "not found") << "\n";
    }
}