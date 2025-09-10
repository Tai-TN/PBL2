#pragma once
#include <string>
#include <vector>
#include <list>

class CustomHashMap{
private:
    std::vector<std::list<std::pair<std::string,int>>> hash;
    int capacity;

    int hashFunction(std::string &key){
        int h = 5381;
        for (char c : key){
            h = (h*33)^c; // Hàm băm djb2
        }
        return h % capacity;
    }

public:
    CustomHashMap(int capacity){
        this->capacity = capacity;
        hash.resize(capacity);
    }
    void insert(){

    }
};