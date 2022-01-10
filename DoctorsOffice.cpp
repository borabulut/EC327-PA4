#include <iostream>
#include "DoctorsOffice.h"
using namespace std;

DoctorsOffice :: DoctorsOffice()
{
    display_code = 'D';
    vaccine_capacity = 100;
    num_vaccine_remaining = vaccine_capacity;
    dollar_cost_per_vaccine = 5;
    state = VACCINE_AVAILABLE;
    cout << "DoctorsOffice default constructed" << endl;
}

DoctorsOffice :: DoctorsOffice(int in_id, double vaccine_cost, unsigned int vaccine_cap, Point2D in_loc)
{
    display_code = 'D';
    id_num = in_id;
    location = in_loc;
    dollar_cost_per_vaccine = vaccine_cost;
    vaccine_capacity = vaccine_cap;
    num_vaccine_remaining = vaccine_cap;
    state = VACCINE_AVAILABLE;
    cout << "DoctorsOffice constructed" << endl;
}

DoctorsOffice :: ~DoctorsOffice()
{
    cout << "Doctors Office destructed." << endl;
}

bool DoctorsOffice :: HasVaccine()
{
    if (num_vaccine_remaining >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned int DoctorsOffice :: GetNumVaccineRemaining()
{
    return num_vaccine_remaining;
}

bool DoctorsOffice :: CanAffordVaccine(unsigned int vaccine, double budget)
{
    if (vaccine*dollar_cost_per_vaccine <= budget)
    {
        return true;
    }
    else
    {
        return false;
    }
}


double DoctorsOffice :: GetDollarCost(unsigned int vaccine)
{
    return vaccine * dollar_cost_per_vaccine;
}

unsigned int DoctorsOffice :: DistributeVaccine(unsigned int vaccine_needed)
{
    if (num_vaccine_remaining >= vaccine_needed)
    {
        num_vaccine_remaining -= vaccine_needed;
        return num_vaccine_remaining;
    }
    else
    {
        int num_vaccine_return = num_vaccine_remaining;
        num_vaccine_remaining = 0;
        return num_vaccine_return;
    }
}

unsigned int DoctorsOffice :: SetNumVaccineRemaining(unsigned int vaccines_to_buy)
{
    num_vaccine_remaining = num_vaccine_remaining - vaccines_to_buy;
}


bool DoctorsOffice :: Update()
{
    if ((num_vaccine_remaining == 0) && (state = VACCINE_AVAILABLE))
    {
        state = NO_VACCINE_AVAILABLE;
        display_code = 'd';
        cout << "DoctorsOffice " << id_num << " has ran out of vaccine." << endl;
        return true;
    }
    return false;
}

void DoctorsOffice :: ShowStatus()
{
    cout << "DoctorsOffice Status: ";
    Building :: ShowStatus();
    cout << "Dollars per vaccine: " << dollar_cost_per_vaccine << endl;
    cout << "has " << num_vaccine_remaining << " vaccine(s) remaining." << endl;
}