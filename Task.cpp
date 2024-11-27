#include "Task.h"
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

// 比较任务，用于排序
bool compareTasks(const Task& a, const Task& b) {
    if (a.priority != b.priority) {
        return a.priority < b.priority; // 优先级越小越高
    }
    return a.deadline < b.deadline; // 截止时间更早优先
}

void addTask(vector<Task>& tasks) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空缓冲区

    Task newTask;

    cout << "请输入事件名称: ";
    getline(cin, newTask.name);

    cout << "请输入优先级 (1-5，1为最高优先级): ";
    cin >> newTask.priority;
    while (newTask.priority < 1 || newTask.priority > 5) {
        cout << "优先级输入无效，请输入 1 到 5 的数字: ";
        cin >> newTask.priority;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 再次清理缓冲区

    cout << "请输入标签 (例如: 工作, 学习, 个人): ";
    getline(cin, newTask.tag);

    cout << "请输入截止时间 (格式: YYYY-MM-DD): ";
    getline(cin, newTask.deadline);

    tasks.push_back(newTask);
    cout << "任务已成功添加！" << endl;
}

void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "当前没有任务！" << endl;
        return;
    }

    cout << "\n请选择删除条件:" << endl;
    cout << "1. 根据事件名称删除" << endl;
    cout << "2. 根据标签删除" << endl;
    cout << "3. 根据优先级删除" << endl;
    cout << "4. 根据截止日期删除" << endl;
    cout << "请选择操作 (输入数字): ";

    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空缓冲区

    switch (choice) {
    case 1: {
        // 按事件名称删除
        cout << "请输入任务名称: ";
        string name;
        getline(cin, name);
        auto it = remove_if(tasks.begin(), tasks.end(),
            [&name](const Task& task) { return task.name == name; });
        if (it != tasks.end()) {
            tasks.erase(it, tasks.end());
            cout << "已删除与名称匹配的任务！" << endl;
        }
        else {
            cout << "未找到匹配的任务名称。" << endl;
        }
        break;
    }
    case 2: {
        // 按标签删除
        cout << "请输入任务标签: ";
        string tag;
        getline(cin, tag);
        auto it = remove_if(tasks.begin(), tasks.end(),
            [&tag](const Task& task) { return task.tag == tag; });
        if (it != tasks.end()) {
            tasks.erase(it, tasks.end());
            cout << "已删除与标签匹配的任务！" << endl;
        }
        else {
            cout << "未找到匹配的任务标签。" << endl;
        }
        break;
    }
    case 3: {
        // 按优先级删除
        cout << "请输入任务优先级 (1-5): ";
        int priority;
        cin >> priority;
        auto it = remove_if(tasks.begin(), tasks.end(),
            [priority](const Task& task) { return task.priority == priority; });
        if (it != tasks.end()) {
            tasks.erase(it, tasks.end());
            cout << "已删除与优先级匹配的任务！" << endl;
        }
        else {
            cout << "未找到匹配的优先级任务。" << endl;
        }
        break;
    }
    case 4: {
        // 按截止日期删除
        cout << "请输入任务截止日期 (格式: YYYY-MM-DD): ";
        string deadline;
        getline(cin, deadline);
        auto it = remove_if(tasks.begin(), tasks.end(),
            [&deadline](const Task& task) { return task.deadline == deadline; });
        if (it != tasks.end()) {
            tasks.erase(it, tasks.end());
            cout << "已删除与截止日期匹配的任务！" << endl;
        }
        else {
            cout << "未找到匹配的截止日期任务。" << endl;
        }
        break;
    }
    default:
        cout << "无效选择，请重试。" << endl;
        break;
    }
}

// 查看任务
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "当前没有任务！" << endl;
        return;
    }

    vector<Task> sortedTasks = tasks;
    sort(sortedTasks.begin(), sortedTasks.end(), compareTasks);

    cout << "\n当前任务列表（已排序）:" << endl;
    for (size_t i = 0; i < sortedTasks.size(); ++i) {
        cout << i + 1 << ". 名称: " << sortedTasks[i].name
            << ", 优先级: " << sortedTasks[i].priority
            << ", 标签: " << sortedTasks[i].tag
            << ", 截止时间: " << sortedTasks[i].deadline
            << endl;
    }
}

// 高级搜索任务
void searchTask(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "当前没有任务！" << endl;
        return;
    }

    cout << "\n请选择搜索条件:" << endl;
    cout << "1. 根据事件名称搜索" << endl;
    cout << "2. 根据标签搜索" << endl;
    cout << "3. 根据优先级搜索" << endl;
    cout << "4. 根据截止日期搜索" << endl;
    cout << "请选择操作 (输入数字): ";

    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空缓冲区

    vector<Task> filteredTasks;

    switch (choice) {
    case 1: {
        cout << "请输入事件名称: ";
        string name;
        getline(cin, name);
        for (const auto& task : tasks) {
            if (task.name == name) {
                filteredTasks.push_back(task);
            }
        }
        break;
    }
    case 2: {
        cout << "请输入标签: ";
        string tag;
        getline(cin, tag);
        for (const auto& task : tasks) {
            if (task.tag == tag) {
                filteredTasks.push_back(task);
            }
        }
        break;
    }
    case 3: {
        cout << "请输入优先级 (1-5): ";
        int priority;
        cin >> priority;
        for (const auto& task : tasks) {
            if (task.priority == priority) {
                filteredTasks.push_back(task);
            }
        }
        break;
    }
    case 4: {
        cout << "请输入截止日期 (格式: YYYY-MM-DD): ";
        string deadline;
        getline(cin, deadline);
        for (const auto& task : tasks) {
            if (task.deadline == deadline) {
                filteredTasks.push_back(task);
            }
        }
        break;
    }
    default:
        cout << "无效选择，请重试。" << endl;
        return;
    }

    if (filteredTasks.empty()) {
        cout << "未找到符合条件的任务。" << endl;
    }
    else {
        cout << "\n=== 搜索结果 ===" << endl;
        for (const auto& task : filteredTasks) {
            cout << "名称: " << task.name
                << ", 优先级: " << task.priority
                << ", 标签: " << task.tag
                << ", 截止时间: " << task.deadline
                << endl;
        }
    }
}

// 比较函数：根据截止日期排序
bool compareByDeadline(const Task& a, const Task& b) {
    return a.deadline < b.deadline; // 按截止日期从早到晚排序
}

// 查看任务时间线
void viewTimeline(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "当前没有任务！" << endl;
        return;
    }

    // 复制任务列表进行排序
    vector<Task> sortedTasks = tasks;
    sort(sortedTasks.begin(), sortedTasks.end(), compareByDeadline);

    // 输出排序后的任务
    cout << "\n=== 任务时间线一览 ===" << endl;
    for (const auto& task : sortedTasks) {
        cout << "截止时间: " << task.deadline
            << ", 名称: " << task.name
            << ", 优先级: " << task.priority
            << ", 标签: " << task.tag
            << endl;
    }
}