#include<bits/stdc++.h>
using namespace std;
int T,h[200][10010],sa,sc,ans,hh[200],pc[10010];
string s,mb;
int main(){
	freopen("string .in","r",stdin);
	freopen("string .out","w",stdout);
    cin>>T;
    for (int js=1; js<=T; js++)
    {
    	memset(h,0,sizeof(h));
    	cin>>s;
    	for (int i=0; i<s.size(); i++)
    	{
    		h[s[i]][i]++;
    		if (i==0) continue;
    		for (int j='a'; j<='z'; j++)
    		  h[j][i]=h[j][i-1]+h[j][i];
		}
		for (int i=0; i<s.size()-2; i++)
		{
			
			
			
			for (int j=i+1; j<s.size()-1; j++)
			{
				
				sa=0;
			
			    for (int z='a'; z<='z'; z++)
			      if (h[z][i]%2==1) sa++;
				
			    sc=0;
				for (int z='a'; z<='z'; z++)
			      if ((h[z][s.size()-1]-h[z][j])%2==1) sc++;
			    
//			    cout<<i+1<<' '<<j-i<<' '<<sa<<' '<<sc<<endl,
			    if (sa<=sc) ans++;//,cout<<'@'
				        //    if (i==0&&j==3) cout<<'!'<<h['k'][0]<<' ';
						 //   cout<<i+1<<' '<<j-i<<' '<<sa<<' '<<sc<<endl,
			//sta
			mb="";
			memset(hh,0,sizeof(hh));
			int cs=0;
			    for (int b=0; b<=j; b++)
			    {
			    	mb=mb+s[b];
			    	if (hh[s[b]]==0) hh[s[b]]=1,cs++;
				}
				int css,fcs;
				css=0,cs=sa;fcs=0;
				
				int kk=j+1,pd=0;
				while (kk+j<s.size()-1)
				{
					fcs++;
					for (int b=kk; b<=kk+j; b++)
					{
						if (s[b]!=mb[b-kk]){
							pd=1;break;
						}
					}
					if (pd==1) break;
					kk+=j;
							sa=0,sc=0;
							if (fcs%2==1) sa=css;
							else sa=cs; 
							
							
						
								for (int z='a'; z<='z'; z++)
							      if ((h[z][s.size()-1]-h[z][kk])%2==1) sc++;
							    
				
							    if (sa<=sc) ans++;//&&pc[j]==0
							
					//if (mb=="mml") cout<<'!'<<kk<<' '<<sa<<' '<<sc<<endl;
					    
					//
				}
				
				
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	
	return 0;
}
