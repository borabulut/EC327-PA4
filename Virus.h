#ifndef VIRUS_H
#define VIRUS_H
#include "GameObject.h"
#include "Student.h"
#include <string>
using namespace std;

enum VirusStates {
IN_ENVIRONMENT = 10, DEAD = 11, IN_STUDENT = 12
};

class Virus : public GameObject
{
    protected:
    double virulence;
    double resistance;
    bool variant;
    double energy;
    bool is_in_student;
    string name;
    Student* current_student;

    public:
    Virus(string name, double virulence, double resistance, double energy, bool variant, int id, Point2D in_loc);
    void infect(Student* s);
    bool get_variant();
    double get_virulence();
    double get_resistance();
    double get_energy();
    bool get_in_student();
    bool Update();
    void ShowStatus();
    bool IsAlive();
    bool ShouldBeVisible();
};

#endif