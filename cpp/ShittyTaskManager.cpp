// This task manager has memory issues... so be careful whiel re-using

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <chrono>
#include <thread>
#include <fstream>

using namespace std;

class Task {
public: 
    string title, description;
    int priority;
    string deadline;

    Task(string t, string d, int p, string dl) : title(t), description(d), priority(p), deadline(dl) {}     //  Constructor

    bool operator<(const Task& other) const {
        return priority < other.priority;       // Min-Heap
    }
};

// Declearation 
void addTask(priority_queue<Task>& tasks);
void viewTasks(const priority_queue<Task>& tasks);
void saveTasks(const priority_queue<Task>& tasks);
void loadTasks(priority_queue<Task>& tasks);

int main() {
    priority_queue<Task> tasks;
    int choice;

    do {
    cout<<"1. Add Task\n2. View Tasks\n3. Save Tasks\n4. Load Tasks\n5. Exit"<<endl;
    cin>>choice;
    
    switch (choice) {
        case 1: addTask(tasks); break;
        case 2: viewTasks(tasks); break;
        case 3: saveTasks(tasks); break;
        case 4: loadTasks(tasks); break;
        case 5: {
            cout<<"Killing Program..."<<endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(1500));       // Gives a delay of 1.5 secs

            cout<<"\033[1mProgram Killed Successfully\033[0m"<<endl;
            break;
        }
        default: cout<<"Invalid choice!!"<<endl;
    }
    } while (choice != 5);

    return 0;
}

// add a task to the Priority_Queue
void addTask(priority_queue<Task>& tasks) {
    string title, description, deadline;
    int priority;

    cout<<"Enter Title: ";
    cin.ignore();
    getline(cin, title);
    cout<<"Enter Description: ";
    cin.ignore();
    getline(cin, description);
    cout<<"Enter Priority (1-10): ";
    cin>>priority;
    cout<<"Enter Deadline (dd-mm-yyyy): ";
    cin.ignore();
    getline(cin, deadline);

    tasks.push(Task(title, description, priority, deadline));
    cout<<"\nTask added successfully!\n";
}

// print tasks
void viewTasks(const priority_queue<Task>& tasks) {
    auto temp = tasks;
    while (!temp.empty()) {
        const Task& t = temp.top();
        cout<<"Title: "<<t.title<<endl;
        cout<<"Priority: "<<t.priority<<endl;
        cout<<"Deadline: "<<t.deadline<<endl;
        cout<<"---------------------------------------------"<<endl;
        temp.pop();
    }
}

// Save the tasks in a file
void saveTasks(const priority_queue<Task>& tasks) {
    ofstream file("tasks.txt");

    if (!file) {
        cout<<"Error Saving File!!"<<endl;
        return;
    }
    auto temp = tasks;
    while (!temp.empty()){
        const Task& t = temp.top();
        file<<t.title<<"|"<<t.description<<"|"<<t.priority<<"|"<<t.deadline<<"\n";
        temp.pop();        
    }
    cout<<"Task Saved successfully!"<<endl;
}

// Load teh the tasks from saved file
void loadTasks(priority_queue<Task>& tasks) {
    ifstream file("tasks.txt");

    if (!file) {
        cout<<"Error Loading tasks!!"<<endl;
        return;
    }
    string title, description, deadline, line;
    int priority;

    set<string> uniqueTasks;
    priority_queue<Task> tempQ;

    auto temp = tasks;

    // Tracking unique tasks through a set so that tasks don't get overlapped
    while (!temp.empty()) {
        const Task& t = temp.top();
        string taskID = title + "|" + description + "|" + to_string(priority) + "|" + deadline;

        uniqueTasks.insert(taskID);
        tempQ.push(t);
        temp.pop();
    }

    while (getline(file, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);

        title = line.substr(0, pos1);
        description= line.substr(pos1 + 1, pos2 - pos1 - 1);
        priority = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
        deadline = line.substr(pos3 + 1);

        string taskID = title + "|" + description + "|" + to_string(priority) + "|" + deadline;

        if (uniqueTasks.find(taskID) == uniqueTasks.end()) {
            uniqueTasks.insert(taskID);
            tempQ.push(Task(title, description, priority, deadline));
        }
    }
    swap(tasks, tempQ);

    cout<<"Tasks Loaded Succesfully!"<<endl;
}
