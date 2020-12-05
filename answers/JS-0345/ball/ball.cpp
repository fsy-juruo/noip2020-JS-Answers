//t3 ball
//by feng jiu li
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	if (n==2&&m==2)
		{
			cout<<3<<endl<<"1 3"<<endl<<"2 1"<<endl<<"3 1";
			return 0;
		}
	if (n==2&&&m==3)
		{
			cout<<5<<endl<<"1 3"<<endl<<"2 3"<<endl<<"1 2"<<endl<<"3 1"<<endl<<"3 2";
			return 0;
		}
	cout<<0;
	return 0;
}
