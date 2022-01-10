#include <iostream>
#include "Virus.h"
using namespace std;

Virus :: Virus(string name, double virulence, double resistance, double energy, bool variant, int id, Point2D in_loc) : GameObject(in_loc, id, 'V')
{
    this -> name = name;
    this -> virulence = virulence;
    this -> resistance = resistance;
    this -> energy = energy;
    this -> variant = variant;
    this -> id_num = id;
    location = in_loc;
    is_in_student = false;
    state = IN_ENVIRONMENT;
}


void Virus :: infect(Student* s)
{
        current_student = s;
        //if ((s -> GetAntibodies()) > 5)
        //{

        if ((((s->GetLocation()).x) == (location.x)) && ((((s->GetLocation()).y) == (location.y))))
        {
            is_in_student = true;
            state = IN_STUDENT;
            s -> VirusHit();
            cout << "Virus hit! -1 antibodies!" << endl;
            energy -= 1;
        }
        else
        {
            state = IN_ENVIRONMENT;
            is_in_student = false;
        }
        //else
        //{
        //    cout << "I don't want to kill you, so I'm not going to infect you!!" << endl;
        //}
    /*This should both change the Virus’ current_student value and update the
student’s information as needed as well*/
}

bool Virus :: get_variant()
{
    return variant;
}

double Virus :: get_virulence()
{
    return virulence;
}

double Virus :: get_resistance()
{
    return resistance;
}

double Virus :: get_energy()
{
    return energy;
}

bool Virus :: get_in_student()
{
    return is_in_student;
}


bool Virus :: Update()
{
    if (state==IN_ENVIRONMENT) 
    {
        return false;
    }
    else if (energy==0) 
    {
        state=DEAD;
    }
    else if (state == IN_STUDENT)
    {
        (location.x) = ((current_student->GetLocation()).x);
        (location.y) = ((current_student->GetLocation()).y);
        current_student -> VirusHit();
    }
    else if (is_in_student==true)
    {
        (location.x) = ((current_student->GetLocation()).x);
        (location.y) = ((current_student->GetLocation()).y);
        current_student -> VirusHit();
    }
    else
    {
        return false;
    }
}

/*
- state ‘DEAD: When the Virus’ energy is 0 or below
- state ‘IN_STUDENT’: when the Virus is in a student
*/

void Virus :: ShowStatus()
{
    cout << name << " status: " << endl;
    GameObject :: ShowStatus();
    if (IsAlive() == true)
    {
        cout << "State: Alive" << endl;
    }
    else
    {
        cout << "State: Dead" << endl;
    }
}

bool Virus :: IsAlive()
{
    if (energy > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Virus :: ShouldBeVisible()
{
    if (IsAlive() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}