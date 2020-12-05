#include<bits/stdc++.h>
using namespace std;

const int maxn=1050005;
int T;
string s;
int length;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>T;
	while(T--){
		cin>>s;
		length=s.size();
		
		int res=0;
		for(int lena=1;lena<=length-2;lena++)
			for(int lenb=1;lenb<=length-lena-1;lenb++){
				int lenc=length-lena-lenb;
				//cout<<lena<<' '<<lenb<<' '<<lenc<<' '<<length<<endl;
				int cnta[30]={0},cntb[30]={0},cntc[30]={0};
				for(int i=0;i<=lena-1;i++)  cnta[int(s[i]-'a'+1)]++;
				for(int i=lena;i<=lena+lenb-1;i++)  cntb[int(s[i]-'a'+1)]++;
				for(int i=length-1;i>=length-lenc;i--)  cntc[int(s[i]-'a'+1)]++;
				int cntodda=0,cntoddc=0;
				for(int i=1;i<=26;i++){
					if(cnta[i]%2==1)  cntodda++;
					if(cntc[i]%2==1)  cntoddc++;
				}
				if(cntodda<=cntoddc){
					res++;
					//cout<<lena<<' '<<lenb<<' '<<lenc<<endl;
				}  
				//cout<<res<<endl;
				while(lenc>0){
					if(lenc>lena+lenb){
						//cout<<lena<<' '<<lenb<<' '<<lenc<<' '<<length<<endl;
						bool f=1;
						int i,k;
						for(i=length-lenc,k=0;k<=lena-1;i++,k++)
							if(s[i]!=s[k]){
								f=0;
								break;
							}
						if(f==1){
							for(k=lena;k<=lena+lenb-1;i++,k++)
							if(s[i]!=s[k]){
								f=0;
								break;
							}
						}
						if(f==0)  break;
						lenc=lenc-lena-lenb;
						cntoddc=0;
						for(int j=1;j<=26;j++){
							cntc[j]=cntc[j]-cnta[j]-cntb[j];
							if(cntc[j]%2==1)  cntoddc++;
						}  
						if(cntodda<=cntoddc){
							res++;
							//cout<<lena<<' '<<lenb<<' '<<lenc<<endl;
						} 
					}
					else break;
				}
				
			}
		
		cout<<res<<endl;
	}
}
