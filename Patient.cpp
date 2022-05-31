#include "Patient.h"
using namespace std;
Patient::Patient(int theSpecialization,string theName,int theStatus)
{
    set_status(theStatus);
    set_name(theName);
    set_specialization(theSpecialization);
}
int Patient::get_specialization() const
{
    return specialization;
}
int Patient::get_status() const
{
    return status;
}
string Patient::get_name() const
{
    return name;
}
void Patient::set_status(int newStatus)
{
    assert(newStatus == 1 || newStatus == 0);
    status = newStatus;
    return;
}
void Patient::set_specialization(int newSpecialization)
{
    assert(newSpecialization >= 1 && newSpecialization <= 20);
    specialization = newSpecialization;
    return;
}
void Patient::set_name(string newName)
{
    name = newName;
    return;
}
Patient::~Patient()
{
    //dtor
}
