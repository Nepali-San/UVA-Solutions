#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long int

int dollars[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
int size    = 11;
ull table[30001];

int main() {
	double amount;
	int amt;

	for(int i = 0; i < 30001; i++) table[i] = 0;
	table[0] = 1;

	for(int i = 0; i < 11; i++){
		for(int j = dollars[i]; j < 30001; j++){
			 table[j] += table[j-dollars[i]];
		}
	}

	while(scanf("%lf",&amount)){
		if(amount*100.00 == 0) break;

		amt = amount * 20.00;
		amt = amt * 5;

		printf("%6.2lf %16llu\n",amount,table[amt]);
	}

	return 0;
}
