// bitset.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "boost\dynamic_bitset.hpp"
//#include <bitset>
using namespace std;
using namespace boost;
class Bit_Set
{
private:
	int size;
	dynamic_bitset<> a;
public:
	Bit_Set()
	{
		for (int i = 0; i < size; i++)
		{
			a[i] = 0;
		}
	}
	void set_size(int n)
	{
		a.resize(n);
	}

	void add(int n)
	{
		a[n - 1] = 1;
	}


	Bit_Set Union(Bit_Set k) {
		Bit_Set temp;
		temp.a = a | k.a;
		return temp;
	}
	Bit_Set Intersect(Bit_Set k) {
		Bit_Set temp;
		temp.a = a & k.a;
		return temp;
	}
	Bit_Set Subs(Bit_Set k) {
		Bit_Set temp;
		temp.a = a & ~(k.a);
		return temp;
	}
	void Output()
	{
		for (int i = 0; i < 32; i++)
		{
			if (a[i] == 1)
				cout << i + 1 << " ";
		}
		/*cout<<a<<endl;*/
	}
};


int main()
{
	Bit_Set a, b, c, d, e;
	int n;
	cin >> n;
	a.set_size(n);
	b.set_size(n);
	c.set_size(n);
	d.set_size(n);
	e.set_size(n);
	a.add(10); a.add(20); a.add(30); a.add(18); a.add(19); a.add(15); a.add(13); a.add(11); a.add(7); a.add(5); a.add(4); a.add(2); a.add(1);
	b.add(23); b.add(94); b.add(25); b.add(18); b.add(15); b.add(13); b.add(11); b.add(10); b.add(9);
	c = a.Union(b);
	d = a.Intersect(b);
	e = a.Subs(b);

	a.Output();
	cout << endl;
	b.Output();
	cout << endl;
	c.Output();
	cout << endl;
	d.Output();
	cout << endl;
	e.Output();
	cout << endl;

	return 0;
}

