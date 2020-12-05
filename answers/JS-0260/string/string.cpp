#include <bits/stdc++.h>
#define endl '\n'
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
int rdi(){
	int a=0,b=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')b=-1,ch=getchar();
	while(ch>='0'&&ch<='9')a=a*10+ch-'0',ch=getchar();
	return a*b;
}
int n;
char s[2000010];
int calc(int x){
	for(int k=2;k<=n;k++){
//		cout<<k<<endl;
		int ed=k*x;
		bool flg=1;
		for(int i=k*x-x+1,j=1;i<=ed;i++,j++){
			if(s[i]!=s[j]){
				flg=0;
				break;
			}
		}
//		cout<<k-1<<endl;
		if(!flg)return k-1;
	}
//	cout<<1919<<endl;
	return 1;
}
int ha[30],hc[30],ans;
void calcc(int x){
//	cout<<x<<endl;
	memset(hc,0,sizeof hc);
	for(int i=n-x+1;i<=n;i++)hc[s[i]-'a']++;
}
bool checkac(int x,int y,int z){
	int cnta=0,cntb=0;
	for(int i=0;i<26;i++)if(ha[i]&1)cnta++;
	for(int i=0;i<26;i++)if(hc[i]&1)cntb++;
//	cout<<"###"<<cnta<<' '<<cntb<<endl;
	if(cnta>cntb)return 0;
	else return 1;
}
void solve48(){
	for(int i=1;i<=n;i++){//lenA
		ha[s[i]-'a']++;
		for(int j=1;j<=n;j++){//lenB
//			cout<<i<<' '<<j<<endl;
			int cj=calc(i+j);
			for(int len=1;len<=cj;len++){
				int k=n-len*(i+j);
				if(k<=0)break;
				if(len==1)calcc(k);
				else for(int tp=1;tp<=i+j;tp++)hc[s[tp]-'a']--;
//				calcc(k);
				if(checkac(i,j,k)){
//					cout<<i<<' '<<j<<' '<<k<<endl;
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
}
void solve8(){
//	solve48();
//	return;
	for(int i=1;i<n;i++){
		//606813357
		for(int j=1;i+j<=n;j++){
			int cj=n/(i+j);
//			cout<<n/(i+j)*(i+j)<<endl;
			if(i%2==0){
				ans+=cj;
				if(n-cj*(i+j)==0)ans--;
				continue;
			}else if((i+j)%2==0){
				if(n%2==0)continue;
				else{
					ans+=cj;
					if(n==cj*(i+j))ans--;
					continue;
				}
			}
			for(int len=1;len<=cj;len++){
				int k=n-len*(i+j);
				if(k<=0){
//					cout<<"yattaze\n";
					break;
				}
				if(!((i&1)&&k%2==0))ans++;
			}
		}
	}
	printf("%d\n",ans);
}
void solve12(){
	solve48();
}
int main(){
#ifndef OFFLINE
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		ans=0;
		memset(s,0,sizeof s);
		memset(ha,0,sizeof ha);
		memset(hc,0,sizeof hc);
		scanf("%s",s+1);
		n=strlen(s+1);
//		cout<<(s+1)<<endl;
		int cnt=0;
		char cx=0,cy=0;
		for(int i=1;i<=n;i++){
			if(cx==0&&cy==0)cnt++,cx=s[i];
			else if(cy==0){
				if(cx!=s[i])cnt++,cy=s[i];
			}else{
				if(cx!=s[i]&&cy!=s[i]){
					cnt++;
					break;
				}
			}
		}
//		cout<<cnt<<endl;
		if(cnt==1)solve8();
		else if(cnt==2)solve12();
		else solve48();
	}
	return 0;
}
/*
114514
k
kk
kkk
kkkk
kkkkk
kkkkkk
kkkkkkk
kkkkkkkk
kkkkkkkkk
kkkkkkkkkk
kkkkkkkkkkk
kkkkkkkkkkkk
kkkkkkkkkkkkk
kkkkkkkkkkkkkk
kkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkkk



114514
kk
kkkk
kkkkkk
kkkkkkkk
kkkkkkkkkk
kkkkkkkkkkkk
kkkkkkkkkkkkkk
kkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
*/
