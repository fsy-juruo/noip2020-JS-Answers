#include<iostream>
#include<cstdio>
#include<fstream>
#include<vector>
#define N 51
#define M 410
#define PII pair<int,int>
#define mk make_pair
#define pb push_back
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
int n,m,empty;
int arr[N][M];
vector<PII> ans;
void solve(){
	int a=m-1,b=m-1,c=-1;
	int white=arr[0][a],black;
	while(arr[0][a]==white){
		ans.pb(mk(1,3));
		arr[2][++c]=arr[0][a--];
	}
	black=arr[0][a];
	while(a<m-1&&b>=0&&c<m-1){
		if(arr[1][b]==white){
			ans.pb(mk(2,3));
			arr[2][++c]=arr[1][b--];
		}else{
			ans.pb(mk(2,1));
			arr[0][++a]=arr[1][b--];
		}
	}
	while(b>=0){
		ans.pb(mk(2,3));
		arr[2][++c]=arr[1][b--];
	}
	while(arr[0][a]==black&&a>=0){
		ans.pb(mk(1,2));
		arr[1][++b]=arr[0][a--];
	}
	while(a>=0){
		if(arr[0][a]==white)ans.pb(mk(1,3));
		else ans.pb(mk(1,2));
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)arr[i][j]=read();
	}
	if(n==2)solve();
	else cout<<0;
	return 0;
}
