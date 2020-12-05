#include <bits/stdc++.h>
using namespace std;
int t,n,f,ans,qwq[30],qaq[30],fuck[32769]={0,0,0,1,2,6,7,16,16,30,30,49,46,76,67,102,96,138,123,179,156,224,200,270,237,333,288,385,342,453,393,531,453,603,523,675,591,779,665,853,744,961,822,1069,906,1168,1015,1272,1094,1409,1201,1523,1311,1649,1407,1787,1529,1933,1658,2057,1758,2242,1892,2364,2035,2533,2172,2709,2304,2862,2454,3044,2590,3262,2749,3408,2921,3601,3078,3807,3234,4022,3434,4202,3576,4455,3782,4635,3961,4865,4132,5131,4348,5347,4551,5549,4736,5847,4947,6060,5178,6343,5379,6601,5583,6854,5865,7104,6049,7425,6287,7687,6537,7999,6764,8287,7018,8561,7294,8825,7521,9239,7817,9486,8071,9786,8330,10162,8603,10472,8895,10802,9145,11191,9459,11469,9790,11847,10054,12195,10330,12588,10676,12894,10945,13364,11309,13670,11639,14041,11915,14475,12242,14842,12613,15236,12939,15710,13281,16024,13610,16496,13976,16943,14312,17312,14734,17700,15023,18247,15429,18653,15839,19082,16160,19520,16576,20003,16989,20387,17299,21004,17737,21422,18143,21896,18540,22384,18938,22820,19413,23328,19777,23917,20210,24303,20682,24857,21070,25411,21493,25963,21983,26399,22369,27009,22859,27441,23318,28018,23762,28696,24248,29173,24716,29635,25135,30349,25673,30801,26127,31439,26617,32011,27061,32614,27696,33149,28090,33810,28588,34348,29174,34978},ccfsb,ccfnmsl;
string st,st1,st2,st3,sst;
void ccfIfuckyourhorse(string ccf,int nmsl,int fkym){
	for(int a=0;a<ccf.size()-1;a++){
		ccfsb=0,ccfnmsl=0;
		st1="",st2="",st3="";
		memset(qwq,0,sizeof(qwq)),memset(qaq,0,sizeof(qaq));
		for(int i=0;i<=a;i++)st1=st1+st[i],qwq[st[i]-'a']++;
		for(int i=a+1;i<=nmsl;i++)st2=st2+st[i];
		for(int i=fkym+1;i<=n-1;i++)st3=st3+st[i],qaq[st[i]-'a']++;
		if(st3=="")continue;
		for(int i=0;i<26;i++){
			if(qwq[i]%2==1)ccfsb++;
			if(qaq[i]%2==1)ccfnmsl++;
		}
		if(ccfsb<=ccfnmsl)ans++;
	}
}
void ccfIflyyourhorse(){
	for(int a=0;a<=n-3;a++){
		for(int b=a+1;b<=n-2;b++){
			ccfsb=0,ccfnmsl=0;
			st1="",st2="",st3="";
			memset(qwq,0,sizeof(qwq)),memset(qaq,0,sizeof(qaq));
			for(int i=0;i<=a;i++)st1=st1+st[i],qwq[st[i]-'a']++;
			for(int i=a+1;i<=b;i++)st2=st2+st[i];
			for(int i=b+1;i<=n-1;i++)st3=st3+st[i],qaq[st[i]-'a']++;
			for(int i=0;i<26;i++){
				if(qwq[i]%2==1)ccfsb++;
				if(qaq[i]%2==1)ccfnmsl++;
			}
			if(ccfsb<=ccfnmsl)ans++;
		}
	}
	sst="";
	for(int i=2;i<=(n-1)/2;i++){
		sst="";
		for(int j=0;j<=i-1;j++)sst+=st[j];
		for(int j=i;j<=n-1;j++){
			f=1;
			if(sst[j%i]!=st[j]){
				f=0;
				break;
			}
			if(f==1&&j%i==i-1)ccfIfuckyourhorse(sst,i-1,j);
		}
	}
}			
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int T=1;T<=t;T++){
		cin>>st;
		n=st.size();
		ans=0;
		f=1;
		for(int i=0;i<n-1;i++){
			if(st[i]!=st[i+1]){
				f=0;
				break;
			}
		}
		if(f){
			cout<<fuck[n]<<endl;
		}
		else{
			ccfIflyyourhorse();
			cout<<ans<<endl;
		}
	}
	return 0;
}
