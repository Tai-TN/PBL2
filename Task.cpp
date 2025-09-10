#include <iostream>
#include "Task.h"

Task::Task(std::string t, int p,std::string d, bool completed ){
    this->id = std::to_string(std::time(nullptr));
    this->title = t;
    this->priority = p;
    this->deadline = d;
    this->completed = completed;
}

Task::Task(){
    this->id = std::to_string(std::time(nullptr));
    this->completed = false;
}
void Task::display(){
    std::cout << this->id;
    std::cout << "Tiêu đề :" << this->title << std::endl << "Mức độ ưu tiên : " << this->priority << std::endl
    << "Thời gian :" << this->deadline << std::endl << "Trạng thái :";
    if (this->completed){
        std::cout << "Đã hoàn thành" << std::endl;
    }
    else{
        std::cout << "Chưa hoàn thành" << std::endl;
    }
}



void Task::nhap(){
    std::cout << "Nhập title :";getline(std::cin,this->title);
    std::cout << "Nhập độ ưu tiên :"; std::cin >> this->priority;
    std::cout << "Nhập deadline :"; std::cin >> this->deadline;
    std::cin.ignore();
}
