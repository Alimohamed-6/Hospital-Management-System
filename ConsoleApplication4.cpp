#include <iostream>
using namespace std;

class Branch {
public:
    int id;
    string name;
    string location;
    Branch* next;
    Branch(int id, string name, string location) : id(id), name(name), location(location), next(NULL) {}
};

class Doctor {
public:
    int id;
    string name;
    string specialization;
    int branchID;
    Doctor* next;
    Doctor(int id, string name, string specialization, int branchID)
        : id(id), name(name), specialization(specialization), branchID(branchID), next(NULL) {}
};

class Patient {
public:
    int id;
    string name;
    string address;
    int appointment;
    Patient* next;
    Patient(int id, string name, string address, int appointment)
        : id(id), name(name), address(address), appointment(appointment), next(NULL) {}
};

class Hospital {
private:
    Branch* branchHead;
    Doctor* doctorHead;
    Patient* patientHead;
public:
    Hospital() : branchHead(NULL), doctorHead(NULL), patientHead(NULL) {}

    void addBranch() {
        int id;
        string name, location;
        cout << "Enter Branch ID: ";
        cin >> id;
        cout << "Enter Branch Name: ";
        cin >> name;
        cout << "Enter Branch Location: ";
        cin >> location;
        Branch* newBranch = new Branch(id, name, location);
        newBranch->next = branchHead;
        branchHead = newBranch;
        cout << "Branch added successfully!\n";
    }
    void displayBranches() {
        if (branchHead == NULL) {
            cout << "No branches available.\n";
            return;
        }
        Branch* temp = branchHead;
        while (temp != NULL) {
            cout << "Branch ID: " << temp->id << ", Name: " << temp->name << ", Location: " << temp->location << endl;
            temp = temp->next;
        }
    }
    void searchBranchByID() {
        int id;
        cout << "Enter Branch ID to search: ";
        cin >> id;
        Branch* temp = branchHead;
        while (temp != NULL) {
            if (temp->id == id) {
                cout << "Branch Found: ID: " << temp->id
                    << ", Name: " << temp->name
                    << ", Location: " << temp->location << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Branch with ID " << id << " not found.\n";
    }

    void addDoctor() {
        int id, branchID;
        string name, specialization;
        cout << "Enter Doctor ID: ";
        cin >> id;
        cout << "Enter Doctor Name: ";
        cin >> name;
        cout << "Enter Specialization: ";
        cin >> specialization;
        cout << "Enter Branch ID: ";
        cin >> branchID;
        Doctor* newDoctor = new Doctor(id, name, specialization, branchID);
        newDoctor->next = doctorHead;
        doctorHead = newDoctor;
        cout << "Doctor added successfully!\n";
    }
    void removeDoctor() {
        int id;
        cout << "Enter Doctor ID to remove: ";
        cin >> id;
        Doctor* delptr = doctorHead;
        Doctor* prev = NULL;
        while (delptr != NULL) {
            if (delptr->id == id) {
                if (prev != NULL) { // The node to be deleted is not the first node
                    prev->next = delptr->next;
                }
                else { // The node to be deleted is the first node
                    doctorHead = delptr->next;
                }
                delete delptr;
                cout << "Doctor removed successfully!\n";
                return;
            }
            prev = delptr;
            delptr = delptr->next;
        }
        cout << "Doctor with ID " << id << " not found.\n";
    }
    void displayDoctorAppointments() {
        int id;
        cout << "Enter Doctor ID to display appointments: ";
        cin >> id;
        Doctor* docTemp = doctorHead;
        while (docTemp != NULL) {
            if (docTemp->id == id) {
                cout << "Doctor: " << docTemp->name << " (" << docTemp->specialization << ")\n";
                Patient* patientTemp = patientHead;
                bool found = false;
                while (patientTemp != NULL) {
                    if (patientTemp->appointment == id) {
                        cout << "  Patient: " << patientTemp->name
                            << ", Address: " << patientTemp->address << endl;
                        found = true;
                    }
                    patientTemp = patientTemp->next;
                }
                if (found == false) {
                    cout << "No appointments for this doctor.\n";
                }
                return;
            }
            docTemp = docTemp->next;
        }
        cout << "Doctor with ID " << id << " not found.\n";
    }
    // Patient Management
    void addPatient() {
        int id, appointment;
        string name, address;
        cout << "Enter Patient ID: ";
        cin >> id;
        cout << "Enter Patient Name: ";
        cin >> name;
        cout << "Enter Address: ";
        cin >> address;
        cout << "Enter Appointment (Doctor ID): ";
        cin >> appointment;
        Patient* newPatient = new Patient(id, name, address, appointment);
        newPatient->next = patientHead;
        patientHead = newPatient;
        cout << "Patient added successfully!\n";
    }
    void removePatient() {
        int id;
        cout << "Enter Patient ID to remove: ";
        cin >> id;
        Patient* delptr = patientHead;
        Patient* prev = NULL;
        while (delptr != NULL) {
            if (delptr->id == id) {
                if (prev != NULL) {
                    prev->next = delptr->next;
                }
                else {
                    patientHead = delptr->next;
                }
                delete delptr;
                cout << "Patient removed successfully!\n";
                return;
            }
            prev = delptr;
            delptr = delptr->next;
        }
        cout << "Patient with ID " << id << " not found.\n";
    }
    void bookAppointment() {
        int patientID, doctorID;
        cout << "Enter Patient ID: ";
        cin >> patientID;
        cout << "Enter Doctor ID: ";
        cin >> doctorID;
        Patient* patientTemp = patientHead;
        while (patientTemp != NULL) {
            if (patientTemp->id == patientID) {
                patientTemp->appointment = doctorID;
                cout << "Appointment booked successfully!\n";
                return;
            }
            patientTemp = patientTemp->next;
        }
        cout << "Patient with ID " << patientID << " not found.\n";
    }
    void searchPatientByName() {
        string name;
        cout << "Enter Patient Name to search: ";
        cin >> name;
        Patient* temp = patientHead;
        while (temp != NULL) {
            if (temp->name == name) {
                cout << "Patient Found: ID: " << temp->id
                    << ", Name: " << temp->name
                    << ", Address: " << temp->address
                    << ", Appointment with Doctor ID: " << temp->appointment << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Patient with name " << name << " not found.\n";
    }
    void updatePatientInfo() {
        int id;
        cout << "Enter Patient ID to update: ";
        cin >> id;
        Patient* temp = patientHead;
        while (temp != NULL) {
            if (temp->id == id) {
                cout << "Enter New Name: ";
                cin >> temp->name;
                cout << "Enter New Address: ";
                cin >> temp->address;
                cout << "Enter New Appointment (Doctor ID): ";
                cin >> temp->appointment;
                cout << "Patient information updated successfully!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Patient with ID " << id << " not found.\n";
    }
    void removeBranch() {
        int id;
        cout << "Enter Branch ID to remove: ";
        cin >> id;
        Branch* delptr = branchHead;
        Branch* prev = NULL;
        while (delptr != NULL) {
            if (delptr->id == id) {
                if (prev != NULL) {
                    prev->next = delptr->next;
                }
                else {
                    branchHead = delptr->next;
                }
                delete delptr;
                cout << "Branch removed successfully!\n";
                return;
            }
            prev = delptr;
            delptr = delptr->next;
        }
        cout << "Branch with ID " << id << " not found.\n";
    }
    void displayAllAppointmentsByBranch() {
        if (branchHead == NULL) {
            cout << "No branches available.\n";
            return;
        }
        Branch* branchTemp = branchHead;
        while (branchTemp != NULL) {
            cout << "\nBranch ID: " << branchTemp->id
                << ", Name: " << branchTemp->name
                << ", Location: " << branchTemp->location << "\n";
            bool doctorFound = false;
            Doctor* doctorTemp = doctorHead;
            while (doctorTemp != NULL) {
                if (doctorTemp->branchID == branchTemp->id) {
                    doctorFound = true;
                    cout << "  Doctor: " << doctorTemp->name
                        << " (" << doctorTemp->specialization << ")\n";

                    bool patientFound = false;
                    Patient* patientTemp = patientHead;
                    while (patientTemp != NULL) {
                        if (patientTemp->appointment == doctorTemp->id) {
                            patientFound = true;
                            cout << "    - Patient: " << patientTemp->name
                                << ", Address: " << patientTemp->address << endl;
                        }
                        patientTemp = patientTemp->next;
                    }
                    if (patientFound == false) {
                        cout << "    No patients assigned to this doctor.\n";
                    }
                }
                doctorTemp = doctorTemp->next;
            }
            if (doctorFound == false) {
                cout << "  No doctors available in this branch.\n";
            }
            branchTemp = branchTemp->next;
        }
    }
};
int main() {
    Hospital hospital;
    int choice;
    do {
        cout << "\n--- Hospital Management System ---\n";
        cout << "1. Add Branch\n2. Display Branches\n3. Search Branch by ID\n";
        cout << "4. Add Doctor\n5. Remove Doctor\n6. Display Doctor Appointments\n";
        cout << "7. Add Patient\n8. Remove Patient\n9. Search Patient by Name\n";
        cout << "10. Update Patient Information\n11. Remove Branch\n";
        cout << "12. Book Appointment\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: hospital.addBranch(); break;
        case 2: hospital.displayBranches(); break;
        case 3: hospital.searchBranchByID(); break;
        case 4: hospital.addDoctor(); break;
        case 5: hospital.removeDoctor(); break;
        case 6: hospital.displayDoctorAppointments(); break;
        case 7: hospital.addPatient(); break;
        case 8: hospital.removePatient(); break;
        case 9: hospital.searchPatientByName(); break;
        case 10: hospital.updatePatientInfo(); break;
        case 11: hospital.removeBranch(); break;
        case 12: hospital.bookAppointment(); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
    return 0;
}
