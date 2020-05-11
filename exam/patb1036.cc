#include <iostream>

using namespace std;

int main() 
{
    int row, col;
    char c;

    cin >> col >> c;
    
    if(col % 2 == 1) row = col / 2 + 1;
    else row = col / 2;

    // 1
    for(int i = 0; i < col; i++){
        cout << c << "";
    }
    cout << endl;

    //2 - row - 1
    for(int i = 2; i < row; i++){
        cout << c << "";
        for(int j = 0; j < col - 2; j++){
            cout << " ";
        }
        cout << c << endl;
    }

    // row 
    for(int i = 0; i < col; i++){
        cout << c << "";
    }
    cout << endl;
    return 0;
}