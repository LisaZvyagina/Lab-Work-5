#include<iostream>
#include<ctime>
using namespace std;


int main() 
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	cout << "Введите количество чисел в массиве: " << endl;
	int size;
	cin >> size;
	while (size <= 0) {
		cout << "Размер массива не может быть <= 0. Введите новое число: " << endl;
		cin >> size;
	}

	short* arr = new short[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
	}
	cout << "Элементы массива: ";

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "Адрес начала массива: " << arr << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "Расстояние " << i << "-го элемента массива в памяти от начала массива - " << (char*)(&arr[i]) - (char*)(arr) << " байт(-а)" << endl;
	}

	delete[] arr;
}


//int main()
//{
//	setlocale(LC_ALL, "rus");
//	srand(time(NULL));
//
//	double arr[10] = {};
//	cout << "Заполните массив 10-ю элементами: " << endl;
//
//	for (int i = 0; i < 10; i++)
//	{
//		double n;
//		cin >> n;
//		arr[i] = n;
//	}
//
//	cout << "Элементы массива: ";
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//
//	cout << "Адрес начала массива: " << arr << endl;
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << "Расстояние " << i << "-го элемента массива в памяти от начала массива - " << (char*)(&arr[i]) - (char*)(arr) << " байт(-а)" << endl;
//	}
//
//}

//int main()
//{
//	setlocale(LC_ALL, "rus");
//	srand(time(NULL));
//
//	short arr[10] = {};
//	cout << "Заполните массив 10-ю элементами: " << endl;
//
//	for (int i = 0; i < 10; i++)
//	{
//		short n;
//		cin >> n;
//		arr[i] = n;
//	}
//
//	cout << "Элементы массива: ";
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//
//	cout << "Адрес начала массива: " << arr << endl;
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << "Расстояние " << i << "-го элемента массива в памяти от начала массива - " << (char*)(&arr[i]) - (char*)(arr) << " байт(-а)" << endl;
//	}
//
//}