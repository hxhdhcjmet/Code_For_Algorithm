#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printArr(vector<int>& record){
    for(int v:record){
        cout<<v<<"\t";
    }
    cout<<endl;
}
void bucketSort(vector<int>& record,int B,int minval,int maxval){
    vector<vector<int>> buckets(B);//创建桶
    int range=maxval-minval;
    for(int v:record){
        int index=(((v-minval)*B)/range);
        if(index<0) index=0;
        else if(index>=B) index=B-1;
        buckets[index].push_back(v);
    }
    for(int k=0;k<B;k++){
        sort(buckets[k].begin(),buckets[k].end());//对每个桶中的元素排序
    }
    int pos=0;
    for(int i=0;i<B;i++){
        for(int v:buckets[i]){
            record[pos++]=v;
        }
    }
}
int main(){
    vector<int> record={9,5,7,2,0,1,6,7,8,8,100};
    int B=record.size();
    bucketSort(record,B,0,100);
    printArr(record);
    return 0;
}