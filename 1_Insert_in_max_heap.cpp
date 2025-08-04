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

int main()
{
    int n; cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    int val; cin >> val;
    v.push_back(val);

    int current_idx = v.size()-1;
    
    // cout<<parent_idx<<endl;
    
    while(current_idx != 0)
    {
        int parent_idx = (current_idx-1)/2;

        if(v[parent_idx] < v[current_idx])
            swap(v[parent_idx], v[current_idx]);
        else
            break;
        
        current_idx = parent_idx;
    }

    for(int x : v)
        cout << x << " ";


    return 0;
}