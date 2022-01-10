#include <iostream>
#include "GameCommand.h"
using namespace std;

void DoMoveCommand(Model & model, int student_id, Point2D p1)
{
    /*
    int student_id, x, y;
    cout << "Enter student id, x, y" << endl;
    if (!(cin >> student_id >> x >> y))
    {
        throw Invalid_Input("Was expecting three integers");
    }
    Point2D loc(x,y);
    */
    if (model.GetStudentPtr(student_id))
    {
        cout << "Moving " << model.GetStudentPtr(student_id) -> GetName() << " to " << p1 << endl;
        model.GetStudentPtr(student_id) -> StartMoving(p1);
    }
    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoGradMoveCommand(Model & model, int grad_id, Point2D p1)
{
    if (model.GetStudentPtr(grad_id))
    {
        cout << "Moving " << model.GetGradPtr(grad_id) -> GetName() << " to " << p1 << endl;
        model.GetGradPtr(grad_id) -> StartMoving(p1);
    }
    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoMoveToDoctorCommand(Model & model, int student_id, int office_id)
{
    if (model.GetStudentPtr(student_id) && model.GetDoctorsOfficePtr(office_id))
    {
        cout << "Moving " << model.GetStudentPtr(student_id) -> GetName() << " to doctors office " << office_id << endl;
        model.GetStudentPtr(student_id) -> StartMovingToDoctor(model.GetDoctorsOfficePtr(office_id));
    }
    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoMoveToClassCommand(Model & model, int student_id, int class_id)
{
    if ((model.GetStudentPtr(student_id)) && (model.GetClassRoomPtr(class_id)))
    {
        cout << "Moving " << model.GetStudentPtr(student_id) -> GetName() << " to class " << class_id << endl;
        model.GetStudentPtr(student_id) -> StartMovingToClass(model.GetClassRoomPtr(class_id));
    }
    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoStopCommand(Model & model, int student_id)
{
    if ((model.GetStudentPtr(student_id)))
    {
        cout << "Stopping " << model.GetStudentPtr(student_id) -> GetName() << endl;
        model.GetStudentPtr(student_id) -> Stop();
    }
    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoLearningCommand(Model & model, int student_id, unsigned int assignments)
{
    if ((model.GetStudentPtr(student_id)))
    {
        cout << "Teaching " << model.GetStudentPtr(student_id) -> GetName() << endl;
        model.GetStudentPtr(student_id) -> StartLearning(assignments);
    }
    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoRecoverInOfficeCommand(Model& model, int student_id, unsigned int vaccine_needs)
{
    if ((model.GetStudentPtr(student_id)))
    {
        cout << "Recovering " << model.GetStudentPtr(student_id) -> GetName() << "'s antibodies " << endl;
        model.GetStudentPtr(student_id) -> StartRecoveringAntibodies(vaccine_needs);
    }
    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoGoCommand(Model& model, View& view)
{
    model.Update();
    model.Display(view);
    cout << "Advancing one tick." << endl;
}

void DoRunCommand(Model& model, View& view)
{
    if (model.Update())
    {
        model.Display(view);
    }
    else
    {
        model.Update();
        model.Update();
        model.Update();
        model.Update();
        model.Update();
    }
    model.Display(view);
    cout << "Advancing to next event." << endl;
}
//
void virus_infect_cmd(Model & model, int student_id, int virus_id)
{
    model.GetVirusPtr(virus_id) -> infect(model.GetStudentPtr(student_id));
}