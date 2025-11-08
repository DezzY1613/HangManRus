#include <iostream>
#include <String>
#include "windows.h"
#include <stdlib.h>
using namespace std;

const string hangman[] = {"ghost", "flame", "brick", "hello" , "storm" , "crisp" , "blend" , "quick" , "frost" , "plumb" , "waltz" };
const string hangmanArt[7] = {
	"   \n   \n   \n   \n   \n   \n=========",
	"   \n   |\n   |\n   |\n   |\n   |\n=========",
	"  +---+\n   |\n   |\n   |\n   |\n   |\n=========",
	"  +---+\n  |   |\n   |\n   |\n   |\n   |\n=========",
	"  +---+\n  |   |\n  O   |\n   |\n   |\n   |\n=========",
	"  +---+\n  |   |\n  O   |\n /|\\  |\n   |\n   |\n=========",
	"  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n   |\n========="};
string hangmanword;
char word[5];
char succesBukva[6]{ '_','_','_','_','_', '\0' };
int random, attempt = 0;
char letter;
bool win = false, successfully;

int main() {
	// рандом
	srand(time(NULL));
	// русиш вайн
	setlocale(LC_ALL, "Ru_ru");

	cout << "Привет это моя первая программа прошу не судить строго!\n";
	cout << "by Dezz\n";
	cout << "Подождите 2 секунд для запуска!\n";
	char VarMainMenu;
	Sleep(2000);


	while (true) {

		system("cls");
		cout << "Это игра Hangman. Правила думаю знаете.\n\n1) Начать игру\n2) Правила\n3) Выйти\n";
		cout << "Выберите действие: ";
		cin >> VarMainMenu;

		switch (VarMainMenu) {
		case '1':
			system("cls");
			random = rand() % 10;

			hangmanword = hangman[random];

			for (size_t i = 0; i < hangmanword.length(); i++)
			{
				word[i] = hangmanword[i];
			}
			


			while (!win && attempt !=6) {
				system("cls");
				cout << hangmanArt[attempt] << endl;
				cout << "Слово:" << succesBukva[0] << " " << succesBukva[1] << " " << succesBukva[2] << " " << succesBukva[3] << " " << succesBukva[4] << endl;
				cout << "Введите букву: ";
				cin >> letter;

				for (size_t i = 0; i < 5; i++) //letter != word[i]
				{
					if (letter == word[i])
					{
						succesBukva[i] = letter;
						successfully = true;
					}
				}

				if (!successfully)
				{
					attempt++;
				}

				successfully = false;

				if (word[0] == succesBukva[0] && word[1] == succesBukva[1] && word[2] == succesBukva[2] && word[3] == succesBukva[3] && word[4] == succesBukva[4])
				{
					win = true;
				}

			}
			system("cls");
			cout << hangmanArt[attempt] << endl;
			
			if (win)
			{
				cout << "Вы выйграли, слово было: " << hangmanword;
			}
			else
			{
				cout << "Вы проиграли, слово было: " << hangmanword;
			}

			
			Sleep(10000);
			return 0;

			break;
		case '2':
			system("cls");
			cout << "Программа загадывает слово (например: hello).\n";
			cout << "Ты видишь его как: _ _ _ _ _\n";
			cout << "У тебя 6 попыток (ошибок).\n";
			cout << "Вводишь по одной букве.\n";
			cout << "Если буква есть она открывается:\n";
			cout << "Если нет рисуется часть виселицы, +1 ошибка.\n";
			cout << "Цель: угадать слово до 6 ошибок.\n";
			cout << "Угадал все буквы Победа!\n";
			cout << "6 ошибок Поражение, слово показывается.\n";
			cout << "Обратно в меню вернетесь через 15 секунд...\n";
			Sleep(15000);
			break;
		case '3':
			system("cls");
			cout << "Удачи!\n";
			return 0;
			break;
		default:
			cout << "Выбери число из предоставленных!\n";
			break;
		}
	}



	return 0;
}