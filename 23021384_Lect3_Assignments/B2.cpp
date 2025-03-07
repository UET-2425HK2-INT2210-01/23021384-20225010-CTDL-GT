#include<iostream>
using namespace std;
long long powerOfTwo_Iterative(int n){
	long long result = 1;
	for (int i = 0; i < n; i++){
		result *= 2;
	}
	return result;
}
int main(){
	int n;
	cin >> n;
	cout << "2^" << n << " = " << powerOfTwo_Iterative(n) << endl;
	return 0;
}