#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read(){
	int res=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res;
}

#define N 1100005
string s,a,p;
int num[155],na,nc,A[N];
ll res;
int n;
void solve(){
	res=0;
	for(int len=2;len<n;len++){
		a=s.substr(0,len);
		memset(num,0,sizeof num);
		for(int i=0;i<len-1;i++){
			num[(int)a[i]]++;
			A[i]=0;
			for(int j='a';j<='z';j++){
				if(num[(int)j]&1) A[i]++;
			}
		}
		memset(num,0,sizeof num);
		nc=0;
		for(int i=0;i<n;i++){
			num[(int)s[i]]++;
		}
		int t=0;
		while(t<n-len){
			p=s.substr(t,len);
			if(a!=p) break;
			for(int i=0;i<len;i++){
				num[(int)p[i]]--;
			}
			nc=0;
			for(int i='a';i<='z';i++){
				if(num[(int)i]&1) nc++;
			}
			for(int i=0;i<len-1;i++){
				if(A[i]<=nc) res++;
			}
			t+=len;
		}
	}
	printf("%lld\n",res);
}

void solve1(){
	res=0;
	for(int len=2;len<n;len++){
		if(n&1){
			if(len&1){
				res+=(n-1)/(2*len)*(len-1); //no change -> odd
				res+=((n-1)/len-(n-1)/(2*len))*((len-1)/2);
			}
			else{
				res+=(n-1)/len*(len-1);
			}
		}
		else{
			if(len&1){
				res+=(n-1)/(2*len)*(len/2); //no change -> even
				res+=((n-1)/len-(n-1)/(2*len))*(len-1);
			}
			else{
				res+=(n-1)/len*((len-1)/2);
			}
		}
	}
	printf("%lld\n",res);
}

//void solve2(){
//	
//}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		n=s.size();
		char k1;
		int flag1=1;
		k1=s[0];
		for(int i=0;i<n;i++){
			if(s[i]!=k1){
				flag1=0;
				break;
//				if(!k2){
//					k2=s[i];
//					continue;
//				}
//				if(s[i]!=k2){
//					flag2=0;
//					break;
//				}
			}
		}
		if(flag1&&n>1000){
			solve1();
			continue;
		}
//		if(flag2&&n>1000){
//			solve2();
//			continue;
//		}
		solve();
	}
	return 0;
}
