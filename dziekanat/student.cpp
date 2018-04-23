#include "student.h"

//Funkcja addOrUpdateStudent tworzy nowy element listy jednokierunkowej (nowego studenta) lub aktualizuje istniej�cego.

void addOrUpdateStudent(student* &head, const string& name, const string& surname, const int& idNumber, const string& teacher, const string& subject, const float& grade, const string& date)
{
	if (!head)   //Sprawdzamy czy istnieje pierwszy element listy, je�li nie, to:
	{
		head = new student{ name, surname, idNumber, nullptr };		//Dodajemy pierwszy element listy(pierwszego studenta).
		addSubject(head->subjects, teacher, subject, grade, date);	//Przypisujemy mu drzewko przedmiot�w i ocen.
	}
	else
	{
		student* temp = head;	//Tworzymy zmienn� pomocnicz�.
		while (temp->next && temp->idNumber != idNumber)
			temp = temp->next;

		if (temp->idNumber != idNumber)
		{
			//Dodawanie nowego studenta na koniec listy.
			temp->next = new student{ name, surname, idNumber, nullptr };
			addSubject(temp->next->subjects, teacher, subject, grade, date);
		}
		else
		{
			//Zaktualizowanie istniej�cego ju� studenta.
			addSubject(temp->subjects, teacher, subject, grade, date);
		}
	}
}

/*Funkcja saveList tworzy i zapisuje zawarto�� ka�dego elementu z listy do nowego pliku .txt.
Tworzy tyle plik�w wyj�ciowych, ile znajduje si� student�w w protoko�ach wej�ciowych.
Nazwa pliku .txt jest to�sama z numerem albumu danego studenta.*/

void saveList(student* head)
{
	stringstream ss;  //Zmienna pomocnicza.
	ofstream file;
	while (head)
	{
		ss << head->idNumber;    //Do stworzenia nazwy przekazujemy numer albumu studenta.
		ss << ".txt";    //Tworzymy plik z rozszerzeniem .txt
		file.open(ss.str());    //Otwieramy plik.

		file << head->name << " " << head->surname << endl;
		file << head->idNumber << endl << endl;		//Zapisujemy do pliku imi�, nazwisko i numer albumu.

		if (head->subjects)
		{
			printSubject(&file, head->subjects);    //Dopisujemy do studenta drzewko przedmiot�w i ocen.
		}

		ss.str("");   //Czyszczenie bufora.

		file.close();	  //Zamykamy otwarty plik.
		head = head->next;	  //Ustawiamy wska�nik head na nast�pny, a� natrafimy na koniec listy.
	}
	cout << "\n";
}

/*Funkcja removeStudent usuwa po kolei elementy jednokierunkowej listy (najpierw usuwa drzewko, a nast�pnie sam element listy),
zwalniaj�c zaalokowan� pami��.*/

void removeStudent(student* &head)
{
	while (head)
	{
		student* tmp = head;
		head = head->next;
		removeNode(tmp->subjects);
		delete tmp;
	}
}