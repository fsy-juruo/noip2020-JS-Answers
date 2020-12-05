#include<bits/stdc++.h>
using namespace std;
int T,len,t,cnt,tmp;
string s;
bool flag=0;
int f[27],c1[500000],c2[500000];
unsigned long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	getchar();
	while(T--){
		ans=0;
		memset(f,0,sizeof(f));
		getline(cin,s);
		len=s.size()-1;
		//cout<<len<<endl;
		//cout<<endl;
		c1[0]=1;
		f[s[0]-'a'+1]=1;
		for(int i=1;i<=len;++i){
			f[s[i]-'a'+1]++;
			if(f[s[i]-'a'+1]%2!=0)c1[i]=c1[i-1]+1;
			else c1[i]=c1[i-1]-1;
			//cout<<c1[i]<<' ';
		}
		//cout<<endl;
		memset(f,0,sizeof(f));
		for(int i=len;i>=0;--i){
			f[s[i]-'a'+1]++;
			if(f[s[i]-'a'+1]%2!=0)c2[i]=c2[i+1]+1;
			else c2[i]=c2[i+1]-1;
		}
		//for(int i=0;i<=len;++i)cout<<c2[i]<<' ';
		//cout<<endl;
		for(int l=1;l<len;++l){
			t=l+1;
			flag=0;
			if(l<=len/2){
			while(t+l<len){
				for(int j=0;j<=l;j++)
					if(s[j]!=s[j+t]){flag=1;break;}
				if(flag==1)break;
				t=t+l;
			}
			}
			cnt=(t-1)/l;
			//cout<<t<<" "<<cnt<<endl;
			for(int i=1;i<=cnt;++i){
				tmp=(l+1)*i;
				if(tmp>len||tmp<=l)continue;
				//cout<<tmp<<endl;
				for(int j=0;j<l;++j){	
					if(c1[j]<=c2[tmp]&&tmp<=len){
						//for(int k=0;k<=j;++k)cout<<s[k];
						//cout<<endl;
						//for(int k=tmp;k<=len;++k)cout<<s[k];
						//cout<<endl;
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

5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab

*/
