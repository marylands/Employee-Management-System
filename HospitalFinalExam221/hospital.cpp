#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define structures for patient, doctor, and appointment
struct Patient {
    string name;
    int age;
    string gender;
    string medicalHistory;
    // Add more fields as needed
};

struct Doctor {
    string name;
    string specialization;
    // Add more fields as needed
};

struct Appointment {
    string patientName;
    string doctorName;
    string date;
    string time;
};

// Hospital class to manage patients, doctors, and appointments
class HospitalManagement {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;

public:
    // Function to add a new patient
    void addPatient(const Patient& patient) {
        patients.push_back(patient);
    }

    // Function to add a new doctor
    void addDoctor(const Doctor& doctor) {
        doctors.push_back(doctor);
    }

    // Function to schedule an appointment
    void scheduleAppointment(const Appointment& appointment) {
        appointments.push_back(appointment);
    }

    // Function to display all patients
    void displayPatients() {
        cout << "Patients:\n";
        for (const auto& patient : patients) {
            cout << "Name: " << patient.name << ", Age: " << patient.age << ", Gender: " << patient.gender << endl;
        }
    }

    // Function to display all doctors
    void displayDoctors() {
        cout << "Doctors:\n";
        for (const auto& doctor : doctors) {
            cout << "Name: " << doctor.name << ", Specialization: " << doctor.specialization << endl;
        }
    }

    // Function to display all appointments
    void displayAppointments() {
        cout << "Appointments:\n";
        for (const auto& appointment : appointments) {
            cout << "Patient: " << appointment.patientName << ", Doctor: " << appointment.doctorName << ", Date: " << appointment.date << ", Time: " << appointment.time << endl;
        }
    }
};

int main() {
    HospitalManagement hospital;

    int choice;
    do {
        // Display main menu
        cout << "\nHospital Management System\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. Schedule Appointment\n";
        cout << "4. View Patients\n";
        cout << "5. View Doctors\n";
        cout << "6. View Appointments\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // Flush the input buffer

        switch (choice) {
            case 1: {
                // Add Patient
                Patient patient;
                cout << "Enter patient name: ";
                getline(cin, patient.name);
                cout << "Enter patient age: ";
                cin >> patient.age;
                cin.ignore(); // Flush the input buffer
                cout << "Enter patient gender: ";
                getline(cin, patient.gender);
                hospital.addPatient(patient);
                break;
            }
            case 2: {
                // Add Doctor
                Doctor doctor;
                cout << "Enter doctor name: ";
                getline(cin, doctor.name);
                cout << "Enter doctor specialization: ";
                getline(cin, doctor.specialization);
                hospital.addDoctor(doctor);
                break;
            }
            case 3: {
                // Schedule Appointment
                Appointment appointment;
                cout << "Enter patient name: ";
                getline(cin, appointment.patientName);
                cout << "Enter doctor name: ";
                getline(cin, appointment.doctorName);
                cout << "Enter date (YYYY-MM-DD): ";
                getline(cin, appointment.date);
                cout << "Enter time: ";
                getline(cin, appointment.time);
                hospital.scheduleAppointment(appointment);
                break;
            }
            case 4:
                // View Patients
                hospital.displayPatients();
                break;
            case 5:
                // View Doctors
                hospital.displayDoctors();
                break;
            case 6:
                // View Appointments
                hospital.displayAppointments();
                break;
            case 0:
                // Exit
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

