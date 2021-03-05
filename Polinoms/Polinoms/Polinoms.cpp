#include <iostream>
#include "List.h"
#include <locale.h>

using namespace std;


void main()
{
	int choise;
	setlocale(LC_ALL, "Russian");
	cout << "Выберите операцию для полиномов из предложенных ниже:" << endl << " 1.Cумма двух полиномов" << endl << " 2.Добавление полинома к текущему" << endl << " 3. Умножение" << endl << "Для выхода нажмите 0"<< endl;
	do
	{
		TPolinom P, Q;
		int tmp;
		bool flag = true;
		cin >> choise;
		TPolinom res1,res2;
		switch (choise)
		{
		case 1:
			cout << "P: ";
			cin >> P;
			cout << endl << "Q: ";
			cin >> Q;
			res1 = P + Q;
			cout << endl << P << " + " << Q << " = " << res1 << endl;
			break;
		case 2 :
			cout << "P: ";
			cin >> P;
			cout << endl << "Q: ";
			cin >> Q;
			cout << endl << P << " += " << Q << " = ";
			P += Q;
			cout << P << endl;
			break;
		case 3:
			cout << "1.Умножение на число" << endl << "2.Умножение на моном" << endl;
			std::cin >> tmp;
			switch (tmp)
			{
			case 1:
			{
				cout << "P:";
				cin >> P;
				cout << endl << "Число =";
				double val;
				cin >> val;
				res2 = P * val;
				cout << endl << P << " * " << val << " = " << res2 << endl;
				break;
			}
			case 2:
			{
				TPolinom res;
				cout << "P:";
				cin >> P;
				cout << endl << "Моном =";
				TMonom m;
				cin >> m;
				res = P * m;
				cout << endl << P << " * " << m << " = " << res << endl;
				break;
			}
			default:
				break;
			}break;

		}
	} while (choise != 0);
}