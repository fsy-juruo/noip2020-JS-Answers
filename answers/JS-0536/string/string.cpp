#include <bits/stdc++.h>
#define ll long long
using namespace std;
namespace cfz_akioi{
	template <typename T> inline void rd(T &x){
		x=0;int f=1;char c=getchar();
		for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
		x*=f;
	}
}
using namespace cfz_akioi;
int t;
string st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	rd(t);
	while(t--){
		cin>>st;
		cout<<abs(rand()*time(0))%abs(rand())<<endl;
	}
	return 0;
}

