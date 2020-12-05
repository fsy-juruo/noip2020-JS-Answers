#include <bits/stdc++.h>
#define ll long long
#define re register
#define PII pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int maxn=(1<<20)+5;
int t,num1[27],num3[27],cnt3[maxn],cnt1[maxn];
string s;
ll ans;
bool check(int st,int lenth,int en){
	string orig=s.substr(st,lenth);
	for(re int i=st;i<=en;i+=lenth){
		string tmp=s.substr(i,lenth);
		if(tmp!=orig) return false;
	}
	return true;
} 
void get_ans(int c_len){
	for(re int l=2;l<=s.size()-c_len;l++){
		if((s.size()-c_len)%l) continue;
		if(!check(0,l,s.size()-c_len-1)) continue;
		for(re int i=0;i<l-1;i++){
			if(cnt1[i]>cnt3[c_len]) continue;
			ans++;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--){
		memset(num1,0,sizeof num1);
		memset(num3,0,sizeof num3);
		ans=0;
		cin>>s;
		for(re int i=0;i<=s.size()-3;i++){
			num1[s[i]-'a']++;
			num3[s[s.size()-i-1]-'a']++;
			if(i) cnt1[i]=cnt1[i-1];
			cnt3[i+1]=cnt3[i];
			if(num1[s[i]-'a']&1) ++cnt1[i];
			else --cnt1[i];
			if(num3[s[s.size()-i-1]-'a']&1) ++cnt3[i+1];
			else --cnt3[i+1];
		}
		for(re int i=s.size()-2;i>=1;i--){
			get_ans(i);
		}
		printf("%lld\n",ans);
		for(re int i=0;i<=s.size();i++) cnt1[i]=cnt3[i]=0;
	}
	return 0;
}
/*
5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
