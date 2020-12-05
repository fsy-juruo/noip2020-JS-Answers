#include <bits/stdc++.h>
using namespace std;
int bb[110];string s;int mm[110];	int ton1[30],ton2[30];
void cons(int a,int b,int c,int k){
	memset(bb,0,sizeof(bb));
	for(int i=1;i<=k;i++){
		for(int j1=1;j1<=b;j1++){
			bb[j1+(i-1)*b]=mm[j1];
			
		}
		
		
	}
	for(int i=1;i<=c;i++)
			bb[k*b+i]=mm[s.length()-i+1];
			
		
		
	
	/*for(int i=1;i<=k*b+c;i++)cout<<bb[i]<<" ";
	cout<<endl;*/
	
}
bool bi(){
	for(int i=1;;i++)
	{
		if(mm[i]!=bb[i])return false;
		if(mm[i]==0&&bb[i]==0)break;
	}
	return true;
}
bool oo(int a,int c){
memset(ton1,0,sizeof(ton1));memset(ton2,0,sizeof(ton2));
	for(int i=s.length()-c+1;i<=s.length();i++)
	{
		
		if(mm[i]==0)break;
		ton1[mm[i]]++;
		
	}
	for(int i=1;i<=a;i++)
	{
		
		if(mm[i]==0)break;
		ton2[mm[i]]++;
		
	}
	int ss1=0,ss2=0;
	for(int i=1;i<=26;i++)if(ton1[i]%2)ss1++;
	for(int i=1;i<=26;i++)if(ton2[i]%2)ss2++;
	if(ss1>=ss2)
	return true;return false;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	srand(time(NULL));
	int T,ans=0;
	
	cin>>T;
	while(T--){
		cin>>s;
		for(int i=0;i<s.length();i++){
			mm[i+1]=s[i]-'a'+1;
			if(mm[i+1]<=0||mm[i+1]>26)mm[i+1]=0;
			//cout<<mm[i+1]<<" ";
			
			
		}
		for(int a=1;a<=s.length()-2;a++)
		{
			for(int b=a+1;b<=s.length()-1;b++){
				for(int c=1;c<=s.length()-2;c++){
					for(int i=1;i<=9;i++){
						
						cons(a,b,c,i);//return 0;
				        if(bi())
				        {
				        	if(oo(a,c))
				        	ans++;
				    	
						
						
						
						}
				    
				    	
				    	
				    	
					}
				    
				    
				    
			    }
			    
			    
			    
			}
			
			
			
			
			
		}
		cout<<ans;
		
		
	}
	return 0;
}
/*
1
nnrnnr
*/
