#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
const int P = 1e9+7;
#define fr(i,a,b) for(int i = a;i <= b; ++i)
#define nfr(i,a,b) for(int i = a;i >= b; --i)

int n,k;
int w[N];
int c[N],d[N];
int num[11];
int mxv[11],mnv[11],mnp[11],mxp[11];
int ans;

inline void add(int &x,int y){
	x += y; if(x >= P)x -= P;
}
int val[11],cur[11];

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	
	bool flag = true;
	fr(i,1,k)scanf("%d",w+i),flag &= (w[i] <= 10);
	fr(i,1,n){
		scanf("%d%d",c+i,d+i);
	}
	
	fr(i,1,n){
		num[c[i]] += d[i];
		if(num[c[i]] > mxv[c[i]])mxp[c[i]] = i;
		if(num[c[i]] < mnv[c[i]])mnp[c[i]] = i;
		mxv[c[i]] = max(mxv[c[i]],num[c[i]]);
		mnv[c[i]] = min(mnv[c[i]],num[c[i]]);
	}

	//check for infinity
	bool flag2 = true;
	fr(i,1,k)flag2 &= num[i] == 0;
	if(flag2){
		fr(i,1,k)flag2 &= w[i]-1 >= mxv[c[i]]-mnv[c[i]];
		if(flag2){
			puts("-1"); return 0;
		}
	}
	
	w[0] = 1;
	if(flag && n <= 100 && k <= 5){
		fr(i,1,k)val[i] = 1;
		ans = 0;
		do{
			memcpy(cur,val,sizeof cur);
			int i = 1;
			while(1){
				cur[c[i]] += d[i];++ans;
				if(cur[c[i]] > w[c[i]] || cur[c[i]] <= 0)break;
				i = i%n+1;
			}
	//		fr(i,1,k)cerr << val[i] <<' ';
	//		cerr << endl <<' ' << ans << endl;
			int j = k;
			while(val[j] == w[j])val[j--] = 1;
			++val[j];
		} while(val[0] == 0);
		printf("%d\n",ans);
	}
}
