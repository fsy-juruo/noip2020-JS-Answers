#include<bits/stdc++.h>
using namespace std;
int T;
int m[100];
int fa[1010],fc[1010];
string s[1010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;++i){
		long long ans=0;
		string st;
		cin>>st;
		int l=st.length();
		memset(m,0,sizeof(m));
		memset(fa,0,sizeof(fa));memset(fc,0,sizeof(fc));
		for(int j=0;j<l;++j){
			int pp=(int)st[j]-97;
			if(!j){
			s[j]=st[j];
			fa[j]=1;
			m[pp]++;	
			}
			else {
			s[j]=s[j-1]+st[j];
			fa[j]=fa[j-1];
			m[pp]++;
			if(m[pp]%2)fa[j]++;
			else fa[j]--;
			}
		}
		memset(m,0,sizeof(m));
		for(int j=l-1;j>=0;--j){
			int pp=(int)st[j]-97;
			fc[j]=fc[j+1];
			m[pp]++;
			if(m[pp]%2)fc[j]++;
			else fc[j]--;
		}
		string aa="";
		for(int j=0;j<l-2;++j){
			aa+=st[j];
			string bb="";
			for(int k=j+1;k<l-1;++k){
				bb+=st[k];
				string al=aa+bb;
				string sal="";
				for(int cnt=1;cnt*(k+1)<l;++cnt){
					sal+=al;
					if(s[(k+1)*cnt-1]==sal){
						if(fa[j]<=fc[(k+1)*cnt])ans++;
					}
					else break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

