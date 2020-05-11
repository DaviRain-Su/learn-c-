/*
 * 
 * 
 * 
 * */
#include <iostream>
#include <vector>

using namespace std;

void simple_insert_sort(vector<int> &vec)
{
    int len = vec.size();
    for(int i = 1; i < len; i++){
        int temp = vec[i], j = i;
        while(j > 0 && temp < vec[j - 1]) {
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = temp;
    }
}

void print(const vector<int> &vec){
    for(auto iter : vec){
        cout << iter << " ";
    }
    cout << endl;
}

int main() {
#if 0
    vector<int> vec;
    for(int i = 0; i < 10; i++){
        vec.push_back(10 - i);
    }
#else 
    vector<int> vec;
    vec.push_back(1);
#endif

    print(vec);
    simple_insert_sort(vec);
    print(vec);
    
    return 0;
}