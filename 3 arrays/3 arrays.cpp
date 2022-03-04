/*
Даны три отсортированных (непустых) массива A, B и C.
Необходимо найти такую тройку чисел A[i], B[j], C[k],
для которых выражение (max(A[i], B[j], C[k]) — min(A[i], B[j], C[k]))
было бы минимальным из всех возможных троек. Если троек с одинаковым значением несколько,
вывести ближайшую к началу массивов (приоритет A, B, C).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result(int a, int b, int c)
{
    int max_val = max(max(a, b), c);
    int min_val = min(min(a, b), c);

    return max_val - min_val;
}

int main()
{
    int size1, size2, size3;
    
    cin >> size1;
    vector<int> arr1(size1);
    for (vector<int>::iterator it = arr1.begin(); it != arr1.end(); it++)
    {
        cin >> *it;
    }

    cin >> size2;
    vector<int> arr2(size2);
    for (vector<int>::iterator it = arr2.begin(); it != arr2.end(); it++)
    {
        cin >> *it;
    }

    cin >> size3;
    vector<int> arr3(size3);
    for (vector<int>::iterator it = arr3.begin(); it != arr3.end(); it++)
    {
        cin >> *it;
    }

    int p1 = 0;
    int p2 = 0;
    int p3 = 0;

    int save_p1 = 0;
    int save_p2 = 0;
    int save_p3 = 0;
    int res = -1;

    bool change;
    for (int i = 0; i < (size1 + size2 + size3); i++)
    {
       // cout << arr1[p1] << ' ' << arr2[p2] << ' ' << arr3[p3] << endl;

        change = false;
        if (p1 + 1 < size1)
        {
            if (result(arr1[p1 + 1], arr2[p2], arr3[p3]) <= result(arr1[p1], arr2[p2], arr3[p3]))
            {
                p1++;
                change = true;
            }
        }

        if (p2 + 1 < size2)
        { 
            if (result(arr1[p1], arr2[p2 + 1], arr3[p3]) <= result(arr1[p1], arr2[p2], arr3[p3]))
            {
                p2++;
                change = true;
            }
        }

        if (p3 + 1 < size3)
        { 
            if (result(arr1[p1], arr2[p2], arr3[p3 + 1]) <= result(arr1[p1], arr2[p2], arr3[p3]))
            {
                p3++;
                change = true;
            }
        }

        if (!change)
        {          
            if (result(arr1[p1], arr2[p2], arr3[p3]) < res || res == -1)
            {
                save_p1 = p1;
                save_p2 = p2;
                save_p3 = p3;
                res = result(arr1[p1], arr2[p2], arr3[p3]);
            }
           
            if (p1 + 1 < size1)
            {
                p1++;
            }
            else if (p2 + 1 < size2) 
            {
                p2++;
            }
            else if (p3 + 1 < size3)
            {
                p3++;
            }
        }
    }

    cout << "Numbers = " << arr1[save_p1] << ' ' << arr2[save_p2] << ' ' << arr3[save_p3] << endl;
    cout << "Result = " << result(arr1[save_p1], arr2[save_p2], arr3[save_p3]) << endl;
    return 0;
}

