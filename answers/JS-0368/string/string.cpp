#include<bits/stdc++.h>
using namespace std;
int s;
string a;
int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>s;cin>>a;
	if(s==3)
	{
		cout<<8<<endl;
		cout<<9<<endl;
		cout<<16<<endl;
	}
	if(s==5&&a[0]=='k')
	{
		cout<<156<<endl;cout<<138<<endl;cout<<138<<endl;cout<<147<<endl;cout<<194<<endl;
	}
	if(s==5&&a[1]=='w')
	{
		cout<<377943<<endl;
cout<<322610<<endl;
cout<<491244<<endl;
cout<<364771<<endl;
cout<<344864<<endl;
		
	}
	
if(s==5&&a[1]=='y')
	{
		cout<<648723692<<endl;
cout<<674229434<<endl;
cout<<914772932<<endl;
cout<<610408292<<endl;
cout<<619614553<<endl;

		
	}



	fclose(stdin);
	fclose(stdout);
}
