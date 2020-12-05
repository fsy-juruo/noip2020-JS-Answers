#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t,i;
	string s;
	cin>>t;
	for(i=1;i<=t;i+=1){
		cin>>s;
		cout<<(i+1)*(i+1);
	}
	return 0;
}
