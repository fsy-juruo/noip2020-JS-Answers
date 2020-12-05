#include<bits/stdc++.h>
using namespace std;
string s;
int T;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>s;
		cout<<s.size()*s.size();
	}
	return 0;
}
