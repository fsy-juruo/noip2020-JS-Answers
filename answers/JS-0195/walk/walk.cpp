#include<bits/stdc++.h>
using namespace std;
struct step{
	int c,d;
}s[100005];
int ans;
int n,k;
int w[6];
int a[6];
int st[6];
int go(int x,int cnt){
	if(x>n){
		x=1;
		int flag=0;
		for(int i=1;i<=k;i++){
			if(a[i]!=st[i])flag=1;
		}
		if(flag==0){
			return -1;
		}
	}
	a[s[x].c]+=s[x].d;
	
//	for(int i=1;i<=k;i++){
//		cout<<a[i]<<"!!!!!!!!!!!"<<endl;
//	}
//	cout<<cnt<<endl<<endl;
	
	if(a[s[x].c]>w[s[x].c]||a[s[x].c]<=0){
		return (cnt+1)%1000000007;
	}else return go(x+1,cnt+1);
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int x=1;
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>w[i];
		x*=w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>s[i].c>>s[i].d;
	}
	for(int i=1;i<=k;i++){
		st[i]=1;
	}
	while(x--){
		for(int i=1;i<=k;i++){
			a[i]=st[i];
		}
		int hxd=go(1,0);
		if(hxd==-1){
			cout<<"-1"<<endl;
			return 0;
		}
		ans+=hxd;
		for(int i=k;i>=1;i--){
			st[i]++;
			if(st[i]>w[i]){
				st[i]=1;
				continue;
			}
			break;
		}
//		for(int i=1;i<=k;i++){
//			cout<<st[i]<<"!!!!!!!!!"<<endl;
//		}
	}
	cout<<ans;
	return 0;
}
