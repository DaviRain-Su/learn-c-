#include <iostream>
#include <string>
using namespace std;

int main() {

    string s;
    cin >> s;

    int cnt = 1;
    char temp  = s[0]; 
    string result;

    for (int i = 1; i != s.size(); i++){
        if(temp == s[i] && i != s.size() - 1){
            cnt++;
        }else if (temp == s[i] && i == s.size() - 1)
        {
            cnt++;
            result.insert(result.end(), cnt + '0');
            result.insert(result.end(), temp);
            //result += to_string(cnt);
            //result += temp;
        }else{
            result.insert(result.end(), cnt + '0');
            result.insert(result.end(), temp);
            //result += to_string(cnt);
            //result += temp;
            cnt = 1;
            temp = s[i];

        }
        
    }

    cout << result << endl;
    return 0;
}