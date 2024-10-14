#include <iostream> #include <string> #include <vector>

using namespace std;

// Patient Class class Patient { private:
string name; int age;
string disease; string gender;

public:
Patient(string n, int a, string d, string g) : name(n), age(a), disease(d), gender(g) {}

void displayDetails() {
cout << "Patient Name: " << name << endl; cout << "Age: " << age << endl;
cout << "Disease: " << disease << endl;
 
cout << "Gender: " << gender << endl;
}

string getName() { return name;
}
};

// Doctor Class class Doctor { private:
string name;
string specialization; int experience;

public:
Doctor(string n, string s, int e) : name(n), specialization(s), experience(e) {}

void displayDetails() {
cout << "Doctor Name: " << name << endl;
cout << "Specialization: " << specialization << endl;
 
cout << "Experience: " << experience << " years" <<
endl;
}

string getName() { return name;
}
};

// Appointment Class class Appointment { private:
Patient patient; Doctor doctor; string date; string time;

public:
Appointment(Patient p, Doctor d, string dt, string t) : patient(p), doctor(d), date(dt), time(t) {}

void displayAppointment() {
cout << "Appointment Details:" << endl;
 
cout << "Date: " << date << endl; cout << "Time: " << time << endl;
cout << "Patient Name: " << patient.getName() << endl; cout << "Doctor Name: " << doctor.getName() << endl;
}
};

// Hospital Management Class class HospitalManagement { private:
vector<Patient> patients; vector<Doctor> doctors; vector<Appointment> appointments;

public:
void addPatient() {
string name, disease, gender; int age;

cout << "Enter Patient Name: "; cin >> name;
cout << "Enter Patient Age: "; cin >> age;
 
cout << "Enter Disease: "; cin >> disease;
cout << "Enter Gender: "; cin >> gender;

patients.push_back(Patient(name, age, disease, gender)); cout << "Patient added successfully!" << endl;
}

void addDoctor() {
string name, specialization; int experience;

cout << "Enter Doctor Name: "; cin >> name;
cout << "Enter Specialization: "; cin >> specialization;
cout << "Enter Experience (in years): "; cin >> experience;

doctors.push_back(Doctor(name, specialization, experience));
cout << "Doctor added successfully!" << endl;
 
}

void bookAppointment() {
if (patients.empty() || doctors.empty()) {
cout << "Patients or Doctors not available to book an appointment." << endl;
return;
}

string date, time;
int patientIndex, doctorIndex;

cout << "Select Patient by index:" << endl; for (int i = 0; i < patients.size(); ++i) {
cout << i + 1 << ". " << patients[i].getName() << endl;
}
cin >> patientIndex;

cout << "Select Doctor by index:" << endl; for (int i = 0; i < doctors.size(); ++i) {
cout << i + 1 << ". " << doctors[i].getName() << endl;
}
cin >> doctorIndex;
 
cout << "Enter Appointment Date (DD/MM/YYYY): "; cin >> date;
cout << "Enter Appointment Time (HH:MM): "; cin >> time;

appointments.push_back(Appointment(patients[patientIn dex - 1], doctors[doctorIndex - 1], date, time));
cout << "Appointment booked successfully!" << endl;
}

void viewPatients() {
cout << "Patient List:" << endl; for (Patient &p : patients) {
p.displayDetails();
cout << "------------------" << endl;
}
}

void viewDoctors() {
cout << "Doctor List:" << endl; for (Doctor &d : doctors) {
d.displayDetails();
 
cout << "------------------" << endl;
}
}

void viewAppointments() {
cout << "Appointments List:" << endl; for (Appointment &a : appointments) {
a.displayAppointment();
cout << "------------------" << endl;
}
}
};

// Main Function int main() {
HospitalManagement hospital; int choice;

do {
cout << "\nHospital Management System" << endl; cout << "1. Add Patient" << endl;
cout << "2. Add Doctor" << endl;
cout << "3. Book Appointment" << endl;
 
cout << "4. View Patients" << endl; cout << "5. View Doctors" << endl;
cout << "6. View Appointments" << endl; cout << "0. Exit" << endl;
cout << "Enter your choice: "; cin >> choice;

switch (choice) { case 1:
hospital.addPatient(); break;
case 2:
hospital.addDoctor(); break;
case 3:
hospital.bookAppointment(); break;
case 4:
hospital.viewPatients(); break;
case 5:
hospital.viewDoctors(); break;
 
case 6:
hospital.viewAppointments(); break;
case 0:
cout << "Exiting..." << endl; break;
default:
cout << "Invalid choice, please try again!" << endl;
}
} while (choice != 0);

return 0;
}
