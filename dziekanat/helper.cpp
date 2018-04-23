#include "helper.h"

void processFile(student* &head, const string &fileName, int &counter)
{
	ifstream file;
	string subject;
	string teacher;
	string row;

	file.open(fileName);   //Wczytywanie protoko³ów z parametru.

	if (!file.good())
		cout << "Nie udalo sie odczytac pliku" << endl;   //Sprawdzanie poprawnoœci odczytu protoko³ów.

	getline(file, subject);    //Pobiera pierwsz¹ linikê w pliku .txt.
	getline(file, teacher);    //Pobiera drug¹ linikê w pliku .txt.

							   /*Pêtla while, która czyta plik .txt, zapisuje go tymczasowo do zmiennej pomocniczej buf,
							   a nastêpnie zapisuje wyraz po wyrazie do kolejnych zmiennych (przyjmuje, ¿e po spacji jest kolejny wyraz).*/

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
		addOrUpdateStudent(head, name, surname, idNumber, teacher, subject, grade, date);  //Dodawanie do/lub uzupe³nianie listy jednokierunkowej.

		counter++; //Inkrementacja licznika przetworzonych studentów.
	}

	file.close(); //Funkcja zamykaj¹ca otwarty plik .txt.
}