#include "DeadLine.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <time.h>
#include <iomanip>

using namespace std;

// ���������ַ���
bool parseDate(const string& dateStr, struct tm& date) {
    istringstream ss(dateStr);
    ss >> get_time(&date, "%Y-%m-%d");
    if (ss.fail()) {
        cerr << "���ڽ���ʧ��: " << dateStr << endl;
        return false;
    }
    return true;
}

// ��������֮�������
int calculateDaysLeft(const string& deadline) {
    struct tm deadlineDate = {};
    if (!parseDate(deadline, deadlineDate)) {
        return 0; // �޷���������ʱ������ 0
    }

    time_t now = time(nullptr); // ��ǰʱ��
    time_t deadlineTime = mktime(&deadlineDate); // �� tm ת��Ϊ time_t

    double diffSeconds = difftime(deadlineTime, now); // ����ʱ���룩
    return static_cast<int>(diffSeconds / (60 * 60 * 24)); // ת��Ϊ����
}

// ��������DDL
void checkDeadlines(const vector<Task>& tasks) {
    vector<Task> incomplete, complete;

    for (const auto& task : tasks) {
        int daysLeft = calculateDaysLeft(task.deadline);
        if (daysLeft < 0) {
            incomplete.push_back(task);
        }
        else {
            complete.push_back(task);
        }
    }

    cout << "\n=== ��������� ===" << endl;
    for (const auto& task : incomplete) {
        cout << "����: " << task.name << ", ��ֹʱ��: " << task.deadline
            << ", �ѹ��� " << abs(calculateDaysLeft(task.deadline)) << " ��" << endl;
    }

    cout << "\n=== δ������� ===" << endl;
    for (const auto& task : complete) {
        cout << "����: " << task.name << ", ��ֹʱ��: " << task.deadline
            << ", ���� " << calculateDaysLeft(task.deadline) << " �쵽��" << endl;
    }
}

