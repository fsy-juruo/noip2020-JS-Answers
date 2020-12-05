#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1005;
int T,n,tot;
string s;
vector<int> tag[maxn];
int cnt_front[maxn],sum_front[maxn],cnt_back[maxn],sum_back[maxn];
int read(){
	int res=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+ch-'0';
		ch=getchar();
	}
	return res*f;
}
bool check(int pos,int len){
	if(pos%len!=0) return false;
	for(int i=1;i<=pos;i++){
		if(s[i]!=s[(i-1)%len+1]) return false;
	}
	return true;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	cin.tie(0);cout.tie(0);
//	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--){
		for(int i=1;i<=1005;i++){
			tag[i].clear();
		}
		memset(cnt_front,0,sizeof(cnt_front));
		memset(cnt_back,0,sizeof(cnt_back));
		memset(sum_front,0,sizeof(sum_front));
		memset(sum_back,0,sizeof(sum_back));
		tot=0;
		cin>>s;
		n=s.length();
		s=" "+s;
		for(int i=1;i<=n;i++){
			int now=s[i]-'a'+1;
			cnt_front[now]++;
			if(cnt_front[now]%2==1) sum_front[i]=sum_front[i-1]+1;
			else if(cnt_front[now]%2==0) sum_front[i]=sum_front[i-1]-1;
		}
		for(int i=n;i>=1;i--){
			int now=s[i]-'a'+1;
			cnt_back[now]++;
			if(cnt_back[now]%2==1) sum_back[i]=sum_back[i+1]+1;
			else if(cnt_back[now]%2==0) sum_back[i]=sum_back[i+1]-1;
		}
		for(int i=1;i<=n;i++){
			for(int j=2;j<=i;j++){
				if(check(i,j)) tag[i].push_back(j);
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=0;j<tag[i].size();j++){
//				cout<<tag[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		for(int i=2;i<n;i++){
			if(!tag[i].size()) continue;
			for(int j=0;j<tag[i].size();j++){
				int len=tag[i][j];
				for(int k=1;k<len;k++){
					if(sum_front[k]<=sum_back[i+1]) tot++;
				}
			}
		}
		cout<<tot<<endl;
	}
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo

5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
