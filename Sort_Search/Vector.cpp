#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> TuanVu;
	int n;
	int input; // n la so luong phan tu cua mang, input la gtri nhap vao
	cin >> n;


	//Nhap
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		TuanVu.push_back(input);
	}


	//Xuat
	//Cach 1
	// for (int i = 0; i < TuanVu.size(); i++){
	// 	// cout << TuanVu[i] << " "; 
	// 	//co the thay the 
	// 	// cout << TuanVu.at(i) << " ";
	// }
	cout << TuanVu.capacity();
	//Cach 2
	for (auto i : TuanVu)
	{
		cout << i << " ";
	}	
	cout << endl;
	int length = TuanVu.size();

	cout << length << endl;
	cout << TuanVu[0] + 0;

    //Xoa
	// TuanVu.pop_back();

	// for (auto i : TuanVu)
	// {
	// 	cout << i << " ";
	// }	

	// cout << endl << TuanVu.front();
	// cout << endl << TuanVu.back();


	// for (auto i : TuanVu)
	// {
	// 	cout << i << " ";
	// }	

	// cout << endl << TuanVu.empty();

}
