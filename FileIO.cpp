#include "FileIO.h"
#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

// 加载任务列表
void loadTasks(vector<Task>& tasks, const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "任务文件未找到，将创建新文件。" << endl;
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
    cout << "任务已成功加载！" << endl;
}

// 保存任务列表
void saveTasks(vector<Task>& tasks, const string& fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cerr << "无法保存任务列表！" << endl;
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
    cout << "任务已成功保存！" << endl;
}
