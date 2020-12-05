#include<bits/stdc++.h>
using namespace std;
string read(){
	char c;
	string s;
	while((c=getchar())!='\n')
		s.push_back(c);
	return s;	
}
bool eql(string a,string b){
	if(a.size()!=b.size()) return false;
	for(int i=0;i<a.size();i++)
		if(a[i]!=b[i]) return false;
	return true;		
}
int f(string s){
	map<char,int> tong;
	int cnt=0;
	for(int i=0;i<s.size();i++)
		tong[s[i]]++;
	for(map<char,int>::iterator it=tong.begin();it!=tong.end();it++)
		if((it->second)&1) cnt++;
	return cnt;	 	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		s=read();
		if(i){
			int way=0;
			for(int clen=1;s.size()-clen>=2;clen++){
				for(int ablen=2;ablen<=s.size()-clen;ablen++){
					bool flag=false;
					if(!((s.size()-clen)%ablen)){
						if(ablen!=s.size()-clen){
							for(int i=0;i+ablen<s.size()-clen;i+=ablen){	
								if(!eql(s.substr(i,ablen),s.substr(i+ablen,ablen))){
									flag=true;
									break;
								}									
							}
						}
						if(!flag){
							string t=s.substr(0,ablen);
							for(int index=1;index<=ablen-1;index++)
								if(f(t.substr(0,index))<=f(s.substr(s.size()-clen,clen)))
									way++;								
						}			
					}
				}
			}
			if(i>1) printf("\n");
			printf("%d",way);			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

