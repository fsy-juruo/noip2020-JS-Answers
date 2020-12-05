#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
	int f=1;
	int s=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		s=s*10+(c-'0');
		c=getchar();
	}
	return f*s;
}
inline string read2(){
	string s;
	char c=getchar();
	while(islower(c)){
		s=s+c;
		c=getchar();
	}
	return s;
}
vector<int>c[1048576];//存储C中出现奇数次的字母的首字母坐标 
int numz[30];//存储每个字母的出现个数 
ll tongji(int la,int lb,int rb,string s){
	if(rb-lb+1<=la+1)return 1;
	int ans=0;
	for(int k=la+2;k<=rb+1;++k){
		if((rb+1)%k)continue;
		//str=str+s[k-1];
		string str=s.substr(0,k);
		int i=k;
	//	cout<<i<<endl;
	//	string str=s.substr(0,k);
	///	cout<<str<<endl;
		bool flg=1;
		while(i<rb){
	//		cout<<s.substr(i,k)<<endl;
			if(s.substr(i,k)!=str){
			//	cout<<s.substr(i,k)<<' '<<str<<endl;
				flg=0;
				break;
			}
			i+=k;
		}
		ans+=flg;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	int T=read();
	
	int maxt=0;
	while(T--){
		for(int i=0;i<=maxt;++i){
			while(c[i].size())c[i].pop_back();
		}
		string s=read2();
		int len=s.size(); 
		bool flg=1;
		for(int i=1;i<len;++i){
			if(s[i]!=s[0]){
				flg=0;
				break;
			}
		}
		ll ans=0;
		if(flg){
			for(int i=len-1;i>1;--i){
				int l=i;
				for(int j=1;j*j<=l;++j){
					if(l%j)continue;
					
					if((len-i)%2){
						if(j*j==l){
							ans+=j-1;
							continue;
						}
						ans+=j-1+l/j-1;
					}else{
						if(j*j==l){
						ans+=(j-1)/2;
						continue;
					}
						ans+=(j-1)/2+(l/j-1)/2;
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		//枚举出现奇数次字母的个数的C 
		int t=0;
		maxt=0;
		memset(numz,0,sizeof(numz));
		for(int i=len-1;i>1;--i){
			++numz[s[i]-'a'];
			if(numz[s[i]-'a']%2)++t;
			else --t;
			c[t].push_back(i);
			maxt=max(maxt,t);
		}
		t=0;
		memset(numz,0,sizeof(numz));
		string str;
		
		for(int i=0;i<len-2;++i){
			str=str+s[i];
			++numz[s[i]-'a'];
			if(numz[s[i]-'a']%2)++t;
			else --t;
			for(int j=t;j<=maxt;++j){
				for(int h=0;h<c[j].size();++h){
					if(c[j][h]<=i+1)break;
					ans+=tongji(i,i+1,c[j][h]-1,s);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//1048576

