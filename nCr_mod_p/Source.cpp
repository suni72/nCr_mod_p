#include <stdio.h>
#include <iostream>

using namespace std;

int minInt(int x, int y)
{
	return (x < y) ? x : y;
}

int nCr(int n, int r)
//dynamic programming approach used to calculate nCr using Pascal's triangle
/*
initial array: [1, 0, 0, 0, 0...]
first run:     [1, 1, 0, 0, 0...]
second run:    [1, 2, 1, 0, 0...]

value of arr[j] is equal to the values of arr[j] + arr[j-1] in the previous run (special case arr[0] == 1)

value of r is used as cutoff because values of concern only require up to r values each run

Pascal's triangle shows the desired values

0					1
				   / \
1			      1   1
				 / \ / \
2               1   2   1
			   / \ / \ / \
3		      1   3   3   1
*/

{
	int* PascalRow = new int[r + 1];
	for (int i = 1; i <= r; ++i)
		PascalRow[i] = 0;
	PascalRow[0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = minInt(i, r); j >= 0; --j)
			//proceed horizontally through Pascal's triangle using smallest of i or r as bounds - note that the 
			//iterations proceed in the reverse direction so that values from the previous run can be used to calculate
			//values for the current run
		{
			if (j == 0)
				PascalRow[j] = 1;
			else
				PascalRow[j] = PascalRow[j] + PascalRow[j - 1];
		}
		for (int k = 0; k <= minInt(i, r); ++k)
			cout << PascalRow[k] << " ";
		cout << endl;
	}
	cout << "nCr for " << n << "C" << r << " = " << PascalRow[r] << endl;
	int copy = PascalRow[r];
	delete[] PascalRow;
	return copy;
}

int nCrModNum(int n, int r, int p)
{
	
	return nCr(n, r) % p;
}



int main()
{
	cout << nCrModNum(0, 0, 5) << endl;
	cout << nCrModNum(5, 2, 4) << endl;		//expect 2
	return 0;
}