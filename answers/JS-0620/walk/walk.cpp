#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define int long long
const int mod=1e9+7;
struct node{
	int c,d;
}a[N],final[15];
int n,k,size[15],change[15],sizef,flag=0,res[15],ans=0;
int calc(){
	int cnt=0,res2[15],ff=0;
	for(int i=1;i<=k;i++)res2[i]=res[i];
	while(ff==0){
		for(int i=1;i<=n;i++){
			res2[a[i].c]+=a[i].d;
			cnt++;
			if(res2[a[i].c]<=0||res2[a[i].c]>size[a[i].c]){
				ff=1;
				break;
			}
		}
	}
	return cnt;
}
void dfs(int step){
	if(step==k+1){
//		for(int i=1;i<=k;i++){
//			cout<<res[i]<<" ";
//		}
//		cout<<endl;
		int t=calc();
//		cout<<t<<endl;
		ans+=t;
//		cout<<ans<<endl;
		return;
	}
	for(int i=1;i<=size[step];i++){
		res[step]=i;
		dfs(step+1);
		res[step]=0;
	}
}
signed main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		scanf("%d",&size[i]);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].c,&a[i].d);
//	cout<<endl;
	for(int i=1;i<=n;i++){
		change[a[i].c]+=a[i].d;
	}
	for(int i=1;i<=k;i++){
		if(change[i]!=0){
			flag=1;
		}
	}
	if(flag==0){
		cout<<-1;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
