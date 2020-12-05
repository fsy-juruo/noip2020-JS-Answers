#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MAXN 1200005
int t;
int tmp[30];
string s;
ull ha[MAXN];
ull po2(int x){
    ull res=ull(1),base=ull(29);
    int p=1;
    while(x>0){
	if(x&p){
	    res=res*base;
	    x-=p;
	}
	p*=2;
	base*=base;
    }
    return res;
}
ull po[2005];
ull has(int x,int y){
    return ha[y]-ha[x-1]*po[y-x];
}
int f[1005][1005];
int main(){
    ios::sync_with_stdio(false);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>t;
    while(t--){
	int ans=0;
	cin>>s;
	int len=s.size();
	s=" "+s;
	for(int i=1;i<=len;i++){
	    memset(tmp,0,sizeof(tmp));
	    for(int j=i;j<=len;j++){
		if(tmp[s[j]-'a']&1)f[i][j]=f[i][j-1]-1;
		else f[i][j]=f[i][j-1]+1;
		tmp[s[j]-'a']++;
	    }
	}
	for(int i=0;i<2005;i++)po[i]=po2(i);
	ha[0]=0;
	for(int i=1;i<=len;i++){
	    ha[i]=ha[i-1]*ull(29)+ull(s[i]-'a'+1);
	}
	for(int i=1;i<=len-2;i++){
	    for(int j=i+1;j<=len-1;j++){
		int abl=j;
		ull tt=has(1,j),adt=has(1,j);
		for(int k=1;abl*k<len;k++){
		    if(tt!=has(1,abl*k))continue;
		    if(f[1][i]<=f[abl*k+1][len])ans++;
		    tt=tt*po[abl]+adt;
		}
	    }
	}
	printf("%d\n",ans);
    }
    return 0;
}
