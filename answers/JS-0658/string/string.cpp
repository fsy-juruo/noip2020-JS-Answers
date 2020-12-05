//start:10:48
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n;
const int N=1e5+100;
int p[31],t[31],ps,ts;
int ver[N],has[N];
string st;
int kasumi(int x,int p){
	int s=1;
	while (p){
		if (p&1) s=s*x;
		x*=x;p/=2;
	}
	return s;
}
int hashval(int,int);
void init_ver(){
	ver[0]=1;
	ver[1]=kasumi(101,-1ull);
//	cout << -1ull << endl;
//	cout << ver[1]*101 << endl;
	for (int i=2;i<=n;i++) ver[i]=ver[i-1]*ver[1];
//	for (int i=1;i<=n;i++) cout << kasumi(101,i)*ver[i] << ' ';cout << endl;
	has[0]=0;
	for (int i=1;i<=n;i++){
		has[i]=(has[i-1]*101+st[i-1]-'a'+1);
	}
	for (int i=1;i<=n;i++) cout << has[i] << ' ';cout << endl;
	cout << hashval(2,3) << endl;
}
int hashval(int x,int y){
	return (has[y]-has[x-1])*ver[x-1];
}
int calc2(int a,int c){
	int tmp=n-c;
	vector < int > ve;
	for (int i=1;i*i<=tmp;i++){
		if (tmp%i==0){
			if (i>a) ve.push_back(i);
			if (i*i!=tmp && tmp/i>a) ve.push_back(tmp/i);
		}
	}
	int s=0;
	for (int i=0;i<ve.size();i++){
		if (hashval(1,n-c-ve[i]+1)==hashval(ve[i]+1,n-c)) s++;
	}
	return s;
}
int vv[N],tp=0;
int calc(int a,int c){
//	return calc2(a,c);// change it later!
	int tmp=n-c;
	tp=0;
//	vector < int > ve;
	for (int i=1;i*i<=tmp;i++){
		if (tmp%i==0){
			if (i>a) vv[++tp]=i;
			if (i*i!=tmp && tmp/i>a) vv[++tp]=tmp/i;
//			if (i>a) ve.push_back(i);
//			if (i*i!=tmp && tmp/i>a) ve.push_back(tmp/i);
		}
	}
	int s=0;
	for (int i=1;i<=tp;i++){
//	for (int i=0;i<ve.size();i++){
		int ff=1;
		for (int j=vv[i];j<n-c;j+=vv[i]){
			bool flag=true;
			for (int p=0;p<vv[i];p++){
				if (st[p]!=st[j+p]){
					flag=false;break;
				}
			}
			if (!flag){
				ff=false;break;
			}
		}
		s+=ff;
	}
	return s;
}
void work1(){
	memset(p,0,sizeof(p));ps=0;
	int ans=0;
//	cout << st << endl;
	for (int i=1;i<=n;i++){
		int pp=st[i-1]-'a'+1;
		if (p[pp]%2) ps--; else ps++;
		p[pp]++;
//		cout << "p:" << i << ' ' << ps << endl;
		memset(t,0,sizeof(t));ts=0;
		for (int j=n;j>=1;j--){
			int tt=st[j-1]-'a'+1;
			if (t[tt]%2) ts--; else ts++;
			t[tt]++;
//			cout << i << ' ' << n-j+1 << endl;
			if (ps>ts) continue;
			int tmp=calc(i,n-j+1);
			ans+=tmp;
		}
	}
	cout << ans << endl;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int cas;cin >> cas;
	while (cas--){
		cin >> st;n=st.length();
//		init_ver();
//		cout << n << endl;
		work1();
	}
	return 0;
}
