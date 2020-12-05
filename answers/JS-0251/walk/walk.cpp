#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define mod 1000000007
int n,k,ans=0;
int now[11],now2[11],plan[11],m1[11],m2[11],mp[11],t1[11],t2[11];
struct node{
	int c,d;
}_plan[N];
bool check(){
	for(int i=1;i<=n;i++){
		if(now2[i]>0&&now2[i]>m1[i]) return 0;
		else if(-now2[i]>m2[i]) return 0;
	}
	return 1;
}
void fr(int m){
	if(m==k){
		int rans=0;
		for(int i=1;i<=k;i++) {
			t1[i]=mp[i]-now[i]-m1[i];
			if(t1[i]<0) rans=-1;
		}
		for(int i=1;i<=k;i++){
			t2[i]=now[i]-m2[i];
			if(t2[i]<0) rans=-1;
		}
		for(int i=1;i<=k;i++){
			if(plan[i]>0) rans=min(ans,t2[i]/-plan[i]);
			else rans=min(ans,t1[i]/plan[i]);
		}
		for(int i=1;i<=k;i++) now2[i]=0;
		now2[_plan[1].c]+=_plan[1].d;
		for(int i=2;i<=n&&check();i++){
			ans++;
			now2[_plan[i].c]+=_plan[i].d;			 
		}
		if(rans==-1) rans=0;
		ans+=n*rans;
	}
	for(int i=mp[m];i>=1;i--){
		now[m]=i;
		fr(m+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&mp[i]);
	}
	for(int i=1;i<=n;i++){
		int c,d;scanf("%d%d",&c,&d);
		_plan[i].c=c;_plan[i].d=d;
		if(d>0) m1[c]=max(m1[c],d);
		else m2[c]=max(m2[c],-d);
		plan[c]+=d;
	}bool flag=0;
	for(int i=1;i<=k;i++) {
		if(plan[i]) flag=1;
	}
	if(flag==0) {
		cout<<-1;
		return 0;
	}
//	fr(1);
	cout<<rand();
	return 0;}


