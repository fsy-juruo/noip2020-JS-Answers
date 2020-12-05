#include <bits/stdc++.h>
using namespace std;
bool flag;
int a_le[50];
int b_le[50];
bool panduan(string a,string b)
{
	int e=0,r=0;
	//cout<<a<<" "<<b<<endl;
	for(int u=1;u<=26;u++)
	{
		a_le[u]=0;
		b_le[u]=0;
	}
	for(int u=0;u<a.size();u++)a_le[a[u]-96]++;
	for(int u=0;u<b.size();u++)b_le[b[u]-96]++;
	for(int u=1;u<=26;u++)
	{
		if(a_le[u]%2==1)e++;
		if(b_le[u]%2==1)r++;
	}
	//cout<<e<<" "<<r<<endl;
	if(e>r)return 0;
	else return 1;
}
struct string_node{
	string ao,bo,co;
} ;
deque<string_node> de;
bool chazhao(string_node uio)
{
	for(int u=0;u<de.size();u++)
	{
		if(uio.ao==de[u].ao&&uio.bo==de[u].bo&&uio.co==de[u].co&&uio.ao.size()==de[u].ao.size()&&uio.bo.size()==de[u].bo.size()&&uio.co.size()==de[u].co.size())return 0;
		/*if(uio.ao==de[u].bo&&uio.bo==de[u].ao&&uio.co==de[u].co&&uio.ao.size()==de[u].bo.size()&&uio.bo.size()==de[u].ao.size()&&uio.co.size()==de[u].co.size())return 0;
		if(uio.ao==de[u].co&&uio.bo==de[u].bo&&uio.co==de[u].ao&&uio.ao.size()==de[u].co.size()&&uio.bo.size()==de[u].bo.size()&&uio.co.size()==de[u].ao.size())return 0;
		if(uio.ao==de[u].ao&&uio.bo==de[u].co&&uio.co==de[u].bo&&uio.ao.size()==de[u].ao.size()&&uio.bo.size()==de[u].co.size()&&uio.co.size()==de[u].bo.size())return 0;
		if(uio.ao==de[u].bo&&uio.bo==de[u].co&&uio.co==de[u].ao&&uio.ao.size()==de[u].bo.size()&&uio.bo.size()==de[u].co.size()&&uio.co.size()==de[u].ao.size())return 0;
		if(uio.ao==de[u].co&&uio.bo==de[u].ao&&uio.co==de[u].bo&&uio.ao.size()==de[u].co.size()&&uio.bo.size()==de[u].ao.size()&&uio.co.size()==de[u].bo.size())return 0;*/
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t,num;
	string st;
	cin>>t;
	getline(cin,st);
	for(int q=1;q<=t;q++)
	{
		de.clear();
		getline(cin,st);
		string nowa="",nowb="",nowk,nowc="";
		for(int i=0;i<st.size()-2;i++)
		{
			nowa=nowa+st[i];
			nowb="";
			for(int k=i+1;k<st.size()-1;k++)
			{
				nowb=nowb+st[k];
				nowk=nowa+nowb;
				if(st.size()-k-1<=nowk.size())
				{
					//cout<<"GO TO 1"<<endl;
					nowc="";
					for(int o=k+1;o<st.size();o++)nowc+=st[o];
					bool po=panduan(nowa,nowc);
					if(po==0)continue;
					string_node uy;
					uy.ao=nowa;uy.bo=nowb;uy.co=nowc;
					if(chazhao(uy)==1)de.push_back(uy);
					continue;
				}			
				flag=0;
				for(int o=k+1;o<=k+nowk.size();o++)
				{
					if(st[o]!=nowk[o-k-1])
					{
						flag=1;
						break;
					}
				}
				if(flag==1)
				{
					//cout<<"GO TO 2"<<endl;
					nowc="";
					for(int o=k+1;o<st.size();o++)nowc+=st[o];
					bool po=panduan(nowa,nowc);
					if(po==0)continue;
					string_node uy;
					uy.ao=nowa;uy.bo=nowb;uy.co=nowc;
					if(chazhao(uy)==1)de.push_back(uy);
					continue;
				}
				else
				{
					//cout<<"GO TO 3"<<endl;				
					num=k+1;
					while(true)
					{
						for(int o=num;o<num+nowk.size()-1;o++)
						{
							if(st[o]!=nowk[o-num])
							{
								flag=1;
								break;
							}
						}
						if(flag==1)break;
						nowc="";
						for(int o=num;o<st.size();o++)nowc+=st[o];
						bool po=panduan(nowa,nowc);
						num+=nowk.size();
						if(po==0)continue;
						string_node uy;
						uy.ao=nowa;uy.bo=nowb;uy.co=nowc;
						if(chazhao(uy)==1)de.push_back(uy);
						//cout<<"ANS"<<num<<" "<<nowa<<" "<<nowb<<" "<<nowc<<endl;
					}
					nowc="";
					for(int o=num;o<st.size();o++)nowc+=st[o];
					bool po=panduan(nowa,nowc);
					num+=nowk.size();
					if(po==0)continue;
					string_node uy;
					uy.ao=nowa;uy.bo=nowb;uy.co=nowc;
					if(chazhao(uy)==1)de.push_back(uy);						//cout<<"ANS"<<num<<" "<<nowa<<" "<<nowb<<" "<<nowc<<endl;
				}
			}
		}
		cout<<de.size()<<endl;
	//	for(int i=0;i<de.size();i++)cout<<de[i].ao<<" "<<de[i].bo<<" "<<de[i].co<<endl;
	}
	return 0;
}

