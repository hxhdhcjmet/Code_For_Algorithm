#include<iostream>
#include<vector>
using namespace std;
//寻找第序列第k大元素
class Solution{
    private:
    int getPivot(int left,int right){
        srand(time(nullptr));
        return left+rand()%(right-left+1);
    }
    int partition(vector<int>& input,int left,int right,int pivotIndex){
        int pivotValue=input[pivotIndex];
        swap(input[right],input[pivotIndex]);//交换轴值到最右边
        int stored=left;
        for(int i=left;i<right;i++){
            if(input[i]>pivotValue){//大的值换到左边,形成 大值-轴值-小值 形式
                swap(input[i],input[stored]);
                stored++;
            }
        }
        swap(input[stored],input[right]);
        return stored;//返回新的轴值下标
    }
    int quickFind(vector<int>& input,int left,int right,int k){
        if(right==left) return input[left];
        int pivot=getPivot(left,right);//获得轴值
        pivot=partition(input,left,right,pivot);
         if(pivot==k-1) return input[pivot];
         else if(pivot>k-1){//轴值大，左边找
            return quickFind(input,left,pivot-1,k);
         }else{
            return quickFind(input,pivot+1,right,k);
         }
    }
    public:
    int quickFindKthLargest(vector<int>& input,int k){
        int left=0;
        int right=input.size()-1;
        return quickFind(input,left,right,k);
    }
};
int main(){
    vector<int> test={9,4,3,2,2,1,1,0,12,33,45,56,77,88};
    Solution sl;
    int result=sl.quickFindKthLargest(test,14);//预期结果
    cout<<result;
    return 0;
}