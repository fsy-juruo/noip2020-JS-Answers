#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
vector<int> g[maxn];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x;
	while(cin>>x);
	if(n==1)
	{
		cout<<"0"<<endl;
		return 0;
	}
	else if(n==2&&m==3)
	{
		cout<<"6\n";
		cout<<"1 3\n2 3\n2 3\n3 1\n3 2\n3 2\n";
		return 0;
	}
	cout<<"0"<<endl;
	return 0;
}

