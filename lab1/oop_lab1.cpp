#include <iostream>
#include <vector>
using namespace std;

//class Book
//{
//public:
//	string author;
//	string name;
//	bool type;
//
//	Book(string author1, string name1, bool type1) : author(author1), name(name1), type(type1) {}
//
//};
//
//
//void addBook(vector<Book>& books, string author, string name, bool type) {
//	if (author.empty()) {
//		cout << "У книги не указан автор. Она не будет добавлена в библиотеку. " << endl;
//		return;
//	}
//	if (name.empty()) {
//		cout << "У книги не указано название. Она не будет добавлена в библиотеку. " << endl;
//		return;
//	}
//	books.push_back(Book(author, name, type));
//}
//
//void If_Else(vector<Book>& books) {
//	int fiction = 0;
//	int technical = 0;
//	for (const auto& Book : books)
//	{
//		if (Book.type == true)
//		{
//			fiction += 1;
//		}
//		else
//		{
//			technical += 1;
//		}
//	}
//
//	cout << "С помощью конструкции if/else: " << endl;
//	cout << "Количество художественной литературы:  " << fiction << endl;
//	cout << "Количество технической литературы: " << technical << endl;
//}
//
//void oper_switch(vector<Book>& books) {
//	int fiction_s = 0;
//	int technical_s = 0;
//
//	for (const auto& Book : books)
//	{
//		switch (Book.type)
//		{
//		case true:
//			fiction_s += 1;
//			break;
//		case false:
//			technical_s += 1;
//			break;
//		}
//	}
//	cout << "С помощью оператора switch: " << endl;
//	cout << "Количество художественной литературы: " << fiction_s << endl;
//	cout << "Количество технической литературы: " << technical_s << endl;
//
//}
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	vector<Book> books;
//
//	addBook(books, "Н.В.Гоголь", "Ревизор", true);
//	addBook(books, "", "Метель", true);
//	addBook(books, "А.С.Пушкин", "", true);
//	addBook(books, "Д.А.Бадугин", "Электроавтоматика ПК", false);
//
//	cout << endl;
//	cout << "Библиотека: " << endl;
//	for (const auto& Book : books)
//	{
//		cout << "Автор: " << Book.author << " Название книги: " << Book.name << " Тип: " << Book.type << endl;
//	}
//	cout << endl;
//	If_Else(books);
//	cout << endl;
//	oper_switch(books);
//
//}

class Book
{
public:
	string author;
	string name;

	enum class Genre { FICTION, TECHNICAL };
	Genre genre;

	Book(string author1, string name1, Genre genre1) : author(author1), name(name1), genre(genre1) {}

	string getGenreName() const {
		if (genre == Genre::FICTION)
		{
			return "Художественная";
		}
		else
		{
			return "Техническая";
		}
	}
};


void addBook(vector<Book>& books, string author, string name, Book :: Genre genre) {
	if (author.empty()) {
		cout << "У книги не указан автор. Она не будет добавлена в библиотеку. " << endl;
		return;
	}
	if (name.empty()) {
		cout << "У книги не указано название. Она не будет добавлена в библиотеку. " << endl;
		return;
	}
	books.push_back(Book(author, name, genre));
}

void If_Else(vector<Book>& books) {
	int fiction = 0;
	int technical = 0;
	for (const auto& Book : books)
	{
		if (Book.genre == Book::Genre::FICTION) 
		{
			fiction += 1;
		}
		else 
		{
			technical += 1;
		}
	}

	cout << "С помощью конструкции if/else: " << endl;
	cout << "Количество художественной литературы:  " << fiction << endl;
	cout << "Количество технической литературы: " << technical << endl;
}

void oper_switch(vector<Book>& books) {
	int fiction_s = 0;
	int technical_s = 0;

	for (const auto& Book : books)
	{
		switch (Book.genre)
		{
		case Book :: Genre :: FICTION:
			fiction_s += 1;
			break;
		case Book :: Genre :: TECHNICAL:
			technical_s += 1;
			break;
		}
	}
	cout << "С помощью оператора switch: " << endl;
	cout << "Количество художественной литературы: " << fiction_s << endl;
	cout << "Количество технической литературы: " << technical_s << endl;

}

// int main()
// {
// 	setlocale(LC_ALL, "rus");
// 	vector<Book> books;

// 	addBook(books, "Н.В.Гоголь", "Ревизор", Book :: Genre :: FICTION);
// 	addBook(books, "", "Метель", Book::Genre::FICTION);
// 	addBook(books, "А.С.Пушкин", "", Book::Genre::FICTION);
// 	addBook(books, "Д.А.Бадугин", "Электроавтоматика ПК", Book::Genre::TECHNICAL);

// 	cout << endl;
// 	cout << "Библиотека: " << endl;
// 	for (const auto& Book : books)
// 	{
// 		cout << "Автор: " << Book.author << " Название книги: " << Book.name << " Тип: " << Book.getGenreName() << endl;
// 	}
// 	cout << endl;
// 	If_Else(books);
// 	cout << endl;
// 	oper_switch(books);

// }
