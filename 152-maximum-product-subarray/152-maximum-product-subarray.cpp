class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int prod=INT_MIN,lp=1,rp=1;
	    for(int i=0;i<n;i++){
	        lp*=nums[i];
	        rp*=nums[n-i-1];
	        prod=max(prod,max(lp,rp));
	        if(lp==0) lp=1;
	        if(rp==0) rp=1;
	    }
	    return prod;
    }
};