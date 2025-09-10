#pragma once
#include <string>
#include <ctime>
class Task{
private:
    std::string id;
    std::string title;
    int priority;
    std::string deadline;
    bool completed;
public:
    Task();
    Task(std::string t, int p,std::string d, bool completed = false);
    void nhap();
    virtual void display();
    virtual ~Task(){}


    std::string getTitle(){return title;}
    int getPriority(){return priority;}
    bool isCompleted(){return completed;}
    void setCompleted(bool c){completed = c;}

};

// class UrgentTask : public Task{ // Task uu tien cao
// public:
//     UrgentTask(std::string t, int p,std::string d, bool completed = false);
//     void display() override;
// };

// class RegularTask : public Task{ // Task uu tien binh thuong
// public:
//     RegularTask(std::string t, int p,std::string d, bool completed = false);
//     void display() override;
// };