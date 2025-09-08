#include <iostream>
#include "Task.h"

Task::Task(std::string t, int p,std::string d, bool completed ){
    this->title = t;
    this->priority = p;
    this->deadline = d;
    this->completed = completed;
}

void Task::display(){
    std::cout << "Tiêu đề :" << this->title << std::endl << "Mức độ ưu tiên : " << this->priority << std::endl
    << "Thời gian :" << this->deadline << std::endl << "Trạng thái :";
    if (this->completed){
        std::cout << "Đã hoàn thành" << std::endl;
    }
    else{
        std::cout << "Chưa hoàn thành" << std::endl;
    }
}

Task::~Task(){

}
