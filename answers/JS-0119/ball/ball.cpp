#include<bits/stdc++.h>
#define rep(a,b) for(int a=0;a<b;++a)
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
using namespace std;
vector<int> ball[51];
int n,m;
vector<pair<int,int> > v;
int move(int x,int y,int z,int h){ 
	int cnt=0;
	rep(i,m){
		cnt+=(ball[x][i]==z);
	}
	rb(i,1,cnt){
		v.PB(II(y,h));
	}
	rl(i,m-1,0){
		if(ball[x][i]==z){
			v.PB(II(x,y));
		}
		else{
			v.PB(II(x,h));
		}
	}
	rb(i,1,m-cnt){
		v.PB(II(h,x));
	}
	rb(i,1,cnt){
		v.PB(II(y,x));
	}
	rb(i,1,cnt){
		v.PB(II(h,y));
	}
	vector<int> ne;
	rep(i,m){
		if(ball[x][i]!=z){
			ne.PB(ball[x][i]);
		}
	}
	ball[x]=ne;
	return cnt;
}
void solve(int now){
	if(now==1) return ;
	vector<int> st;
	rb(i,1,now){
		st.PB(move(i,(i==now? i-1:i+1),now,now+1));
	}
	vector<int> em;
	rep(i,now){
		rb(j,1,st[i]){
			v.PB(II(i+1,now+1));
			em.PB(i+1);
		}
	}
	int sss=0;
	while(!ball[now].empty()){
		v.PB(II(now,em[sss]));
		ball[em[sss]].PB(ball[now].back());
		ball[now].pop_back();
		sss++;
	}
	solve(now-1);
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	rb(i,1,n){
		ball[i].resize(m);
		rep(j,m) scanf("%d",&ball[i][j]);
	}
	solve(n);
	printf("%d\n",v.size());
	rep(i,v.size()){
		printf("%d %d\n",v[i].first,v[i].second);
	}
	return 0;
}
/*

1. 数组大小是1倍还是2倍？
2. 有没有用long long
3. 特判有没有return 0
4. 需不需要特判
5. if的条件是否并列
6. vector ,函数返回值是否是long long
7. 有没有注意中途取模
8. dfn有没有错
9. 下标顺序有没有错

*/

