#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool compare(string a, string b) {		//check if a >= b, yes return true
	if (a.length() == b.length() || a.length() > b.length()) {
		for (int i = 0; i < b.length(); ++i) {
			if (a[i] > b[i]) return true;
			if (a[i] < b[i]) return false;
		}
		return true;
	}
	else {
		for (int i = 0; i < a.length(); ++i) {
			if (a[i] > b[i]) return true;
			if (a[i] < b[i]) return false;
		}
		return false;
	}	
}
void print(vector<string> arr) {
	if (arr.size() != 0) {
		cout << arr[0];
	}
	for (int i = 1; i < arr.size(); ++i) {
		cout << ' ' << arr[i];
	}
}
void swap(string& a, string& b) {
	string temp = a;
	a = b;
	b = temp;
}
int partition(vector<string>& arr, int left, int right) {
	int loc = left;
	while (true) {
		bool b = compare(arr[right], arr[loc]); 
		while (b && loc != right) {	//arr[right] >= arr[loc]
			right--;
			b = compare(arr[right], arr[loc]);
		}
		//b = compare(arr[right], arr[loc]);
		if (loc == right) return loc;
		else if (!b) {	//loc > right
			swap(arr[loc], arr[right]);
			loc = right;
		}
		b = compare(arr[loc], arr[left]);
		while (b && loc != left) {	//arr[loc] >= arr[left]
			left++;
			b = compare(arr[loc], arr[left]);
		}
		//b = compare(arr[loc], arr[left]);
		if (loc == left) return loc;
		else if(!b){	//left > loc
			swap(arr[loc], arr[left]);
			loc = left;
		}
	}
}
void quickSort(vector<string>& arr, int begin, int end) {
	int loc = 0;	
	if (begin < end) {
		loc = partition(arr, begin, end);
		quickSort(arr, begin, loc - 1);
		quickSort(arr, loc + 1, end);
	}
}
int main(void) {
	stringstream ss;
	vector<string> arr;
	string str;
	getline(cin, str);
	ss << str;
	while (ss >> str) {
		arr.push_back(str);
	}
	quickSort(arr, 0, arr.size() - 1);
	print(arr);
}