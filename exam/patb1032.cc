#include <iostream>
#include <map>

using namespace std;

const int maxn = 100010;
int school[maxn] = {0};

int main() {

    int n;
    cin >> n;
    int schId, score;
    for(int i = 0; i < n; i++)
    {
        cin >> schId >> score;
        school[schId] += score;
    }

    int k = 1, MAX = -1;
    for(int i = 1; i <= n; i++){
        if(MAX < school[i]){
            MAX = school[i];
            k = i;
        }
    }

    cout << k << " " << MAX << endl;
#if 0
    map<int, int> Map;

    int a, b;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if(Map.find(a) == Map.end())
            Map[a] = b;
        else 
            Map[a] += b;
    }

    Map.
    for(auto &item : Map)
    {
        cout << item.first << " --- " << item.second << endl;
    }
#endif

    //sort(Map.begin(), Map.end(), Cmp());

    return 0;

}