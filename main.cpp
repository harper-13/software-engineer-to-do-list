#include "Task.h"
#include "FileIO.h"
#include "DeadLine.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

// ȫ�ֱ���
string currentUser;               // ��ǰ��¼�û�
const string usersFile = "users.txt"; // �û��˺��ļ�

void displayMainMenu();
void login();
string getTaskFileName();

int main() {
    login(); // ��¼ϵͳ

    vector<Task> tasks;
    const string fileName = getTaskFileName();

    // ���ص�ǰ�û��������б�
    loadTasks(tasks, fileName);
    while (true) {
        displayMainMenu();

        int choice;
        cout << "��ѡ�����: ";
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
            searchTask(tasks); // ������������
            break;
        case 6:
            viewTimeline(tasks); // ��������ʱ����һ��
            break;
        case 7:
            saveTasks(tasks, fileName);
            cout << "���沢�˳������ټ���" << endl;
            return 0;
        default:
            cout << "��Чѡ�������ԡ�" << endl;
        }
    }
    return 0;
}


// ��ʾ��ʼ����
void displayMainMenu() {
    cout << "\n";
    cout << "  �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
    cout << "  �U                    ��ӭʹ�� To-Do List                 �U" << endl;
    cout << "  �U--------------------------------------------------------�U" << endl;
    cout << "  �U   1. �鿴����                                          �U" << endl;
    cout << "  �U   2. �������                                          �U" << endl;
    cout << "  �U   3. ɾ������                                          �U" << endl;
    cout << "  �U   4. DDL ����                                          �U" << endl;
    cout << "  �U   5. ��������                                          �U" << endl;
    cout << "  �U   6. ����ʱ����һ��                                    �U" << endl;
    cout << "  �U   7. ���沢�˳�                                        �U" << endl;
    cout << "  �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << endl;
    cout << "  ��ѡ��������������֣�: ";
}


// ���ݵ�ǰ�û����������ļ���
string getTaskFileName() {
    return "user_todolist_" + currentUser + ".txt";
}


// ��¼��ע��
void login() {
    map<string, string> users; // �洢�û���������
    ifstream userFile(usersFile);
    if (userFile.is_open()) {
        string username, password;
        while (userFile >> username >> password) {
            users[username] = password; // ���������û�
        }
        userFile.close();
    }

    while (true) {
        cout << "�������˺�: ";
        string username;
        cin >> username;
        cout << "����������: ";
        string password;
        cin >> password;

        if (users.find(username) != users.end()) {
            // �û����ڣ���֤����
            if (users[username] == password) {
                cout << "��¼�ɹ�����ӭ������" << username << "��" << endl;
                currentUser = username;
                break;
            } else {
                cout << "������������ԡ�" << endl;
            }
        } else {
            // �û������ڣ�ע�����û�
            cout << "�˺Ų����ڣ��Ƿ񴴽����˺ţ�(y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                users[username] = password;
                currentUser = username;
                ofstream userFile(usersFile, ios::app);
                userFile << username << " " << password << endl; // �������û�
                userFile.close();
                cout << "�˺Ŵ����ɹ�����ӭ��" << username << "��" << endl;
                break;
            }
        }
    }
}

