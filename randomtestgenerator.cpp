//random test
//file input: primal.txt
//file output: input.txt
#include <bits/stdc++.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

string const tentepin("primal.txt");
string const tentepout("input.txt");

short a[200][200];

int getrandom(int n, int m);

int main() {
	int m,n,range;
	
	ifstream in(tentepin.c_str());
	if(in) {
		in>>m>>n>>range;
		for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) a[i][j]=0;
	}
	else {cout<<"loi khong doc duoc file in";
	}
	
	ofstream out(tentepout.c_str());
	if(out) {
		
		out<<m<<" "<<n<<' ';
		for (int k=0;k<2;k++)
		out<<getrandom(n,k)<<' ';
		out<<"\n";
		
		for (int k=0;k<m;k++) {
			int i,j;
			int f=0;
			do {
				i = (getrandom(n,k+f)+f)%n;
				f++;
				j = (getrandom(n,f)+f)%n;
			} while (a[i][j]!=0 || i==j);
			if (i<j) {
				int s=j;j=i;i=s;
			}
			a[i][j] = 1+(getrandom(range,k)+k)%range;
			a[j][i] = a[i][j];
		}
		for (int i=0;i<n;i++) {
			for (int j=i+1;j<n;j++) 
			if (a[i][j]!=0)
			out<<i<<" "<<j<<" "<<a[i][j]<<"\n";
		}
	}
	else {cout<<"loi khong doc duoc file out";
	}
	return 0;
}

int getrandom(int n, int m) {
	srand(m);
	int i=rand()%10;
	int rng=i;
	for (int k=0;k<i;k++) {
		srand(rng);
		rng=rand();
	}
	return rng%n;
}
