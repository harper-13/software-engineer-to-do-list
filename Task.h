#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

// 任务结构体
struct Task {
    std::string name;        // 事件名称
    int priority;            // 优先级
    std::string tag;         // 标签
    std::string deadline;    // 截止时间 (格式: YYYY-MM-DD)
};

// 任务相关函数声明
bool compareTasks(const Task& a, const Task& b);
void addTask(std::vector<Task>& tasks);
void deleteTask(std::vector<Task>& tasks);
void viewTasks(const std::vector<Task>& tasks);
void searchTask(const std::vector<Task>& tasks); // 搜索任务功能
void viewTimeline(const std::vector<Task>& tasks); // 时间线一览功能

#endif // TASK_H
