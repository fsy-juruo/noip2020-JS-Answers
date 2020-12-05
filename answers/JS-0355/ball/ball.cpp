#include<bits/stdc++.h>
using namespace std;

inline void read(int &x){
	x = 0;
	static int f; static char ch; f = 1,ch = getchar();
	while (!isdigit(ch)){ if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) x = x * 10 + ch - '0',ch = getchar();
	x *= f;
}
inline void write(int x){ if (x < 0) x = -x,putchar('-'); if (x > 9) write(x/10),x %= 10; putchar(x + '0'); }

struct Answer{
	int ax[820005],ay[820005],l;
	inline void add(int x,int y){ ++l; ax[l] = x,ay[l] = y; }
	inline void print(){ write(l),putchar('\n'); for (int i = 1; i <= l; ++i) write(ax[i]),putchar(' '),write(ay[i]),putchar('\n'); }
}Ans;

const int N = 55,M = 410;
int n,m,len[N],a[N][M]; bool is[N],isc[N],can[N];
int sum[N],mxd[N];

int col;
inline int havev(int x,int v){
	for (int i = 1; i <= len[x]; ++i) if (a[x][i] == v) return i;
	return 0;
}
inline bool ok(int x,int v){
	if (len[x] < m) return 0;
	for (int i = 1; i <= len[x]; ++i) if (a[x][i] != v) return 0;
	return 1;
}
inline void Throw(int x,int y=-1){
	for (int i = 1; i <= n+1; ++i) if (is[i] && len[i] < m && i != x && i != y){
		Ans.add(x,i); a[i][++len[i]] = a[x][len[x]],--len[x];
		return;
	}
}
inline void Throw2(int x,int y=-1){
	for (int i = 1; i <= n+1; ++i) if (is[i] && len[i] >= 1 && i != x && i != y){
		Ans.add(i,x); a[x][++len[x]] = a[i][len[i]],--len[i];
		return;
	}
}
inline int same(int x){
	if (len[x] < m) return 0;
	int v = a[x][1];
	for (int i = 1; i <= len[x]; ++i) if (a[x][i] != v) return 0;
	return v;
}

inline void work(){
	int i,j,pos = -1;
	bool flag = 0;
	for (i = 1; i <= n+1; ++i) if (is[i] || isc[i]) flag = 1;
	if (!flag) return;
	for (i = 1; i <= n+1; ++i) if (is[i] && same(i)){ is[i] = 0; isc[same(i)] = 0; return; }
	for (i = 1; i <= n+1; ++i) can[i] = 1;
	for (i = 1; i <= n+1; ++i) if (is[i] && len[i] == 0) pos = i;
	if (pos == -1){
		for (i = 1; i <= n+1; ++i) if (is[i]){
			if (pos == -1 || len[i] < len[pos]) pos = i;
		}
		while (len[pos]){
			for (i = 1; i <= n+1; ++i) if (is[i] && i != pos && len[i] < m){
				Ans.add(pos,i),a[i][++len[i]] = a[pos][len[pos]],--len[pos];
				break;
			}
		}
		for (i = 1; i <= n+1; ++i) if (is[i] && len[i]) can[a[i][len[i]]] = 1;
	}
	//an empty position -> cost : <= nm
	col = -1;
	for (i = 1; i <= n+1; ++i) if (is[i] && len[i]){
		for (j = 1; j <= n; ++j) mxd[i] = 0;
		for (j = len[i]; j ; --j) mxd[a[i][j]] = len[i]-j+1;
		for (j = 1; j <= n; ++j) sum[i] += mxd[i];
	}
	for (i = 1; i <= n; ++i) if (isc[i] && can[i] && (col == -1 || sum[col] > sum[i])) col = i;
	//get an position color
	int t,h,hh,cnt;
	int p;
	int llst;
//	cerr<<"work " << col << " " << pos << '\n';
	while (!ok(pos,col)){
	//	cerr<< "now " << len[pos] << ' ' << '\n';
	//	cerr << is[1] <<' ' << is[2] << ' ' << havev(1,col) << ' ' << havev(2,col) << ' ' << len[1] << ' ' << len[2] << ' ' << a[1][1] << ' ' << a[1][2] << ' ' << a[2][1] << ' ' << a[2][2] << '\n';
		for (t = 1; t <= n+1; ++t) while (t != pos && is[t] && len[t] && a[t][len[t]] == col){  Ans.add(t,pos); --len[t],a[pos][++len[pos]] = col; }
		for (t = 1; t <= n+1; ++t) if (is[t] && t != pos && (h=havev(t,col))){
			
			p = -1;
			cnt = 0; llst = len[pos]; hh = len[t];
			
			for (i = 1; i <= len[t]; ++i) if (a[t][i] == col) ++cnt;
			for (i = 1; i <= n+1; ++i) if (is[i] && i != pos && i != t && (p==-1||abs(len[i]+cnt-m)<abs(len[p]+cnt-m))) p = i;
			while (len[p]+cnt > m){ Throw(p); }
			while (len[p]+cnt < m){ Throw2(p,t),llst = len[pos],hh = len[t]; }
			
		//	cerr << "workk " << t << '\n'; 
		//	if (t == 9){
		//		for (int i = 1; i <= len[t]; ++i) cerr << a[t][i] << ' '; cerr << '\n';
			//	cerr << hh << ' ' << h <<  ' ' << cnt << '\n';
		//	}
			while (len[t] >= h){
		//		cerr << "qwq " << len[t] << '\n';
				if (a[t][len[t]] == col && len[t] <= hh){ Ans.add(t,p); --len[t]; a[p][++len[p]] = col; }
				else Throw(t,p);
			}
			while (len[pos] > llst) Throw(pos);
			for (i = 1; i <= cnt; ++i) Ans.add(p,pos),--len[p],a[pos][++len[pos]] = col;
			break;
		}
	}
	isc[col] = is[pos] = 0;
}

int v[N*M],lv;
inline void qwq(){
	sort(v+1,v+lv+1);int i,j;
	lv = unique(v+1,v+lv+1)-v-1;
	for (i = 1; i <= n; ++i)
	for (j = 1; j <= m; ++j) a[i][j] = lower_bound(v+1,v+lv+1,a[i][j])-v;
}

int main(){
	freopen("ball.in","r",stdin); freopen("ball.out","w",stdout);
	int i,j;
	read(n),read(m);
	for (i = 1; i <= n; ++i)
	for (j = 1,len[i] = m; j <= m; ++j) read(a[i][j]),v[++lv] = a[i][j];
	qwq();
	len[n+1] = 0;
	for (i = 1; i <= n+1; ++i) is[i] = 1;
	for (i = 1; i <= n; ++i) isc[i] = 1;
	for (i = 1; i <= n; ++i) work();
	Ans.print();
	return 0;
}
