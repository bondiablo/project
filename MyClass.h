#pragma once

#include <iostream>
#include <math.h> 
#include <conio.h>


using namespace std;
class MyClass
{

private:
	int size_of_array;
	int *mas;
	int comparisons;
	void Set_comparisons();
public:
	int Get_size();
	int Get_comparisons();
	MyClass(int);
	MyClass(const MyClass &);
	MyClass(const MyClass&, const MyClass &);

	~MyClass();
	friend istream &operator >> (istream&stream, MyClass & object);
	friend ostream &operator<<(ostream&stream, MyClass & object);

	bool operator == (MyClass &);
	bool operator >(MyClass &);//количество положителных
	bool operator <(MyClass &);
	friend MyClass operator+(MyClass&, int);
	friend MyClass operator *(const MyClass&, const MyClass&);
	friend  MyClass operator /(const MyClass&, const MyClass&);
	MyClass operator=(int);
	MyClass operator=(MyClass &);
}; 