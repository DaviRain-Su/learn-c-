#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
void to_array(int n, vector<int> & vec) {
    for(int i = 0; i < vec.size(); i++){
        vec[i] = n % 10;
        n /= 10;
    }
}
int to_number(const vector<int> &vec)
{
    int sum = 0;
    for(int i = 0; i < vec.size(); i++){
        sum = sum * 10 + vec[i];
    }
    return sum;
}

int main() {
    int n, MIN, MAX;
    cin >> n;
    vector<int> vec(4);
    while(true){
        to_array(n, vec);
        sort(vec.begin(), vec.end());// inc
        MIN = to_number(vec);
        sort(vec.begin(), vec.end(), cmp); // dec
        MAX = to_number(vec);
        n = MAX  - MIN;
        printf("%04d - %04d = %04d\n", MAX, MIN, n);
        if( n == 0 || n == 6174) break;
    }
    return 0;
}