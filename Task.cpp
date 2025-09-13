#include <iostream>
#include "Task.h"

size_t Task::Next_id = 0;

Task::Task(std::string t, int p,std::string d, bool completed ){
    this->id = ++(Task::Next_id);
    this->title = t;
    this->priority = p;
    this->deadline = d;
    TransformDealine(this->deadline);
    this->completed = completed;
}

Task::Task(){
    this->id = ++(Task::Next_id);
    this->completed = false;
}
void Task::display(){
    std::cout << "ID : " << this->id << std::endl;
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
    TransformDealine(this->deadline);
    std::cin.ignore();
}


void Task::TransformDealine(std::string &s){
    // Định dạng deadline YYYY-MM-DD Giờ
    if (s[7]!='-'){
        s.insert(5,"0");
    }
    if (s[9] == ' '){
        s.insert(8,"0");
    }
}