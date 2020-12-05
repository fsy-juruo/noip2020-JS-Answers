#include<bits/stdc++.h>
//#define int long long
//#define mo
using namespace std;
int read(){
	int num=0,f=1;char c=getchar();
	while(!isdigit(c)){if (c=='-') f=-1; c=getchar(); }
	while(isdigit(c)){num=num*10+c-'0'; c=getchar(); }
	return num*f;
}
int n,m;
int sta[55][405],top[55];
vector<pair<int,int> > ans;
void put(int x,int lx,int y,int ly){
	if (top[y]+x-lx<=m) 
	{
		for(int i=top[x];i>lx;i--)
		{
			ans.push_back(make_pair(x,y));
			sta[y][++top[y]]=sta[x][i];
		}
		top[x]=lx;
		return;
	}
	if (top[x]+y-ly<=m)
	{
		swap(x,y);
		swap(lx,ly);
		for(int i=top[x];i>lx;i--)
		{
			ans.push_back(make_pair(x,y));
			sta[y][++top[y]]=sta[x][i];
		}
		top[x]=lx;
	}
	for(int i=1;i<=n+1;i++)
	{
		if (top[i]+top[y]-ly+top[x]-lx<=m)
		{
			for(int j=top[x];j>lx;j--)
			{
				sta[i][++top[i]]=sta[x][j];
				ans.push_back(make_pair(x,i));
			}
			for(int j=top[y];j>ly;j--)
			{
				sta[i][++top[i]]=sta[y][j];
				ans.push_back(make_pair(y,i));
			}
			return;
		}
	}
	int mi=0;
	top[0]=INT_MAX;
	for(int i=1;i<=n+1;i++)
	{
		bool fff=0;
		for(int j=2;j<=top[i]/4*3;j++)
			if (top[j]!=top[j-1])
			{
				fff=1;
				break;
			}
		if (fff==1) continue;
		if (top[i]<top[mi]) mi=i;
	}
	if (mi==0) mi=1;
	if (mi==x||mi==y) mi++;
	if (mi==x||mi==y) mi++;
	for(int i=top[mi];i>=1;i--)
	{
		for(int j=1;j<=n+1;j++)
		{
			if (mi==j) continue;
			if (top[mi]==0) break;
			while(top[j]!=m)
			{
				sta[j][++top[j]]=sta[mi][top[mi]--];
				ans.push_back(make_pair(j,mi));
				if (top[mi]==0) break;
			}
		}
	}
	for(int i=top[x];i>lx;i--)
	{
		sta[mi][++top[mi]]=sta[x][i];
		ans.push_back(make_pair(x,mi));
	}
	top[x]=lx;
	for(int i=top[y];i>ly;i--)
	{
		sta[mi][++top[mi]]=sta[y][i];
		ans.push_back(make_pair(y,mi));
	}
	top[y]=ly;
}
bool merge(){
	bool flag=0;
	for(int i=1;i<=n+1;i++)
		for(int j=i+1;j<=n+1;j++)
			if (sta[i][top[i]]==sta[j][top[j]])
			{
				flag=1;
				int ii,jj;
				for(ii=top[i]-1;ii>=0;ii--)
					if (sta[i][ii]!=sta[i][ii+1]) break;
				for(jj=top[j]-1;jj>=0;jj--)
					if (sta[j][jj]!=sta[j][jj+1]) break;
				int x=i,y=j;
				if (ii==0) put(y,jj,x,ii);
				else if (jj==0) put(x,ii,y,jj);
				else
				{
					if (top[x]-ii>=top[y]-jj) 
					{
						swap(x,y);
						swap(ii,jj);
					}
					put(x,ii,y,jj);
				}
			}
	return flag;
}
void put2(){
	int x,i;
	while(1)
	{
		x=rand()%(n+1)+1;
		for(i=top[x]-1;i>=0;i--)
			if (sta[x][i]!=sta[x][i+1])	break;
		if (i>m/3) ;
		else
		{
			int y;
			while(1)
			{
				
				y=rand()%(n+1)+1;
				if (x==y) continue;
				while(top[y]!=m&&top[x]!=0)
				{
					sta[y][++top[y]]=sta[x][top[x]--];
					ans.push_back(make_pair(x,y));
				}
				break;
			}
			break;
		}
	}
}
void put3(){
	int x=rand()%(n+1)+1,y=rand()%(n+1)+1;
	if (x==y||top[x]==m||top[y]==0) return ;
	sta[x][++top[x]]=sta[y][top[y]--];
}
signed main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	srand(time(0));
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			sta[i][++top[i]]=read();
	int flag=1;
	while(flag)
	{
		put3();
		flag=0;
		for(int i=1;i<=n;i++)
		{
			if (top[i]!=m) 
			{
				flag=1;
			}
			for(int j=2;j<=top[i];j++)
				if (sta[i][j]!=sta[i][j-1]) 
				{
					flag=1;
				}
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].first<<" "<<ans[i].second<<'\n';
	return 0;
}

