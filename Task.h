#pragma once
#include <string>
#include <ctime>
class Task{
private:
    static size_t Next_id;
    size_t id;
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

    size_t getID(){return id;}
    std::string getTitle(){return title;}
    int getPriority(){return priority;}
    std::string getDeadline(){return deadline;}
    bool isCompleted(){return completed;}
    void setCompleted(bool c){completed = c;}
    void TransformDealine(std::string &s);

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