#include<bits/stdc++.h>

using namespace std;
const int MAXN=1010;
void file(string s){freopen((s+".in").c_str(),"r",stdin),freopen((s+".out").c_str(),"w",stdout);}
int read(){
	int a=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		a=a*10+ch-'0';
		ch=getchar();
	}
	return a*f;
}

string s;

namespace sub1{
	int n;
	int num[MAXN],sum[MAXN],totnum[30];
	inline int count(int k){
		int re=0;
		while(k){
			if(k&1)re++;
			k>>=1;
		}
		return re;
	}
	void build(){
		for(int i=0;i<=26;++i){
			totnum[i]=0;
		}
		for(int i=1;i<=n;++i){
			num[i]=num[i-1]^(1<<(s[i]-'a'));
			sum[i]=count(num[i]);
//			cout<<"num "<<num[i]<<" sum "<<sum[i]<<endl;
		}
	}
	int check(int x){
		for(int i=2;i*x<=n;++i){
			for(int j=1;j<=x;++j){
				if(s[j]!=s[(i-1)*x+j]){
					return i-1;
				}
			}
		}
		return n/x;
	}
	void work(){
		n=s.length();
		s=' '+s;
		build();
		int cnt=0;
		for(int i=2;i<n;++i){
//			cout<<"check "<<i<<endl;
			int k=check(i);
//			cout<<"finish check"<<k<<endl;
//			if(n%i!=0)k++;
			for(int j=sum[i-1];j<=26;++j){
				totnum[j]++;
			}
//			cout<<"finish add"<<endl;
			int sumo=count(num[n]^num[k*i]),sumj=count(sumo^num[i]);
//			cout<<num[n]<<' '<<num[k*i]<<' '<<num[i]<<endl;
//			cout<<sumo<<' '<<sumj<<' '<<totnum[sumj]<<' '<<k/2<<' '<<totnum[sumo]<<' '<<(k-1-k/2+((n-i*k)>0))<<endl;
//			cout<<(totnum[sumj]*(k/2))<<' '<<(totnum[sumo]*(k-1-k/2+((n-i*k)>0)))<<endl;
			cnt+=(totnum[sumj]*(k/2))+(totnum[sumo]*(k-1-k/2+((n-i*k)>0)));
//			cout<<"all finsh "<<(totnum[sumj]*(k/2))+(totnum[sumo]*(k-1-k/2+((n-i*k)>0)))<<endl;
		}
		cout<<cnt<<endl;
	}	
}

namespace sub2{
	void work(){
		int n=s.length(),cnt=0;
		for(int i=2;i<n;++i){
			int k=n/i-1,kk=(i-1)/2,kkk=0;
			if(n%i!=0)k++;
			cnt+=kk*k;
			kk=i-1-kk;
			if((n%i)&1){
				kkk+=k/2;
				if(n%i!=0)kkk++;
			}
			if((n%i+i)&1){
				kkk+=(k+1)/2;
			}
			cnt+=kk*kkk;
		}
		cout<<cnt<<endl;
	}
}

signed main(){
	file("string");
	int NT=read();
	while(NT--){
		cin>>s;
		if(s.length()<=1000){
			sub1::work();
		}else{
			sub2::work();
		}
	}
	return 0;
}
