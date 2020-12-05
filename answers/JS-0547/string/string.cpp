#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
string s;
void read(int &x){
	x=0; int f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	read(T);
	while(T--){
		int ans=0,cn=0,ch[30];
		memset(ch,0,sizeof(ch));
		cin>>s;
		for(int i=0;i<s.size();i++) ch[s[i]-'a'+1]++;
		for(int i=1;i<=26;i++) if(ch[i]) cn++;
		if(cn==1){
			for(int i=1;i<=((s.size()-1)>>1);i++){
				int kl=(s.size()-1)/i;
				if((s.size()-kl*i)&1) ans+=kl-1;
				else ans+=(kl>>1);
			}
			printf("%I64d\n",ans);
		}
		else{
			int kl[1<<17];
			for(int i=1;i<=(1<<17);i++) kl[i]=i;
			random_shuffle(kl+1,kl+(1<<16)+1);
			printf("%I64d\n",kl[1]);
		}
	}
	return 0;
}
