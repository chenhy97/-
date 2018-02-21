#include <iostream>
using namespace std;
void priority(int prio[]){
	string index = "RWQOJMVAHBSGZXNTCIEKUPDYFL";
	for(int i = 0;i < 26;i ++){
		int temp = index[i] - 'A';
		prio[temp] = 26 - i;
	}
}

int main(){
	string c;
	cin >> c;
	int prio[26];
	for(int i = 0;i < 26;i ++){
		prio[i] = 0;
	}
	priority(prio);
	for(int i = 0;i < c.length();i ++){
		int min = i;
		for(int j = i + 1;j < c.length();j ++){
			int temp = c[j]-'A';
			int p = prio[temp];
			if(p > prio[c[min] - 'A'])	min = j;
		}
		char temp = c[min];
		c[min] = c[i];
		c[i] = temp;
	}
	cout << c;
}
