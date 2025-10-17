#include <iostream>
#include "Task.h"
#include <sstream>

size_t Task::Next_id = 0;

std::string getCurrentDateTime(){
    QDateTime now = QDateTime::currentDateTime();
    return now.toString("yyyy-MM--dd HH:mm").toStdString();
}


Task::Task(std::string t, int p,std::string d, bool completed ){
    this->id = ++(Task::Next_id);
    this->title = t;
    this->description = "";
    this->priority = p;
    this->deadline = d;
    this->createdAt = getCurrentDateTime();
    this->updatedAt = getCurrentDateTime();
    this->completed = completed;
    this->category = "";
    this->estimatedHours = 0;
    this->actualHours = 0;
    this->recurrence = "none";
    TransformDeadline(this->deadline);
}

Task::Task(std::string t, std::string desc, int p, std::string d, 
           std::vector<std::string> tags, std::string cat, 
           int estHours, std::string recur, bool completed) {
    this->id = ++(Task::Next_id);
    this->title = t;
    this->description = desc;
    this->priority = p;
    this->deadline = d;
    this->createdAt = getCurrentDateTime();
    this->updatedAt = getCurrentDateTime();
    this->completed = completed;
    this->tags = tags;
    this->category = cat;
    this->estimatedHours = estHours;
    this->actualHours = 0;
    this->recurrence = recur;
    TransformDeadline(this->deadline);
}

Task::Task(){
    this->id = ++(Task::Next_id);
    this->completed = false;
    this->createdAt = getCurrentDateTime();
    this->updatedAt = getCurrentDateTime();
    this->estimatedHours = 0;
    this->actualHours = 0;
    this->recurrence = "none";
}

void Task::setDescription(const std::string& desc){
    this->description = desc;
    updateTimestamp();
}
void Task::addTag(const std::string& tag){
    for (auto &exist_tag : tags){
        if (exist_tag == tag){
            return;
        }
    }
    tags.push_back(tag);
    updateTimestamp();
}


void Task::removeTag(const std::string& tag){
    tags.erase(std::remove(tags.begin(), tags.end(), tag), tags.end());
    updateTimestamp();
}

void Task::setCategory(const std::string& category){
    this->category = category;
    updateTimestamp();
}

void Task::setEstimatedHours(int hours){
    this->estimatedHours = hours;
    updateTimestamp();
}

void Task::setActualHours(int hours){
    this->actualHours = hours;
    updateTimestamp();
}

void Task::setRecurrence(const std::string& recur){
    this->recurrence = recur;
    updateTimestamp();
}

void Task::updateTimestamp(){
    this->updatedAt = getCurrentDateTime();
}


bool Task::isValidDeadline() const{
    if (deadline.length() != 16) return false; // yyyy-mm-dd hh-mm

    QDateTime deadlineDt = QDateTime::fromString(
        QString::fromStdString(deadline),
        "yyyy-MM-dd HH-mm"
    );
    return deadlineDt.isValid(); // neu 30-2 => trả về false
}

bool Task::isOverdue() const{ //kiểm tra xem công việc đã quá hạn (overdue) hay chưa.
    if (completed) return false;

    QDateTime deadlineDT = QDateTime::fromString(
        QString::fromStdString(deadline),
        "yyyy-MM-dd HH-mm"
    );

    QDateTime now = QDateTime::currentDateTime();
    
    return deadlineDT < now;

}

int Task::daysUntilDeadline() const{
    QDateTime deadlineDT = QDateTime::fromString(
        QString::fromStdString(deadline),
        "yyyy-MM-dd HH-mm"
    );
    QDateTime now = QDateTime::currentDateTime();
    return now.daysTo(deadlineDT);
}

double Task::completionPercentage() const {
    if (estimatedHours == 0) return completed ? 100.0 : 0.0;
    return std::min(100.0, (actualHours / static_cast<double>(estimatedHours)) * 100.0);
}





void Task::TransformDeadline(std::string &s){
    // Định dạng deadline YYYY-MM-DD HH-mm
    if (s.length() >= 16){
        if (s[4]!= '-'){
            s.insert(4, "-");
        }
        if (s[7]!= '-'){
            s.insert(7, "-");
        }
        if (s[13]!=':'){
            s.insert(13, ":");
        }
    }
}


std::string Task::toString() const {
    std::stringstream ss;
    ss << id << "|" << title << "|" << description << "|" << priority << "|"
       << deadline << "|" << (completed ? 1 : 0) << "|" << createdAt << "|"
       << updatedAt << "|" << category << "|" << estimatedHours << "|"
       << actualHours << "|" << recurrence;
    
    // Serialize tags
    ss << "|";
    for (size_t i = 0; i < tags.size(); ++i) {
        if (i > 0) ss << ",";
        ss << tags[i];
    }
    
    return ss.str();
}

