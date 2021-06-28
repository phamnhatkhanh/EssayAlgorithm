#include <bits/stdc++.h>
using namespace std;
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Prints the items which are put in a knapsack of capacity W
void KnapsackDynamicProgramming(int W, int wt[], int val[], int n)
{
	//There is an opinion that the bag that was previously optimized (with the largest value) 
	//now compares whether to choose or not to choose the larger package 
	//(depending on the case that the problem can choose more packages, 
	//the value of bags will be higher larger did not choose,

	// but since the bag limit has been exceeded, it is better not to choose the package).
	int i, w;
	int K[n + 1][W + 1];

	// Build table K[][] in bottom up manner.
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				//case selection pack:
					//take the value (val[i - 1]) + the value weight of the bag(w) when subtracting the weight 
 					//of the current pack(wt[i - 1]).(because the previous weight has found the optimal value)
			// then comparecase selected and not selected pack If the value of any party is greater, chose that side
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	// stores the result of Knapsack
	int res = K[n][W];
  
	printf("%d\n", res);
	
	w = W;
	for (i = n; i > 0 && res > 0; i--) {
		// compare the bag value at the present time with the bag value at the time of previous item selection.
		if (res == K[i - 1][w])
			// If the current bag value remains unchanged, it means that you have ignored the current package.
			continue;	
		else {

			// This item is included.
			printf("%d ", wt[i - 1]);
			
			// Since this weight is included its
			// value is deducted
			res = res - val[i - 1];
			w = w - wt[i - 1];
		}
	}
  
	cout<<endl;
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {	
				cout<<K[i][w]<<" ";
		}
		cout<<endl;
	}
}

// Driver code
int main()
{
	int val[] = { 60, 100, 120,130 };
	int wt[] = { 10, 20, 25,15 };
	int W = 35;
	int n = sizeof(val) / sizeof(val[0]);
	
	KnapsackDynamicProgramming(W, wt, val, n);
	
	return 0;
}

/*
	230
15 20 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 
0 0 0 0 0 0 0 0 0 0 60 60 60 60 60 60 60 60 60 60 100 100 100 100 100 100 100 100 100 100 160 160 160 160 160 160 
0 0 0 0 0 0 0 0 0 0 60 60 60 60 60 60 60 60 60 60 100 100 100 100 100 120 120 120 120 120 160 160 160 160 160 180 
0 0 0 0 0 0 0 0 0 0 60 60 60 60 60 130 130 130 130 130 130 130 130 130 130 190 190 190 190 190 190 190 190 190 190 230 
*/