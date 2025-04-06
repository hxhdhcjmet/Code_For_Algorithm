#include<iostream>
#include<vector>
using namespace std;
int RainSquare(vector<int>& height){
    int left=0,right=height.size()-1,left_max=0,right_max=0,S=0;
    while(left<=right){
        if(left_max<=right_max){
            if(left_max<=height[left]){
                left_max=height[left];
            }else{
                S+=left_max-height[left];

            }
            left++;
        }
        else{
            if(right_max<=height[right]){
                right_max=height[right];
            }else{
                S+=right_max-height[right];
            }
            right--;
        }
    }
    return S;
}
int main(){
    vector<int> height={0,1,0,2,1,0,1,3,2,1};
    int result=RainSquare(height);
    cout<<"the Rainsquare is:"<<result<<endl;
    return 0;
}