#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void selectSort(vector<T> &A)
{
    size_t length  = A.size();
    for(int i = 0; i < length; i++){
        int k = i;
        for(int j = i; j < length; j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        swap(A[i], A[k]);
    }
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
    selectSort(vec);
    for(auto i : vec){
        cout << i << " ";
    }
    cout << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

