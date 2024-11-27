#ifndef DEADLINE_H
#define DEADLINE_H

#include "Task.h"
#include <vector>
#include <string>

// DDL ¼ì²é²Ù×÷
bool parseDate(const std::string& dateStr, struct tm& date);
int calculateDaysLeft(const std::string& deadline);
void checkDeadlines(const std::vector<Task>& tasks);

#endif // DEADLINE_H
