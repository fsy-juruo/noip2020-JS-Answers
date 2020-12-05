#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005,MAXM=11;
int n,m,mp[MAXN][6];
int wat[MAXN][2];
int _gcd(int aa,int bb){
	while(aa!=bb)
	{
		if(aa>bb) aa-=bb;
		else bb-=aa;
	}
	return aa;
}
void free(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	return;
}
void dfs(int aa,int bb,int cc){
	int dd;
	if(mp[aa][0]==0)
	{
		if(wat[aa][0]==0)
		{
			wat[aa][0]=bb;
			wat[aa][1]=cc;
		}
		else
		{
			wat[aa][0]=wat[aa][0]*cc+bb*wat[aa][1];
			wat[aa][1]*=cc;
			dd=_gcd(wat[aa][0],wat[aa][1]);
			wat[aa][0]/=dd;
			wat[aa][1]/=dd;
		}
		return;
	}
	cc*=mp[aa][0];
	dd=_gcd(bb,cc);
	bb/=dd;
	cc/=dd;
	for(int ii=1;ii<=mp[aa][0];ii++) dfs(mp[aa][ii],bb,cc);
	return;
}
int rin(){
	char cc;
	int aa=1,bb;
	cc=getchar();
	if(cc=='-') aa=-1;
	else bb=cc-48;
	cc=getchar();
	while(cc<=57&&cc>=48)
	{
		bb*=10;
		bb+=cc-48;
		cc=getchar();
	}
	return aa*bb;
}
int main()
{
	free();
	n=rin();
	m=rin();
	memset(mp,0,sizeof(m));
	for(int i=1;i<=n;i++)
	{
		mp[i][0]=rin();
		for(int j=1;j<=mp[i][0];j++) mp[i][j]=rin();
	}
	for(int i=1;i<=m;i++) dfs(i,1,1);    //at point i, water 1/1
	for(int i=1;i<=n;i++) if(mp[i][0]==0) printf("%d %d\n",wat[i][0],wat[i][1]);
	return 0;
}
