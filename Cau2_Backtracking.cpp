#include<iostream>
using namespace std;
int n,W; // quantify pack and weight balo.
int wt[100]; // weight item
int val[100]; // value item
int b[100]; // save package states (select || don't select) during maximum value finding.
int sumMax =0; // the end of the result.

void enterInput(){
    cin>>n>>W;
    for(int i=1;i<=n;i++){
        cin>>wt[i]>>val[i];
        b[i]=1;
    }
}

void KnapsackBacktracking(int k){
    // stopping condition.
    if(k==n+1){
        
        int sumWeight =0;
        for(int i=1;i<=n;i++){
            // calculate total baggage weight of all packages
            if(b[i]){
                sumWeight+=wt[i];
            }
        }
        if(sumWeight<=W){
            // filter the case where the bag has a valid weight compared to the bag value of the given problem
            int sumValue=0;
            for(int i=1;i<=n;i++){
                if(b[i]){
                    sumValue+=val[i];
                }
            }
            if(sumValue>sumMax){
                // compare with current max value
                sumMax=sumValue;
            }
        }
        return;
    }
    // Backtracking Algorithm.
    for(int i=0;i<2;i++){
        // create a binary tree -> calculate the value of when the stopping condition is reached.
        b[k]=i;
        KnapsackBacktracking(k+1);
        // when calculating the result at the stop condition 
        //-> return the default value of the bag state TO calculate other cases.
        b[k]=0;
    }
}


void selectedPackage(int k){
    // The same way as the Knapsack Backtracking function, it still calculates 
    //the total weight of the calculation when going through all the packages.
    if(k==n+1){
        int sumWeight =0;
        for(int i=1;i<=n;i++){
            if(b[i]){
                sumWeight+=wt[i];
            }
        }
        if(sumWeight<=W){
            int sumValue=0;
            for(int i=1;i<=n;i++){
                if(b[i]){
                    sumValue+=val[i];
                }
            }
            // But instead of comparing to find the max value, use that max value 
            //to determine the selected packages and output the results.
            if(sumValue==sumMax){
                for(int i=1;i<=n;i++){
                    if(b[i]==1){
                        cout<<wt[i]<<" ";
                    }
                    
                }
                cout<<endl;
            }
        }
        return;
    }
    // Backtracking find packages acepted.
    for(int i=0;i<2;i++){
        b[k]=i;
        selectedPackage(k+1);
        b[k]=0;
    }
}
int main(){
    enterInput();
    KnapsackBacktracking(1);
    cout<<sumMax<<endl;
    selectedPackage(1);
    return 0;
    
// 4 35
// 10 60
// 20 100
// 25 120
// 15 130

// 230
// 20 15 
}