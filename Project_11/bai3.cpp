#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool a[26]{0};
    
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        
        if (isalpha(c)) {
            char kitu = tolower(c);
            int index = kitu - 'a';
            a[index] = true;
        }
    }
    
    int dem = 0;
    for (int i = 0; i < 26; i++) {
        if (!a[i]) {
            dem++;
        }
    }
    
    cout << dem << endl;
    
    return 0;
}