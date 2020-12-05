#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int ans,T,qzh[140000][30],nber[140000],hzh[140000][30],nber_fn[140000];
string s;
void init(){
	ans=0;
	memset(qzh,0,sizeof(qzh));
	memset(nber,0,sizeof(nber));
	memset(hzh,0,sizeof(hzh));
	memset(nber_fn,0,sizeof(nber_fn));
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		cin>>s;
		for(int i=0;i<s.size();i++){
			if(i==0){
			    qzh[i][s[i]-'a']++;
			    nber[i]=1;
			}
			else{
				int id_=26;
				for(int j=0;j<26;j++){
					qzh[i][j]=qzh[i-1][j];
					if(j==s[i]-'a') qzh[i][j]++;
					if(qzh[i][j]%2==1) nber[i]++;
				}
			}
		}
		for(int i=s.size()-1;i>=0;i--){
			if(i==s.size()-1){
			    hzh[i][s[i]-'a']++;
			    nber_fn[i]=1;
			}
			else{
			    int id_=26;
				for(int j=0;j<26;j++){
					hzh[i][j]=hzh[i+1][j];
					if(j==s[i]-'a') hzh[i][j]++;
					if(hzh[i][j]%2==1) nber_fn[i]++;
				}
			}
		}
//		for(int i=0;i<s.size();i++){
//			printf("%d %d\n",nber[i],nber_fn[i]);
//		}
		for(int i=0;i<s.size()-2;i++){
			for(int j=i+1;j<s.size()-1;j++){
				int k=j,len=j-0+1;
				while(k<s.size()-1){
					if(nber[i]<=nber_fn[k+1]) ans++;         
					int  v=1,p=0;
					while(v<=len){
						if(s[k+v]!=s[v-1]||k+v>=s.size()){
							p=1;
							break;
						}
						v++;
					}
					if(p==1) break;
					else k+=len;
				}
			}
		}
		printf("%d\n",ans);	
	}
	return 0;
}    
        	
