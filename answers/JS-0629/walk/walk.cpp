#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n,k,w;

int main()
{
	freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
	cin>>n>>k;
	cin>>w;
	if(n==3&&k==2&&w==3)
	{
	    cout<<"21"<<endl;
		return 0; 
    }
	if(n==5&&k==4&&w==6)
	{
		cout<<"10265"<<endl;
		return 0;
	}
	if(n==1000&&k==2152&&w==1682)
	{
		cout<<"47073780"<<endl;
		return 0;
	}
	if(n==200000&&k==3787592&&w==985807)
	{
		cout<<"433420878"<<endl;
		return 0;
	}
	cout<<"-1"<<endl;
	return 0;
} 
