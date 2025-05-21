#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Graph {
    public:
        map<string, map<string,int>> matrix;

        void themCanh(string u, string v, int TrongSo) {
            matrix[u][v] = TrongSo;
        }

        bool kiemTraDuongDi(vector<string> p,int &tong) {
            if (p.empty() || p.front() != p.back()) 
                return false;
            for (int i = 0; i + 1 < p.size(); ++i) {
                string u=p[i];
                string v =p[i + 1];
                if (matrix.count(u)==0 || matrix.at(u).count(v)==0) 
                    return false;
                tong += matrix.at(u).at(v);
            }
            return true;
        }
};

int main() {
    Graph G;
    int e,n;
    cin >>e>>n;
    for (int i = 0;i<e;++i) {
        string u,v;
        int TrongSo;
        cin >>u>>v>>TrongSo;
        G.themCanh(u,v,TrongSo);
    }
    for (int i = 0; i < n; ++i) {
        vector<string> p;
        string s;
        while(true) {    
            cin >> s;
            if (s ==".") 
                break;
            p.push_back(s);
        }
        int TongTrongSo=0;
        bool check=G.kiemTraDuongDi(p,TongTrongSo);
        if (check)
            cout <<TongTrongSo<<endl;
        else
            cout <<"FALSE"<<endl;
    }
    return 0;
}