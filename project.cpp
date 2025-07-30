#include <iostream>
#include <string>
using namespace std;

// Node for Branch
class BranchNode {
public:
    int id;
    string name;
    string location;
    BranchNode* next;
    BranchNode()
    {
        id = 0;
        name = "";
        location = "";
        next = NULL;
    }
    BranchNode(int branchID, string branchName, string branchLocation) {
        id = branchID;
        name = branchName;
        location = branchLocation;
        next = NULL;
    }
};

// List for Branch
class BranchList {
public:
    BranchNode* Branchhead;
    int EnterBranchID(bool newID)
    {
        int id;
        while (true) {
            cout << "Enter Branch ID : ";
            cin >> id;
            // Check if input is valid
            if (cin.fail()) {
                cin.clear(); // Clear the fail state
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input. Please enter an integer for the Branch ID.\n";
            }
            else {
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Clear any extra input
                bool found = false;

                BranchNode* temp = Branchhead;
                while (temp != NULL) {
                    if (temp->id == id) {
                        found = true;
                        break;
                    }
                    temp = temp->next;
                }

                if (found && newID)
                    cout << "This Entered id Already exists , please enter a new one...\n";
                else if (!found && !newID)
                    cout << "This Branch Id Doesnt Exist! , please enter an existing Id.\n";
                else
                    break; // Exit the loop if input is valid
            }
        }
        return id;
    }
    string EnterBranchName()
    {
        string name;
        while (true) {
            cout << "Enter Branch Name : ";
            cin >> name;
            bool found = false;

            BranchNode* temp = Branchhead;
            while (temp != NULL) {
                if (temp->name == name) {
                    found = true;
                    break;
                }
                temp = temp->next;
            }

            if (!found)
                cout << "This Branch Name Doesnt Exist! , please enter an existing name.\n";
            else
                break; // Exit the loop if input is valid
        }
        return name;
    }

    BranchList() {
        Branchhead = NULL;
    }
    void addBranch() {
        int id;
        string name, location;
        id = EnterBranchID(true);
        cout << "Enter Branch Name: ";
        getline(cin, name); // Allows input with spaces
        cout << "Enter Branch Location: ";
        getline(cin, location);
        BranchNode* newNode = new BranchNode(id, name, location);
        newNode->next = Branchhead;
        Branchhead = newNode;

        cout << "Branch added successfully!\n";
    }
    void displayBranches() {
        if (Branchhead == NULL) {
            cout << "No branches available.\n";
            return;
        }
        BranchNode* temp = Branchhead;
        cout << "Branches:\n";
        while (temp != NULL) {
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Location: " << temp->location << "\n";
            temp = temp->next;
        }
    }
    void searchBranchByID() {
        int id;
        cout << "Enter Branch ID to search: ";
        id = EnterBranchID(false);
        BranchNode* temp = Branchhead;
        while (temp != NULL) {
            if (temp->id == id) {
                cout << "Branch Found - ID: " << temp->id << ", Name: " << temp->name << ", Location: " << temp->location << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Branch not found!\n";
    }
    void RemoveBranch()
    {
        int id;
        cout << "Enter Branch ID to remove: ";
        id = EnterBranchID(false);
        BranchNode* temp = Branchhead;
        if (Branchhead->id == id)
        {
            Branchhead = Branchhead->next;
            delete temp;
            cout << "Deleted Branch Successfully.";
            return;
        }
        while (temp->next) {
            if (temp->next->id == id) {
                BranchNode* delptr = temp->next;
                temp->next = delptr->next;
                delete delptr;
                cout << "Deleted Branch Successfully.";
                return;
            }
            temp = temp->next;
        }
        cout << "Branch not found!\n";
    }
};
BranchList branches;
// Node for Doctor
class DoctorNode {
public:
    int id;
    string name;
    string specialization;
    string branchName;
    DoctorNode* next;
    DoctorNode()
    {
        id = 0;
        name = "";
        specialization = "";
        branchName = "";
        next = NULL;
    }
    DoctorNode(int doctorID, string doctorName, string doctorSpecialization, string branch) {
        id = doctorID;
        name = doctorName;
        specialization = doctorSpecialization;
        branchName = branch;
        next = NULL;
    }
};

// List for Doctor
class DoctorList : public BranchList {
public:
    DoctorNode* Doctorhead;
    int EnterDoctorID(string entered, bool newID)
    {
        int id;
        while (true) {
            cout << "Enter " << entered << ": ";
            cin >> id;
            // Check if input is valid
            if (cin.fail()) {
                cin.clear(); // Clear the fail state
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input. Please enter an integer for the " << entered << ".\n";
            }
            else {
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Clear any extra input
                bool repeated = false; bool found = false;
                if (newID)
                {
                    DoctorNode* temp = Doctorhead;
                    while (temp != NULL) {
                        if (temp->id == id) {
                            repeated = true;
                            break;
                        }
                        temp = temp->next;
                    }
                }
                else
                {

                    DoctorNode* temp = Doctorhead;
                    while (temp != NULL) {
                        if (temp->id == id) {
                            found = true;
                            break;
                        }
                        temp = temp->next;
                    }

                }
                if (repeated)
                {
                    cout << "This Entered id Already exists , please enter a new one...\n";
                }
                else if (!newID && !found)
                {
                    cout << "This Doctor Id Doesnt Exist! , please enter an existing Id.\n";
                }
                else
                {
                    break; // Exit the loop if input is valid
                }
            }
        }
        return id;
    }
    DoctorList() {
        Doctorhead = NULL;
    }
    void RemoveDoctor()
    {
        int id;
        id = EnterDoctorID("Doctor ID to remove", false);
        DoctorNode* temp = Doctorhead;
        if (Doctorhead->id == id)
        {
            Doctorhead = Doctorhead->next;
            delete temp;
            cout << "Deleted Doctor Successfully.";
            return;
        }
        while (temp->next) {
            if (temp->next->id == id) {
                DoctorNode* delptr = temp->next;
                temp->next = delptr->next;
                delete delptr;
                cout << "Deleted Doctor Successfully.";
                return;
            }
            temp = temp->next;
        }
        cout << "Doctor not found!\n";
    }
    void AddDoctor()
    {
        int id;
        string name, specialization, branchNAME;
        id = EnterDoctorID("Doctor Id", true);
        cout << "Enter Doctor Name: ";
        getline(cin, name);
        cout << "Enter Doctor specialization: ";
        getline(cin, specialization);
        branchNAME = branches.EnterBranchName();
        DoctorNode* newNode = new DoctorNode(id, name, specialization, branchNAME);
        newNode->next = Doctorhead;
        Doctorhead = newNode;

        cout << "Doctor added successfully!\n";
    }
    void displayDoctors() {
        if (Doctorhead == NULL) {
            cout << "No doctors available.\n";
            return;
        }
        DoctorNode* temp = Doctorhead;
        cout << "Doctors:\n";
        while (temp) {
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Specialization: " << temp->specialization
                << ", Branch ID: " << temp->branchName << "\n";
            temp = temp->next;
        }
    }
};
// Node for Patient
class PatientNode {
public:
    int id;
    string name;
    string address;
    DoctorNode* appointment;

    PatientNode* next;

    PatientNode(int patientID, string patientName, string patientAddress) {
        id = patientID;
        name = patientName;
        address = patientAddress;
        appointment = NULL;
        next = NULL;
    }
};

// List for Patient
class PatientList {
    void ChooseFromBranches(BranchList bl, DoctorList dl, PatientNode* MYPatient)
    {
        if (bl.Branchhead == NULL) {
            cout << "No branches available.\n";
            return;
        }
        BranchNode* temp = bl.Branchhead;
        int count = 1;
        cout << "Selct From the Following Branches :\n";
        while (temp != NULL) {
            cout << count++ << " ->    " << "ID: " << temp->id << ", Name: " << temp->name << ", Location: " << temp->location << "\n";
            temp = temp->next;
        }

        string SelectedBranchNAME;
        while (true)
        {
            int SelectedBranchNUM;
            SelectedBranchNUM = EnterINT(false, "Number Of Selected Branch");
            if (SelectedBranchNUM<1 || SelectedBranchNUM>count - 1)
            {
                cout << "Invalid Input .. Try Again\n";
            }
            else
            {
                int i = 1;
                BranchNode* temp = bl.Branchhead;
                while (temp != NULL) {
                    if (i == SelectedBranchNUM)
                    {
                        SelectedBranchNAME = temp->name;
                        break;
                    }
                    i++;
                    temp = temp->next;
                }
                break;
            }
        }
        DoctorNode* doctortemp = dl.Doctorhead;
        if (doctortemp == NULL)
            cout << "Sorry, No doctors Available in All Branches";
        else
        {
            int num = 1;
            bool found = false;
            while (doctortemp)
            {
                if (doctortemp->branchName == SelectedBranchNAME)
                {
                    found = true;
                    cout << num++ << " .    id : " << doctortemp->id << " ,  Name : " << doctortemp->name << "  ,  Specialization : " << doctortemp->specialization << endl;
                    doctortemp = doctortemp->next;
                }
                else
                    doctortemp = doctortemp->next;
            }

            if (!found)
            {
                cout << "Sorry, No doctors Available in this Branch"; return;
            }
            cout << num-- << " . Cancel\n";

            while (true)
            {
                int UserChoice;
                cin >> UserChoice;
                if (UserChoice<0 || UserChoice>num)
                {
                    cout << "Invalid Input .. Try Again\n";
                }
                else if (UserChoice == 0)
                {
                    return;
                }
                else
                {
                    int i = 1;
                    DoctorNode* doctortemp = dl.Doctorhead;
                    while (i != UserChoice)
                    {
                        if (doctortemp->branchName == SelectedBranchNAME)
                            i++;
                        doctortemp = doctortemp->next;
                    }
                    MYPatient->appointment = doctortemp;
                    cout << "Appointment Done Successfully.\n";
                    break;


                    temp = temp->next;
                }
                break;
            }
        }
    }

    void ChooseFromDoctors(DoctorList dl, PatientNode* MYPatient)
    {
        DoctorNode* doctortemp = dl.Doctorhead;
        if (doctortemp == NULL)
            cout << "Sorry, No doctors Available";
        else
        {
            int num = 1;
            while (doctortemp != NULL)
            {
                cout << num++ << " ->  id : " << doctortemp->id << " ,  Name : " << doctortemp->name << "  ,  Specialization : " << doctortemp->specialization << "  ,  Branch : " << doctortemp->branchName << ".\n";
                doctortemp = doctortemp->next;
            }

            cout << num-- << " -> Cancel Appointment\n";

            while (true)
            {
                int UserChoice;
                cin >> UserChoice;
                if (UserChoice<0 || UserChoice>num)
                {
                    cout << "Invalid Input .. Try Again\n";
                }
                else if (UserChoice == 0)
                {
                    return;
                }
                else
                {
                    doctortemp = dl.Doctorhead;
                    int counter = 1;
                    while (counter != UserChoice)
                    {
                        counter++;
                        doctortemp = doctortemp->next;
                    }
                    MYPatient->appointment = doctortemp;
                    cout << "Appointment Done Successfully.\n";
                    break;
                }
            }
        }

    }
public:
    PatientNode* head;
    int EnterINT(bool newID, string entered)
    {
        int id;
        while (true) {
            cout << "Enter " << entered << " : ";
            cin >> id;
            // Check if input is valid
            if (cin.fail()) {
                cin.clear(); // Clear the fail state
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input. Please enter an integer for the " << entered << ".\n";
            }
            else {
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Clear any extra input
                bool repeated = false;
                if (newID)
                {
                    PatientNode* temp = head;
                    while (temp != NULL) {
                        if (temp->id == id) {
                            repeated = true;
                            break;
                        }
                        temp = temp->next;
                    }
                }
                if (repeated)
                {
                    cout << "This Entered id Already exists , please enter a new one...\n";
                }
                else
                {
                    break; // Exit the loop if input is valid
                }
            }
        }
        return id;
    }

    PatientList() {
        head = NULL;
    }
    void BookAppointment(BranchList bl, DoctorList dl)
    {
        int id;
        id = EnterINT(false, "Patient Id");
        PatientNode* MYPatient = searchPatientByID(id);
        if (MYPatient)
        {
            bool err = true;
            while (err)
            {
                cout << "1. Select from Branches\n2. Select from Doctors\n";
                int choice = 1;
                cin >> choice;
                switch (choice)
                {
                case 1:
                    err = false;
                    ChooseFromBranches(bl, dl, MYPatient);
                    break;
                case 2:
                    err = false;
                    ChooseFromDoctors(dl, MYPatient);
                    break;
                default:
                    cout << "Invalid Input .. Try Again\n";
                    break;

                }
            }
        }
        else
        {
            cout << "No patient has this id... please write the id correctly.\nTry Again : press T, Cancel : any other key\n";
            string UserDecision;
            cin >> UserDecision;
            if (UserDecision == "T" || UserDecision == "t")
                BookAppointment(bl, dl);
            else
                return;
        }
    }
    void RemovePatient()
    {
        int id;
        cout << "Enter Patient ID to remove: ";
        id = EnterINT(false, "Patient Id");
        PatientNode* temp = head;
        if (head->id == id)
        {
            head = head->next;
            delete temp;
            cout << "Deleted Patient Successfully.";
            return;
        }
        while (temp->next) {
            if (temp->next->id == id) {
                PatientNode* delptr = temp->next;
                temp->next = delptr->next;
                delete delptr;
                cout << "Deleted Patient Successfully.";
                return;
            }
            temp = temp->next;
        }
        cout << "Patient not found!\n";
    }
    void UpdatePatient()
    {
        int id;
        if (!head) {
            cout << "No patients found.\n";
            return;
        }

        cout << "Enter Patient ID to update it: ";
        cin.ignore();
        id = EnterINT(true, "Patient Id");

        PatientNode* temp = head;
        bool found = false;

        while (temp) {
            if (temp->id == id) {
                UpdatePatient(temp);
                found = true;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "No patient with the id '" << id << "' was found.\n";
        }
    }
    void UpdatePatient(PatientNode* p)
    {
        int choice;

        do {
            cout << "\n1. Update ID\n2. Update Name\n3. Update Address\n4. Finished Updates";
            cout << "Enter your choice: ";
            cin >> choice;
            int id; string name; string address;
            switch (choice) {
            case 1:
                cout << "Enter new ID: ";
                id = EnterINT(true, "Patient Id");
                p->id = id;
                cout << "Updated Patient ID successfully.\n";
                cout << "ID: " << p->id << ", Name: " << p->name << ", address: " << p->address << "\n";
                break;
            case 2:
                cout << "Enter new Name: ";
                cin >> name;
                p->name = name;
                cout << "Updated Patient Name successfully.\n";
                cout << "ID: " << p->id << ", Name: " << p->name << ", address: " << p->address << "\n";
                break;
            case 3:
                cout << "Enter new Address: ";
                cin >> address;
                p->address = address;
                cout << "Updated Patient address successfully.\n";
                cout << "ID: " << p->id << ", Name: " << p->name << ", address: " << p->address << "\n";
                break;
            case 4:

                break;
            default:
                cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != 4);

    }
    void AddPatient()
    {
        int id;
        string name, PatientAddress;
        cout << "Enter Patient ID: ";
        id = EnterINT(true, "Patient Id");
        cout << "Enter Patient Name: ";
        getline(cin, name);
        cout << "Enter Patient address: ";
        getline(cin, PatientAddress);
        PatientNode* newNode = new PatientNode(id, name, PatientAddress);
        newNode->next = head;
        head = newNode;
        cout << "Patient added successfully!\n";
    }
    void displayPatients() {
        if (!head) {
            cout << "No patients available.\n";
            return;
        }
        PatientNode* temp = head;
        cout << "Patients:\n";
        while (temp) {
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Address: " << temp->address << "\n";
            temp = temp->next;
        }
    }
    void searchPatientByName() {
        string nameToSearch;
        if (!head) {
            cout << "No patients found.\n";
            return;
        }

        cout << "Enter Patient Name to search: ";
        cin.ignore();
        cin >> nameToSearch;

        PatientNode* temp = head;
        bool found = false;

        while (temp) {
            if (temp->name == nameToSearch) {
                cout << "Patient Found: \n";
                cout << "ID: " << temp->id << ", Name: " << temp->name
                    << ", Address: " << temp->address;
                if (temp->appointment)
                    cout << ", Appointment: " << temp->appointment->name << " - " << temp->appointment->specialization << " - " << temp->appointment->branchName;

                cout << ".\n";
                found = true;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "No patient with the name '" << nameToSearch << "' was found.\n";
        }
    }
    PatientNode* searchPatientByID(int id) {
        if (!head)
            return NULL;
        PatientNode* temp = head;
        while (temp) {
            if (temp->id == id)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }
    void DisplayAppointmentsForBranch(BranchList bl)
    {
        if (bl.Branchhead == NULL)
        {
            cout << "NO Branches Available\n"; return;
        }
        if (head == NULL)
        {
            cout << "There are no Patients\n"; return;
        }
        cout << "1. Display Appointments of specific branch\n2. Display Appointments of all Branches\n";
        int input;

        bool err = true;
        while (err)
        {
            cin >> input;
            if (cin.fail()) {
                cin.clear(); // Clear the fail state
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                cout << "please select 1 or 2 only.\n";
            }
            else if (input == 1 || input == 2)
            {
                err = false;
            }
            else
            {
                cout << "please select 1 or 2 only.\n";
            }
        }
        if (input == 1)
        {
            string BranchName;
            cout << "Enter the name of Branch : ";
            bool foundBranch = false;
            getline(cin, BranchName);
            PatientNode* temp = head;
            if (head == NULL)
            {
                cout << "There are no Patients\n"; return;
            }
            while (temp != NULL)
            {

                if (temp->appointment && temp->appointment->branchName == BranchName)
                {
                    foundBranch = true;
                    cout << "Patient id :" << temp->id << " , Patient Name : " << temp->name << " , doctor id : " << temp->appointment->id << " , doctor name : " << temp->appointment->name << " , specialization: " << temp->appointment->specialization << endl;
                    temp = temp->next;
                }
            }
            if (!foundBranch)
            {
                cout << "No Branch with name : " << BranchName << endl;
            }
        }
        else
        {
            BranchNode* tempBRANCH = bl.Branchhead;
            while (tempBRANCH != NULL)
            {
                bool foundBranch = false;
                string BranchName = tempBRANCH->name;
                cout << "Branch : " << BranchName << "  ,  location :" << tempBRANCH->location << "  ,  id : " << tempBRANCH->id << "   : " << endl;
                PatientNode* temp = head;

                while (temp != NULL)
                {
                    if (temp->appointment->branchName == BranchName)
                    {
                        foundBranch = true;
                        cout << "   Patient id :" << temp->id << " , Patient Name : " << temp->name << " , doctor id : " << temp->appointment->id << " , doctor name : " << temp->appointment->name << " , specialization: " << temp->appointment->specialization << endl;
                        temp = temp->next;
                    }
                    else
                    {
                        temp = temp->next;
                    }
                }
                if (!foundBranch)
                {
                    cout << "    There Are no appointments at this Branch\n";
                }
                tempBRANCH = tempBRANCH->next;
            }

        }
    }
    void DisplayAppointmentsForDoctor(DoctorList dl)
    {
        if (dl.Doctorhead == NULL)
        {
            cout << "NO doctors Available\n"; return;
        }
        if (head == NULL)
        {
            cout << "There are no Patients\n"; return;
        }
        cout << "1. Display Appointments of specific doctor\n2. Display Appointments of all doctors\n";
        int input;

        bool err = true;
        while (err)
        {
            cin >> input;
            if (cin.fail()) {
                cin.clear(); // Clear the fail state
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                cout << "please select 1 or 2 only.\n";
            }
            else if (input == 1 || input == 2)
            {
                err = false;
            }
            else
            {
                cout << "please select 1 or 2 only.\n";
            }
        }
        if (input == 1)
        {
            string BranchName;
            cout << "Enter the name of Branch : ";
            bool foundBranch = false;
            getline(cin, BranchName);
            PatientNode* temp = head;
            if (head == NULL)
            {
                cout << "There are no Patients\n"; return;
            }
            while (temp != NULL)
            {

                if (temp->appointment->branchName == BranchName)
                {
                    foundBranch = true;
                    cout << "Patient id :" << temp->id << " , Patient Name : " << temp->name << " , doctor id : " << temp->appointment->id << " , doctor name : " << temp->appointment->name << " , specialization: " << temp->appointment->specialization << endl;
                    temp = temp->next;
                }
                else
                    temp = temp->next;
            }
            if (!foundBranch)
            {
                cout << "No Branch with name : " << BranchName << endl;
            }
        }
        else
        {
            DoctorNode* tempDOCTOR = dl.Doctorhead;
            while (tempDOCTOR != NULL)
            {
                bool foundDOCTOR = false;
                int DOCTORID = tempDOCTOR->id;
                cout << "Branch : " << tempDOCTOR->name << "  ,  location :" << tempDOCTOR->specialization << "  ,  id : " << tempDOCTOR->id << "  ,  branch :  " << tempDOCTOR->branchName << "   : " << endl;
                PatientNode* temp = head;

                while (temp != NULL)
                {
                    if (temp->appointment && temp->appointment->id == DOCTORID)
                    {
                        foundDOCTOR = true;
                        cout << "   Patient id :" << temp->id << " , Patient Name : " << "  ,  branch :  " << tempDOCTOR->branchName << "." << endl;
                        temp = temp->next;
                    }
                    else
                    {
                        temp = temp->next;
                    }
                }
                if (!foundDOCTOR)
                {
                    cout << "    There Are no appointments at this Branch\n";
                }
                tempDOCTOR = tempDOCTOR->next;
            }

        }

    }
};
// Main Program
int main() {
    DoctorList doctors;
    PatientList patients;
    int choice;

    do {
        cout << "***********************************************************************";
        cout << "\nHospital Management System\n";
        cout << "1. Add Branch      \t2. Display Branches             \t3. Add Doctor         \t4. Display Doctors\t5. Add Patient\t6. Book Appointment\n";
        cout << "7. Display Patients\t8. Display Branchs Appointments \t9. search Branch By ID\t10. Remove Branch\n";
        cout << "11. Remove Doctor  \t12. Display Doctors Appointments\t13. Remove Patient    \t14. Search Patient By Name\n15 . Update Patient Info\t0. Exit\n";
        cout << "\n***********************\n";

        while (true) { // Loop until valid input is received
            cout << "Enter your choice: ";
            cin >> choice;

            if (cin.fail()) { // If input is not an integer
                cin.clear(); // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid choice! Please try again.\n";
            }
            else {
                break; // Exit loop if input is valid
            }
        }

        switch (choice) {
        case 1:
            branches.addBranch();
            break;
        case 2:
            branches.displayBranches();
            break;
        case 3:
            doctors.AddDoctor();
            break;
        case 4:
            doctors.displayDoctors();
            break;
        case 5:
            patients.AddPatient();
            break;
        case 6:
            patients.BookAppointment(branches, doctors);
            break;
        case 7:
            patients.displayPatients();
            break;
        case 8:
            patients.DisplayAppointmentsForBranch(branches);
            break;
        case 9:
            branches.searchBranchByID();
            break;
        case 10:
            branches.RemoveBranch();
            break;
        case 11:
            doctors.RemoveDoctor();
            break;
        case 12:
            patients.DisplayAppointmentsForDoctor(doctors);
            break;
        case 13:
            patients.RemovePatient();
            break;
        case 14:
            patients.searchPatientByName();
            break;
        case 15:
            patients.UpdatePatient();
            break;
        case 0:
            cout << "Exiting Program ...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
