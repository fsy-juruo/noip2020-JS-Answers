#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
string st;
int f1[(1<<17)+5],f2[(1<<17)+5];
int hash[30];
void p(){
	for(int i=1;i<=26;i++)hash[i]=0;
	int s=0;
	for(int i=0;i<st.size();i++){
		int ch=st[i]-'a'+1;
		if(hash[ch]%2){
			s--;
		}else{
			s++;
		}
		hash[ch]++;
		f1[i+1]=s;
	}
	for(int i=1;i<=26;i++)hash[i]=0;
	s=0;
	for(int i=st.size()-1;i>=0;i--){
		int ch=st[i]-'a'+1;
		if(hash[ch]%2){
			s--;
		}else{
			s++;
		}
		hash[ch]++;
		f2[i+1]=s;
	}
}
bool check(int x,int y){
	for(int i=0;i<y;i++){
		if(st[i]!=st[i%x])return false;
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	read(t);
	while(t--){
		cin>>st;
		bool flg=1;
		for(int i=1;i<st.size();i++){
			if(st[i]!=st[i-1])flg=0;
		}
//		cout<<flg<<endl;
		if(flg){
			int ans=0;
			for(int i=1;i<=st.size()-2;i++){
				int x=st.size()-i;
				if(x%2){
					for(int i=1;i*i<=x;i++){
						if(x%i)continue;
						ans+=i-1;
						if(i*i!=x){
							ans+=x/i-1;
						}
//						cout<<x<<" "<<i<<" "<<ans<<endl;
					}
				}else{
					for(int i=1;i*i<=x;i++){
						if(x%i)continue;
						ans+=(i-1)/2;
						if(i*i!=x){
							ans+=(x/i-1)/2;
						}
//						cout<<x<<" "<<i<<" "<<ans<<endl;
					}	
				}
			}
			cout<<ans<<endl;
		}else{
			p();
			int ans=0;
			for(int k=1;k<=st.size()-2;k++){
				int x=st.size()-k;
				for(int i=1;i*i<=x;i++){
					if(x%i==0){
						if(check(i,x)){
							for(int j=1;j<i;j++){
								if(f1[j]<=f2[x+1])ans++;
							}
//							cout<<x<<" "<<i<<" "<<ans<<endl;
						}
						if(i*i!=x&&check(x/i,x)){
							for(int j=1;j<x/i;j++){
								if(f1[j]<=f2[x+1])ans++;
							}
//							cout<<x<<" "<<x/i<<" "<<ans<<endl;
						} 
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
5
ggggggggggggggbaabab
*/
