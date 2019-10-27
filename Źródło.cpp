#include <iostream>		//dzia³a dobrze
#include <fstream>

const int SIZE = 30;

int zliczanie(char[SIZE]);
void wyswietlanie(int, char[SIZE]);


int main()
{
	char file_name[SIZE];
	std::cout << "Podaj nazwe pliku: ";
	std::cin.getline(file_name, SIZE);
	wyswietlanie(zliczanie(file_name), file_name);
	std::cin.get();
	return 0;
}


int zliczanie(char nazwa_pliku[SIZE])
{
	int ilosc = 0;
	char ch;
	std::fstream out_file;
	out_file.open(nazwa_pliku);
	if (out_file.is_open())
	{
		while (out_file.get(ch))
		{
			if (ch == '\n' || ch == ' ')
				continue;
			else
				ilosc++;
		}
		
	}
	else
	{
		ilosc = -10;
	}

	return ilosc;
}


void wyswietlanie(int ilosc, char nazwa_pliku[SIZE] )
{
	switch (ilosc)
	{
	case -10:
		std::cout << "Nieudana proba otwarcia pliku \""<<nazwa_pliku<<"\".\nKoniec programu.";
		break;
	case 0:
		std::cout << "Plik \"" << nazwa_pliku << "\" jest pusty.\nKoniec programu.";
			break;
	default:
		std::cout << "W pliku\"" << nazwa_pliku << "\" znajduje sie " << ilosc << " znakow.";
	}
}
