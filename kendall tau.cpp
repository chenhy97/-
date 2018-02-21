#include <iostream>
using namespace std;
void getpriority(int a[],int size,int aindex[]){
	for(int i = 0;i < size;i ++){
		aindex[a[i]] = i;
	}
}
int getdistance(int a[],int b[],int size){
	int aindex[size];
	getpriority(a,size,aindex);
	int count = 0;
	for(int i = 0;i < size;i ++){
		for(int j = i;j > 0 && aindex[b[j]] < aindex[b[j - 1]];j --){
			int temp = b[j];
			b[j] = b[j - 1];
			b[j - 1] = temp;
			count ++;
		}
	}
	return count;
}
int main(){
	int size = 7;
	int a[size],b[size];
	for(int i = 0;i < size;i ++){
		cin >> a[i];
	}
	for(int i = 0;i < size;i ++){
		cin >> b[i];
	}
	cout << getdistance(a,b,size);
}
