#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;
class Maxheap{
    private:
    vector<int> heap;
    void swap(int i,int j){
        int temp=heap[i];
        heap[i]=heap[j];
        heap[j]=temp;
    }
    void siftUp(int index){
        while(index>0){
            int parent=(index-1)/2;
            if(heap[parent]>=heap[index]) break;
            swap(parent,index);
            index=parent;
        }
    }
    void siftDown(int index){
        int n=static_cast<int>(heap.size());
        while(true){
            int lchild=index*2+1;
            int rchild=index*2+2;
            int biggest=index;
            if(lchild<n&&heap[lchild]>heap[biggest]){
                biggest=lchild;
            }
            if(rchild<n&&heap[rchild]>heap[biggest]){
                biggest=rchild;
            }
            if(index!=biggest){
                swap(index,biggest);
                index=biggest;
            }else{
                break;
            }
        }
    }
    public:
    void insert(int val){
        heap.push_back(val);
        siftUp(static_cast<int>(heap.size()-1));

    }
   Maxheap()=default;
   Maxheap(vector<int>& arr):heap(arr){
    if(!heap.empty()){
    for(int i=((heap.size())/2-1);i>=0;i--){
        siftDown(i);
    }
}
   }
   void deleteNode(size_t index){
    if(index>heap.size()-1){
        throw out_of_range("index out of range");
    }
    swap(index,heap.size()-1);
    heap.pop_back();
    if(index<heap.size()){
        if(index>0&&heap[index]>heap[(index-1)/2]){
            siftUp(index);
        }else{
            siftDown(index);
        }
    }

   }
   const int Top(){
    if(heap.empty()){
        throw out_of_range("heap is empty");
    }
    return heap.front();
   }
   size_t size(){
    return heap.size();
   }
   bool empty(){
    return heap.empty();
   }
};
int main(){
    vector<int> arr={2,5,8,9,6,3,7,4};
    Maxheap pi(arr);
    cout<<pi.Top()<<endl;
    return 0;
}
