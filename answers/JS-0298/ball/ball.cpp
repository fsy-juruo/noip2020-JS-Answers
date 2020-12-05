#include<bits/stdc++.h>
using namespace std;
const int N=820010;
int n,m;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
namespace A{
	int stk[4][22],top[4];
	struct ans{
		int from,to;
	}a[N];
	int tot;
	void move(int x,int y){
		a[++tot].from=x;
		a[tot].to=y;
		stk[y][++top[y]]=stk[x][top[x]];
		top[x]--;
	}
	void solve(){
		if(n==1){
			printf("0\n");
			return;
		}
		top[1]=top[2]=m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)stk[i][j]=read();
		int num=0;
		for(int i=1;i<=m;i++)if(stk[1][i]==1)num++;
		for(int i=1;i<=m-num;i++){//从2中取一部分到3中 
			a[++tot].from=2;
			a[tot].to=3;
			stk[3][++top[3]]=stk[2][top[2]];
			top[2]--;
		}
		for(int i=1;i<=m;i++){//1:分流 
			if(stk[1][top[1]]==1)move(1,3);
			else move(1,2);
		}
		for(int i=1;i<=num;i++)move(3,1);//3的顶部已经全都是1，扔回去 
		for(int i=1;i<=m-num;i++)move(2,1);//2's top are all 2,put them into 1
		while(top[2])move(2,3);
		for(int i=1;i<=m-num;i++)move(1,2);
		while(top[3]){
			if(stk[3][top[3]]==1)move(3,1);
			else move(3,2);
		}
		printf("%d\n",tot);
		for(int i=1;i<=tot;i++)printf("%d %d\n",a[i].from,a[i].to);
	}
}
namespace B{
	void solve(){
		
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(),m=read();
	if(n<=2)A::solve();
	else B::solve();
	return 0;
}

