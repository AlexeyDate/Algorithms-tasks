#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void make_heap_cust(vector<int>& heap, bool display)
{
    int left_child;
    int right_child;
    int max_idx;
    int cur_idx;
    vector<pair<int, int>> swap_element;
    for (int it = heap.size() / 2; it >= 0; it--)
    {
        max_idx = it;
        while (true)                                              // Sift down
        {
            cur_idx = max_idx;
            left_child = max_idx * 2 + 1;
            right_child = max_idx * 2 + 2;

            if (left_child < heap.size() && heap[max_idx] > heap[left_child])
            {
                max_idx = left_child;
            }

            if (right_child < heap.size() && heap[max_idx] > heap[right_child])
            {
                max_idx = right_child;
            }

            if (max_idx != cur_idx)
            {
                swap(heap[cur_idx], heap[max_idx]);
                swap_element.push_back(pair<int, int>(cur_idx, max_idx));
            }
            else
            {
                break;
            }
        }
    }

    if (display)
    {
        cout << swap_element.size() << endl;
        for (int i = 0; i < swap_element.size(); i++)
        {
            cout << swap_element[i].first << ' ' << swap_element[i].second << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> data(n);
    for (vector<int>::iterator it = data.begin(); it != data.end(); it++)

    {
        cin >> *it;
    }

    make_heap_cust(data, true);

    return 0;
}