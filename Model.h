#ifndef MODEL_H
#define MODEL_H
#include "GameObject.h"
#include "Building.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"
#include "Student.h"
#include "GradStudent.h"
#include "View.h"
#include "Virus.h"
#include "Input_Handling.h"
#include <cstdlib>
#include <list>
using namespace std;

class Model
{
    private:
    int time;
    list <GameObject *> object_ptrs;
    list <GameObject *> active_ptrs;
    list <Student *> student_ptrs;
    list <DoctorsOffice *> office_ptrs;
    list <ClassRoom *> class_ptrs;
    list <Virus *> virus_ptrs;
    list <GradStudent *> grad_ptrs;
    list <GameObject*> :: iterator object_itirator;
    list <GameObject *> :: iterator active_itirator;
    list <Student*> :: iterator student_itirator;
    list <DoctorsOffice*> :: iterator office_itirator;
    list <ClassRoom*> :: iterator class_itirator;
    list <Virus *> :: iterator virus_itirator;
    list <GradStudent *> :: iterator grad_itirator;

    public:
    Model();
    ~Model();
    Student * GetStudentPtr(int id);
    GradStudent * GetGradPtr(int id);
    DoctorsOffice * GetDoctorsOfficePtr(int id);
    ClassRoom * GetClassRoomPtr(int id);
    Virus * GetVirusPtr(int id);
    bool Update();
    void Display(View& view);
    void ShowStatus();
    void NewCommand();
};

#endif