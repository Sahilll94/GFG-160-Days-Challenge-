// Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.

    int method2(vector<int>)
    {
        // your code here
        int n = arr.size();
      
        int max_ans = INT_MIN, min_ans = INT_MAX, sum = 0, max_sum = 0, min_sum = 0;
      
        for(int i = 0; i < n; i++)
        {
            max_sum = max(max_sum, 0) + arr[i];
            max_ans = max(max_ans, max_sum);
            min_sum = min(min_sum, 0) + arr[i];
            min_ans = min(min_ans, min_sum);
            sum += arr[i];
        }
      
        if(min_ans == sum)
        {
            return max_ans;
        }
      
        return max(max_ans, sum - min_ans);
        
    }

    
    int subArray(vector<int> &arr)
    {
        int n=arr.size();
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            
            maxi=max(sum , maxi);
             if (sum < 0) sum = 0;
        }
        return maxi;
        
    }
    
    int circularSubarraySum(vector<int> &arr) {

        // your code here
        int n=arr.size();
        int total_sum=0;
        int kadane=subArray(arr);
        
        for(int i=0;i<n;i++)
        {
            total_sum+=arr[i];
            arr[i] = -arr[i]; 
        }
        
        
        int min_subArray = subArray(arr);
        
        int final_maximum=total_sum+min_subArray;
        
        return max(final_maximum , kadane);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends
