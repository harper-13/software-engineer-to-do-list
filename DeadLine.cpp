#include "DeadLine.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <time.h>
#include <iomanip>

using namespace std;

// 解析日期字符串
bool parseDate(const string& dateStr, struct tm& date) {
    istringstream ss(dateStr);
    ss >> get_time(&date, "%Y-%m-%d");
    if (ss.fail()) {
        cerr << "日期解析失败: " << dateStr << endl;
        return false;
    }
    return true;
}

// 计算日期之间的天数
int calculateDaysLeft(const string& deadline) {
    struct tm deadlineDate = {};
    if (!parseDate(deadline, deadlineDate)) {
        return 0; // 无法解析日期时，返回 0
    }

    time_t now = time(nullptr); // 当前时间
    time_t deadlineTime = mktime(&deadlineDate); // 将 tm 转换为 time_t

    double diffSeconds = difftime(deadlineTime, now); // 计算时间差（秒）
    return static_cast<int>(diffSeconds / (60 * 60 * 24)); // 转换为天数
}

// 检查任务的DDL
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

    cout << "\n=== 已完成任务 ===" << endl;
    for (const auto& task : incomplete) {
        cout << "名称: " << task.name << ", 截止时间: " << task.deadline
            << ", 已过期 " << abs(calculateDaysLeft(task.deadline)) << " 天" << endl;
    }

    cout << "\n=== 未完成任务 ===" << endl;
    for (const auto& task : complete) {
        cout << "名称: " << task.name << ", 截止时间: " << task.deadline
            << ", 还有 " << calculateDaysLeft(task.deadline) << " 天到期" << endl;
    }
}

