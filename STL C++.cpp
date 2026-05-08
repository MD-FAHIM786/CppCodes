#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;

bool comparator(pair<int, int> p1, pair<int, int> p2) {
     if(p1.second < p2.second) return true;
     if(p1.second > p2.second) return false;

     if(p1.first < p2.first) return true;
     else return false;
}

int main() {
    vector<pair<int, int>> vec = {{3,1}, {2,1}, {7,1}, {5,2}};

    sort(vec.begin(), vec.end(), comparator);

    for(auto p : vec) {
        cout <<p.first << " " << p.second << endl;
    }
    return 0;
}
