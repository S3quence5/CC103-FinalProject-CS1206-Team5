#include <iostream>
#include <queue>
#include <string>
#include <stack>


using namespace std;


struct Patient {
    string name;
    int age;
    bool pregnant;
    bool pwd;
    int symptomSeverity;


    int getPriorityLevel() const {
        int priority = 0;


        priority += symptomSeverity * 10;


        if (age >= 60) priority += 15;
        if (pregnant) priority += 20;
        if (pwd) priority += 15;


        return priority;
    }
    bool isPriority() const {
        return getPriorityLevel() > 30;
    }
    bool operator<(const Patient& other) const {
        return getPriorityLevel() < other.getPriorityLevel();
    }


};


struct Action {
    enum TYPE {
        ADD_NORMAL,
        ADD_PRIORITY,
        PROCESS_NORMAL,
        PROCESS_PRIORITY,
    };
    TYPE type;
    Patient data;
};


class ClinicSystem {
private:
    queue<Patient> normalPatients;
    priority_queue<Patient> priorityPatients;
    stack<Action> actionStack;


public:
    ClinicSystem() {
        cout << "_____________________________________________________" << endl;
        cout << "                                                     " << endl;
        cout << "    Welcome to Clinic Patient Management System!     " << endl;
        cout << "_____________________________________________________" << endl;
    }
    ~ClinicSystem() {
        cout << endl << "[INFO] System closed.";
    }
    void run() {
        while (true) {
            showMenu();


            int choice;
            cout << "Enter your choice: ";
            cin >> choice;
            cout << endl;


            if (!handleAction(choice))
                break;
        }
    }
    bool handleAction(int action) {
        switch (action) {
            case 1: addPatient(); return true;
            case 2: processPatient(); return true;
            case 3: undoAction(); return true;
            case 4: showPatients(); return true;
            case 5: return false;
            default:
                cout << "[INFO] Invalid choice." << endl;
                return false;
        }
    }
    void showMenu() {
        cout << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "____MENU_____________________________________________" << endl;
        cout << "[1] Add Patient" << endl;
        cout << "[2] Process Patient" << endl;
        cout << "[3] Undo Last Action" << endl;
        cout << "[4] Display All" << endl;
        cout << "[5] Exit" << endl;
        cout << "-----------------------------------------------------" << endl;


    }
    void showPatients() {
        if (priorityPatients.empty())
            cout << "[Priority Patients is empty]" << endl;
        else
            cout << "[Priority Patients]" << endl;
        priority_queue<Patient> tempPriorityPatients = priorityPatients;
        for (int i = 0; i < priorityPatients.size(); i++) {
            Patient patient = tempPriorityPatients.top();
            cout << i << ". " << patient.name << endl;
            tempPriorityPatients.pop();
        }


        cout << endl;


        if (normalPatients.empty())
            cout << "[Normal Patients is empty]" << endl << endl;
        else
            cout << "[Normal Patients]" << endl;


        priority_queue<Patient> tempNormalPatients = priorityPatients;
        for (int i = 0; i < normalPatients.size(); i++) {
            Patient patient = tempNormalPatients.top();
            cout << i << ". " << patient.name << endl;
            tempNormalPatients.pop();
        }
       
    }
    void addPatient() {
        Patient patient;
        cout << "[Patient Details]" << endl;


        cout << "Enter name: ";
        cin.ignore();
        getline(cin, patient.name);


        cout << "Enter age: ";
        cin >> patient.age;


        cout << "Pregnant? (1=yes, 0=no): ";
        cin >> patient.pregnant;


        cout << "PWD? (1=yes, 0=no): ";
        cin >> patient.pwd;


        cout << "Symptom severity (1-10): ";
        cin >> patient.symptomSeverity;


        cout << "[ADDED] " << patient.name << endl;


        if (patient.isPriority()) {
            priorityPatients.push(patient);
            actionStack.push(Action{Action::ADD_PRIORITY, patient});
            cout << "[INFO] " << "This patient is prioritized." << endl;
        }
        else {
            normalPatients.push(patient);
            actionStack.push(Action{Action::ADD_NORMAL, patient});
        }
    }
    void processPatient() {
        if (!priorityPatients.empty()) {
            Patient patient = priorityPatients.top();
            priorityPatients.pop();
            actionStack.push(Action{Action::PROCESS_PRIORITY, patient});
            cout << "[PROCESSED] " << "Priority patient named: " << patient.name << "." << endl;
        }
        else if (!normalPatients.empty()) {
            Patient patient = normalPatients.front();
            normalPatients.pop();
            actionStack.push(Action{Action::PROCESS_NORMAL, patient});
            cout << "[PROCESSED] " << " patient named: " << patient.name << "." << endl;
        }
        else {
            cout << "[INFO] No patients found." << endl;
        }
    }
    void undoAction() {
        if (actionStack.empty()) {
            cout << "[ALERT] Nothing to undo.\n";
            return;
        }


        Action last = actionStack.top();
        actionStack.pop();


        if (last.type == Action::ADD_PRIORITY) {
            priority_queue<Patient> temp;
            priorityPatients.pop();
            while (!priorityPatients.empty()) {
                temp.push(priorityPatients.top());
                priorityPatients.pop();
            }
            priorityPatients = temp;
            cout << "[INFO] Undo last added priority patient." << endl;
        }
        else if (last.type == Action::ADD_NORMAL) {
            queue<Patient> temp;
            normalPatients.pop();
            while (!normalPatients.empty()) {
                temp.push(normalPatients.front());
                normalPatients.pop();
            }
            normalPatients = temp;
            cout << "[INFO] Undo last added patient." << endl;
        }
        else if (last.type == Action::PROCESS_PRIORITY) {
            priorityPatients.push(last.data);
            cout << "[INFO] Undo processing of priority patient." << endl;
        }
        else if (last.type == Action::PROCESS_NORMAL) {
            normalPatients.push(last.data);
            cout << "[INFO] Undo processing of patient." << endl;
        }
    }
};


int main() {
    ClinicSystem system;
    system.run();
   
    return 0;
}


