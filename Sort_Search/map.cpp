#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, int> Roman = { {"I",1}, {"V",5}, {"X",10}, {"L",50}, {"C",100}, {"D",500}, {"M",1000}};
    string s;
    cin >> s;
    int length = s.size();
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (i + 1 < length && Roman[string(1, s[i])] < Roman[string(1, s[i + 1])]) {
            sum -= Roman[string(1, s[i])];
        } else {
            sum += Roman[string(1, s[i])];
        }
    }
    cout << sum << endl;
    return 0;
}