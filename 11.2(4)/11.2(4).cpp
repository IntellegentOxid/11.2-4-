#include <iostream>
#include <algorithm>
using namespace std;

const unsigned int ARRSIZE = 10;

int main()
{
	bool fail = false;
	float arr[ARRSIZE];
	for (int i = 0; i < ARRSIZE; i++)
	{
		do
		{
			fail = false;
			cout << "Enter a value for " << i + 1 << " array item: ";
			cin >> arr[i];
			if (cin.fail())
			{
				cout << "\nIncorrect valye has been entered!" << endl << endl;
				fail = true;
			}
			cin.clear();
			cin.ignore();
		} while (fail);
	}
	cout << "\nAn array has been obtained: ";
	for (int i = 0; i < ARRSIZE; i++)
	{
		cout << arr[i] << " ";
	}

	float A;
	cout << "\n\nEnter a number: ";
	cin >> A;
	unsigned int n = 0;
	for (int i = 0; i < ARRSIZE; i++)
	{
		if (arr[i] < A)
		{
			n++;
		}
	}
	cout << "The number of array elements that are less than the entered number: " << n << endl;

	int sum = 0;
	unsigned int k = 0;
	for (int i = (ARRSIZE - 1); i >= 0; i--)
	{
		if (arr[i] < 0)
		{
			k = i;
			break;
		}
	}
	if ((k == 0 && arr[0] < 0) || (k != 0 && k < (ARRSIZE - 1)))
	{
		do
		{
			sum += arr[k + 1];
			k++;
		} while ((k + 1) < ARRSIZE);
		cout << "\nThe sum of the elements located after the last negative element is equal to " << sum << endl;
	}
	else if (arr[ARRSIZE - 1] < 0)
		cout << "\nThe last negative element of the array is the last element of the array\n";
	else
		cout << "\nThe are no negative elements in the array\n";

	float max_val = arr[0];
	for (int i = 0; i < ARRSIZE; i++)
	{
		if (max_val < arr[i])
		{
			max_val = arr[i];
		}
	}

	unsigned int j = 0, l = 0;
	float sort_arr[ARRSIZE];
	for (int i = 0; i < ARRSIZE; i++)
	{
		if (arr[i] >= (max_val * 0.8))
		{
			sort_arr[j] = arr[i];
			j++;
		}
		else
		{
			sort_arr[ARRSIZE - 1 - l] = arr[i];
			l++;
		}
	}

	sort(sort_arr, sort_arr + (j + 1), greater<>());
	cout << "\nSorted array: ";
	for (int i = 0; i < ARRSIZE; i++)
	{
		cout << sort_arr[i] << " ";
	}
	cout << endl;
}