#include<bits/stdc++.h>
using namespace std;
#define CIN int
#define reg register int
CIN rf(){
	CIN num=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}
stack<int>z[60];int n,m;
bool f[60];
int c[61][411];
int ans[820111][2];
int cnt=0;
void dfs(int C,int l){
	while(c[l][C]<m){
		int x;
		for(reg i=1;i<=l-1;++i){
			if(i!=l&&c[i][C]>0){
				x=i;break;
			}
		}
		while(z[x].size()>0&&z[x].top()!=C){
			for(reg i=1;i<=l;++i){
				if(f[i]==0&&z[x].size()>0&&z[x].top()!=C&&z[i].size()<m&&i!=x){
					z[i].push(z[x].top());
					c[x][z[x].top()]--;
					c[i][z[x].top()]++;
					z[x].pop();
					ans[++cnt][0]=x;
					ans[cnt][1]=i;
				}
			}
		}
		int y=-1;
		for(reg i=1;i<=l;++i){
			if(z[i].size()<m&&i!=x&&i!=l){
				y=i;break;
			}
		}
		if(y==-1){
			for(reg i=1;i<=l;++i){
				if(f[i]==0&&i!=x&&i!=l){
				y=i;z[l].push(z[y].top());
				c[y][z[y].top()]--;
				c[l][z[y].top()]++;
				z[y].pop();
				ans[++cnt][0]=y;
				ans[cnt][1]=l;
				break;
			}		
			}
		}
		z[y].push(z[x].top());
		c[x][z[x].top()]--;
		c[y][z[x].top()]++;
		z[x].pop();
		ans[++cnt][0]=x;
		ans[cnt][1]=y;
		while(z[l].size()>0&&z[l].top()!=C){
			for(reg i=1;i<=l;++i){
				if(z[l].size()>0&&z[l].top()!=C&&z[i].size()<m&&i!=y&&i!=l){
					z[i].push(z[l].top());
					c[l][z[l].top()]--;	
					c[i][z[l].top()]++;
					z[l].pop();
					ans[++cnt][0]=l;
					ans[cnt][1]=i;
				}
			}
		}
		z[l].push(z[y].top());
		c[y][z[y].top()]--;
		c[l][z[y].top()]++;
		z[y].pop();
		ans[++cnt][0]=y;
		ans[cnt][1]=l;
	}
	f[l]=0;
	if(l>=3){		
	while(z[l-1].size()>0){
		for(reg i=1;i<=l-2;++i){
			if(z[l-1].size()>0&&z[i].size()<m){
				z[i].push(z[l-1].top());
				c[l-1][z[l-1].top()]--;	
				c[i][z[l-1].top()]++;
				z[l-1].pop();
				ans[++cnt][0]=l-1;
				ans[cnt][1]=i;
			}
		}
	}
	}
	if(l>3)dfs(C+1,l-1);
}
void OUT(){
	printf("%d\n",cnt);
	for(reg i=1;i<=cnt;i++){
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=rf();m=rf();
	for(reg i=1;i<=n;++i){
		for(reg j=1;j<=m;++j){
			int x=rf();
			z[i].push(x);
			c[i][x]++;
		}
	}
	if(n<=1){
		puts("0");
		return 0;
	}
	dfs(1,n+1);
	OUT();	
	return 0;
}
//zz rp++

