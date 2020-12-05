#include<bits/stdc++.h>
#define N 1000010
using namespace std;
inline int read(){
	int w=1,x=0;
	char ch=0;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return w*x;
}
int n,m,cnt,top[N];
int stk[55][410];
struct node{
	int from,to;
}op[1000010];
bool flag=false;

bool check(){
	for(int i=1;i<=n+1;i++)
		if(top[i]!=m&&top[i]!=0)return false;
	for(int i=1;i<=n+1;i++){
		if(top[i]){
			for(int j=1;j<=m;j++)
				if(stk[i][j]!=stk[i][1])return false;
		}
	}
	return true;
}

void dfs(int step,int f,int e,int ff,int ee){
	if(flag)return ;
	if(check()){
		printf("%d\n",step-1);
		for(int i=1;i<=step-1;i++)
			printf("%d %d\n",op[i].from,op[i].to);
		
		flag=true;
		return ;
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n+1;j++){
			if(top[i]==0||top[j]>=m||(j==i)||(i==f&&j==e)||(i==ff&&j==ee))continue;
			int t=stk[i][top[i]--];
			stk[j][++top[j]]=t;
			op[step].from=i,op[step].to=j;
			dfs(step+1,ff,ee,i,j);
			top[j]--;
			stk[i][++top[i]]=t;
		}
	}
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		top[i]=m;
		for(int j=1;j<=m;j++){
			stk[i][j]=read();
		}
	}
	dfs(1,0,0,0,0);
	return 0;
}
