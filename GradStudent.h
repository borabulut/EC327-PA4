#ifndef GRADSTUDENT_H
#define GRADSTUDENT_H
#include "GameObject.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"
#include "Student.h"
#include <string>
#include <random>
#include "math.h"
using namespace std;

class GradStudent : public Student
{
    public:
    GradStudent();
    GradStudent(char in_code);
    GradStudent(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
    virtual ~GradStudent();
    void StartMoving(Point2D dest);
    void StartMovingToClass(ClassRoom* classr);
    void StartMovingToDoctor(DoctorsOffice* office);
    void StartLearning(unsigned int num_assignments);
    void StartRecoveringAntibodies(unsigned int num_vaccines);
    void Stop();
    bool IsInfected();
    bool ShouldBeVisible();
    void ShowStatus();
    bool Update();
    string GetName();

    protected:
    bool UpdateLocation();
    void SetupDestination(Point2D dest);

    private:
    double speed;
    bool is_at_doctor;
    bool is_in_class;
    unsigned int antibodies;
    unsigned int credits;
    double dollars;
    unsigned int assignments_to_buy;
    unsigned int vaccines_to_buy;
    string name;
    DoctorsOffice* currrent_office;
    ClassRoom* current_class;
    Point2D destination;
    Vector2D delta;
};

double GetRandomAmountOfDollars();

#endif