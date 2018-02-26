#include<iostream>
#include<locale.h>
#include<conio.h>
#include"MyClass.h"
#include"MyInput.h"
#include<time.h>


char* message = "Нажмиле любую клавишу для продолжения или ESC для выхода";

char* res = "";
using namespace std;



int Input_arrays() {
	try {
		int size;

		srand((unsigned)time(NULL));
		//Массив А
		cout << "Введите размер массива А==> ";
		while (InputSize(size));
		cout << "Вы ввели массив А размером ==>" << size << endl;
		MyClass mas_a(size);
		cin >> mas_a;
		cout << mas_a;
		//

		//Массив B
		cout << "Введите размер массива B==> ";
		while (InputSize(size));
		cout << "Вы ввели массив B размером ==>" << size << endl;
		MyClass mas_b(size);
		cin >> mas_b;
		cout << mas_b;
		//

		MyClass mas_x(Set_size(mas_a.Get_size(), mas_b.Get_size()));
		MyClass mas_prom_res(Set_size(mas_a.Get_size(), mas_b.Get_size()));

		if (mas_a == mas_b)
		{
			res = "\t\t\t\t-5";
			cout << res << endl;
#ifdef _DEBUG
			cout << "===============================Массив А == массив B=============================\n";
			cout << res << endl;
#endif // _DEBUG
			mas_x = -5;

		}
		else {
			if (mas_a < mas_b)
			{
				res = "\t\t\t\t(B/A)+5";

#ifdef _DEBUG
				cout << "===============================Массив А < массива B=============================\n";
				cout << res << endl;
#endif // _DEBUG

				mas_x = (mas_b / mas_a) + 5;
				res = "\t\t\t\t(B/A)+5";
#ifdef _DEBUG
				cout << "----------------------------Промежуточные вычисления----------------------------\n";
				mas_prom_res = mas_b / mas_a;
				cout << "B/A == " << mas_prom_res;
				cout << "--------------------------------------------------------------------------------\n";

#endif // _DEBUG

			}
			else
			{
				res = "\t\t\t\t(A*B)/B";

#ifdef _DEBUG
				cout << "===============================Массив А > массива B=============================\n";
				cout << res << endl;
				cout << "\n================================================================================\n";
#endif // _DEBUG

				mas_x = ((mas_a*mas_b) / mas_b);

#ifdef _DEBUG
				cout << "----------------------------Промежуточные вычисления----------------------------\n";
				mas_prom_res = mas_a *mas_b;
				cout << "A*B == " << mas_prom_res;
				cout << "--------------------------------------------------------------------------------\n";
#endif // _DEBUG
			}

		}
		cout << "Результат==> " << res;
		cout << "\nРазмер массива Х==>" << mas_x.Get_size();
		cout << mas_x;


	}
	catch (char* ex) {
		cout << ex << endl;
	}
	cout << message;
	return (_getch());
}


int main()

{

	setlocale(LC_ALL, "");
	int test_num = 0;
	const int ESC = 27;
	int exit_;




	do {
		

#ifdef _DEBUG
		cout << "\n========================Программа запущена в режиме DEBUG=======================";
#endif // _DEBUG

		cout << "\n==================================Тест #" << ++test_num << " ======================================"<<endl;
		cout << "Студент:\tБондаренко Андрей\nВариант:\t№3" << endl;
		cout << "   \t\t\t\t\t\t------------------" << endl;
		cout << "   \t\t\t\t\t\t|(a*b)/b,если a>b|" << endl;
		cout << "\t\t\t\t\tX   =   |-5,если a=b     |" << endl;
		cout << "   \t\t\t\t\t\t|(b/a)+5,если a<b|" << endl;
		cout << "   \t\t\t\t\t\t------------------" << endl;

		exit_ = Input_arrays();



	} while (exit_ != ESC);


	return 0;
}