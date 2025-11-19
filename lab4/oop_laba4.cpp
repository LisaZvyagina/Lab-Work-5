#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class ProgramError {
protected:
     string message;
public:
    ProgramError(const  string& msg = "Ошибка программы") : message(msg) {}
    virtual void print() const {
         cout << "Ошибка: " << message <<  endl;
    }
    virtual ~ProgramError() = default;
};


class MemoryAccessError : public ProgramError {
public:
    MemoryAccessError() : ProgramError("Ошибка доступа к памяти") {}
};

class DivisionByZeroError : public ProgramError {
public:
    DivisionByZeroError() : ProgramError("Деление на ноль") {}
};

class OverflowError : public ProgramError {
public:
    OverflowError() : ProgramError("Переполнение") {}
};


template <typename T>
class PointerArray {
private:
    T** data;
    size_t size;
    size_t capacity;

public:
    PointerArray(size_t cap = 5) : capacity(cap), size(0) {
        if (cap == 0) throw  logic_error("Нулевая вместимость");
        data = new T * [capacity]();
    }

    ~PointerArray() {
        for (size_t i = 0; i < size; ++i) delete data[i];
        delete[] data;
    }

   
    T*& operator[](size_t index) {
        if (index >= capacity) throw  out_of_range("Индекс за границами");
        if (index >= size) throw  logic_error("Элемент не инициализирован");
        return data[index];
    }

    
    void add(T* element) {
        if (!element) throw  logic_error("Нулевой указатель");
        if (size >= capacity) throw  logic_error("Массив переполнен");
        data[size++] = element;
    }


    void printAll() const {
        if (size == 0) throw  logic_error("Массив пуст");
        for (size_t i = 0; i < size; ++i) {
             cout << "[" << i << "] ";
            data[i]->print();
        }
    }

    size_t getSize() const { return size; }
};


void demoLogicError() {
     cout << "\nЛогистические ошибки в коде программы: \n " <<  endl;

    try {
        PointerArray<int> arr(0);
    }
    catch (const  logic_error& e) {
         cout << "Пойман: " << e.what() <<  endl;
    }


    PointerArray<ProgramError> errors(3);


    try {
        errors.add(new MemoryAccessError());
        errors.add(new DivisionByZeroError());
        errors.add(new OverflowError());

        errors.add(nullptr);
    }
    catch (const  logic_error& e) {
         cout << "Пойман: " << e.what() <<  endl;
    }


    errors.printAll();

    try {
         cout << "\nДоступ к элементам: \n" <<  endl;
        errors[0]->print();
        errors[1]->print();

        errors[10]->print();
    }
    catch (const  exception& e) {
         cout << "Исключение: " << e.what() <<  endl;
    }


    try {
        PointerArray<int> arr(3);
        arr.add(new int(42));
         cout << "Элемент 0: " << *arr[0] <<  endl;
         cout << "Элемент 1: " << *arr[1] <<  endl; 
    }
    catch (const  logic_error& e) {
         cout << "Пойман: " << e.what() <<  endl;
    }
}


class SimpleClass {
private:
    int value;
public:
    SimpleClass(int v = 0) : value(v) {
        if (v < 0) throw  logic_error("Отрицательное значение");
    }
    void print() const {
         cout << "SimpleClass: " << value <<  endl;
    }
};

void demoWithSimpleClass() {
     cout << "\nSimpleClass: \n " <<  endl;

    PointerArray<SimpleClass> simpleArr(2);

    try {
        simpleArr.add(new SimpleClass(10));
        simpleArr.add(new SimpleClass(20));

        simpleArr.add(new SimpleClass(-5));
    }
    catch (const  logic_error& e) {
         cout << "Пойман: " << e.what() <<  endl;
    }

    simpleArr.printAll();
}

int main() {
    setlocale(LC_ALL, "rus");

    demoLogicError();
    demoWithSimpleClass();

    return 0;
}








//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// Базовый класс ошибок
//class ProgramError {
//public:
//    virtual void print() const {
//        cout << "Ошибка программы" << endl;
//    }
//    virtual ~ProgramError() = default;
//};
//
//// Конкретные классы ошибок
//class MemoryAccessError : public ProgramError {
//public:
//    void print() const override {
//        cout << "Ошибка доступа к памяти" << endl;
//    }
//};
//
//class DivisionByZeroError : public ProgramError {
//public:
//    void print() const override {
//        cout << "Деление на ноль" << endl;
//    }
//};
//
//class OverflowError : public ProgramError {
//public:
//    void print() const override {
//        cout << "Переполнение" << endl;
//    }
//};
//
//
//template <typename T>
//class PointerArray {
//private:
//    T** data;
//    size_t size;
//    size_t capacity;
//
//public:
//    PointerArray(size_t cap = 5) : capacity(cap), size(0) {
//        data = new T * [capacity];
//        for (size_t i = 0; i < capacity; i++) {
//            data[i] = nullptr;
//        }
//    }
//
//    ~PointerArray() {
//        for (size_t i = 0; i < size; ++i) {
//            delete[] data;
//        }
//    }
//
//    T*& operator[](size_t index) {
//        return data[index];
//    }
//
//    void add(T* element) {
//        if (size < capacity) {
//            data[size++] = element;
//        }
//    }
//
//    void printAll() const {
//        for (size_t i = 0; i < size; ++i) {
//            cout << "[" << i << "] ";
//            data[i]->print();
//        }
//    }
//
//    size_t getSize() const { return size; }
//    size_t getCapacity() const { return capacity; }
//};
//
//class SimpleClass {
//private:
//    int value;
//public:
//    SimpleClass(int v = 0) : value(v) {}
//    void print() const {
//        cout << "SimpleClass: " << value << endl;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "rus");
//
//    cout << "Работа с ошибками" << endl;
//
//    PointerArray<ProgramError> errors(3);
//    errors.add(new MemoryAccessError());
//    errors.add(new DivisionByZeroError());
//    errors.add(new OverflowError());
//
//    cout << "Содержимое массива ошибок:" << endl;
//    errors.printAll();
//
//    cout << "\nДоступ через оператор []:" << endl;
//    cout << "Элемент 0: ";
//    (*errors[0]).print();
//    cout << "Элемент 1: ";
//    (*errors[1]).print();
//
//    cout << "\nSimpleClass" << endl;
//
//    PointerArray<SimpleClass> simpleArr(2);
//    simpleArr.add(new SimpleClass(10));
//    simpleArr.add(new SimpleClass(20));
//
//    simpleArr.printAll();
//
//    return 0;
//}