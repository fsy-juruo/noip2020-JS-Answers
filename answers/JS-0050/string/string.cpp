#include <bits/stdc++.h>
using namespace std;
string e[1000];
int g=0;
int haha(string A,string B,string C){
	int i,j=1;
	for(i=0;i<g;i++){
		if(A+"*"+B+"*"+C==e[i]||A+"*"+C+"*"+B==e[i]||B+"*"+A+"*"+C==e[i]||B+"*"+C+"*"+A==e[i]||C+"*"+A+"*"+B==e[i]||C+"*"+B+"*"+A==e[i]) {j=0;break;}
	}
	return j;
}
int ha(string A,string C){
	int na=0,nc=0,sa=0,sc=0,f=0;
	int lA=A.length(),lC=C.length(),la,lc;
	string a,c;
	int i,j;
	for(i=0;i<lA;i++){
		f=0;
		la=a.length();
		for(j=0;j<la;j++) if(A[i]==a[j]) f=1;
		if(f==1) continue;
		for(j=0;j<lA;j++) if(A[i]==A[j]) na++;
		a+=A[i];
		if(na%2) sa++;
		na=0;
	}
	for(i=0;i<lC;i++){
		f=0;
		lc=c.length();
		for(j=0;j<lc;j++) 
		    if(C[i]==c[j]) f=1;
		    if(f==1) continue;
		for(j=0;j<lC;j++) if(C[i]==C[j]) nc++;
		c+=C[i];
		if(nc%2) sc++;
		nc=0;
	}
	if(sa>sc) return 0;
	else return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T,i,j,k,p,q,r,n=0,f;
	string b;
	string D,E;
	cin>>T;
	for(i=0;i<T;i++){
		string S,A,B,C;
		cin>>S;
		int l=S.length();
		for(j=0;j<l-2;j++){
			A+=S[j];
			for(k=j+1;k<l-1;k++){
				B+=S[k];
				for(r=k+1;r<l;r++) C+=S[r];
					if(ha(A,C)&&haha(A,B,C)){
						 n++;
						 e[g]=A+"*"+B+"*"+C;
						 cout<<A<<"*"<<B<<" "<<C<<endl;
					}
					C=b;
			}
			B=b;
		}
		for(k=0;k<g;k++) e[k]=b;
		g=0;
		D+=S[0];
		for(p=1;p<(l+1)/2;p++){
			D+=S[p];
			for(q=p+1;q<l-1;q++){
				E+=S[q];
				if(D==E){
					n++;
					E=b;
				}
			}
			E=b;
		}
		cout<<n;
		cout<<endl;
		n=0;
		D=b;
		E=b;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

