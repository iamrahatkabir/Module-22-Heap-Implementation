#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

void insert_heap(vector<int> &v, int val)
{
    v.push_back(val);

    int current_idx = v.size()-1;
    while(current_idx != 0)
    {
        int parent_idx = (current_idx - 1)/2;

        if(v[parent_idx] < v[current_idx])
            swap(v[parent_idx], v[current_idx]);
        else
            break;

        current_idx = parent_idx;
    }
}

void print_heap(vector<int> v)
{
    for(int x : v)
        cout << x << " ";
    cout << endl;
}

void delete_heap(vector<int> &v)
{
    v[0] = v.back();
    v.pop_back();

    int curr_idx = 0;

    while(true)
    {
        int left_idx = curr_idx * 2 + 1;
        int right_idx = curr_idx * 2 + 2;   

        int left_val = INT_MIN, right_val = INT_MIN;

        if(left_idx < v.size())
            left_val = v[left_idx];

        if(right_idx < v.size())
            right_val = v[right_idx];

        if(left_val > right_val && left_val > v[curr_idx])
        {
            swap(v[left_idx], v[curr_idx]);
            curr_idx = left_idx;
        }
        else if(right_val > left_val && right_val > v[curr_idx])
        {
            swap(v[left_idx], v[curr_idx]);
            curr_idx = right_idx;
        }
        else 
            break;
    }
    
}


int main()
{
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int val; cin >> val;

        insert_heap(v, val);
    }   

    print_heap(v);
    delete_heap(v);
    print_heap(v);

    return 0;
}