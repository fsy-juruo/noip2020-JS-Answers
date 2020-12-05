#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+500;
const int mod=1e9+7;
int n,k,w[maxn],p,cnt;
int pos[maxn],now_pos[maxn],c[maxn],d[maxn];
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
bool check(){
	for(int i=1;i<=k;i++){
		if(now_pos[i]<1||now_pos[i]>w[i]) return true;
	}
	return false;
}
signed main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	p=1;
	for(int i=1;i<=k;i++){
		cin>>w[i];
		p=p*w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i]>>d[i];
	}
	pos[1]=0,pos[2]=1,pos[3]=1,pos[4]=1,pos[5]=1;
//	cout<<"p: "<<p<<endl;
	for(int i=1;i<=p;i++){
		pos[1]++;
		if(pos[1]==w[1]+1){
			pos[2]++;
			pos[1]=1;
		}
		if(pos[2]==w[2]+1){
			pos[3]++;
			pos[2]=1;
		}
		if(pos[3]==w[3]+1){
			pos[4]++;
			pos[3]=1;
		}
		if(pos[4]==w[4]+1){
			pos[5]++;
			pos[4]=1;
		}
		for(int j=1;j<=k;j++){
			now_pos[j]=pos[j];
		}
		bool flag=true;
		while(1){
			for(int j=1;j<=n;j++){
				cnt++;
				now_pos[c[j]]+=d[j];
				if(check()){
					flag=false;
					break;
				}
				if(cnt>1e8){
					cout<<-1<<endl;
					return 0;
				}
			}
			if(!flag) break;	
		}
//		cout<<cnt<<endl;
		cnt%=mod;
	}
	cout<<cnt%mod<<endl;
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1

5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1


*/

