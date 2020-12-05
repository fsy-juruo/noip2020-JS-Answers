#include<bits/stdc++.h>
using namespace std;
const int M=1050000;
map<char,int>m;
int prf[M],suf[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		string s;
		cin>>s;
		long long ans=0;
		int l=s.size();
		vector<string>v;
		string ts="";
		ts+=s[0];
		v.push_back(ts);
		for(char i='a';i<='z';i++)
		m[i]=0;
		prf[0]=1;
		m[s[0]]++;
		suf[l-1]=1;
		for(int i=1;i<l;i++)
		{
			string tmp=v[i-1];
			tmp+=s[i];
			v.push_back(tmp);
			m[s[i]]++;
		//	cout<<s[i]<<" "<<m[s[i]]<<endl;
			if(m[s[i]]%2==0)
			prf[i]=prf[i-1]-1;
			else
			prf[i]=prf[i-1]+1;
		}
		for(char i='a';i<='z';i++)
		m[i]=0;
		m[s[l-1]]++;
		for(int i=l-2;i>=0;i--){
			m[s[i]]++;
			if(m[s[i]]%2==0)
			suf[i]=suf[i+1]-1;
			else
			suf[i]=suf[i+1]+1;
		}
	//	for(int i=0;i<l;i++){
	//		cout<<prf[i]<<" "<<suf[i]<<" "<<v[i]<<endl;
		//}
		for(int i=2;i<l;i++){
			for(int j=2;j<=i;j++)
			{
				if(i%j==0){
					bool f=true;
				//	if(j!=1){
					int tmp=j-1;
					while(tmp+j<i){
					//	cout<<v[tmp]+v[j]<<" "<<v[tmp+i/j]<<endl;
						if(v[tmp]+v[j-1]!=v[tmp+j])
						{
						f=false;
						break;
						}
						tmp+=j;
				//	}
					}
					if(f){
						for(int k=0;k<j-1;k++){
							if(prf[k]<=suf[i])
							{
							ans++;
							//cout<<v[k]<<" "<<v[i/j-1]<<endl;
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}	
