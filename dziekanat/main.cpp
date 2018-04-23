#include "helper.h"

int main(int argc, char*argv[])
{
	student* head = nullptr;
	int counter = 0;   //Licznik przetworzonych studentów
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

	saveList(head);	  //Wywo³anie funkcji zapisuj¹cej.

	removeStudent(head);   //Wywo³ujemy funkcjê usuwaj¹c¹ zaalokowan¹ pamiêæ.

	cout << "Przetworzono " << counter << " studentow" << endl;
}