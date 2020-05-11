#include <iostream>
#include <string>

using namespace std;

// c++ 种的判断一个字符是数字还是字符
bool jude(string s)
{
    if(isdigit(s[0]))
        return false;
    
    for(int i = 1; i != s.size(); i++ )
    {
        if (isalnum(s[i]) || s[i] == '_' )
            continue;
        else 
            return false;
    }
    return true;
}


int main() {


    string s;
    cin >> s;
    
    if(jude(s))
    {
        cout << "yes" << endl;
    }else {
        cout << "no" << endl;
    }
    
    return 0;
}