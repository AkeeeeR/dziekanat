#include "helper.h"

void processFile(student* &head, const string &fileName, int &counter)
{
	ifstream file;
	string subject;
	string teacher;
	string row;

	file.open(fileName);   //Wczytywanie protoko��w z parametru.

	if (!file.good())
		cout << "Nie udalo sie odczytac pliku" << endl;   //Sprawdzanie poprawno�ci odczytu protoko��w.

	getline(file, subject);    //Pobiera pierwsz� linik� w pliku .txt.
	getline(file, teacher);    //Pobiera drug� linik� w pliku .txt.

							   /*P�tla while, kt�ra czyta plik .txt, zapisuje go tymczasowo do zmiennej pomocniczej buf,
							   a nast�pnie zapisuje wyraz po wyrazie do kolejnych zmiennych (przyjmuje, �e po spacji jest kolejny wyraz).*/

	while (getline(file, row))
	{
		studentNode* studentNode = nullptr;
		string name;
		string surname;
		int idNumber;
		float grade;
		string date;

		istringstream buf(row);
		buf >> name;
		buf >> surname;
		buf >> idNumber;
		buf >> grade;
		buf >> date;
		cout << grade << " " << date << endl;
		addOrUpdateStudent(head, name, surname, idNumber, teacher, subject, grade, date);  //Dodawanie do/lub uzupe�nianie listy jednokierunkowej.

		counter++; //Inkrementacja licznika przetworzonych student�w.
	}

	file.close(); //Funkcja zamykaj�ca otwarty plik .txt.
}