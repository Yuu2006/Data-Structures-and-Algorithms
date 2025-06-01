/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
include
[
]
###End banned keyword*/
#include <iostream>
#include <cmath>

using namespace std;
//###INSERT CODE HERE -

struct Point3D {
    double x, y, z;
    Point3D* next;
};

struct LinkedList {
    Point3D* head;
    
    LinkedList() {
        head = NULL;
    }
    
    // Thêm điểm vào cuối danh sách
    void addPoint(double x, double y, double z) {
        Point3D* newPoint = new Point3D;
        newPoint->x = x;
        newPoint->y = y;
        newPoint->z = z;
        newPoint->next = NULL;
        
        if (head == NULL) {
            head = newPoint;
        } else {
            Point3D* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newPoint;
        }
    }
    
    // Tìm kiếm điểm trong danh sách
    int findPoint(double x, double y, double z) {
        Point3D* current = head;
        int index = 0;
        
        while (current != NULL) {
            // So sánh tọa độ với độ chính xác epsilon
            if (areEqual(current->x, x) && 
                areEqual(current->y, y) && 
                areEqual(current->z, z)) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1; // Không tìm thấy
    }
    
    // Hàm so sánh số thực với độ chính xác
    bool areEqual(double a, double b) {
        const double EPSILON = 1e-9;
        return abs(a - b) < EPSILON;
    }
};

int main() {
    LinkedList pointList;
    int n;
    
    // Nhập n điểm vào danh sách A
    cin >> n;
    for (int i = 0; i < n; i++) {
        double x, y, z;
        cin >> x >> y >> z;
        pointList.addPoint(x, y, z);
    }
    
    // Nhập m điểm để kiểm tra
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        double x, y, z;
        cin >> x >> y >> z;
        
        int result = pointList.findPoint(x, y, z);
        if (result == -1) {
            cout << "KHONG" << endl;
        } else {
            cout << result << endl;
        }
    }
    
    return 0;
}

