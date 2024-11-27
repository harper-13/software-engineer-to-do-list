#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

// ����ṹ��
struct Task {
    std::string name;        // �¼�����
    int priority;            // ���ȼ�
    std::string tag;         // ��ǩ
    std::string deadline;    // ��ֹʱ�� (��ʽ: YYYY-MM-DD)
};

// ������غ�������
bool compareTasks(const Task& a, const Task& b);
void addTask(std::vector<Task>& tasks);
void deleteTask(std::vector<Task>& tasks);
void viewTasks(const std::vector<Task>& tasks);
void searchTask(const std::vector<Task>& tasks); // ����������
void viewTimeline(const std::vector<Task>& tasks); // ʱ����һ������

#endif // TASK_H
