#pragma once
#include "Task.h"
#include <vector>
#include "custom_hashmap.h"


class HeapManager{
private:
    std::vector<Task*> maxHeap; // Sắp xếp theo priority
    std::vector<Task*> minHeap; // Sắp xếp theo deadline
    void HeapifyUpMax(size_t index);
    void HeapifyDownMax(size_t index);
    void HeapifyUpMin(size_t index);
    void HeapifyDownMin(size_t index);
    void RemoveTaskFromMaxHeap(size_t id);
    void RemoveTaskFromMinHeap(size_t id);

public:
    void addTask(Task* task);
    Task* getHighestPriority();
    Task* getEarliestDeadline();
    void removeTask(size_t id);
    bool isEmpty();
    std::vector<Task*> ShowTaskByPriority();
    std::vector<Task*> ShowTaskByDeadline();
    void HeapifyTempDownMax(std::vector<Task*>&, size_t index);
    void HeapifyTempDownMin(std::vector<Task*>&, size_t index);
    Task* getTaskByID(size_t id);
};  