#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxValue(vector<int>& nums) {
       int n=nums.size();
        long  long originalpulse=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                originalpulse+=nums[i];
                
            }else{
                originalpulse-=nums[i];
            }}
            vector<long long>A(n);
            for(int i=0;i<n;i++){
            if(i%2==0){
                A[i]=-2LL*nums[i];
                
            }else{
                 A[i]=2LL*nums[i];
            }}
                long long maxd=0;
                long long currentsum=0;
                for(int i=0;i+1<n;i+=2){
                    long long pairsum=A[i]+A[i+1];
                    currentsum=max(pairsum,currentsum+pairsum);
                    maxd=max(maxd,currentsum);
                }
                 long long currentsum1=0;
                for(int i=1;i+1<n;i+=2){
                    long long pairsum=A[i]+A[i+1];
                    currentsum1=max(pairsum,currentsum1+pairsum);
                    maxd=max(maxd,currentsum1);
                
        }
                return originalpulse+maxd;
    }
};