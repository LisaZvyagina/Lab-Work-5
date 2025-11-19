#include <iostream>
#include<vector>

using namespace std;

class Detail {
protected:
    string name;
    int weight;

    Detail(const string& n, int w) { name = n; weight = w; }

public:
    virtual ~Detail() = default;

    virtual void printInfo() const {
        cout << "Деталь: " << name << ", Вес: " << weight << endl;
    }

    int getWeight() const { return weight; }

    template <typename T, typename ... Args>
    friend T* create(Args&& ... args);
};

class Assembly : public Detail {
protected:
    Assembly(const string& n, int w) : Detail(n, w) {}

public:
    void printInfo() const override {
        cout << "Сборка: " << name << ", Вес: " << weight << endl;
    }

    template <typename T, typename... Args>
    friend T* create(Args&&... args);
};

template <typename T, typename... Args>
T* create(Args&& ... args) {
    return new T(forward<Args>(args)...);
}

int main() {

    setlocale(LC_ALL, "rus");

    vector<Detail*> repository;

    repository.push_back(create<Detail>("Диод", 1));
    repository.push_back(create<Detail>("Микросхема", 10));
    repository.push_back(create<Detail>("Чип памяти", 8));

    repository.push_back(create<Assembly>("Материнская плата", 890));
    repository.push_back(create<Assembly>("Видеокарта", 1250));
    repository.push_back(create<Assembly>("Блок питания", 650));

    cout << "----- СОДЕРЖИМОЕ ХРАНИЛИЩА -----" << endl;
    for (const auto& item : repository) {
        item->printInfo(); 
    }

    cout << endl;
    int totalWeight = 0;
    for (const auto& item : repository) {
        totalWeight += item->getWeight();  
    }
    cout << "Общий вес всех компонентов: " << totalWeight << endl;

    for (auto& item : repository) {
        delete item;
    }
    repository.clear();

    return 0;
}


// ЗАДАНИЕ 2

//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//
//class Base {
//protected:
//    int id;
//
//public:
//    Base(int i) {
//        id = i;
//    }
//    virtual ~Base() = default;
//    virtual void show() const {}
//    virtual Base* clone() const {
//        return new Base(*this);
//    };
//    int getId() const {
//        return id;
//    }
//};
//
//class ConcreteBase : public Base {
//public:
//    ConcreteBase(int i) : Base(i) {}
//
//    void show() const override {
//        cout << "Base ID: " << id << endl;
//    }
//
//    Base* clone() const override {
//        return new ConcreteBase(*this);
//    }
//};
//
//class Derived : public Base {
//public:
//    double value;
//    Derived(int i, double v) : Base(i) {
//        value = v;
//    }
//
//    void show() const override {
//        cout << "Derived ID: " << id << ", Value: " << value << endl;
//    }
//
//    Base* clone() const override {
//        return new Derived(*this);
//    }
//};
//
//void add(vector<Base*>& storage, Base* obj) {
//    storage.push_back(obj->clone());
//}
//
//int main() {
//    setlocale(LC_ALL, "RU");
//    srand(time(0));
//    vector<Base*> storage;
//
//    cout << "Созданные объекты:" << endl;
//    for (int i = 0; i < 6; ++i) {
//        Base* obj = nullptr;
//        int randomNum = rand() % 100;
//
//        cout << "Сгенерировано число: " << randomNum;
//
//        if (randomNum % 2 == 0) {
//            obj = new ConcreteBase(i + 1);
//            cout << " (четное) -> Создан Base: ";
//        }
//        else {
//            obj = new Derived(i + 1, (i + 1) * 2.0);
//            cout << " (нечетное) -> Создан Derived: ";
//        }
//
//        obj->show();
//        add(storage, obj);
//        delete obj;
//    }
//
//    cout << endl << "Данные из хранилища: " << endl;
//    for (size_t i = 0; i < storage.size(); ++i) {
//        cout << "Объект " << i + 1 << " ";
//        storage[i]->show();
//    }
//
//    for (auto obj : storage)
//        delete obj;
//    storage.clear();
//}
