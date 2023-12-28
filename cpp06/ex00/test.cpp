#include <string>
#include <iostream>
using namespace std;

int main() {
	try {
	cout << stof("nAn")<< endl; 
	cout << stof("Nan")<< endl; 
	cout << stof("inf")<< endl; 
	cout << stof("INF")<< endl; 
	cout << stof("naN")<< endl; 
	cout << stof("aaa")<< endl; 
	} catch (const invalid_argument &e) {
		cout	<< e.what()<< endl;
	}
}

// checkInt 
// プラス
// checkFloat
// プラス
// checkDouble
// プラス

// INF
