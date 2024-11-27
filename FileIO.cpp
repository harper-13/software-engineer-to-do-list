#include "FileIO.h"
#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

// ���������б�
void loadTasks(vector<Task>& tasks, const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "�����ļ�δ�ҵ������������ļ���" << endl;
        return;
    }

    string name, tag, deadline;
    int priority;

    while (getline(file, name)) {
        if (name.empty()) continue;
        file >> priority;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(file, tag);
        getline(file, deadline);
        tasks.push_back({name, priority, tag, deadline});
    }

    file.close();
    cout << "�����ѳɹ����أ�" << endl;
}

// ���������б�
void saveTasks(vector<Task>& tasks, const string& fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cerr << "�޷����������б�" << endl;
        return;
    }

    for (const auto& task : tasks) {
        file << task.name << endl;
        file << task.priority << endl;
        file << task.tag << endl;
        file << task.deadline << endl;
        //cout << task.name << endl;
    }

    file.close();
    cout << "�����ѳɹ����棡" << endl;
}
