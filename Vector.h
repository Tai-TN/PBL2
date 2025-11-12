// #include "Task.h"
// #include <iostream>
// using namespace std;
// class Vector {
//     private:

//         int capacity;// sức chứa
//         int size;// số phần tử hiện tại
//         Task* arr;// con trỏ của mảng

//     public:

//         Vector();// tạo vector không có tham số
//         Vector(int capacity);// tạo vector có sức chứa ban dầu
//         Vector(const Vector& other);// hàm tạo với vector có sẵn
//         ~Vector();// hàm hủy

//         bool empty();// hàm kiểm tra rỗng
//         bool full();// hàm kiểm tra đầy
//         void push_back(const Task& T);// đẩy phần tử vào cuối
//         void pop_back();// xóa phẩn tử ở cuối
//         int getSize();// lấy size vector

//         Task& operator[](int index);// nạp chồng toán tử lấy vị trí

//         Vector(const Vector& other);// hàm tạo với vector có sẵn
//         Vector& operator=(const Vector& other);//nạp chông toán tử gán


// };