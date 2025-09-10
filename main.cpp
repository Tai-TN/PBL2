#include <bits/stdc++.h>
#include "Task.h"
#include <windows.h>



using namespace std;
int main(){
    SetConsoleOutputCP(CP_UTF8); // in ra console có tiếng việt
    Task *a = new Task();
    a->nhap();
    a->display();
}