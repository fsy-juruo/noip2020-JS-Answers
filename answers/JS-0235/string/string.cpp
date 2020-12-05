#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string r;
		cin>>r;
		cout<<r.size();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

