#include "Vector.h"

Vector :: Vector() :  capacity(100), size(0){// hàm tạo không có tham số
    arr = new Task[capacity];
}

Vector :: Vector(int capacity) : size(0), capacity(capacity){// hàm tạo có tham số kích cỡ
    arr = new Task[capacity];
}

Vector :: Vector(const Vector& other) : size(other.size), capacity(other.capacity) {// hàm tạo với tham số là vector
    arr = new Task[capacity];
    for (int i = 0; i < size; i++) arr[i] = other.arr[i];
}

Vector :: ~Vector(){// hàm hủy
    delete[] arr;
}

bool Vector :: empty(){// hàm kiểm tra rỗng
    return size == 0;
}

int Vector :: getSize(){
    return this -> size;
}

bool Vector :: full(){// hàm kiểm tra đầy
    return size == capacity;
}

void Vector :: push_back(const Task& T){// hàm đẩy vào vector
    if(full()){
        Task* NewV = new Task[capacity * 2];
        for (int i = 0 ; i < size ; i++){
            *(NewV + i) = *(arr + i);
        }
        delete[] arr;
        arr = NewV;
        capacity *= 2;
    }
    arr[size++] = T;
}

void Vector :: pop_back(){// hàm xóa vị trí cuối
    if(empty()){
        cout << "Loi! Vector dang rong." << endl;
        return;
    }
    size--;
}

Task& Vector :: operator[](int index) {
    if (index < 0 || index >= size) {
        cout << "Loi! Vi tri khong hop le." << endl;
        static Task Temp("", 0, "00:00 00/00/0000", 0);
        return Temp;
    }
    return arr[index];
}

Vector& Vector :: operator=(const Vector& other) {
    if (this == &other) return *this;
    delete[] arr;
    size = other.size;
    capacity = other.capacity;
    arr = new Task[capacity];
    for (int i = 0; i < size; i++) arr[i] = other.arr[i];
    return *this;
}

