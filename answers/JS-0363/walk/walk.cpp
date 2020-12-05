#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int N=10005;
int n,m,w[N],ans,x[N];
struct Node{
	int c,v;
}a[N];
bool check(){
	for(int i=1;i<=m;i++)if(x[i]<=0||x[i]>w[i])return false;
	return true;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>a[i].c>>a[i].v;
	}
	for(int i=0;i<=w[1];i++){
		for(int j=0;j<=w[2];j++){
			for(int k=0;k<=w[3];k++){
				for(int p=0;p<=w[4];p++){
					for(int q=0;q<=w[5];q++){
						int t=1;
						x[1]=i;x[2]=j;x[3]=k;x[4]=p;x[5]=q;
						while(check()){
							x[a[t].c]+=a[t].v;ans++;ans%=MOD;
							t++;if(t>n)t=1;
						}
						//cout<<i<<" "<<j<<" "<<k<<" "<<p<<" "<<q<<" : "<<sum<<endl;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}//15~30
/*
3 2
3 3
1 1
2 -1
1 1

5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1
*/
