/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multi_set
map
unordered_map
include
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

struct Customer {
    int number;
    char rice_type[20];
    Customer* next;
};

// Biến toàn cục cho Linked List
Customer* head = NULL;
Customer* tail = NULL;

// Hàm copy string thủ công
void copyString(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Thêm khách vào cuối danh sách
void addCustomer(int num, const char* type) {
    Customer* newCustomer = new Customer;
    newCustomer->number = num;
    copyString(newCustomer->rice_type, type);
    newCustomer->next = NULL;
    
    if (head == NULL) {
        head = tail = newCustomer;
    } else {
        tail->next = newCustomer;
        tail = newCustomer;
    }
}

// Xóa khách đầu danh sách
void removeCustomer() {
    if (head != NULL) {
        Customer* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
    }
}

// In danh sách khách hàng
void printCustomers() {
    if (head == NULL) {
        cout << "Tiem qua e, khong co khach nao" << endl;
    } else {
        Customer* current = head;
        while (current != NULL) {
            cout << current->number << " " << current->rice_type << endl;
            current = current->next;
        }
    }
}

int main() {
    int state;
    int customer_number = 1;
    char rice_type[20];
    
    while (cin >> state && state != -1) {
        if (state == 0) {
            // Khách vào quán
            cin >> rice_type;
            addCustomer(customer_number, rice_type);
            customer_number++;
        }
        else if (state == 1) {
            // Khách ra về
            removeCustomer();
        }
    }
    
    // In kết quả
    printCustomers();
    
    return 0;
}


