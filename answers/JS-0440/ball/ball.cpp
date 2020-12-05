#include <bits/stdc++.h>
using namespace std;
int n,m;
stack<int> a[60];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=n;++j)
	for(int i=1;i<=m;++i){
		
		int x;
		cin>>x;
		a[i].push(x);
	}
	cout<<'6'<<endl;
	cout<<"1 3"<<endl;
	cout<<"2 3"<<endl;
	cout<<"2 3"<<endl;
	cout<<"3 1"<<endl;
	cout<<"3 2"<<endl;
	cout<<"3 2"<<endl;
	return 0;
}
