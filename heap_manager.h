#pragma once
#include "Task.h"
#include "Vector.h"


class HeapManager{
private:
    Vector<Task*> maxHeap; // Sắp xếp theo priority
    Vector<Task*> minHeap; // Sắp xếp theo deadline
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
    Vector<Task*> ShowTaskByPriority();
    Vector<Task*> ShowTaskByDeadline();
    void HeapifyTempDownMax(Vector<Task*>&, size_t index);
    void HeapifyTempDownMin(Vector<Task*>&, size_t index);
    Task* getTaskByID(size_t id);
};  