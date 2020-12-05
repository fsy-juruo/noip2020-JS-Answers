#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],x[100001],y[100001];
long long ans;
void dfs(int c,int k){
	if(c!=m){
		for(int i=1;i<=a[c+1];i++){
			dfs(c+1,100*k+i);
		}
	}
	else{
		int i=1,s[101],r=0;
		while(k!=0){
			r++;
			s[r]=k%100;
			k/=100;
		}
		while(1){
			ans++;
			s[x[i]]+=y[i];
			if(s[x[i]]>a[x[i]]||s[x[i]]<1){
				break;
			}
			i++;
			if(i!=n)i%=n;
		}
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=a[1];i++){
		dfs(1,i);
	}
	long long ssss=1000000007;
	cout<<ans%ssss;
	return 0;
}

