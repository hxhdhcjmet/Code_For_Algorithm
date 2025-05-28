//置换选择排序
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<limits>
using namespace std;
const string inpath="input.txt";
const string outpath="output.txt";
const int memorySize=5;
class Minheap{
   public:
   vector<int> heap;
   int last;//指示最后一个值的位置
   Minheap():last(-1){};
   void buildHeap(const vector<int>& data){
    heap=data;
   last=static_cast<int>(data.size())-1;
   for(int i=(last-1)/2;i>=0;i--){
    siftDown(i);
   }
   }
   void siftUp(int index){
    while(index>0){
        int parrent=(index-1)/2;
        if(heap[index]>=heap[parrent]) break;
        swap(heap[index],heap[parrent]);
        index=parrent;
    }
   }
   void siftDown(int index){
    while(true){
        int left=2*index+1;
        int right=2*index+2;
        int smallest=index;
        if(left<=last&&heap[left]<heap[smallest]) smallest=left;
        if(right<=last&&heap[right]<heap[smallest]) smallest=right;
        if(smallest!=index){
            swap(heap[smallest],heap[index]);
            index=smallest;
        }else{
            break;
        }
    }
   }

    bool empty() const{
        return last<0;
   }

   int top() const{
    if(empty()){
        throw runtime_error("Heap is empty!");
    }
    return heap[0];
   }
   void pop(){
    if(empty()) return;
    swap(heap[0],heap[last]);
    last--;
    siftDown(0);
   }
   void insert(int val){
   if(last+1<static_cast<int>(heap.size())){
    heap[++last]=val;
   }else{
    heap.push_back(val);
    last++;
   }
   siftUp(last);
   }
};
void replaceSelection(const string& inpath,const string& outpath,int memorySize){//输入输出流,内存大小memorySize
   ios::sync_with_stdio(false);
   const int SENTINEL=INT_MAX; 
   ifstream fin(inpath);
   ofstream fout(outpath);
   if(!fin||!fout){
    cerr<<"文件打开失败"<<endl;
    exit(1);
   }
   int value;
   vector<int> initial;
   for(int i=0;i<memorySize&&(fin>>value);i++){
    initial.push_back(value);//初始化读入memorize个元素,
   }
   Minheap mp;
   mp.buildHeap(initial);//构建堆
   bool firstruns=true;//构建是否是第一趟标志
   while(!mp.empty()){
    if(!firstruns) fout<<"\n";//不是第一趟都先输出一个换行
   
   firstruns=false;
   int currentBaseSize=mp.heap.size();
   while(!mp.empty()&&mp.top()!=SENTINEL){
    //不空且第一个不是冻结元素,可以进行下一步操作
    int minval=mp.top();
    mp.pop();
    fout<<minval<<" ";
    if(fin>>value){//尝试读取新的值
        if(value>=minval){//新读取的值大于原最小的值，可以进入本轮循环
            mp.insert(value);
        }else{
            mp.heap.push_back(value);//否则只读入但不递增last
        }
    }
    while(!mp.empty()&&mp.top()==SENTINEL){
        mp.pop();
    }
   }
      //重建下一个堆
    vector<int> nexturn;
    for(int i=currentBaseSize;i<(int)mp.heap.size();i++){
        nexturn.push_back(mp.heap[i]);
    }
    mp.heap.clear();
    mp.last=-1;
    if(nexturn.empty()) break;
    mp.buildHeap(nexturn);
}
}
int main(){
    replaceSelection(inpath,outpath,memorySize);
    cout<<"finish"<<endl;
    return 0;
}