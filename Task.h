#pragma once
#include <string>
#include <ctime>
#include <QDateTime>

class Task{
private:
    static size_t Next_id;
    size_t id;
    std::string title;
    std::string description;
    int priority;
    std::string deadline;
    std::string createdAt;
    std::string updatedAt;
    bool completed;
    std::string category;
    std::string recurrence;// lặp lại ngày, tuần , tháng ...vv

public:
    Task();
    Task(std::string t, int p,std::string d, bool completed = false);
    Task(std::string t, std::string description, int p, std::string d, std::string cate = "",
    /*nt estHours = 0,*/ std::string recur = "none", bool completed = false);

    virtual ~Task(){}

    

    // new
    void setDescription(const std::string& desc);
    void setCategory(const std::string& category);
    // void setEstimatedHours(int hours);
    // void setActualHours(int hours);
    void setRecurrence(const std::string& recur);
    void updateTimestamp();


    bool isValidDeadline() const; // kiểm tra deadline hợp lệ chưa
    bool isOverdue() const; // kiểm tra quá hạn hay chưa
    int daysUntilDeadline() const; // kiểm tra số ngày còn lại hay số ngày quá hạn

    //getter
    std::string getDescription() const { return description; }
    std::string getCreatedAt() const { return createdAt; }
    std::string getUpdatedAt() const { return updatedAt; }
    std::string getCategory() const { return category; }
    //int getEstimatedHours() const { return estimatedHours; }
    //int getActualHours() const { return actualHours; }
    std::string getRecurrence() const { return recurrence; }
    


    size_t getID(){return id;}
    std::string getTitle(){return title;}
    int getPriority(){return priority;}
    std::string getDeadline(){return deadline;}
    bool isCompleted(){return completed;}
    
    
    void setCompleted(bool c){
        completed = c;
        updateTimestamp();
    }
    void setTitle(const std::string& t){
        title = t;
        updateTimestamp();
    }
    void setPriority(int p){
        priority = p;
        updateTimestamp();
    }
    void TransformDeadline(std::string &s);
    void setDeadline(const std::string& dead){
        deadline = dead;
        TransformDeadline(deadline);
        updateTimestamp();
    }
    

    std::string toString() const; // chuyển định dạng để lưu vào file


};
