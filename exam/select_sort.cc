/*
 * 
 * 
 * 
 * */
#include <iostream>
#include <vector>

using namespace std;

void select_sort(vector<int> &vec)
{
    int len = vec.size();
    for(int i = 0; i < len; i++){
        int k  = i;
        for(int j = i; j < len; j++){
            if(vec[j] < vec[k]){
                k = j;
            }
        }
        swap(vec[i], vec[k]);
    }
}

void print(const vector<int> &vec){
    for(auto iter : vec){
        cout << iter << " ";
    }
    cout << endl;
}

int main() {
    
    vector<int> vec;
    for(int i = 0; i < 10; i++){
        vec.push_back(10 - i);
    }

    print(vec);
    select_sort(vec);
    print(vec);
    
    return 0;
}