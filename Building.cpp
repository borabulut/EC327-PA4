#include <iostream>
#include "Building.h"
using namespace std;

Building :: Building() : GameObject('B')
{
    id_num = 1;
    state = 0;
    student_count = 0;
    cout << "Building default constructed" << endl;
}

Building :: Building(char in_code, int in_id, Point2D in_loc) : GameObject('B')
{
    id_num = in_id;
    location = in_loc;
    display_code = in_code;
    state = 0;
    student_count = 0;
    cout << "Building constructed" << endl;
}


void Building :: AddOneStudent()
{
    student_count += 1;
}

void Building :: RemoveOneStudent()
{
    if (student_count > 0)
    {
        student_count -= 1;
    } 
    else
    {
        cout << "No student to remove" << endl;
    }
}

void Building :: ShowStatus()
{
    cout << display_code << id_num << " located at " << location << endl;
    if (student_count == 1)
    {
        cout << student_count << " student is in this building" << endl;
    }
    else
    {
        cout << student_count << " students are in this building" << endl;
    }
}

bool Building :: ShouldBeVisible()
{
    return true;
}