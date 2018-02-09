#include <std>


int main(){
    

vector<int> max;
        int i;
        for(int j =0;j<max.size();j++){
            max[j]=1;
        }
        
        for(i =1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                max[i] = 1 + max[i-1];
            }
        }
        int mx =max[0];
        for(i =1; i<max.size();i++){
            if (mx < max[i])
                mx = max[i];
        }
        
        return mx;

        }