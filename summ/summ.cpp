/*
Дан массив из N положительных чисел, надо найти в нем несколько чисел (не менее одного),
идущих подряд, так, чтобы их сумма была больше или равна K,
а чисел в нем содержалось бы как можно меньше.
При равенстве размера вывести последовательность с бОльшей суммой, 
при равенстве и размеров и сумм - ближайшую к началу массива.
В случае, если таких последовательностей нет необходимо вывести "No summ"
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> vec(n);

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cin >> *it;
	}

	int temp_sum = 0;
	int sum = 0;
	int start = 0;
	int end = vec.size() - 1;
	vector<int>::const_iterator save_it = vec.cbegin();
	for (vector<int>::const_iterator it = vec.cbegin(); it != vec.cend(); it++)
	{
		for (vector<int>::const_iterator next_it = save_it; next_it != vec.cend(); next_it++)
		{
			temp_sum += *next_it;
		//	cout << *it << ' ' << *next_it << ' ' << ' ' << next_it - it << ' ' << temp_sum << endl;

			if (temp_sum >= k && (((next_it - it) < (end - start)) || ((next_it - it) == (end - start) && temp_sum > sum)))
			{
				start = it - vec.cbegin();
				end = next_it - vec.cbegin();
				save_it = next_it;
				sum = temp_sum;
				break;
			}
			else if (temp_sum >= k)
			{
				save_it = next_it;
				break;
			}
		}
		temp_sum -= *it;
		temp_sum -= *save_it;
	}

	if (sum < k)
	{
		cout << "No summ" << endl;
	}
	else
	{
		cout << "Length = " << end - start + 1 << endl;
		cout << "Sum = " << sum << endl;
		cout << "Start = " << start << endl;
		cout << "Finish = " << end << endl;
	}

	return 0;
}

