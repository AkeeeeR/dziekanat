#include "helper.h"

int main(int argc, char*argv[])
{
	student* head = nullptr;
	int counter = 0;   //Licznik przetworzonych student�w
	const string paramIn = "-i";

	if (argc < 2)
	{
		cout << "Podaj parametr" << endl;
		return 0;
	}
	else if (argv[1] == paramIn)
	{
		for (int i = 1; i < argc - 1; i++)
		{
			processFile(head, argv[i + 1], counter);
		}
	}

	saveList(head);	  //Wywo�anie funkcji zapisuj�cej.

	removeStudent(head);   //Wywo�ujemy funkcj� usuwaj�c� zaalokowan� pami��.

	cout << "Przetworzono " << counter << " studentow" << endl;
}