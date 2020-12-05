#include<bits/stdc++.h>
#define int long long
#define bug cout<<"bug: "<<__LINE__<<endl
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=505;

int n,m;
int col[maxn][maxn];
int vis[maxn];
pair<int,int> opt[100005];

signed main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	if(n==1){
		cout<<0<<endl;
	}	
	else if(n==2){
		int col1[25],col2[25],vis1[25],vis2[25];
		memset(vis1,0,sizeof vis1);
		memset(vis2,0,sizeof vis2);
		int tx=0;
		int ans=0;
		stack<int> st1,st2,st3;
		for(int i=1;i<=m;i++){
			cin>>col1[i];
			if(col1[i]==1){
				tx++;
			}
			st1.push(col1[i]);
		}
		for(int i=1;i<=m;i++){
			cin>>col2[i];
			st2.push(col2[i]);
		}
		for(int i=1;i<=tx;i++){
			ans++;
			opt[ans]={2,3};
			st3.push(st2.top());
			st2.pop();
		}
		int st1sz=st1.size();
		for(int i=0;i<st1sz;i++){
			int x=st1.top();
			st1.pop();
			if(x==1){
				ans++;
				opt[ans]={1,2};
				st2.push(x);
			}
			else{
				ans++;
				opt[ans]={1,3};
				st3.push(x);
			}
		}
//		bug;
		for(int i=0;i<tx;i++){
			st1.push(st2.top());
			st2.pop();
			ans++;
			opt[ans]={2,1};
		}
		for(int i=0;i<(m-tx);i++){
			st1.push(st3.top());
			st3.pop();
			ans++;
			opt[ans]={3,1};
		}
//		bug;
		int t[35];
		memset(t,0,sizeof t);
		int y=0;
		int st3sz=st3.size();
		for(int i=st3sz;i>0;i--){
			t[i]=st3.top();
			st3.pop();
			if(t[i]==1){
				y++;
			}
		}
		for(int i=1;i<=st3sz;i++){
			st3.push(t[i]);
		}
//		bug;
		for(int i=1;i<=y;i++){
			st2.push(st1.top());
			st1.pop();
			ans++;
			opt[ans]={1,2};
		}
//		bug;
		for(int i=1;i<=st3sz;i++){
			int x=st3.top();
			st3.pop();
			if(x==1){
				st1.push(1);
				ans++;
				opt[ans]={3,1};
			}
			else{
				st2.push(2);
				ans++;
				opt[ans]={3,2};
			}
		}
//		bug;
		while(st2.size()){
			if(st2.top()!=2){
				break;
			}
			st2.pop();
			st3.push(2);
			ans++;
			opt[ans]={2,3};
			if(st2.size()==0){
				break;
			}
		}
//		bug;
		while(st1.top()==1 && st1.size()){
//			bug;
			if(st1.top()!=1){
				break;
			}
			st1.pop();
			st2.push(1);
			ans++;
			opt[ans]={1,2};
			if(st1.size()==0){
				break;
			}
		}
//		bug;
		while(st1.size()){
			if(st1.top()!=2){
				break;
			}
			st1.pop();
			st3.push(2);
			ans++;
			opt[ans]={1,3};
			if(st1.size()==0){
				break;
			}
		}
//		bug;
		while(st2.size()){
			int x=st2.top();
			st2.pop();
			if(x==1){
				ans++;
				opt[ans]={2,1};
			}
			else{
				ans++;
				opt[ans]={2,3};
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=ans;i++){
			cout<<opt[i].first<<" "<<opt[i].second<<endl;
		}
	}
	
	return 0;
}
/*
2 3
1 1 2
2 1 2
*/
