#include <iostream>
#include <string.h>
#include <algorithm>
using std::sort;
const int MAXDIGT = 50;

struct numNode {
    bool isPositive;
    int digit;
    char value[MAXDIGT + 2];

    bool operator<(const numNode &b) const 
    {
        if(isPositive == true && b.isPositive == true)
        {
            if(digit != b.digit)
                return digit < b.digit;
            else 
                return strcmp(value, b.value) < 0;
        }else if (isPositive == false && b.isPositive == false)
        {
            if(digit != b.digit)
                return digit > b.digit;
            else 
                return strcmp(value, b.value) > 0;
        }
        else {
            return b.isPositive;
        }
    }
};

int main()
{
    int N;
    std::cin >> N;
    numNode *s = new numNode[N];
    for (int i = 0; i < N; i++ )
    {
        std::cin >> s[i].value;
        s[i].digit = strlen(s[i].value);
        if(s[i].value[0] == '-')
            s[i].isPositive = false;
        else 
            s[i].isPositive = true;
    }

    sort(s, s + N);

    for (int i = 0; i < N; i++)
        std::cout << s[i].value << " ";
    std::cout << std::endl;
    delete [] s;

    return 0;
}

