#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	ios::sync_with_stdio(false);
	srand(time(0));
	int x,y,t,a,b;
	cin>>x>>y;
	for(int i=1;i<=x;i++)	
		cin>>t;
	for(int i=1;i<=y;i++)	
		cin>>t;
	cout<<x+y<<endl;
	for(int i=1;i<=x+y;i++){
		a=rand()%(x+1);
		b=rand()%(x+1);
		while(a==b)
			b=rand()%(x+1);
		cout<<a+1<<' '<<b+1<<endl;
	}
	return 0;
}

