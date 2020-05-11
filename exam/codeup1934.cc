#include <iostream>

using namespace std;

int main() 
{

    int n;
    cin >> n;

    int *arr = new int[n];

    int temp = 0;
    for(int i = 0; i < n ; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }
#if 0
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
#endif
    int k = 0;
    cin >> k;
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(arr[i] == k){
            cout << i << endl;
            flag = true;
            break;
        }
    }
    if(!flag)
        cout << -1 << endl;

    delete [] arr;
    return 0;
}