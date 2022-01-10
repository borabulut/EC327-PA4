#ifndef STUDENT_H
#define STUDENT_H
#include "GameObject.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"
#include <string>
#include <random>
#include "math.h"
using namespace std;

enum StudentStates {
STOPPED = 0, MOVING = 1, INFECTED = 2, AT_DOCTORS = 3, IN_CLASS = 4, MOVING_TO_DOCTOR = 5, MOVING_TO_CLASS = 6, STUDYING_IN_CLASS = 7, RECOVERING_ANTIBODIES = 8
};

class Student : public GameObject
{
    public:
    Student();
    Student(char in_code);
    Student(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
    virtual ~Student();
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
    void VirusHit();
    int GetAntibodies();

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