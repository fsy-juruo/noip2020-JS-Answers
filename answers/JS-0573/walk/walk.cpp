#include<bits/stdc++.h>
using namespace std;
int n,k;
int w[100005],c[100005],d[100005];
int hash[15],flag;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&d[i]);
		hash[c[i]]+=d[i];
	}
	for(int i=1;i<=k;i++)
		if(hash[i]!=0)flag=1;
	if(!flag){
		cout<<-1;
		return 0;
	}
	return 0;
	
}
/*
3 2
3 3
1 1
2 -1
1 1
*/
