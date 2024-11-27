#ifndef FILEIO_H
#define FILEIO_H

#include "Task.h"
#include <string>
#include <vector>

// ÎÄ¼þ¶ÁÐ´²Ù×÷
void loadTasks(std::vector<Task>& tasks, const std::string& fileName);
void saveTasks(std::vector<Task>& tasks, const std::string& fileName);

#endif // FILEIO_H
