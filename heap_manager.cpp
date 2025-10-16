#include <iostream>
#include "heap_manager.h"
#include <QString>
#include <QWidgetList>


void HeapManager::HeapifyUpMax(size_t index){
    while(index > 0){
        size_t parent = (index-1) / 2;
        if (maxHeap[index]->getPriority() > maxHeap[parent]->getPriority()){
            std::swap(maxHeap[index], maxHeap[parent]);
            index = parent;
        }
        else break;
    }
}
void HeapManager::HeapifyDownMax(size_t index){
    size_t size = maxHeap.size();
    while(true){
        size_t left = 2*index + 1; // Heap bắt đầu bằng chỉ số 0
        size_t right = 2*index + 2;
        size_t largest = index;

        if (left < size && maxHeap[left]->getPriority() > maxHeap[largest]->getPriority()){
            largest = left;
        }
        if (right < size && maxHeap[right]->getPriority() > maxHeap[largest]->getPriority()){
            largest = right;
        }

        if (largest != index){
            std::swap(maxHeap[index],maxHeap[largest]);
            index = largest;
        }
        else break;
    }
}


void HeapManager::HeapifyUpMin(size_t index){
    while(index > 0){
        size_t parent = (index-1) / 2;
        if (minHeap[index]->getDeadline() < minHeap[parent]->getDeadline()){
            std::swap(minHeap[index], minHeap[parent]);
            index = parent;
        }
        else break;
    }
}
void HeapManager::HeapifyDownMin(size_t index){
    size_t size = minHeap.size();
    while(true){
        size_t left = 2*index + 1; // Heap bắt đầu bằng chỉ số 0
        size_t right = 2*index + 2;
        size_t largest = index;

        if (left < size && minHeap[left]->getDeadline() < minHeap[largest]->getDeadline()){
            largest = left;
        }
        if (right < size && minHeap[right]->getDeadline() < minHeap[largest]->getDeadline()){
            largest = right;
        }

        if (largest != index){
            std::swap(minHeap[index],minHeap[largest]);
            index = largest;
        }
        else break;
    }
}

void HeapManager::addTask(Task* task){
    maxHeap.push_back(task);
    HeapifyUpMax(maxHeap.size()-1);
    // them vao max heap
    minHeap.push_back(task);
    HeapifyUpMin(minHeap.size()-1);
}


bool HeapManager::isEmpty(){
    return maxHeap.empty() && minHeap.empty();
}

Task* HeapManager::getEarliestDeadline(){
    if (minHeap.empty()) return NULL;
    return minHeap[0];
}

Task* HeapManager::getHighestPriority(){
    if (maxHeap.empty()) return NULL;
    return maxHeap[0];
}

void HeapManager::RemoveTaskFromMaxHeap(size_t id){
    for (size_t i = 0 ;i<maxHeap.size();i++){
        if (maxHeap[i]->getID() == id){
            maxHeap[i] = maxHeap.back();
            maxHeap.pop_back();
            if(i < maxHeap.size()){
                HeapifyDownMax(i);
                HeapifyUpMax(i);
            }
        return;
        }
    }
}


void HeapManager::RemoveTaskFromMinHeap(size_t id){
for (size_t i = 0 ;i<minHeap.size();i++){
        if (minHeap[i]->getID() == id){
            minHeap[i] = minHeap.back();
            minHeap.pop_back();
            if(i < minHeap.size()){
                HeapifyDownMin(i);
                HeapifyUpMin(i);
            }
        return;
        }
    }
}


void HeapManager::removeTask(size_t id){

    RemoveTaskFromMaxHeap(id);
    RemoveTaskFromMinHeap(id);
    if (maxHeap.size() != minHeap.size()){
        std::cerr << "Error: maxHeap and minHeap are out of sync!" << std::endl;
    }
}


void HeapManager::HeapifyTempDownMax(std::vector<Task*> &temp, size_t index){
    size_t size = temp.size();
    while(true){
        size_t left = 2*index + 1; // Heap bắt đầu bằng chỉ số 0
        size_t right = 2*index + 2;
        size_t largest = index;

        if (left < size && temp[left]->getPriority() > temp[largest]->getPriority()){
            largest = left;
        }
        if (right < size && temp[right]->getPriority() > temp[largest]->getPriority()){
            largest = right;
        }

        if (largest != index){
            std::swap(temp[index],temp[largest]);
            index = largest;
        }
        else break;
    }
}


void HeapManager::HeapifyTempDownMin(std::vector<Task*> &temp, size_t index){
    size_t size = temp.size();
    while(true){
        size_t left = 2*index + 1; // Heap bắt đầu bằng chỉ số 0
        size_t right = 2*index + 2;
        size_t largest = index;

        if (left < size && temp[left]->getDeadline() < temp[largest]->getDeadline()){
            largest = left;
        }
        if (right < size && temp[right]->getDeadline() < temp[largest]->getDeadline()){
            largest = right;
        }

        if (largest != index){
            std::swap(temp[index],temp[largest]);
            index = largest;
        }
        else break;
    }
}
std::vector<Task*> HeapManager::ShowTaskByPriority(){
    std::vector<Task*> temp = maxHeap;
    std::vector<Task*> result;
    while(!temp.empty()){
        Task* top = temp.front();
        result.push_back(top);
        std::swap(temp[0],temp[temp.size()-1]);
        temp.pop_back();
        HeapifyTempDownMax(temp, 0);
    }
    return result;
}


std::vector<Task*> HeapManager::ShowTaskByDeadline(){
    std::vector<Task*> temp = minHeap;
    std::vector<Task*> result;
    while(!temp.empty()){
        Task* top = temp.front();
        result.push_back(top);

        std::swap(temp[0],temp[temp.size()-1]);
        temp.pop_back();
        HeapifyTempDownMin(temp, 0);
    }
    return result;
}

Task* HeapManager::getTaskByID(size_t id){
    for (Task* t : maxHeap){
        if (t->getID() == id){
            return t;
        }
    }
    return nullptr;
}