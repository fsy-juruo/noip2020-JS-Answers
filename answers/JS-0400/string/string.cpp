#include<bits/stdc++.h>
using namespace std;
int T,pre[(1<<20)+7],suf[(1<<20)+7],num[30];
long long sum;
string s;

inline int read(){
	char ch;
	int x=0,f=1;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--){
		memset(pre,0,sizeof(pre));
		memset(suf,0,sizeof(suf));
		memset(num,0,sizeof(num));
		sum=0;
		cin>>s;
		char ch=s[0];
		bool flag=true;
		pre[0]=1;
		for(int i=0;i<s.size();i++){
			if(s[i]!=ch) flag=false;
			int k=s[i]-'a';
			num[k]++;
			if(i)
				if(num[k]&1) pre[i]=pre[i-1]+1;
				else pre[i]=pre[i-1]-1;
		}
		memset(num,0,sizeof(num));
		for(int i=s.size()-1;i>=0;i--){
			int k=s[i]-'a';
			num[k]++;
			if(num[k]&1) suf[i]=suf[i+1]+1;
			else suf[i]=suf[i+1]-1;
		}
		for(int i=1;i<s.size()-1;i++){
			int cnt=0;
			for(int j=i;j<s.size()-1;j++){
				if(s[j%(i+1)]!=s[j]) break;
				else if((j-i)%(i+1)==0){
					for(int k=0;k<i;k++)
						if(pre[k]<=suf[j+1]) cnt++;
				}
			}
			sum+=cnt;
		}
		cout<<sum<<endl;
	}
	return 0;
}

