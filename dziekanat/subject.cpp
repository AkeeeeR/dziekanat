#include "subject.h"

void addSubject(studentNode* &root, const string& teacher, const string& subject, const float& grade, const string& date)
{
	if (!root)
		root = new studentNode{ teacher, subject, grade, date, nullptr, nullptr };
	else
	{
		studentNode* pom = root;
		while (true)
		{
			if (subject < pom->subject)
			{
				if (!pom->left)
				{
					pom->left = new studentNode{ teacher, subject, grade, date, nullptr, nullptr };
					return;
				}
				pom = pom->left;
			}
			else
			{
				if (!pom->right)
				{
					pom->right = new studentNode{ teacher, subject, grade, date, nullptr, nullptr };
					return;
				}
				pom = pom->right;
			}
		}
	}
}

/*Funkcja printSubject zapisuje do pliku zawarto�� drzewka rekurencyjnie.
Wywo�ujemy j� w funkcji saveList w celu dopisania m.in. przedmiot�w i ocen do pliku.*/

void printSubject(ofstream *file, studentNode* root)
{
	if (root)
	{
		printSubject(file, root->right);

		*file << root->teacher << " " << root->subject << " " << root->grade << " " << root->date << "\n";

		printSubject(file, root->left);

	}
}

//Funkcja removeNode usuwaj�ca zaalokowan� pami�� przez drzewko.

void removeNode(studentNode* &root)
{
	if (root != nullptr)
	{
		removeNode(root->left);
		removeNode(root->right);
		delete root;
		root = nullptr;
	}
}