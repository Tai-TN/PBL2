#include <bits/stdc++.h>
#include "Task.h"
#include <windows.h>

// Chạy file main
// g++ main.cpp Task.cpp => a.exe, chạy file exe là được

using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8); // in ra console có tiếng việt
    Task *a = new Task("Tập thể dục",1, "2025-07-13",false);
    a->display();
    delete a;
    return 0;
}