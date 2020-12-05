#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=b;++i)
const int M=405,N=55;
int intrd(){int aaa;scanf("%d",&aaa);return aaa;}
void intpf(int aaa,int bbb){printf("%d %d\n",aaa,bbb);return;}
int n,m;
int l[N][M];
int ans[820005][2],step,aim,len;
void move(int x,int y){
	l[y][0]++;l[y][l[y][0]]=l[x][l[x][0]];l[x][0]--;
	step++;ans[step][0]=x;ans[step][1]=y;return;
}
void clearr(int t){
	int i=1;
	while(l[t][0]){
		while(l[i][0]<m&&l[t][0])move(t,i);
		i++;
	}
	return;
}
int find(int i){
	for(int j=l[i][0];j>=1;j--)
	    if(l[i][j]==aim)return j;
	return 0;
}
int empty(int x,int y){
	int i=1;
	while(l[i][0]==m)i++;if(i==x||i==y)i++;while(l[i][0]==m)i++;
	if(i==x||i==y)i++;while(l[i][0]==m)i++;
	return i;
}
void operat(int i,int p,int t){
	while(l[i][0]>p)move(i,empty(t-1,i));
	move(i,t-1);
	while(l[t][0]>len)move(t,empty(t-1,t));
	move(t-1,t);len++;return;
}
void solve()
{
	int t=n+1;
	while(t>1){
		clearr(t);
		move(t-1,t);aim=l[t][1];
		len=1;
		F(i,1,t-2){
			int p=find(i);
			while(p!=0){
			    operat(i,p,t);
			    p=find(i);
			}
		}
		int p=find(t-1);
		while(p!=0){
			    while(l[t-1][0]>p)move(t-1,empty(t-1,t-1));
				move(t-1,t);
			    p=find(t-1);
			}
		t--;
	}
	
}
void pf(){
	cout<<step<<endl;
	F(i,1,step)intpf(ans[i][0],ans[i][1]);
	return;
}
int main()
{
	freopen("ball.in","r",stdin);
        freopen("ball.out","w",stdout);
	cin>>n>>m;
	F(i,1,n)
	    F(j,1,m)l[i][j]=intrd();
	F(i,1,n)l[i][0]=m;
	solve();
	pf();
	return 0;
}
/*2 3
1 1 2
2 1 2*/
