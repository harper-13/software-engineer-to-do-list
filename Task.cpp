#include "Task.h"
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

// �Ƚ�������������
bool compareTasks(const Task& a, const Task& b) {
    if (a.priority != b.priority) {
        return a.priority < b.priority; // ���ȼ�ԽСԽ��
    }
    return a.deadline < b.deadline; // ��ֹʱ���������
}

void addTask(vector<Task>& tasks) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ��ջ�����

    Task newTask;

    cout << "�������¼�����: ";
    getline(cin, newTask.name);

    cout << "���������ȼ� (1-5��1Ϊ������ȼ�): ";
    cin >> newTask.priority;
    while (newTask.priority < 1 || newTask.priority > 5) {
        cout << "���ȼ�������Ч�������� 1 �� 5 ������: ";
        cin >> newTask.priority;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �ٴ���������

    cout << "�������ǩ (����: ����, ѧϰ, ����): ";
    getline(cin, newTask.tag);

    cout << "�������ֹʱ�� (��ʽ: YYYY-MM-DD): ";
    getline(cin, newTask.deadline);

    tasks.push_back(newTask);
    cout << "�����ѳɹ���ӣ�" << endl;
}

void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "��ǰû������" << endl;
        return;
    }

    cout << "\n��ѡ��ɾ������:" << endl;
    cout << "1. �����¼�����ɾ��" << endl;
    cout << "2. ���ݱ�ǩɾ��" << endl;
    cout << "3. �������ȼ�ɾ��" << endl;
    cout << "4. ���ݽ�ֹ����ɾ��" << endl;
    cout << "��ѡ����� (��������): ";

    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ��ջ�����

    switch (choice) {
    case 1: {
        // ���¼�����ɾ��
        cout << "��������������: ";
        string name;
        getline(cin, name);
        auto it = remove_if(tasks.begin(), tasks.end(),
            [&name](const Task& task) { return task.name == name; });
        if (it != tasks.end()) {
            tasks.erase(it, tasks.end());
            cout << "��ɾ��������ƥ�������" << endl;
        }
        else {
            cout << "δ�ҵ�ƥ����������ơ�" << endl;
        }
        break;
    }
    case 2: {
        // ����ǩɾ��
        cout << "�����������ǩ: ";
        string tag;
        getline(cin, tag);
        auto it = remove_if(tasks.begin(), tasks.end(),
            [&tag](const Task& task) { return task.tag == tag; });
        if (it != tasks.end()) {
            tasks.erase(it, tasks.end());
            cout << "��ɾ�����ǩƥ�������" << endl;
        }
        else {
            cout << "δ�ҵ�ƥ��������ǩ��" << endl;
        }
        break;
    }
    case 3: {
        // �����ȼ�ɾ��
        cout << "�������������ȼ� (1-5): ";
        int priority;
        cin >> priority;
        auto it = remove_if(tasks.begin(), tasks.end(),
            [priority](const Task& task) { return task.priority == priority; });
        if (it != tasks.end()) {
            tasks.erase(it, tasks.end());
            cout << "��ɾ�������ȼ�ƥ�������" << endl;
        }
        else {
            cout << "δ�ҵ�ƥ������ȼ�����" << endl;
        }
        break;
    }
    case 4: {
        // ����ֹ����ɾ��
        cout << "�����������ֹ���� (��ʽ: YYYY-MM-DD): ";
        string deadline;
        getline(cin, deadline);
        auto it = remove_if(tasks.begin(), tasks.end(),
            [&deadline](const Task& task) { return task.deadline == deadline; });
        if (it != tasks.end()) {
            tasks.erase(it, tasks.end());
            cout << "��ɾ�����ֹ����ƥ�������" << endl;
        }
        else {
            cout << "δ�ҵ�ƥ��Ľ�ֹ��������" << endl;
        }
        break;
    }
    default:
        cout << "��Чѡ�������ԡ�" << endl;
        break;
    }
}

// �鿴����
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "��ǰû������" << endl;
        return;
    }

    vector<Task> sortedTasks = tasks;
    sort(sortedTasks.begin(), sortedTasks.end(), compareTasks);

    cout << "\n��ǰ�����б�������:" << endl;
    for (size_t i = 0; i < sortedTasks.size(); ++i) {
        cout << i + 1 << ". ����: " << sortedTasks[i].name
            << ", ���ȼ�: " << sortedTasks[i].priority
            << ", ��ǩ: " << sortedTasks[i].tag
            << ", ��ֹʱ��: " << sortedTasks[i].deadline
            << endl;
    }
}

// �߼���������
void searchTask(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "��ǰû������" << endl;
        return;
    }

    cout << "\n��ѡ����������:" << endl;
    cout << "1. �����¼���������" << endl;
    cout << "2. ���ݱ�ǩ����" << endl;
    cout << "3. �������ȼ�����" << endl;
    cout << "4. ���ݽ�ֹ��������" << endl;
    cout << "��ѡ����� (��������): ";

    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ��ջ�����

    vector<Task> filteredTasks;

    switch (choice) {
    case 1: {
        cout << "�������¼�����: ";
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
        cout << "�������ǩ: ";
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
        cout << "���������ȼ� (1-5): ";
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
        cout << "�������ֹ���� (��ʽ: YYYY-MM-DD): ";
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
        cout << "��Чѡ�������ԡ�" << endl;
        return;
    }

    if (filteredTasks.empty()) {
        cout << "δ�ҵ���������������" << endl;
    }
    else {
        cout << "\n=== ������� ===" << endl;
        for (const auto& task : filteredTasks) {
            cout << "����: " << task.name
                << ", ���ȼ�: " << task.priority
                << ", ��ǩ: " << task.tag
                << ", ��ֹʱ��: " << task.deadline
                << endl;
        }
    }
}

// �ȽϺ��������ݽ�ֹ��������
bool compareByDeadline(const Task& a, const Task& b) {
    return a.deadline < b.deadline; // ����ֹ���ڴ��絽������
}

// �鿴����ʱ����
void viewTimeline(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "��ǰû������" << endl;
        return;
    }

    // ���������б��������
    vector<Task> sortedTasks = tasks;
    sort(sortedTasks.begin(), sortedTasks.end(), compareByDeadline);

    // �������������
    cout << "\n=== ����ʱ����һ�� ===" << endl;
    for (const auto& task : sortedTasks) {
        cout << "��ֹʱ��: " << task.deadline
            << ", ����: " << task.name
            << ", ���ȼ�: " << task.priority
            << ", ��ǩ: " << task.tag
            << endl;
    }
}