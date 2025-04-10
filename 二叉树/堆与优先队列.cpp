#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;
class MinHeap{
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
            if(heap[parent<=heap[index]]) break;
            swap(parent,index);
            index=parent;
        }
    }//让一个元素回到应有的位置上去
    void siftDown(int index){
        int n=static_cast<int> (heap.size());
        while(true){
        int lchild=2*index+1;
        int rchild=2*index+2;
        int smallest=index;
        if(lchild<n&&heap[lchild]<heap[smallest]){
            smallest=lchild;
        }
        if(rchild<n&&heap[rchild]<heap[smallest]){
            smallest=rchild;
        }
        if(smallest!=index){
            swap(index,smallest);
            index=smallest;
        }else{
            break;
        }

    }
    }//下沉
    public:
    void insert(int val){
        heap.push_back(val);
        siftUp(static_cast<int>(heap.size()-1));
    }
    MinHeap()=default;
    MinHeap(const vector<int>& arr):heap(arr){
        if(!heap.empty()){
            for(int i=((heap.size())/2)-1;i>=0;i--){
                siftDown(i);
            }
        }
    }
    const int Top(){
        if(heap.empty()){
            throw out_of_range("heap is empty!");
        }
        return heap.front();
    }
    void deleteNode(size_t index){
        if(index>=heap.size()){
            throw out_of_range("index out of range");
        }
        swap(index,heap.size()-1);
        heap.pop_back();
        if(index<heap.size()){//index下标错误和特殊情况的处理
        if(index>0&&heap[index]<heap[(index-1)/2]){
            siftUp(index);
        }else{
            siftDown(index);
        }
    }
    }
    size_t size() const{
        return heap.size();
    }
    bool empty() const{
        return heap.empty();
    }
};
int main(){
    vector<int> test={5,6,8,9,7,1};
    MinHeap pi(test);
    cout<<pi.Top()<<endl;
    pi.deleteNode(6);
    return 0;
}