using namespace std;
#include <bits/stdc++.h>
#include "Patient.cpp"

map<int,deque<Patient>> mp ;

void insert_patient(int spec, string name, int status);
void print_patients();
void next_patient(int spec);

int main()
{
    cout << "Enter your choice:" << endl;
    cout << "1) Add new Patient" << endl;
    cout << "2) Print all Patients" << endl;
    cout << "3) Get next Patient" << endl;
    cout << "4) Exit" << endl;

    int command;
    while(cin>>command)
    {

        switch(command)
        {
        case 1:
        {
            cout << "Enter specialization, name, status: ";

            int spec,status;
            string name;

            cin>>spec>>name>>status;

            insert_patient(spec,name,status);

            break;
        }
        case 2:
            print_patients();
            break;
        case 3:
        {
            cout << "Enter specialization: ";

            int spec;
            cin>>spec;

            next_patient(spec);

            break;
        }
        case 4:
            return 1;
        default:
            cout << "not supported" << endl;
        }
        cout << "Enter your choice:" << endl;
        cout << "1) Add new Patient" << endl;
        cout << "2) Print all Patients" << endl;
        cout << "3) Get next Patient" << endl;
        cout << "4) Exit" << endl;
        cout << endl;
    }

    return 0;
}
void next_patient(int spec)
{
    if(spec < 1 || spec > 20)
    {
        cout << "specialization should be between 1 and 20";
        return;
    }
    deque<Patient>& dq = mp[spec];
    if(dq.empty())
    {
        cout << "no patients in this specialization" << endl;
        return;
    }
    cout << "patient " +  dq.front().get_name() << " please go with the doctor" << endl;
    dq.pop_front();
}
void insert_patient(int spec, string name, int status)
{

    Patient p{spec,name,status};
    deque<Patient>& dq = mp[spec];
    if(dq.size() == 5)
    {
        cout << "Sorry, there are 5 people already in queue" << endl;
        return;
    }
    if(status)
        dq.push_front(p);
    else
        dq.push_back(p);
}
void print_patients()
{
    cout << "****************************" << endl;
    for(int i = 0; i < mp.size(); i++)
    {
        deque<Patient> dq = mp[i];
        if(!dq.empty())
        {
            string diff_1,diff_2;
            bool sz = dq.size() == 1;
            diff_1 = (sz ? "is" : "are");
            diff_2 = (sz ? "patient" : "patients");
            string p_template = "There " + diff_1 + ' ' + to_string(dq.size()) + ' ' + diff_2
                                + " in specialization " +  to_string(i);
            cout << p_template << endl;
            for (int f = 0; f < dq.size(); f++)
                cout << dq[f].get_name() << ' ' << (dq[f].get_status() ? "urgent" : "regular") << endl;

        }
    }
}

