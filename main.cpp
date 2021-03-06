#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Repository.h"

using namespace std;

Repository * createRepository();
Repository * openRepository();
bool addPersonne(Repository *);
bool searchPersonne(Repository *);
void printRepository(Repository *);

int main()
{
	Repository * current = NULL;

	cout << "ANNUAIRE :)" << endl;

	int i = -1;
	bool flag = true;

	while(flag)
	{
		cout << "0. Quitter" << endl;
		cout << "1. Créer un nouveau répertoire" << endl;
		cout << "2. Ouvrir un répertoire existant" << endl;
		cout << "3. Ajouter un contact" << endl;
		cout << "4. Rechercher une personne" << endl;
		cout << "5. Afficher le répertoire dans l'ordre d'enregistrement" << endl;

		cout << endl;

		cin >> i;
		cin.ignore();

		switch(i)
		{
			case 0:
				flag = false;

				if(current != NULL)
				{
					current->save();
				}

				break;
			case 1:
			{
				if(current != NULL)
				{
					current->save();
				}

				current = createRepository();
				break;
			}
			case 2:
			{
				if(current != NULL)
				{
					current->save();
				}

				current = openRepository();
				break;
			}
			case 3:
				addPersonne(current);
				break;
			case 5:
				printRepository(current);
				break;
			default:
				cout << "Code inconnu :/" << endl;
				break;
		}

		cout << "----------------" << endl;
	}


}

Repository * createRepository()
{
	cout << "CRÉATION D'UN NOUVEAU RÉPERTOIRE ..." << endl;
	cout << "Quel nom voulez-vous donner à ce répertoire ?" << endl << "(si un répertoire porte déjà ce nom il sera écrasé)" << endl;

	string n = "";
	getline(cin, n);

	ofstream repository;
	string s = "repos/" + n + ".txt";

	repository.open(s.c_str(), ios::out | ios::app);

	if(repository)
	{
		cout << "Répertoire créé !" << endl;
	}
	else
	{
		cout << "Erreur lors de la création du répertoire ..." << endl;
	}

	repository.close();

	return new Repository(n);
}

Repository * openRepository()
{
	cout << "OUVERTURE D'UN RÉPERTOIRE EXISTANT ..." << endl;
	cout << "Quel est le nom du répertoire à ouvrir ?" << endl;

	string n = "";
	getline(cin, n);

	ifstream repository;
	string s = "repos/" + n + ".txt";

	repository.open(s.c_str());

	if(repository)
	{
		cout << "Répertoire ouvert !" << endl;
	}
	else
	{
		cout << "Erreur lors de l'ouverture du répertoire ..." << endl;
		repository.close();
		return NULL;
	}

	Repository * r = new Repository(n);

	int count = 0;
	string line = "";
	Personne * p = new Personne();

	while(getline(repository, line))
	{
		switch(count)
		{
			case 0:
				p->setNom(line);
				break;
			case 1:
				p->setPrenom(line);
				break;
			case 2:
				p->setAdresse(line);
				break;
			case 3:
			{
				stringstream convert(line);
				int z;
				convert >> z;
				p->setZip(z);
				break;
			}
			case 4:
				p->setPhone(line);
				r->add(p);
				p = new Personne();
				break;
			default:
				cout << "Wut ?" << endl;
				break;
		}

		count = (count + 1) % 5;
	}

	repository.close();
	return r;
}

bool addPersonne(Repository * r)
{
	if(r == NULL)
	{
		cout << "Un répertoire doit être actif !" << endl;
		return false;
	}

	string nom, prenom, adresse, phone;
	int zip;

	cout << "Nom : ";
	getline(cin, nom);

	cout << "Prenom : ";
	getline(cin, prenom);

	cout << "Adresse : ";
	getline(cin, adresse);

	cout << "Code postal : ";
	cin >> zip;

	cout << "Téléphone : ";
	getline(cin, phone);

	Personne * p = new Personne(nom, prenom, adresse, zip, phone);
	r->add(p);
	return true;
}

bool searchPersonne(Repository * r)
{
	if(r == NULL)
	{
		cout << "Un répertoire doit être actif !" << endl;
		return false;
	}

	
}

void printRepository(Repository * r)
{
	r->print();
}