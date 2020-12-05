#include<bits/stdc++.h>
#define mkp make_pair
#define ms(a,x) memset(a,x,sizeof (a))
#define io_speed_up ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug cout<<"bug"<<"\n"
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rrep(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int maxk=15;
const int maxn=5e5+5;

int n,k;
int w[maxk];
int c[maxn],d[maxn];
vector<int> pos;

set<pair<vector<int>,int> > vis;

int ans=0;

void output(vector<int> v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<"\n";
}

void dfs(vector<int> &pos,int i,int cnt){
//	debug;
	if(vis.find(mkp(pos,i))!=vis.end()){
		output(pos);
		ans=-1;
		return;
	} 
	vis.insert(mkp(pos,i));
	pos[c[i]]+=d[i];
	if(pos[c[i]]>w[c[i]] || pos[c[i]]<1){
		ans+=cnt+1;
		return;
	}
	int NXT=i+1;
	if(NXT>n) NXT=1;
	dfs(pos,NXT,cnt+1);
}

void nxt(vector<int> &pos){
	pos[0]+=1;
	int i=0;
	while(i<k && pos[i]>w[i]){
		pos[i]=1;
		pos[i+1]+=1;
		i++;
	}
//	for(int i=0;i<pos.size();i++){
//		cout<<pos[i]<<" ";
//	}
//	cout<<"\n";
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	io_speed_up;
	cin>>n>>k;
	int day=1;
	rep(i,0,k-1){
		cin>>w[i];
		day*=w[i];
	}
	rep(i,1,n){
		cin>>c[i]>>d[i];
		c[i]--;
	}
	rep(i,1,k){
		pos.push_back(i);
	}
	vis.clear();
	vector<int> tmp=pos;
	dfs(tmp,1,0);
	if(ans==-1){
		cout<<"-1\n";
		return 0;
	}
	rep(i,2,day){
		nxt(pos);
		vis.clear();
		vector<int> tmp=pos;
		dfs(tmp,1,0);
		if(ans==-1){
			cout<<"-1\n";
			return 0;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
//remember to check:
//1.long long
//2.freopen
//3.array size
//4.big testdata
//5.file name
//6.file comparison
//7.mod

