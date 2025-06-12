//顺序检索
#include<iostream>
#include<vector>
#include<random>
#include<ctime>
const int MAXSIZE=15;
using namespace std;
class GetArr{
    private:
    vector<int> record;
    public:
    GetArr():record(MAXSIZE){};
    void postOrder(){
        for(int i=0;i<MAXSIZE;i++){
            record[i]=i+1;
        }
    }
    void reverOrder(){
        for(int i=0;i<MAXSIZE;i++){
            record[MAXSIZE-i-1]=i;
        }
    }
    void randomOrder(){
        srand(time(nullptr));//设置随机数种子
        for(int i=0;i<MAXSIZE;i++){
            record[i]=rand()%1000;//范围定在0~999;
        }
    }
    void printResult(){
        for(int v:record){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    vector<int>& getRecord(){
        return record;
    }
};
class Search{
    public:
    int sequSearch(vector<int>& target,int k){//从target中检索目标值k
        target[0]=k;//设置监视哨
        int i=target.size()-1;
        while(target[i]!=k&&i>0){
            i--;
        }
        return i;
    }
    int binarySearch(vector<int>& target,int k){
        int l=0,r=target.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;//不直接使用mid=(l+r)/2,能够防止整数溢出
            if(target[mid]<k) l=mid+1;
            if(target[mid]>k) r=mid-1;
            if(target[mid]==k) return mid;
        }
        return -1;//返回-1表示没有找到
    }
};
int main(){
    GetArr record; 
    record.reverOrder();
    record.printResult();
    Search search;
    int pos=search.sequSearch(record.getRecord(),6);
    cout<<pos<<endl;
    return 0;
}