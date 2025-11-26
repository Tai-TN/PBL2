#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Vector {
    private:

        int capacity;// sức chứa
        int m_size;// số phần tử hiện tại
        T* arr;// con trỏ của mảng

    public:

        Vector();// tạo vector không có tham số
        Vector(int capacity);// tạo vector có sức chứa ban dầu
        Vector(const Vector& other);// hàm tạo với vector có sẵn
        
        ~Vector();// hàm hủy
        T* begin();
        T* end();
        const T* begin() const;
        const T* end() const;
        bool empty();// hàm kiểm tra rỗng
        bool full();// hàm kiểm tra đầy
        void push_back(const T& t);// đẩy phần tử vào cuối
        void pop_back();// xóa phẩn tử ở cuối
        int size() const;// lấy size vector
        T& back();
        T& front();

        T& operator[](int index);// nạp chồng toán tử lấy vị trí
        Vector& operator=(const Vector& other);//nạp chông toán tử gán
        Vector(int , int);
};

/*for (Task* t : T) sẽ dịch thành T.begin(),  T.end(), it++ => nên cần có hàm trả về begin và end*/



template <typename T>
Vector<T>::Vector() :  capacity(100), m_size(0){// hàm tạo không có tham số
    arr = new T[capacity];
}
template <typename T>

Vector<T>::Vector(int capacity) : m_size(0), capacity(capacity){// hàm tạo có tham số kích cỡ
    arr = new T[capacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) : m_size(other.m_size), capacity(other.capacity) {// hàm tạo với tham số là vector
    arr = new T[capacity];
    for (int i = 0; i < m_size; i++) arr[i] = other.arr[i];
}



template <typename T>
Vector<T>:: ~Vector(){// hàm hủy
    delete[] arr;
}

template <typename T>
bool Vector<T> :: empty(){// hàm kiểm tra rỗng
    return m_size == 0;
}

template <typename T>
int Vector<T>::size() const{
    return this -> m_size;
}

template <typename T>
bool Vector<T>:: full(){// hàm kiểm tra đầy
    return m_size == capacity;

}

template <typename T>
void Vector<T>:: push_back(const T& t){// hàm đẩy vào vector
    /*Khi pushback mà hết chỗ thì cấp lại vùng nhớ rộng hơn (capacity*2) copy dữ liệu từ mảng cữ sang, giải phóng mảng cũ và
    cho con trỏ trỏ đến mản mới*/
    if(full()){
        T* NewV = new T[capacity * 2];
        for (int i = 0 ; i < m_size ; i++){
            *(NewV + i) = *(arr + i);
        }
        delete[] arr;
        arr = NewV;
        capacity *= 2;
    }
    arr[m_size++] = t;
}
template <typename T>

void Vector<T>:: pop_back(){// hàm xóa vị trí cuối
    if(empty()){
        cout << "Loi! Vector dang rong." << endl;
        return;
    }
    m_size--;
}

template <typename T>
T& Vector<T>::operator[](int index) {
    if (index < 0 || index >= m_size) {
        cout << "Loi! Vi tri khong hop le." << endl;
        static T temp{};
        return temp;
    }
    return arr[index];
}

template <typename T>
Vector<T>& Vector<T> :: operator=(const Vector<T>& other) {
    if (this == &other) return *this;
    delete[] arr;
    m_size = other.m_size;
    capacity = other.capacity;
    arr = new T[capacity];
    for (int i = 0; i < m_size; i++) arr[i] = other.arr[i];
    return *this;
}

template <typename T>
T& Vector<T>::back(){
    if (empty()){
        std::cout << "Vector rong" << std::endl;
        static T temp{};
        return temp;
    }
    return arr[m_size - 1];
}

template <typename T>
T& Vector<T>::front(){
    if (empty()){
        std::cout << "Vector rong" << std::endl;
        static T temp{};
        return temp;
    }
    return arr[0];
}

template <typename T>
T* Vector<T>::begin(){
    return arr;
}

template <typename T>
T* Vector<T>::end(){
    return arr + m_size;
}

template <typename T>
const T* Vector<T>::begin() const{
    return arr;
}

template <typename T>
const T* Vector<T>::end() const{
    return arr + m_size;
}

template <typename T>
Vector<T>::Vector(int size, int value)
    : capacity(100), m_size(size)
    {   
        arr = new T[capacity];
        for (int i = 0; i< size; i++){
            arr[i] = value;
        }
    }