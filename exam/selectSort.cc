#include <iostream>
#include <vector>

using namespace std;
void generate(vector<int> &vec, int size);

template<typename T>
void select(vector<T> &vec);

int main() {

    vector<int> v;
    generate(v, 10);

    select(v);
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}


void generate(vector<int> &vec, int size)
{
    for(int i = 0; i < size; i++){
        vec.push_back(i);
    }
}


template<typename T>
void select(vector<T> &vec)
{
    int len = vec.size();
    for(int i = 0; i < len; i++)
    {
        int k = i; // iter n step find the peer loop the min value
        for(int j = i; j < len; j++){// find i - (len - 1) min vlaue
            if(vec[j] < vec[k])
            {
                k = j;
            }
        }
        swap(vec[i], vec[k]);// swap i, k
    }
}