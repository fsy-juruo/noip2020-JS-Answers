#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
int n,w[20],k,pos[20],tmp[20];
int sc[100086],sp[100086];
long long ans;
bool check(){
	for(int i=1;i<=k;i++){
		if(tmp[i]>w[i]||tmp[i]<1)return false;
	}
	return true;
}
void dfs(int de){
	if(de==k+1){
		int i=1;
		int sum=0;
		for(int i=1;i<=k;i++)tmp[i]=pos[i];
		while(check()){
			tmp[sc[i]]+=sp[i];
			i++;
			sum++;
			if(i>n)i=1;
		}
		ans+=sum;
	}else{
		for(int i=1;i<=w[de];i++){
			pos[de]=i;
			dfs(de+1);
		}
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)scanf("%d",w+i);
	for(int i=1;i<=n;i++){
		scanf("%d%d",sc+i,sp+i);
	}
	dfs(1);
	printf("%d\n",ans);
}
