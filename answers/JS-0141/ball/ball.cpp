#include<bits/stdc++.h>
using namespace std;
int n,m,top[55],a[55][405],mov1[820001],mov2[820001],lasfr=0,lasto=0,mov=0,l=1;
bool check(){
	for(int i=1;i<=n;i++){
		int s=a[i][1];
		if(top[i]<m)return 0;
		for(int j=1;j<=m;j++)if(a[i][j]!=s)return 0;
	}
	return 1;
}
void move(int fr,int to){
	top[to]++;
	a[to][top[to]]=a[fr][top[fr]];
	top[fr]--;
	lasfr=mov1[mov]=fr;
	lasto=mov2[mov]=to;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		top[i]=m;
		for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	}
	while(1){
		l=1,mov++;
		for(int i=1;i<=n;i++)
			if(top[n+1]>0&&top[i]<m&&a[n+1][top[n+1]]==a[i][top[i]]&&l&&(n+1!=lasto||i!=lasfr))
				move(n+1,i),l--;
		for(int i=1;i<=n;i++)
			if(top[i]>0&&a[i][top[i]]!=a[i][top[i]-1]&&top[n+1]<m&&l&&(i!=lasto||n+1!=lasfr))
				move(i,n+1),l--;
		if(check()||mov>820000)break;
	}
	printf("%d\n",mov);
	for(int i=1;i<=mov;i++)printf("%d %d\n",mov1[i],mov2[i]);
	return 0;
}
