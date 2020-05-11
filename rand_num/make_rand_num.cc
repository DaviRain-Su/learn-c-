#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <fstream>
#include <string>

using std::vector;
using std::string;
using std::ofstream;
using std::cout;
using std::endl;
using std::cin;

const int CNT = 65536;
//void make_num(ofstream os, int num);
int main(int argc, char ** argv)
{
    for(int j = 0; j < 10; j++){
        string temp = "temp" + std::to_string(j);
        cout << temp << endl;

        ofstream out(temp, std::ios::binary);
        if(out.fail()){
            cout << "Can't open " << temp << endl;
        }
        std::default_random_engine random(time(nullptr));
        std::uniform_int_distribution<int16_t> dis1(-32767, 32767);

        vector<int16_t> collect;
        for (int i = 0; i < CNT; ++i){
            collect.push_back(dis1(random));
            cout << dis1(random) << " ";
        }
        cout << endl;
        out.write((char*)collect.data(), collect.size()*sizeof(int16_t));
        cout << "collect size is " << collect.size() << endl;
        out.close();
    }
    cout << endl;
    return 0;
}
#if 0
void make_num(ofstream os, int num)
{
    std::default_random_engine random(time(nullptr));
    std::uniform_int_distribution<int16_t> dis1(0, 100);

    vector<int16_t> collect;
    for (int i = 0; i < num; ++i){
        collect.push_front(dis1(random));
        cout << dis1(random) << " ";
    }
    cout << endl;
    cout << "collect size is " << collect.size() << endl;
}
#endif
