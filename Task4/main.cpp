#include "iostream"
#include "string"

using namespace std;

// Функция compute_multiplication_table строит
// таблицу умножения до числа num
void compute_multiplication_table(int num);


// Функция enter_number осуществляет проверку
// корректности введенного пользователем числа.
// Число должно быть целым и положительным.
int enter_number();


int main()
{
	setlocale(LC_ALL, "Russian");

	int num;

	cout << "Введите целое положительное число, до которого нужно построить таблицу умножения: \n";

	num = enter_number(); // Вводим число и проверяем корректность.

	compute_multiplication_table(num); // Строим таблицу умножения.

	system("pause");
}

// Функция compute_multiplication_table строит
// таблицу умножения до числа num
void compute_multiplication_table(int num)
{
	// Создаем верхнюю "шапку" таблицы:
	// выводим числа от 1 до num,
	// под ними рисуем разделитель в виде ___

	cout << "\n " << "\t";

	for (int i = 0; i < num; i++) cout << i + 1 << "\t";

	cout << "\n";

	for (int i = 0; i < num + 1; i++) cout << "___" << "\t";

	cout << "\n";

	// Выводим на экран строки: элемент боковой 
	// "шапки" таблицы + разделитель | + результаты умножений

	for (int i = 0; i < num; i++)
	{
		cout << "   " << i + 1 << "|" << "\t";

		for (int j = 0; j < num; j++)
		{
			cout << (i + 1) * (j + 1) << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}


// Функция enter_number осуществляет проверку
// корректности введенного пользователем числа.
// Число должно быть целым и положительным.
int enter_number()
{
	string str_number; // В эту переменную будем считывать число в виде строки
	int number; // В эту переменную будет помещено число, преобразованное из строки

	int flag = 0;
	do
	{
		try
		{
			cin >> str_number; // Считаем число в виде строки
			number = stoi(str_number); // Конвертируем строку в число int

			if (number < 1)
				cout << "Введено неположительное число. Введите число еще раз: \n";
			else flag = 1;
		}
		catch (invalid_argument)
		{
			cout << "Число введено неверно. Введите число еще раз: ";
		}
		catch (out_of_range)
		{
			cout << "Число слишком большое. Введите число еще раз: ";
		}
		catch (...)
		{
			cout << "Ошибка! Введите число еще раз: ";
		}

	} while (flag == 0);

	return number; // Возвращаем корректное число
}