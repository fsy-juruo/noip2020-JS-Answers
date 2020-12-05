#include <bits/stdc++.h>

using namespace std;

//const int N=;

int n;
int odd[30];
char s[1200000],copy[1200000];
//bool
//vector<int>
//pair<int,int>

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		int ans=0;	
		int len=strlen(s);
		int F=0;
		for (int j=0;j<len;++j){
			if(s[i]!=s[j]){
				F=1;
				break;
			}
		}
		if(F==0){
			for (int j=len-1;j>=2;j--){//j-s[0]~s[j-1] ABi
				int Oddc=0;
				if((len-j)%2==1) Oddc=1;
				for (int k=2;k<=j;k++){//k-"how long the AB is"
					if(j%k!=0) continue;
					int f=0;
					for (int m=0;m<=j-k-1;m++){
						if(s[m]!=s[m+k]){
							f=-1;
							break;
						}
					}
					if(f==-1) continue;
					for (int m=1;m<=k-1;m++){
						int Odda=0;
						if(m%2==1) Odda=1;
						//cout << j << " " << k << " " << m << " " << Odda << " " << Oddc << endl;
						if(Odda<=Oddc){
							ans++;
						}
					}
				}			
			}
			printf("%d\n",ans);
			continue;
		}
		for (int j=len-1;j>=2;j--){//j-s[0]~s[j-1] ABi
			int Oddc=0;
			for (int k=0;k<=26;k++){
				odd[k]=0;
			}
			for (int k=j;k<=len-1;k++){
				odd[s[k]-'a']++;
			}
			for (int k=0;k<=26;k++){
				if(odd[k]%2==1){
					Oddc++;
				}
			}
			for (int k=2;k<=j;k++){//k-"how long the AB is"
				if(j%k!=0) continue;
				int f=0;
				for (int m=0;m<=j-k-1;m++){
					if(s[m]!=s[m+k]){
						f=-1;
						break;
					}
				}
				if(f==-1) continue;
				for (int m=1;m<=k-1;m++){
					int Odda=0;
					for (int M=0;M<=26;M++){
						odd[M]=0;
					}
					for (int M=0;M<m;M++){
						odd[s[M]-'a']++;
					}
					for (int M=0;M<=26;M++){
						if(odd[M]%2==1){
							//cout << M;
							Odda++;
						}
					}
					//cout << j << " " << k << " " << m << " " << Odda << " " << Oddc << endl;
					if(Odda<=Oddc){
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
