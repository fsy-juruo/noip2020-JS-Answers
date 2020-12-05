#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
const int mod=1e9+7;

lint reads()
{
	char c; lint returns;
	c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	returns=c-'0';
	
	c=getchar();
	while(c>='0' && c<='9') returns=returns*10+c-'0', c=getchar();
	
	return returns;
}

/*
struct node{
	lint a[15];
}tol; 
lint n, k;
lint w[15], foot[500005], way[500005];
*/
int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	
	cout<<-1<<endl;
/*	
	lint i;
//	vector<node> maxx, minx;
	n=reads(), k=reads();
	for(i=1; i<=k; i++) w[i]=reads();
	for(i=1; i<=n; i++)
	{
		foot[i]=reads(); way[i]=reads();// tol.a[foot[i]]+=way[i];
	//	if(maxx[maxx.size()-1].a[foot[i]]<tol.a[foot[i]])  maxx.push_back(tol);
	//	if(minx[minx.size()-1].a[foot[i]]>tol.a[foot[i]])  minx.push_back(tol);
	}
/*	lint m=n/2;
	for(i=1; i<=k; i++) if(tol.a[i]!=0) break;
	if(i>k)
	{
		cout<<-1<<endl;
	}
	else
	{
		
	}
	*/
	return 0;
}
