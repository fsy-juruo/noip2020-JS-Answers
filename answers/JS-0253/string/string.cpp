#include<bits/stdc++.h>
#define int long long
#define bug cout<<"bug: "<<__LINE__<<endl
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=100005;

int vis[30];

int cal(string a){
	int len=a.length();
	memset(vis,0,sizeof vis);
	int ret=0;
	for(int i=0;i<len;i++){
		vis[a[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		if(vis[i]%2==1){
			ret++;
		}
	}
	return ret;
}

bool isdis(string a,string b){
	int na=a.length();
	int nb=b.length();
	if(na!=nb){
		return  false;
	}
	for(int i=0;i<na;i++){
		if(a[i]!=b[i]){
			return false;
		}
	}
	return true;
}

bool check(string a,string b,int i,string str){
	int n=(long long)str.length(),na=(long long)a.length(),nb=(long long)b.length();
	for(int now=0;now<i*(na+nb);now++){
		int res=now%(na+nb);
		if(res<na){
			if(str[now]!=a[res]){
				return false;
			}
		}
		else{
			if(str[now]!=b[res-na]){
				return false;
			}
		}
	}
	return true;
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int ans=0;
		string str;
		cin>>str;
		int n=str.length();
//		cout<<n<<endl;
		string a,b,c;
		int fa=0,fc=0;
		for(int len1=1;len1<=n-2;len1++){
			a=str.substr(0,len1);
//			cout<<"a: "<<a<<endl;
			fa=cal(a);
			for(int len2=1;len2<=n-len1-1;len2++){
				b=str.substr(len1,len2);
//				cout<<"	b: "<<b<<endl;
				for(int i=1;i<=n/(len1+len2);i++){
					int len3=(n-(len1+len2)*i);
					if(len3==0){
						continue;
					}
					c=str.substr(n-len3,len3);
//					cout<<"		c: "<<c<<endl;
					fc=cal(c);
					if(fa>fc){
//						bug;
						continue;
					}
					if(check(a,b,i,str)){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo
*/
/*
5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
