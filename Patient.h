#ifndef PATIENT_H
#define PATIENT_H

#include <bits/stdc++.h>
class Patient
{
    public:
        Patient(int theSpecialization,std::string theName,int theStatus);

        std::string get_name() const;

        int get_status() const;

        int get_specialization() const;

        void set_status(int newStatus);

        void set_specialization(int newSpecialization);

        void set_name(std::string newName);


        virtual ~Patient();

    protected:

    private:
        int specialization;
        std::string name;
        int status;
};

#endif // PATIENT_H
