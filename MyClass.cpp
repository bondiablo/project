
#include<iostream>
#include"MyInput.h"
#include"MyClass.h"
#include<time.h>


using namespace std;

inline int Rand() {

	int num = -1000 + rand() % 2000;
	return num;

}

MyClass::MyClass(int _size) :comparisons(0)
{
	size_of_array = _size;
	if (_size == 1) {
		mas = new int;
	}
	else
	{
		mas = new int[_size];
	}
}

MyClass::MyClass(const MyClass &object_1, const MyClass &object_2){

	if (object_1.size_of_array > object_2.size_of_array)
		this->size_of_array = object_1.size_of_array;
	else
		this->size_of_array = object_2.size_of_array;


	if (this->size_of_array == 1)
	{
		mas = new int;

	}
	else
	{
		mas = new int[this->size_of_array];
	}

}

MyClass::MyClass(const MyClass&object)
{
	this->size_of_array = object.size_of_array;
	this->mas = new int[object.size_of_array];
	for (int i = 0; i < size_of_array; i++)
	{
		mas[i] = object.mas[i];
	}
}




//Äåñòðóêòîð
MyClass::~MyClass()
{
	if (size_of_array == 1) {
		delete mas;
	}
	else delete[]mas;
}






//Ëåãåíäà
void MyClass::Set_comparisons()
{
	int count = 0;
	for (int i = 0; i < size_of_array; i++) {
		if (mas[i] % 2 == 0) {
			count++;
		}
	}
	this->comparisons = count;
}


int MyClass::Get_comparisons()
{
	return this->comparisons;
}





istream & operator >> (istream &stream, MyClass& object)
{

	if (object.size_of_array < 10) {
		for (int i = 0; i < object.size_of_array; i++)
		{
			cout << "Ââåäèòå ýåìåíò #" << i + 1 << " ==>";
			Check_input(object.mas[i]);

		}

	}

	else {

		cout << "Âûïîëíûåòñÿ àâòîìàòè÷åñêîå çàïîëíåíèå ìàññèâà==>\n";
		for (int i = 0; i < object.size_of_array; i++)
		{

			object.mas[i] = Rand();
		}

	}

	object.Set_comparisons();
	return stream;
}

ostream & operator<<(ostream & stream, MyClass & object)
{

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	for (int i = 0; i < object.size_of_array; i++)
	{
		stream << object.mas[i] << "\t";
	}
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	return stream;
}


bool MyClass::operator==(MyClass &object)
{
	bool res = true;
	if (this->size_of_array == object.size_of_array)
	{
		for (int i = 0; i < object.size_of_array; i++) {
			if (mas[i] != object.mas[i]) {
				res = false;
			}
		}
	}
	else { res = false; }
	return res;
}


bool MyClass::operator>(MyClass &object)
{
	if (size_of_array == 1 && object.size_of_array == 1) {
		return *mas > *object.mas;
	}

	else {
		if (this->size_of_array == object.size_of_array)
		{
			return(Get_comparisons() > object.Get_comparisons());
		}
		else
		{
			//ïðîâåðêà íà äëèíó ìàññèâà
			if (this->size_of_array > object.size_of_array) {
				return true;
			}
			else
			{
				return false;
			}
		}

	}

}

bool MyClass::operator< (MyClass & object)
{
	if (size_of_array == 1 && object.size_of_array == 1) {
		return *mas < *object.mas;
	}

	else {
		if (this->size_of_array == object.size_of_array)
		{
			return(Get_comparisons() < object.Get_comparisons());
		}
		else
		{
			//ïðîâåðêà íà äëèíó ìàññèâà
			if (this->size_of_array < object.size_of_array) {
				return true;
			}
			else
			{
				return false;
			}
		}

	}

}

MyClass operator+(MyClass&object, int num)
{
	MyClass c(object);
	long double check;
	for (int i = 0; i < object.size_of_array; i++)
	{
		check = 1.0*object.mas[i] + num;
		if (check > INT_MAX || check < INT_MIN) {
			throw "Ïåðåïîëíåíèå ïðè âû÷èñëåíèè ñóììû!";
		}
		else
		{
			c.mas[i] = object.mas[i] + num;
		}
	}
	return c;
}


MyClass operator*(const MyClass&object_1, const MyClass& object_2)
{
	MyClass new_mas(object_1, object_2);
	long double check;

	for (int q = 0, w = 0, k = 0; k < new_mas.size_of_array; q++, w++, k++) {
		if (q == object_1.size_of_array)
			q = 0;
		if (w == object_2.size_of_array)
			w = 0;
		check = 1.0*object_1.mas[q] * object_2.mas[w];

		if (check > INT_MAX || check < INT_MIN)
		{
			throw "Ïåðåïîëíåíèå ïðè âû÷èñëåíèè óìíîæåíèÿ!";
		}
		else
		{
			new_mas.mas[k] = object_1.mas[q] * object_2.mas[w];
		}
	}
	return new_mas;
}

MyClass operator/(const MyClass&object_1, const MyClass& object_2) {


	MyClass new_mas(object_1, object_2);

	long double check;
	for (int i = 0, q = 0, w = 0; i < new_mas.size_of_array; i++, q++, w++)
	{
		if (q == object_1.size_of_array)
			q = 0;
		if (w == object_2.size_of_array)
			w = 0;
		if (object_2.mas[w] == 0)
			throw "Îøèáêà äåëåíèÿ íà íîëü!";
		check = 1.0*object_1.mas[q] / object_2.mas[w];
		if (check > INT_MAX || check < INT_MIN)
		{
			throw "Ïåðåïîëíåíèå ïðè âû÷èñëåíèè äåëåíèÿ!";
		}
		else new_mas.mas[i] = object_1.mas[q] / object_2.mas[w];

	}


	return new_mas;
}


MyClass MyClass::operator=(MyClass &object)
{

	for (int i = 0; i < this->size_of_array; i++)
	{
		this->mas[i] = object.mas[i];
	}
	return *this;
}

MyClass MyClass:: operator=(int num)
{
	MyClass new_mas(this->size_of_array);
	for (int i = 0; i < this->size_of_array; i++)
	{
		this->mas[i] = num;
	}
	return *this;
}



int MyClass::Get_size() {
	return this->size_of_array;
}
