#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int lim=820000;
int press[55],tmp[55],a[55][405],S[55];
int look[5*lim][35],looks[5*lim][35];
struct step
{
	int u,v;
}stp[lim+5],ans[lim+5];
int n,m,cnt,cap,cc;
bool flag;
bool judge()
{
	for (int i=1;i<=n+1;i++)
		if (press[i]!=0&&press[i]!=((1<<m)-1)) return false; 
	return true; 
}
void copy(int L)
{
	cc=L-1;
	for (int i=1;i<=L;i++) ans[i]=stp[i];	
}
void dfs(int dep)
{
	if (flag) return;
	if (dep>lim+1) return;
	if (judge()) {flag=true;copy(dep);return;}
	for (int i=1;i<=n+1;i++) 
		for (int j=1;j<=n+1;j++)
			if (i!=j&&S[i]>0&&S[j]<m) 
			{
				int npress[55]={0};
				for (int l=1;l<=n+1;l++) npress[l]=press[l];
				npress[j]=(press[j]<<1)+(press[i]&1);
				npress[i]>>=1;
				S[i]--,S[j]++;
				bool t=false,f;
				for (int p=1;p<=cnt;p++)
				{
					f=false;
					for (int l=1;l<=n+1;l++)
						if (npress[l]!=look[p][l]||S[l]!=looks[p][l]) {f=true;break;}
					if (!f) {t=true;break;}
				}
				if (!t) 
				{
//					cout<<dep<<" "<<i<<" "<<j<<endl;
//					for (int l=1;l<=n+1;l++) cout<<npress[l]<<" ";
//					cout<<endl;
					cnt++;
					for (int l=1;l<=n+1;l++)
						look[cnt][l]=npress[l],looks[cnt][l]=S[l],tmp[l]=press[l],press[l]=npress[l];
					stp[dep].u=i,stp[dep].v=j;
					dfs(dep+1);
					for (int l=1;l<=n+1;l++) press[l]=tmp[l];
				}
				S[i]++,S[j]--;
			} 	
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)	
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]),a[i][j]--,S[i]++;
// 	if (n==2)
	{
		flag=false;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				press[i]=(press[i]<<1)+a[i][j];
//		for (int i=1;i<=n;i++) cout<<press[i]<<" ";
		cap=0;dfs(1);
		printf("%d\n",cc);
		for (int i=1;i<=cc;i++) printf("%d %d\n",ans[i].u,ans[i].v);
	}
	return 0; 
}

