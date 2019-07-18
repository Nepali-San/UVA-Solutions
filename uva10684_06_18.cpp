#include<bits/stdc++.h>
using namespace std;

#define ALLONS_Y  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

//use Kadane algorithm for maximum subsequence sum.

int maxSum(int n,int arr[]){
    int maxsum = arr[0];
    int maxans = arr[0];

    for(int i = 1; i < n; i++){
        maxsum = max(maxsum+arr[i],arr[i]);
        maxans = max(maxans,maxsum);
    }
    return maxans;
}


int main(){

    ALLONS_Y;

    int n;
    cin >> n;
    while(n != 0){                        
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        int ans = maxSum(n,arr);  
        if(ans > 0){
            cout << "The maximum winning streak is " << ans << '.'<< endl;
        }else{
            cout << "Losing streak." << endl;
        }
        cin >> n;
    }
    return 0;
}