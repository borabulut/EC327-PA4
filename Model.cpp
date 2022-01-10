#include <iostream>
#include "Model.h"
using namespace std;

Model :: Model()
{
    time = 0;
    Point2D Homer_loc(5,1);
    Student *S1 = new Student("Homer", 1, 'S', 2, Homer_loc);
    object_ptrs.push_back(S1);
    active_ptrs.push_back(S1);
    student_ptrs.push_back(S1);
    Point2D Marge_loc(10,1);
    Student *S2 = new Student("Marge", 2, 'S', 1, Marge_loc);
    object_ptrs.push_back(S2);
    active_ptrs.push_back(S2);
    student_ptrs.push_back(S2);
    Point2D D1_loc(1,20);
    DoctorsOffice *D1 = new DoctorsOffice(1, 1, 100, D1_loc);
    object_ptrs.push_back(D1);
    active_ptrs.push_back(D1);
    office_ptrs.push_back(D1);
    Point2D D2_loc(10,20);
    DoctorsOffice *D2 = new DoctorsOffice(2, 2, 200, D2_loc);
    object_ptrs.push_back(D2);
    active_ptrs.push_back(D2);
    office_ptrs.push_back(D2);
    Point2D C1_loc(0,0);
    ClassRoom *C1 = new ClassRoom(10, 1, 2, 3, 1, C1_loc);
    object_ptrs.push_back(C1);
    active_ptrs.push_back(C1);
    class_ptrs.push_back(C1);
    Point2D C2_loc(5,5);
    ClassRoom *C2 = new ClassRoom(20, 5, 7.5, 4, 2, C2_loc);
    object_ptrs.push_back(C2);
    active_ptrs.push_back(C2);
    class_ptrs.push_back(C2);
    Point2D V1_loc(10, 12);
    Virus *V1 = new Virus("Virus1", 5, 2, 10, false, 1, V1_loc);
    object_ptrs.push_back(V1);
    active_ptrs.push_back(V1);
    virus_ptrs.push_back(V1);
    Point2D V2_loc(15, 5);
    Virus *V2 = new Virus("Virus2", 5, 2, 10, false, 2, V2_loc);
    object_ptrs.push_back(V2);
    active_ptrs.push_back(V2);
    virus_ptrs.push_back(V2);
    Point2D Grad1_loc(10,8);
    GradStudent *G1 = new GradStudent("Grad1", 1, 'G', 2, Grad1_loc);
    object_ptrs.push_back(G1);
    active_ptrs.push_back(G1);
    grad_ptrs.push_back(G1);
    Point2D Grad2_loc(20,8);
    GradStudent *G2 = new GradStudent("Grad2", 2, 'G', 2, Grad2_loc);
    object_ptrs.push_back(G2);
    active_ptrs.push_back(G2);
    grad_ptrs.push_back(G2);
    cout << "Model default constructed" << endl;
}

Model :: ~Model()
{
    for (object_itirator = object_ptrs.begin(); object_itirator != object_ptrs.end(); object_itirator++)
    {
        delete *object_itirator;
    }
    cout << "Model destructed." << endl;
}

Student* Model :: GetStudentPtr(int id)
{
    for (student_itirator = student_ptrs.begin(); student_itirator != student_ptrs.end(); student_itirator++)
    {
        if (((*student_itirator) -> GetId()) == id)
        {
            return *student_itirator;
        }
    }
    return 0;
}

GradStudent* Model :: GetGradPtr(int id)
{
    for (grad_itirator = grad_ptrs.begin(); grad_itirator != grad_ptrs.end(); grad_itirator++)
    {
        if (((*grad_itirator) -> GetId()) == id)
        {
            return *grad_itirator;
        }
    }
    return 0;
}

DoctorsOffice* Model :: GetDoctorsOfficePtr(int id)
{
    for (office_itirator = office_ptrs.begin(); office_itirator != office_ptrs.end(); office_itirator++)
    {
        if (((*office_itirator) -> GetId()) == id)
        {
            return *office_itirator;
        }
    }
    return 0;
}

ClassRoom* Model :: GetClassRoomPtr(int id)
{
    for (class_itirator = class_ptrs.begin(); class_itirator != class_ptrs.end(); class_itirator++)
    {
        if (((*class_itirator) -> GetId()) == id)
        {
            return *class_itirator;
        }
    }
    return 0;
}

Virus* Model :: GetVirusPtr(int id)
{
    for (virus_itirator = virus_ptrs.begin(); virus_itirator != virus_ptrs.end(); virus_itirator++)
    {
        if (((*virus_itirator) -> GetId()) == id)
        {
            return *virus_itirator;
        }
    }
    return 0;
}

bool Model :: Update()
{
    time += 1;
    bool result = false;
    for (object_itirator = object_ptrs.begin(); object_itirator != object_ptrs.end(); object_itirator++)
    {
        if (((*object_itirator) -> Update()) == true)
        {
            result = true;
        }
    }
    int total_classrooms = 0;
    for (class_itirator = class_ptrs.begin(); class_itirator != class_ptrs.end(); class_itirator++)
    {
        if ((*class_itirator)->passed() == true)
        {
            total_classrooms++;
            active_ptrs.remove(*class_itirator);
            cout << "Dead object removed" << endl;
            if (total_classrooms == class_ptrs.size())
            {
                cout << "GAME OVER: You win! All assignments done!" << endl;
                exit(0);
            }
        }
    }
    int total_infected = 0;
    for (student_itirator = student_ptrs.begin(); student_itirator != student_ptrs.end(); student_itirator++)
    {
        if ((*student_itirator)->IsInfected() == true)
        {
            total_infected++;
            active_ptrs.remove(*student_itirator);
            cout << "Dead object removed" << endl;
            if (total_infected == student_ptrs.size())
            {
                cout << "GAME OVER: You lose! All of your Students are infected!" << endl;
                exit(0);
            }   
        }
    }
    for (grad_itirator = grad_ptrs.begin(); grad_itirator != grad_ptrs.end(); grad_itirator++)
    {
        if ((*grad_itirator)->IsInfected() == true)
        {
            active_ptrs.remove(*grad_itirator);
            cout << "Dead object removed" << endl;
        }
    }
    for (virus_itirator = virus_ptrs.begin(); virus_itirator != virus_ptrs.end(); virus_itirator++)
    {
        if ((*virus_itirator)->IsAlive() == false)
        {
            active_ptrs.remove(*virus_itirator);
            cout << "Dead object removed" << endl;
        }
    }
    for (virus_itirator = virus_ptrs.begin(); virus_itirator != virus_ptrs.end(); virus_itirator++)
    {
        for (student_itirator = student_ptrs.begin(); student_itirator != student_ptrs.end(); student_itirator++)
        {
            (*virus_itirator) -> infect(*student_itirator);
        }
    }
    return result;
}

/*Model::update() should update each object in the active_ptrs list, and then scan the list
looking for dead objects; if found, the dead object is removed 
from the active_ptrs list so that it is no longer updated. For debugging and demonstration purposes, 
output a message like “Dead object removed”.
*/


void Model :: Display(View& view)
{
    cout << "Time: " << time << endl;
    view.Clear();
    for (active_itirator = active_ptrs.begin(); active_itirator != active_ptrs.end(); active_itirator++)
    {
        view.Plot(*active_itirator);
    }
    view.Draw();
}


void Model :: ShowStatus()
{
    cout << "Time: " << time << endl;
    
    for (object_itirator = object_ptrs.begin(); object_itirator != object_ptrs.end(); object_itirator++)
    {
        (*object_itirator) -> ShowStatus();
    }
}

void Model :: NewCommand()
{
    char type_id;
    int id;
    int x;
    int y;
    cout << "Enter type id" << endl;
    cin >> type_id;
    if (type_id != 'd' && type_id != 'c' && type_id != 's' && type_id != 'v')
    {
        throw Invalid_Input("Not a valid type id");
    }
    cout << "Enter id, x, y" << endl;
    if (!(cin >> id >> x >> y))
    {
        throw Invalid_Input("Was expecting three integers");
    }
    if (x > 20 || y > 20)
    {
        throw Invalid_Input("Out of bounds");
    }
    if (type_id == 'd' && GetStudentPtr(id))
    {
        throw Invalid_Input("ID already exists");
    }
    else if (type_id == 'c' && GetClassRoomPtr(id))
    {
        throw Invalid_Input("ID already exists");
    }
    else if (type_id == 's' && GetStudentPtr(id))
    {
        throw Invalid_Input("ID already exists");
    }
    else if (type_id == 'v' && GetVirusPtr(id))
    {
        throw Invalid_Input("ID already exists");
    }
    if (type_id == 's')
    {
        Point2D loc(x,y);
        Student *new_student = new Student("User-made-student", id, 'S', 2, loc);
        object_ptrs.push_back(new_student);
        active_ptrs.push_back(new_student);
        student_ptrs.push_back(new_student);
    }
    else if (type_id == 'd')
    {
        Point2D loc(x,y);
        DoctorsOffice *new_office = new DoctorsOffice(id, 1, 100, loc);
        object_ptrs.push_back(new_office);
        active_ptrs.push_back(new_office);
        office_ptrs.push_back(new_office);
    }
    else if (type_id == 'c')
    {
        Point2D loc(x,y);
        ClassRoom *new_class = new ClassRoom(10, 1, 2, 3, id, loc);
        object_ptrs.push_back(new_class);
        active_ptrs.push_back(new_class);
        class_ptrs.push_back(new_class);
    }
    else if (type_id == 'v')
    {
        Point2D loc(x,y);
        Virus *new_virus = new Virus("User-made-virus", 5, 2, 10, false, id, loc);
        object_ptrs.push_back(new_virus);
        active_ptrs.push_back(new_virus);
        virus_ptrs.push_back(new_virus);
    }
}