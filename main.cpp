#include <bits/stdc++.h>
#include "Task.h"
#include <windows.h>
#include "heap_manager.h"
#include <fstream>
#include <sstream>
using namespace std;

void LoadFile(const string& filename, HeapManager& manager){
    ifstream f(filename);
    if (!f){
        cout << "Khong mo duoc file" << endl;
        return;
    }
    string line;
    while(getline(f,line)){
        stringstream ss(line);
        string idStr, title , priorityStr, deadline, completedStr;
        
        getline(ss,idStr,'|');
        getline(ss,title,'|');
        getline(ss,priorityStr,'|');
        getline(ss,deadline,'|');
        getline(ss,completedStr,'|');

        size_t id = size_t(stoll(idStr));
        int priority = stoi(priorityStr);
        bool completed = (completedStr == "1");

        Task* t = new Task(title, priority, deadline, completed);
        manager.addTask(t);
    }
    f.close();

}




int main(){
    SetConsoleOutputCP(CP_UTF8); // in ra console có tiếng việt
    
    HeapManager manager;
    LoadFile("D:\\PBL\\PBL2\\ToDoList\\Data\\test.txt", manager);
    int choice;
    while(true){
         do {
        cout << "\n===== TODO LIST MENU =====\n";
        cout << "1. Them task\n";
        cout << "2. Hien thi MaxHeap (priority)\n";
        cout << "3. Hien thi MinHeap (deadline)\n";
        cout << "4. Lay task co do uu tien cao nhat\n";
        cout << "5. Lay task co deadline som nhat\n";
        cout << "6. Xoa task theo ID\n";
        cout << "0. Thoat\n";
        cout << "==========================\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Task* t = new Task();
            t->nhap();
            manager.addTask(t);
            cout << "Them task thanh cong!\n";
        }
        else if (choice == 2) {
            manager.ShowTaskByPriority();
        }
        else if (choice == 3) {
            manager.ShowTaskByDeadline();
        }
        else if (choice == 4) {
            Task* t = manager.getHighestPriority();
            if (t) {
                cout << "Task uu tien cao nhat:\n";
                t->display();
            } else {
                cout << "Danh sach rong!\n";
            }
        }
        else if (choice == 5) {
            Task* t = manager.getEarliestDeadline();
            if (t) {
                cout << "Task co deadline som nhat:\n";
                t->display();
            } else {
                cout << "Danh sach rong!\n";
            }
        }
        else if (choice == 6) {
            size_t id;
            cout << "Nhap ID muon xoa: ";
            cin >> id;
            manager.removeTask(id);
            cout << "Da xoa task (neu ton tai)\n";
        }

    } while (choice != 0);

    cout << "Thoat chuong trinh!\n";
    return 0;
    }
}