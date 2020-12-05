#include<bits/stdc++.h>
using namespace std;
	double t,ans;
	string st;
	//map <string int> h;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>st;
		for(int i1=0;i1<st.size()-2;i1++){
			string st1="";
			for(int k=0;k<=i1;k++){
				st1=st1+st[k];
			}
			for(int i2=1;i2<st.size()-1-st1.size();i2++){
				string st2="";
				for(int k2=st1.size();k2<=st1.size()+i2;k2++){
				st2=st2+st[k2];
			
			string st3="";
			for(int k3=st1.size()+st2.size();k3<st.size();k3++){
				st3=st3+st[k3];
			}
		
			long long l1=st1.size(),l2=st2.size(),l3=st3.size();
			if(l1+l2+l3==st.size()) ans=ans+0.5;
			else{
				string st4=st1+st2;
				long long l4=st4.size();
				for(int ci=1;ci<=st.size();ci++){
					if(ci*l4+l3>st.size()){
						break;
					}
						if(ci*l4+l3<st.size()){
						continue;
					}
					int f=0;
					for(int check=l4;check<st.size();check=check+l4){
						string ch;
						ch[0]=st[check];
						ch[1]=st[check+1];
						ch[2]=st[check+2];
						if(ch!=st4) f=1; 
					}
					if(f==0){
						ans++;
					}
				}
			}
			}
		}
		

	}	cout<<ans<<endl;	
}
	return 0;
}
