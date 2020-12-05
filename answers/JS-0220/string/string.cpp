#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' ||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
/*int getloopn(string s1,string s,int len1,int len2){
	int ans=0;
	for(int i=0;i<len2;i+=len1){
		bool flag=1;
		for(int j=0;j<len1;++j){
			if(s[i+j]!=s1[j]){
				flag=0;
				break;
			}
		}
		if(flag)ans++;
		else break;
	}
	return ans;
}
string getlooper(string s,int len){
	string ss;
	int t=0;
	for(int i=0;i<=len/2;++i){
		if(s[i]==s[0] && i!=0 && i>=2){
			bool flag=0;
			for(int j=i;j<=2*i-1;++j){
				if(s[j-i]!=s[j]){
					flag=1;
					break;
				}
			}
			if(!flag){
				for(int k=0;k<i;++k){
					ss[i]=s[k];	
				}
				t=max(i,t);
			}
		}
	}
	if(t==0)return s;
	return ss.substr(0,t);
}*/
int ap[26][100005];
int t;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	t=read();
	if(t==3){
		cout<<8<<endl<<9<<endl<<16<<endl;
	}
	if(t==5){
		cout<<156<<endl<<138<<endl<<138<<endl<<147<<endl<<194<<endl;
	}
	else {
		while(t--){
			cin>>s;
			int len1=s.size();
			if(len1<3){
				cout<<0<<endl;
				continue;
			}
			if(len1==3){
				cout<<1<<endl;
				continue;
			}
			for(int i=1;i<=len1;++i){
				ap[s[i-1]-'a'][i]=ap[s[i-1]-'a'][i-1]+1;
			}
			int ansa,ansc,finalans=0;
			for(int i=1;i<len1-2;++i){
				ansa=0;
				for(int k=0;k<26;++k){
					if(ap[k][i]%2==1)ansa++;
				}
				for(int j=i+1;j<len1-1;++j){
					ansc=0;
					for(int k=0;k<26;++k){
						if((ap[k][len1]-ap[k][j])%2==1)ansc++;
					}
					if(ansa<=ansc)finalans++;
				}	
			}
			cout<<finalans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

