#include <iostream>
#include <string>

using namespace std;

bool judge(string s)
{
    int len = s.size();
    for(int i = 0; i < len / 2 ; i++){
        if(s[i] != s[len - 1 - i])
            return false;
    }
    return true;
}
int main() 
{
    string s;
    cin >> s;

    if(judge(s))
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;


    return 0;
}