//check result;
//check if the path travel through all nodes
#include <bits/stdc++.h>
using namespace std;

string const tentepin("output.txt");

int n, a[100],check,length;
int main() {
	for (int i=0;i<100;i++) a[i]=0;
	ifstream in(tentepin.c_str());
	if (in) {
		in>>n>>length;
		for (int i=0;i<length;i++) {
			int k;
			in>>k;
			a[k]++;
		}
		check=1;
		for (int i=0;i<n;i++) 
			if (a[i]==0) {
				check=0;
				break;
			}
	} else cout<<"khong doc duoc file";
	if (check==0) cout<<"FALSE";
	else cout<<"TRUE";
	return 0;
}
