#pragma once
#include "Task.h"
#include <vector>
#include "custom_hashmap.h"


class HeapManager{
private:
    std::vector<Task*> maxHeap;// theo do uu tien
    std::vector<Task*> minHeap;//theo dealine
    
};  