#include<bits/stdc++.h>
using namespace std;
unsigned long long base=233;//
const unsigned long long maxn=1024*1024+10;
unsigned long long poww[maxn+10];
char c[maxn+10];
unsigned long long hash[maxn+10];
unsigned long long gethash(unsigned long long q,unsigned long long w)
{
	return hash[w]-hash[q-1]*poww[w-q+1];
}
int A[maxn];
int B[maxn];
int C[maxn];
int D[maxn];
int E[maxn];
int F[maxn];
int G[maxn];
int H[maxn];
int I[maxn];
int J[maxn];
int K[maxn];
int L[maxn];
int M[maxn];
int N[maxn];
int O[maxn];
int P[maxn];
int Q[maxn];
int R[maxn];
int s[maxn];
int t[maxn];
int U[maxn];
int V[maxn];
int W[maxn];
int X[maxn];
int Y[maxn];
int Z[maxn];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	poww[0]=1;
	for(int i=1;i<=maxn;i++)
	{
		poww[i]=poww[i-1]*base;
	}
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		int len=S.length();
		for(int i=0;i<len;i++)
		{
			c[i+1]=S[i];
		}
		for(int i=1;i<=len;i++)
		{
			A[i]=A[i-1];
			B[i]=B[i-1];
			C[i]=C[i-1]+0;
			D[i]=D[i-1]+0;
			E[i]=E[i-1]+0;
			F[i]=F[i-1]+0;
			G[i]=G[i-1]+0;
			H[i]=H[i-1]+0;
			I[i]=I[i-1]+0;
			J[i]=J[i-1]+0;
			K[i]=K[i-1]+0;
			L[i]=L[i-1]+0;
			M[i]=M[i-1]+0;
			N[i]=N[i-1]+0;
			O[i]=O[i-1]+0;
			P[i]=P[i-1]+0;
			Q[i]=Q[i-1]+0;
			R[i]=R[i-1]+0;
			s[i]=s[i-1]+0;
			t[i]=t[i-1]+0;
			U[i]=U[i-1]+0;
			V[i]=V[i-1]+0;
			W[i]=W[i-1]+0;
			X[i]=X[i-1]+0;
			Y[i]=Y[i-1]+0;
			Z[i]=Z[i-1]+0;
			if(c[i]=='a') A[i]++;
			if(c[i]=='b') B[i]++;
			if(c[i]=='c') C[i]++;
			if(c[i]=='d') D[i]++;
			if(c[i]=='e') E[i]++;
			if(c[i]=='f') F[i]++;
			if(c[i]=='g') G[i]++;
			if(c[i]=='h') H[i]++;
			if(c[i]=='i') I[i]++;
			if(c[i]=='j') J[i]++;
			if(c[i]=='k') K[i]++;
			if(c[i]=='l') L[i]++;
			if(c[i]=='m') M[i]++;
			if(c[i]=='n') N[i]++;
			if(c[i]=='o') O[i]++;
			if(c[i]=='p') P[i]++;
			if(c[i]=='q') Q[i]++;
			if(c[i]=='r') R[i]++;
			if(c[i]=='s') s[i]++;
			if(c[i]=='t') t[i]++;
			if(c[i]=='u') U[i]++;
			if(c[i]=='v') V[i]++;
			if(c[i]=='w') W[i]++;
			if(c[i]=='x') X[i]++;
			if(c[i]=='y') Y[i]++;
			if(c[i]=='z') Z[i]++;
		}
		hash[1]=c[1]-'a';//
		for(int i=2;i<=len;i++)
		{
			hash[i]=hash[i-1]*233+(c[i]-'a');
		//	cout<<i<<" "<<hash[i]<<endl;
		}
	//	cout<<gethash(1,2)<<" "<<gethash(3,4);
		unsigned long long ans=0;
		for(int st=len;st>=3;st--)
		{
			unsigned long long cnt=0;
			if((A[len]-A[st-1])%2==1) cnt++;
			if((B[len]-B[st-1])%2==1) cnt++;
			if((C[len]-C[st-1])%2==1) cnt++;
			if((D[len]-D[st-1])%2==1) cnt++;
			if((E[len]-E[st-1])%2==1) cnt++;
			if((F[len]-F[st-1])%2==1) cnt++;
			if((G[len]-G[st-1])%2==1) cnt++;
			if((H[len]-H[st-1])%2==1) cnt++;
			if((I[len]-I[st-1])%2==1) cnt++;
			if((J[len]-J[st-1])%2==1) cnt++;
			if((K[len]-K[st-1])%2==1) cnt++;
			if((L[len]-L[st-1])%2==1) cnt++;
			if((M[len]-M[st-1])%2==1) cnt++;
			if((N[len]-N[st-1])%2==1) cnt++;
			if((O[len]-O[st-1])%2==1) cnt++;
			if((P[len]-P[st-1])%2==1) cnt++;
			if((Q[len]-Q[st-1])%2==1) cnt++;
			if((R[len]-R[st-1])%2==1) cnt++;
			if((s[len]-s[st-1])%2==1) cnt++;
			if((t[len]-t[st-1])%2==1) cnt++;
			if((U[len]-U[st-1])%2==1) cnt++;
			if((V[len]-V[st-1])%2==1) cnt++;
			if((W[len]-W[st-1])%2==1) cnt++;
			if((X[len]-X[st-1])%2==1) cnt++;
			if((Y[len]-Y[st-1])%2==1) cnt++;
			if((Z[len]-Z[st-1])%2==1) cnt++;
//			for(int k=1;k<=st-2;k++)
//			{
//				int kk=k;
//				int cnt2=0;
//				if((A[kk])%2==1) cnt2++;
//				if((B[kk])%2==1) cnt2++;
//				if((C[kk])%2==1) cnt2++;
//				if((D[kk])%2==1) cnt2++;
//				if((E[kk])%2==1) cnt2++;
//				if((F[kk])%2==1) cnt2++;
//				if((G[kk])%2==1) cnt2++;
//				if((H[kk])%2==1) cnt2++;
//				if((I[kk])%2==1) cnt2++;
//				if((J[kk])%2==1) cnt2++;
//				if((K[kk])%2==1) cnt2++;
//				if((L[kk])%2==1) cnt2++;
//				if((M[kk])%2==1) cnt2++;
//				if((N[kk])%2==1) cnt2++;
//				if((O[kk])%2==1) cnt2++;
//				if((P[kk])%2==1) cnt2++;
//				if((Q[kk])%2==1) cnt2++;
//				if((R[kk])%2==1) cnt2++;
//				if((s[kk])%2==1) cnt2++;
//				if((t[kk])%2==1) cnt2++;
//				if((U[kk])%2==1) cnt2++;
//				if((V[kk])%2==1) cnt2++;
//				if((W[kk])%2==1) cnt2++;
//				if((X[kk])%2==1) cnt2++;
//				if((Y[kk])%2==1) cnt2++;
//				if((Z[kk])%2==1) cnt2++;
//				if(cnt2<=cnt) ans++;
//			}
//			for(int kk=1;kk<=(st-1)/i-1;kk++)
//			{
//				if((A[kk])%2==1) cnt2++;
//				if((B[kk])%2==1) cnt2++;
//				if((C[kk])%2==1) cnt2++;
//				if((D[kk])%2==1) cnt2++;
//				if((E[kk])%2==1) cnt2++;
//				if((F[kk])%2==1) cnt2++;
//				if((G[kk])%2==1) cnt2++;
//				if((H[kk])%2==1) cnt2++;
//				if((I[kk])%2==1) cnt2++;
//				if((J[kk])%2==1) cnt2++;
//				if((K[kk])%2==1) cnt2++;
//				if((L[kk])%2==1) cnt2++;
//				if((M[kk])%2==1) cnt2++;
//				if((N[kk])%2==1) cnt2++;
//				if((O[kk])%2==1) cnt2++;
//				if((P[kk])%2==1) cnt2++;
//				if((Q[kk])%2==1) cnt2++;
//				if((R[kk])%2==1) cnt2++;
//				if((s[kk])%2==1) cnt2++;
//				if((t[kk])%2==1) cnt2++;
//				if((U[kk])%2==1) cnt2++;
//				if((V[kk])%2==1) cnt2++;
//				if((W[kk])%2==1) cnt2++;
//				if((X[kk])%2==1) cnt2++;
//				if((Y[kk])%2==1) cnt2++;
//				if((Z[kk])%2==1) cnt2++;
//			}
//			if(cnt2<=cnt) ans++;
			for(int i=2;i<=st-1;i++)
			{
				if((st-1)%i==0 && gethash(1,i)==gethash(st-i,st-1))
				{ //  cout<<i<<"   *   "<<st-1<<endl;
					
					for(int kk=1;kk<=i-1;kk++)
					{int cnt2=0;
						if((A[kk])%2==1) cnt2++;
						if((B[kk])%2==1) cnt2++;
						if((C[kk])%2==1) cnt2++;
						if((D[kk])%2==1) cnt2++;
						if((E[kk])%2==1) cnt2++;
						if((F[kk])%2==1) cnt2++;
						if((G[kk])%2==1) cnt2++;
						if((H[kk])%2==1) cnt2++;
						if((I[kk])%2==1) cnt2++;
						if((J[kk])%2==1) cnt2++;
						if((K[kk])%2==1) cnt2++;
						if((L[kk])%2==1) cnt2++;
						if((M[kk])%2==1) cnt2++;
						if((N[kk])%2==1) cnt2++;
					//cout<<"fuck1"<<R[kk]<<endl;
						if((O[kk])%2==1) cnt2++;
						if((P[kk])%2==1) cnt2++;
						if((Q[kk])%2==1) cnt2++;
						if((R[kk])%2==1) cnt2++;
						if((s[kk])%2==1) cnt2++;
						if((t[kk])%2==1) cnt2++;
						if((U[kk])%2==1) cnt2++;
						if((V[kk])%2==1) cnt2++;
						if((W[kk])%2==1) cnt2++;
						if((X[kk])%2==1) cnt2++;
						if((Y[kk])%2==1) cnt2++;
						if((Z[kk])%2==1) cnt2++;
					//	if(i==5 && kk==3) cout<<"cnt2="<<cnt2<<endl;
						if(cnt2<=cnt) 
						{
							ans++;
						//	cout<<kk<<endl;
						}
					}
				}
			}
					
		}
		cout<<ans<<endl;
	}
	return 0;
}
