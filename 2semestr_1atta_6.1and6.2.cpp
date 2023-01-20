/* task1sem2.cpp : Дана структура
struct Date
{
	unsigned short day, month, year;
}
и перечисление
enum DayOfWeek { mn, td, wd, thd, fd, std, sd };
Считая, что все даты даются по григорианскому календарю(по «новому стилю»), описать:
6.1 функцию, вычисляющую количество дней в том месяце, которому принадлежит
дата d;
6.3 функцию, подсчитывающую, сколько дней прошло от 1 января 1 - го года нашей
эры до даты d; */

#include <iostream>
using namespace std;

struct Date
{
	unsigned short day, month, year;
};


int day_in_month(unsigned short day, unsigned short month, unsigned short year)// функция, вычисляющая количество
//дней в том месяце, которому принадлежит дата d
{
	// {
	if (month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12)
	{
		day = 31;
	}
	if (month == 4 or month == 6 or month == 9 or month == 11)
	{
		day = 30;
	}
	if (month == 2)
	{
		day = 28;

		if (year % 4 == 0)
		{
			day = 29;
			if (year % 100 == 0)
			{
				day = 28;
				if (year % 400 == 0)
				{
					day = 29;

				}
			}
		}
	}
	return day;

}
//#define is_leap(year) ((year) % 4 == 0 && ((year) % 100 != 0 or (year) % 400 == 0))// 
int dni_s_1(unsigned short year, unsigned short month, unsigned short day)
{
	int d_m[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };// считаем сколько дней прошло до
	// нашего месяца
	int y = year - 1;// вычитаем 1, потому что год еще не закончился
	int q = day + d_m[month - 1] + ((year) % 4 == 0 && ((year) % 100 != 0 or (year) % 400 == 0) && month > 2) +
		y * 365 + y / 4 - y / 100 + y / 400;
	return q;
}




int main()
{
	setlocale(LC_ALL, "rus");
	Date d;
	Date m;
	Date y;

	int t = 1;
	while (t)
	{
		cout << "Введите 1, чтобы продложить, 0 , чтобы выйти" << endl;
		cin >> t;
		if (t == 1)
		{

			cout << "Введите день" << endl;
			cin >> d.day;
			while (d.day > 31)
			{
				cout << "Вы неверно ввели день,попробуйте снова" << endl;
				cin >> d.day;
				continue;
			}
			cout << "Введите месяц" << endl;
			cin >> m.month;
			while (m.month > 12)
			{
				cout << "Вы неверно ввели месяц, попобуйте снова" << endl;
				cin >> m.month;
				continue;
			}
			cout << "Введите год" << endl;
			cin >> y.year;
			while (y.year <= 0)
			{
				cout << "Вы неверно ввели год, попобуйте снова" << endl;
				cin >> y.year;
				continue;
			}
			int r;
			cout << "Что вы хотите узнать?" << endl << "1.Количество дней в этом месяце" << endl;
			cout << "2.Cколько дней прошло от 1 января 1 - го года нашей эры до введенной даты" << endl;
			cin >> r;
			while (r)
			{
				if (r == 1)
				{
					int r = day_in_month(d.day, m.month, y.year);
					cout << "В этом месяце введенного года  " << r << " дней " << endl;

				}
				else if (r == 2)
				{
					int f = dni_s_1(y.year, m.month, d.day);
					cout << "От 1 января 0001 года прошло " << f << " дней " << endl;
				}
				else
				{
					cout << "Введите 1 или 2" << endl;
					cin >> r;
				}
				break;
			}
		}
		continue;
	}
}


