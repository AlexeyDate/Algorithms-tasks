#include <iostream>
#include <vector>
using namespace std;

void sift_down(vector<pair<long,int>>& heap)
{
    int left_child;
    int right_child;
    int max_idx = 0;
    int cur_idx;

    while (true)
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
            swap(heap[max_idx], heap[cur_idx]);
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int proc;
    int tasks;
    long time;

    cin >> proc >> tasks;
    vector<pair<long,int>> min_heap(proc);

    for (int i = 0; i < proc; i++)
    {
        min_heap[i].first = 0;
        min_heap[i].second = i;
    }

    for (int i = 0; i < tasks; i++)
    {
        cin >> time;      
        cout << min_heap[0].second << ' ' << min_heap[0].first << endl;   // proc and time
       
        min_heap[0].first += time;
        sift_down(min_heap);
    }

    return 0;
}

