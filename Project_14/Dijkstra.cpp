#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dijkstra(int s, int t, vector<vector<int>> &matrix) {
    int v = matrix.size();
    vector<int> d(v, INT_MAX); 
    vector<int> parent(v, -1);
    vector<bool> close(v, false); 

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> open;

    d[s] = 0;
    open.push({0, s});

    while (!open.empty()) {
        int p = open.top().second;
        open.pop();

        if (close[p]) continue; // 2.3 Nếu đã duyệt thì bỏ qua
        close[p] = true;        // 2.4 Đánh dấu đã duyệt

        if (p == t) {           // 2.2 Nếu là đích thì truy vết đường đi
            vector<int> path;
            for (int u = t; u != -1; u = parent[u])
                path.push_back(u);
            cout << "Duong di ngan nhat: ";
            for (int i = path.size() - 1; i >= 0; --i)
                cout << path[i] << (i > 0 ? " -> " : "\n");
            cout << "Do dai duong di: " << d[t] << endl;
            return;
        }

        // 2.5 Mở các đỉnh kề q
        for (int q = 0; q < v; ++q) {
            if (matrix[p][q] > 0 && !close[q]) {
                int new_dist = d[p] + matrix[p][q];
                if (d[q] > new_dist) { // Gom cả 2.5.1 và 2.5.2
                    d[q] = new_dist;
                    parent[q] = p;
                    open.push({d[q], q}); // push dù q đã có hay chưa trong open
                }
            }
        }
    }

    cout << "Khong tim thay duong di tu " << s << " den " << t << endl;
}

int main() {
    int v, n;
    cin >> v >> n;

    vector<string> vertices(v);
    for (int i = 0; i < v; i++) {
        cin >> vertices[i];
    }

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    cout << "Nhap cac canh (u v w):\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < v; j++) 
            cin >> matrix[i][j];
    }

    int s, t;
    cout << "Nhap dinh bat dau va dinh ket thuc: ";
    cin >> s >> t;

    dijkstra(s, t, matrix);

    return 0;
}