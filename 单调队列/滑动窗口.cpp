#include<iostream>
#include<deque>
#include<vector>
using namespace std;
vector<int> maxWindowData(vector<int>& nums,int k){
    vector<int> result;//数组存窗口最大值结果
    if(nums.size()==0||k<=0) return result;
    deque<int> window;
    for(int i=0;i<nums.size();i++){
        while(!window.empty()&&window.front()<i-k+1){
            window.pop_front();
        }//窗口范围为[i-k+1,i],当front存的索引比这个小的时候就代表元素过期，需要移除
        while(!window.empty()&&nums[i]>=nums[window.back()]){
            window.pop_back();
        }//扫到现在这个元素比窗口的大，就从队列尾部开始弹出，为了保证从front到back的单调性
        window.push_back(i);
        if(i>=k-1){
            result.push_back(nums[window.front()]);
        }//窗口形成，开始记录最大值，以后每次滑动窗口，都是一个完整的窗口，都可记录
    }
    return result;
}
int main(){
    vector<int> num={1,3,2,5,7,6};
    vector<int> result=maxWindowData(num,3);
    for(auto it=result.begin();it!=result.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}
