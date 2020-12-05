#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=55;
const int INF=1000000007;

int read() {
	int x=0,f=1,c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}

int n,m;
vector<int> bs[maxn];

ostream& operator<<(ostream& out,pii p){
	out<<p.first<<' '<<p.second;
	return out;
}

namespace task10 {
	int tot[15];
	stack<pii> now[15];
	pair<pii,int> op[820000];
	int ptr;
	int sum;
	void print() {
		printf("%d\n",sum);
		for(int i=0; i<ptr; ++i) {
			for(int j=0; j<op[i].second; ++j)printf("%d %d\n",op[i].first.first+1,op[i].first.second+1);
		}
	}
	void debug(int x){
		if(now[x].size())cerr<<now[x].top()<<endl;
		else cerr<<"NONE\n";
	}
	void dfs() {
		int cnt=0;
		for(int i=0; i<n+1; ++i)if(now[i].size()&&now[i].top().second==m)cnt++;
		if(cnt==n) {
			print();
			exit(0);
		}
		for(int i=0; i<n+1; ++i) {
			if(ptr&&op[ptr-1].first.second==i)continue;
			if(now[i].size()==0)continue;
			for(int j=0; j<n+1; ++j) {
				if(tot[j]+now[i].top().second>m)continue;
				if(i==j)continue;
				pii tmp=now[i].top();
				op[ptr++]=make_pair(pii(i,j),tmp.second);
				sum+=tmp.second;
				tot[i]-=tmp.second;
				tot[j]+=tmp.second;
				bool flag=true;
				if(now[j].size()&&now[j].top().first==now[i].top().first) {
					pii nw=now[j].top();
					now[j].pop();
					nw.second+=tmp.second;
					now[j].push(nw);
					flag=false;
				} else {
					now[j].push(now[i].top());
				}
				now[i].pop();
				dfs();
				now[i].push(tmp);
				if(flag) {
					now[j].pop();
				} else {
					pii nw=now[j].top();
					now[j].pop();
					nw.second-=tmp.second;
					now[j].push(nw);
				}
				ptr--;
				tot[i]+=tmp.second;
				tot[j]-=tmp.second;
				sum-=tmp.second;
			}
		}
	}
	void solve() {
		for(int i=0; i<n; ++i) {
			int p=0;
			for(; p<bs[i].size();) {
				int j=p;
				while(j<bs[i].size()&&bs[i][j]==bs[i][p])++j;
				now[i].push(make_pair(bs[i][p],j-p));
				p=j;
			}
			tot[i]=m;
		}
		dfs();
	}
}

namespace task70{
	pii op[820000];
	int ptr=0;
	bool done[55];
	void solve(){
		memset(done,0,sizeof(done));
		int ballcnt=0;
		while(1){
			if(ballcnt==n)break;
			cerr<<ballcnt<<endl;
			int nowcolor=bs[0][(int)bs[0].size()-1];
			int dest=n-ballcnt;
			for(int i=0;i<dest;++i){
				if(bs[i].size()&&bs[i][(int)bs[i].size()-1]==nowcolor){
					op[ptr++]=make_pair(i+1,dest+1);
					bs[i].pop_back();
				}
			}
			for(int i=0;i<dest;++i){
				for(int j=(int)bs[i].size()-1;j>=0;--j){
				//	cerr<<"HI\n";
					if(bs[i][j]==nowcolor){
						cerr<<i<<' '<<j<<endl;
						vector<int> need_to_go_back;
						for(int k=(int)bs[i].size()-1;k>=j;--k){
							for(int j=0;j<=dest;++j){
								if(k==j)continue;
								if(bs[j].size()<m){
									op[ptr++]=make_pair(i+1,j+1);
									if(j==dest)need_to_go_back.push_back(j);
									break;
								}
							}
						}
						int nxt=(i==0?i+1:i-1);
						for(int k=0;k<dest;++k)if(k!=i&&bs[k].size()){nxt=k;break;}
						bs[i][j]=bs[nxt].back();
						bs[nxt].pop_back();
						//cerr<<nxt<<endl;
						op[ptr++]=make_pair(nxt+1,i+1);
						op[ptr++]=make_pair(dest+1,nxt+1);
						for(int k=(int)bs[i].size()-1;k>j;--k)op[ptr++]=make_pair(dest+1,i+1);
					//	cerr<<"!\n";
						op[ptr++]=make_pair(nxt+1,dest+1);
					//	cerr<<"!\n";
						while(bs[nxt].size()&&bs[nxt][(int)bs[nxt].size()-1]==nowcolor)op[ptr++]=make_pair(nxt+1,dest+1),bs[nxt].pop_back();
						//cerr<<"!\n";
					}
				}
			}
			for(int i=0;i<dest-1;++i){
				while(bs[i].size()<m)bs[i].push_back(bs[dest-1].back()),op[ptr++]=make_pair(dest,i+1),bs[dest-1].pop_back();
			}
			ballcnt++;
		}
		printf("%d\n",ptr);
		for(int i=0;i<ptr;++i){
			printf("%d %d\n",op[i].first,op[i].second);
		}
	}	
}

int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(),m=read();
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			int x=read();
			bs[i].push_back(x);
		}
	}
	task10::solve();
	return 0;
}

