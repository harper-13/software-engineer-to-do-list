#include "Task.h"
#include "FileIO.h"
#include "DeadLine.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

// 全局变量
string currentUser;               // 当前登录用户
const string usersFile = "users.txt"; // 用户账号文件

void displayMainMenu();
void login();
string getTaskFileName();

int main() {
    login(); // 登录系统

    vector<Task> tasks;
    const string fileName = getTaskFileName();

    // 加载当前用户的任务列表
    loadTasks(tasks, fileName);
    while (true) {
        displayMainMenu();

        int choice;
        cout << "请选择操作: ";
        cin >> choice;

        switch (choice) {
        case 1:
            viewTasks(tasks);
            break;
        case 2:
            addTask(tasks);
            break;
        case 3:
            deleteTask(tasks);
            break;
        case 4:
            checkDeadlines(tasks);
            break;
        case 5:
            searchTask(tasks); // 调用搜索功能
            break;
        case 6:
            viewTimeline(tasks); // 调用任务时间线一览
            break;
        case 7:
            saveTasks(tasks, fileName);
            cout << "保存并退出程序，再见！" << endl;
            return 0;
        default:
            cout << "无效选择，请重试。" << endl;
        }
    }
    return 0;
}


// 显示初始界面
void displayMainMenu() {
    cout << "\n";
    cout << "  ╔════════════════════════════════════════════════════════╗" << endl;
    cout << "  ║                    欢迎使用 To-Do List                 ║" << endl;
    cout << "  ║--------------------------------------------------------║" << endl;
    cout << "  ║   1. 查看任务                                          ║" << endl;
    cout << "  ║   2. 添加任务                                          ║" << endl;
    cout << "  ║   3. 删除任务                                          ║" << endl;
    cout << "  ║   4. DDL 提醒                                          ║" << endl;
    cout << "  ║   5. 搜索任务                                          ║" << endl;
    cout << "  ║   6. 任务时间线一览                                    ║" << endl;
    cout << "  ║   7. 保存并退出                                        ║" << endl;
    cout << "  ╚════════════════════════════════════════════════════════╝" << endl;
    cout << "  请选择操作（输入数字）: ";
}


// 根据当前用户生成任务文件名
string getTaskFileName() {
    return "user_todolist_" + currentUser + ".txt";
}


// 登录或注册
void login() {
    map<string, string> users; // 存储用户名和密码
    ifstream userFile(usersFile);
    if (userFile.is_open()) {
        string username, password;
        while (userFile >> username >> password) {
            users[username] = password; // 加载已有用户
        }
        userFile.close();
    }

    while (true) {
        cout << "请输入账号: ";
        string username;
        cin >> username;
        cout << "请输入密码: ";
        string password;
        cin >> password;

        if (users.find(username) != users.end()) {
            // 用户存在，验证密码
            if (users[username] == password) {
                cout << "登录成功！欢迎回来，" << username << "！" << endl;
                currentUser = username;
                break;
            } else {
                cout << "密码错误，请重试。" << endl;
            }
        } else {
            // 用户不存在，注册新用户
            cout << "账号不存在，是否创建新账号？(y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                users[username] = password;
                currentUser = username;
                ofstream userFile(usersFile, ios::app);
                userFile << username << " " << password << endl; // 保存新用户
                userFile.close();
                cout << "账号创建成功！欢迎，" << username << "！" << endl;
                break;
            }
        }
    }
}

