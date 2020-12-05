#include<bits/stdc++.h>
#define reg register
#define ll long long
#define NOF "string"
#define N 1048580
using namespace std;

inline int read(){
	int s = 0,w = 1;
	char ch; ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+ch-'0';ch=getchar();}
	return s*w;
}

struct node{
	int sum[26];
}sufsum[N];
string s;

inline int makef(int l ,int r){
	int ans = 0;
	for(reg int i = 0;i<=25;++i){
		if((sufsum[r].sum[i]-sufsum[l].sum[i]+( i+'a'==s[l] ? 1 : 0))%2) ++ans;
	}
	return ans;
}

int main(){
	
	freopen(NOF ".in","r",stdin);
	freopen(NOF ".out","w",stdout);
	
	int fccf = read(),cnt;
	
	while(fccf > 0){
		
		cnt = 0;
		cin>>s;
		sufsum[0].sum[s[0]-'a']++;
		for(reg int i = 1;i<s.size();++i){
			sufsum[i] = sufsum[i-1];
			sufsum[i].sum[s[i]-'a'] = sufsum[i-1].sum[s[i]-'a'] + 1; 
		}	
		--fccf;
		
		int cl,cr = s.size() - 1;
		int al = 0, ar;
		int bl , br;
		
		for(reg int i = s.size() - 1 ; i>1 ; --i){
			
			cl = i;
			int tmpfc = makef(cl,cr);
			
			for(reg int k = 2;k<=cl;++k){
				
				if(!(cl%k)){
				//	cout<<al<<ar<<bl<<br<<cl<<cr<<endl;
					br = k-1;
					string tmps = "",com = "";
						
					for(reg int z = 0;z<cl;++z) com+=s[z];
						
					for(reg int z = al;z<=br;++z) tmps+=s[z];
					for(reg int z = 1;z<cl/k;++z) tmps+=tmps;
						
				//	cout<<tmps<<' '<<com<<endl;
					
					if(tmps!=com) continue;
					
					for(reg int j = 0;j<k-1;++j){
						ar = j;bl = ar+1;
						int tmpfa = makef(al,ar);
						if(tmpfa<=tmpfc) ++cnt;
					}
					
				}
				
			}
		}
		
		memset(sufsum,0,sizeof(sufsum));
		
		cout<<cnt<<endl;
		cnt = 0;
	}
	
//	cout<<sizeof(sufsum)/1024/1024<<endl;
	
	return 0;
}
