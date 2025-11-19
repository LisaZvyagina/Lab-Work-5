//#include <iostream>
//#include<string>
//#include <windows.h>
//using namespace std;
//
//class Publication {
//public:
//	string name;
//	float price;
//
//	virtual void getdata() {
//		cout << "Введите название книги: " << endl;
//		getline(cin, name);                          
//		cout << "Введите цену книги: " << endl;
//		cin >> price;
//	}
//	
//	virtual void putdata() {
//		cout << "Название книги: " << name << endl;
//		cout << "Цена книги: " << price << endl;
//	}
//
//	virtual ~Publication() {}
//};
//
//class Book : public Publication {
//private:
//	int pages;
//public:
//	void getdata() override {
//		Publication::getdata();
//		cout << "Введите количество страниц в книге: " << endl;
//		cin >> pages;
//	}
//
//	void putdata() override {
//		Publication::putdata();
//		cout << "Количество страниц в книге: " << pages << endl;
//	}
//};
//
//class Type : public Publication {
//private:
//	float time;
//public:
//	void getdata() override {
//		Publication::getdata();
//		cout << "Введите время записи книги в минутах: " << endl;
//		cin >> time;
//
//	}
//
//	void putdata() override {
//		Publication::putdata();
//		cout << "Время записи книги в минутах: " << time << endl;
//	}
//};
//
//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	Publication* one = new Book();
//	Publication* two = new Type();
//
//	cout << "Книга" << endl;
//	one->getdata();
//	cin.ignore();
//	cout << endl << "Аудиокнига: " << endl;
//	two->getdata();
//	cin.ignore();
//
//	cout << endl << "----- Результат -----" << endl;
//	cout << "Книга: " << endl;
//	one->putdata();
//	cout << endl << "Аудиокнига: " << endl;
//	two->putdata();
//
//	delete one;
//	delete two;
//	return 0;
//}


#include <iostream>
#include<string>
#include <windows.h>
using namespace std;


class Sales {
public:
	float total_coast[3];

	virtual void getdata() {
		cout << "Введите общую стоимость проданных книг за: " << endl;
		for (int i = 0; i < 3; i++) {
			cout << "Месяц #" << i + 1 << ": ";
			cin >> total_coast[i];
		}
	}
	virtual void putdata() {
		for (int i = 0; i < 3; i++) {
			cout << "Общая стоимость проданных книг за месяц #" << i + 1 << ": " << total_coast[i] << endl;
		}
	}

	virtual ~Sales() {}
};


class Publication {
public:
	string name;
	float price;

	virtual void getdata() {
		cout << "Введите название книги: " << endl;
		getline(cin, name);                           
		cout << "Введите цену книги: " << endl;
		cin >> price;
	}

	virtual void putdata() {
		cout << "Название книги: " << name << endl;
		cout << "Цена книги: " << price << endl;
	}

	virtual ~Publication() {}
};

class Book : public Publication, public Sales  {
private:
	int pages;
public:
	void getdata() override {
		Publication::getdata();
		Sales::getdata();
		cout << "Введите количество страниц в книге: " << endl;
		cin >> pages;
	}

	void putdata() override {
		Publication::putdata();
		Sales::putdata();
		cout << "Количество страниц в книге: " << pages << endl;
	}
};

class Type : public Publication, public Sales {
private:
	float time;
public:
	void getdata() override {
		Publication::getdata();
		Sales::getdata();
		cout << "Введите время записи книги в минутах: " << endl;
		cin >> time;
	}

	void putdata() override {
		Publication::putdata();
		Sales::putdata();
		cout << "Время записи книги в минутах: " << time << endl;
	}
};

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Book* one = new Book();
	Type* two = new Type();

	cout << "Книга" << endl;
	one->getdata();
	cin.ignore();
	cout << endl << "Аудиокнига: " << endl;
	two->getdata();
	cin.ignore();

	cout << endl << "----- Результат -----" << endl;
	cout << "Книга: " << endl;
	one->putdata();
	cout << endl << "Аудиокнига: " << endl;
	two->putdata();

	delete one;
	delete two;
	return 0;
}