#include <iostream>
#include "GradStudent.h"
using namespace std;

//Grad Students have more antibodies and money and they are not affected by viruses

GradStudent :: GradStudent() : Student('G')
{
    speed = 5;
    is_at_doctor = false;
    is_in_class = false;
    antibodies = 1000;
    credits = 0;
    dollars = 100;
    assignments_to_buy = 0;
    vaccines_to_buy = 0;
    currrent_office = 0;
    current_class = 0;
    state = STOPPED;
    cout << "GradStudent default constructed." << endl;
}

GradStudent :: GradStudent(char in_code) : Student('G')
{
    speed = 5;
    is_at_doctor = false;
    is_in_class = false;
    antibodies = 1000;
    credits = 0;
    dollars = 100;
    assignments_to_buy = 0;
    vaccines_to_buy = 0;
    currrent_office = 0;
    current_class = 0;
    cout << "GradStudent constructed." << endl;
    state = STOPPED;
    display_code = in_code;
}

GradStudent :: GradStudent(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) : Student('G')
{
    speed = in_speed;
    name = in_name;
    id_num = in_id;
    display_code = in_code;
    location = in_loc;
    is_at_doctor = false;
    is_in_class = false;
    antibodies = 1000;
    credits = 0;
    dollars = 100;
    assignments_to_buy = 0;
    vaccines_to_buy = 0;
    currrent_office = 0;
    current_class = 0;
    state = STOPPED;
    cout << "GradStudent constructed" << endl;
}

GradStudent :: ~GradStudent()
{
    cout << "GradStudent destructed." << endl;
}

void GradStudent :: StartMoving(Point2D dest)
{
    SetupDestination(dest);
    if (location.x == dest.x && location.y == dest.y)
    {
        state = STOPPED;
        cout << display_code << id_num << ": I’m already there. See?" << endl;
    }
    else if (IsInfected() == true)
    {
        state = INFECTED;
        cout << display_code << id_num << ": I am infected. I may move but you cannot see me." << endl;
    }
    else
    {
        cout << display_code << id_num << ": On my way." << endl;
        state = MOVING;
    }
}

void GradStudent :: StartMovingToClass(ClassRoom* classr)
{
    current_class = classr;
    SetupDestination(classr -> GetLocation());
    state = MOVING_TO_CLASS;
    if (IsInfected() == true)
    {
        state = INFECTED;
        cout << display_code << id_num << ": I am infected so I can’t move to class...";
    }
    else if (location.x == (classr -> GetLocation()).x && location.y == (classr -> GetLocation()).y)
    {
        state = IN_CLASS;
        cout << display_code << id_num << ": I am already at the Classroom!" << endl;
    }
    else
    {
        state = MOVING_TO_CLASS;
        cout << display_code << id_num << ": on my way to class " << classr -> GetId() << endl;
    }
}


void GradStudent :: StartMovingToDoctor(DoctorsOffice* office)
{
    currrent_office = office;
    SetupDestination(office -> GetLocation());
    state = MOVING_TO_DOCTOR;
    if (IsInfected() == true)
    {
        state = INFECTED;
        cout << display_code << id_num << ": I am infected so I should have gone to the doctor’s.." << endl;
    }
    else if (location.x == (office -> GetLocation()).x && location.y == (office -> GetLocation()).y)
    {
        state = AT_DOCTORS;
        cout << display_code << id_num << ": I am already at the Doctor's!" << endl;
    }
    else
    {
        state = MOVING_TO_DOCTOR;
        cout << display_code << id_num << ": on my way to doctor's " << office -> GetId() << endl;
    }
}

void GradStudent :: StartLearning(unsigned int num_assignments)
{
    if (IsInfected() == true)
    {
        state = INFECTED;
        cout << display_code << id_num << ": I am infected so no more school for me..." << endl;
    }
    else if (is_in_class == false)
    {
        cout << display_code << id_num << ": I can only learn in a ClassRoom!" << endl;
    }
    else if (dollars < (current_class -> GetDollarCost(num_assignments)))
    {
        cout << display_code << id_num << ": Not enough money for school" << endl;
    }
    else if ((current_class -> GetNumAssignmentsRemaining()) == 0)
    {
        cout << display_code << id_num << ": Cannot learn! This Class has no more assignments!";
    }
    else if (current_class->GetNumAssignmentsRemaining() > num_assignments)
    {
        assignments_to_buy = num_assignments;
        state = STUDYING_IN_CLASS;
        cout << display_code << ": Started to learn at the ClassRoom " << current_class->GetId() << " with " << num_assignments << " assignments" << endl;
    } 
    else
    {
        num_assignments = current_class->GetNumAssignmentsRemaining();
        state = STUDYING_IN_CLASS;
        cout << display_code << ": Started to learn at the ClassRoom " << current_class->GetId() << " with " << num_assignments << " assignments" << endl;
    }
    /*
    else
    {
        state = STUDYING_IN_CLASS;
        cout << display_code << ": Started to learn at the ClassRoom " << current_class -> GetId() << " with " << num_assignments << " assignments" << endl;
        assignments_to_buy = num_assignments;*/

        /*
        IfthisStudentcanstarttraining,setitscredits_to_buytotheminimumofthe requested 
        assignments and update the remaining assignments in the class. This will be used when its Update() function is called.
        */
    
}

void GradStudent :: StartRecoveringAntibodies(unsigned int num_vaccines)
{
    if (dollars < (currrent_office -> GetDollarCost(num_vaccines)))
    {
        cout << display_code << id_num << ": Not enough money to recover antibodies.";
    }
    else if (is_at_doctor == false)
    {
        cout << display_code << id_num << ": I can only recover antibodies at a Doctor’s Office!" << endl;
    }
    else if ((currrent_office -> HasVaccine()) == false)
    {
        cout << display_code << id_num << ": Cannot recover! No vaccine remaining in this Doctor’s Office" << endl;
    }
    else if (currrent_office->GetNumVaccineRemaining() < num_vaccines)
    {
        vaccines_to_buy = currrent_office->GetNumVaccineRemaining();
        state = RECOVERING_ANTIBODIES;
        cout << display_code << id_num << ": Started recovering " << num_vaccines << " vaccine(s) at Doctor’s Office " << currrent_office->GetId() << endl;
    }
    else
    {   
        vaccines_to_buy = num_vaccines;
        state = RECOVERING_ANTIBODIES;
        cout << display_code << id_num << ": Started recovering " << num_vaccines << " vaccine(s) at Doctor’s Office " << currrent_office->GetId() << endl;
    }

    /*
    else
    {
        
        state = RECOVERING_ANTIBODIES;
        cout << display_code << id_num << ": Started recovering" << num_vaccines << "vaccines at Doctor’s Office" << currrent_office -> GetId() << endl;
        vaccines_to_buy = num_vaccines;*/

        //antibodies += 5*vaccines_to_buy;

        /*
        IfthisStudentcanstartrecoveringantibodies,setitsvaccines_to_buytothe minimum of the requested vaccines and update the remaining vaccines in the office.
        This will be used when its Update() function is called.
Five antibodies are gained for each vaccine purchased.
        */
}

void GradStudent :: Stop()
{
    state = STOPPED;
    cout << display_code << id_num << ": Stopping.." << endl;
}

bool GradStudent :: IsInfected()
{
    if (antibodies == 0)
    {
        state = INFECTED;
        return true;
    }
    else
    {
        return false;
    }
}

bool GradStudent :: ShouldBeVisible()
{
    if (IsInfected() == true)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void GradStudent :: ShowStatus()
{
    cout << name << " status: " << endl;
    GameObject :: ShowStatus();
    switch (state)
    {
        case STOPPED:
        cout << "stopped" << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl;
        break;

        case MOVING:
        cout << "moving at a speed of " << speed << " to destination" << destination << " at each step of " << delta << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl;
        break;

        case MOVING_TO_CLASS:
        cout << "heading to Classroom " << current_class -> GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl;
        break;

        case MOVING_TO_DOCTOR:
        cout << "heading to Doctor's Office " << currrent_office -> GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl;

        case IN_CLASS:
        cout << "inside Classroom" << current_class -> GetId() << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl;
        break;

        case AT_DOCTORS:
        cout << "inside Doctor's Office " << currrent_office -> GetId() << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl;
        break;

        case STUDYING_IN_CLASS:
        cout << "studying in Classroom " << current_class -> GetId() << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl;
        break;

        case RECOVERING_ANTIBODIES:
        cout << "recovering antibodies in Doctor's Office " << currrent_office -> GetId() << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl;
        break;
    }
    /*
    Printstatespecificstatusinformation.RefertoHowStudentObjectsBehave
for complete details
    */
}

bool GradStudent :: Update()
{
    // Check “How Student objects behave part”
    switch (state)
    {
        case STOPPED:
        return false;
        break;

        case MOVING:{
        if (is_in_class)
        {
            current_class -> RemoveOneStudent();
            is_in_class = false;
        }
        else if (is_at_doctor)
        {
            currrent_office -> RemoveOneStudent();
            is_at_doctor = false;
        }
        if (antibodies == 0)
        {
            cout << GetName() << " is out of antibodies and can't move." << endl;
            state = INFECTED;
            return true;
        }
        else
        {
        bool arrived = UpdateLocation();
        if (arrived)
        {
            state = STOPPED;
            return true;
        }
        else
        {
            dollars += GetRandomAmountOfDollars();
            antibodies -= 1;
            return false;
        }
        }
        break;
}
        case MOVING_TO_CLASS:
        {if (is_in_class)
        {
            current_class -> RemoveOneStudent();
            is_in_class = false;
        }
        else if (is_at_doctor)
        {
            currrent_office -> RemoveOneStudent();
            is_at_doctor = false;
        }
        if (antibodies == 0)
        {
            cout << GetName() << " is out of antibodies and can't move." << endl;
            state = INFECTED;
            return true;
        }
        else
        {
        bool arrived = UpdateLocation();
        if (arrived)
        {
            state = IN_CLASS;
            is_in_class = true;
            current_class -> AddOneStudent();
            return true;
        }
        else
        {
            dollars += GetRandomAmountOfDollars();
            antibodies -= 1;
            return false;
        }
        }
        break;
}
        case MOVING_TO_DOCTOR:
        {if (is_in_class)
        {
            current_class -> RemoveOneStudent();
            is_in_class = false;
        }
        else if (is_at_doctor)
        {
            currrent_office -> RemoveOneStudent();
            is_at_doctor = false;
        }
        if (antibodies == 0)
        {
            cout << GetName() << " is out of antibodies and can't move." << endl;
            state = INFECTED;
            return true;
        }
        else
        {
        bool arrived = UpdateLocation();
        if (arrived)
        {
            state = AT_DOCTORS;
            is_at_doctor = true;
            currrent_office -> AddOneStudent();
            return true;
        }
        else
        {
            dollars += GetRandomAmountOfDollars();
            antibodies -= 1;
            return false;
        }
        }
        break;
}
        case IN_CLASS:
        is_in_class = true;
        return false;
        break;

        case AT_DOCTORS:
        is_at_doctor = true;
        return false;
        break;

        case STUDYING_IN_CLASS:
        antibodies -= current_class -> GetAntibodyCost(assignments_to_buy);
        dollars -= current_class -> GetDollarCost(assignments_to_buy);
        credits += current_class -> TrainStudents(assignments_to_buy);
        current_class -> SetNumAssignmentsRemaining(assignments_to_buy);
        cout << GetName() << " completed " << assignments_to_buy << " assignment(s)!" << endl;
        cout << GetName() << " gained " << current_class -> TrainStudents(assignments_to_buy) <<" credit(s)!" << endl;
        state = IN_CLASS;
        return true;
        break;

        case RECOVERING_ANTIBODIES:
        antibodies += 5*vaccines_to_buy;
        dollars -= (currrent_office -> GetDollarCost(vaccines_to_buy));
        currrent_office -> SetNumVaccineRemaining(vaccines_to_buy);
        cout << GetName() << " recovered " << 5*vaccines_to_buy <<" antibodies!" << endl;
        cout << GetName() << " bought " << vaccines_to_buy <<" vaccine(s)!" << endl;
        state = AT_DOCTORS;
        return true;
        break;

        case INFECTED:
        cout << GetName() << " is out of antibodies and can’t move" << endl;
    }
}

string GradStudent :: GetName()
{
    return name;
}

bool GradStudent :: UpdateLocation()
{
    if ((fabs(destination.x - location.x) <= fabs(delta.x)) && (fabs(destination.y - location.y) <= fabs(delta.y)))
    {
        location.x = destination.x;
        location.y = destination.y;
        cout << display_code << id_num << " Arrived" << endl;
        return true;
    }
    else
    {
        location = location + delta;
       cout << display_code << id_num << " Moved" << endl;
       return false;
    }
}

void GradStudent :: SetupDestination(Point2D dest)
{
    destination = dest;
    delta = (destination - location) * (speed / GetDistanceBetween(destination, location));
}


/*
● If a Student runs out of antibodies it should not be able to move!
○ When a Student runs out of antibodies Update() should print “(name) is out of antibodies and can’t move”
○ The state should then be set to INFECTED
● When a Students leaves or enters a building it should call the building’s
RemoveOneStudent () and AddOneStudent() function respectively
● a Student can only recover antibodies when its state is AT_DOCTORS. Likewise, a
Student can only study if its state is IN_CLASS.
● If a Student requests more vaccines or assignments then are available, they should get
the available amount
*/