#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
const string input="input.txt";
const string output="output.txt";
const int memorySize=4;
class MinHeap{//创建最小堆
    public:
    vector<int> heap;
    int LAST;
    void siftUp(int index){
        while(index>0){
            int parent=(index-1)/2;
            if(heap[parent]<=heap[index]) break;
            swap(heap[parent],heap[index]);
            index=parent; 
        }
    }
    void siftDown(int index){
        while(true){
            int left=2*index+1;
            int right=2*index+2;
            int smallest=index;
            if(left<=LAST&&heap[smallest]>heap[left]) smallest=left;
            if(right<=LAST&&heap[smallest]>heap[right]) smallest=right;
            if(smallest!=index){
                swap(heap[smallest],heap[index]);
                index=smallest;
            }else{
                break;
            }
        }
    }
    bool empty(){
        return heap.empty();
    }
    int top(){
        if(empty()){
            throw runtime_error("HEAP is EMPTY");
        }
        return heap[0];
    }
    void builtHeap(vector<int>& data){
        heap=data;
        LAST=int(heap.size()-1);
        for(int i=(LAST-1)/2;i>=0;i--){
            siftDown(i);
        }
    }
    void pop(){
        heap[0]=heap[LAST];
        heap.pop_back();
        LAST--;
        siftDown(0);
    }
    void insert(int val){
        heap.push_back(val);
        LAST++;
        siftUp(LAST);
    }
    void setsize(int newsize){
        LAST=newsize-1;
    }
};
void sendToOutput(ofstream& fout,int val,bool& isnewRun){
    if(isnewRun){
        fout<<"\n";
        isnewRun=false;
    }
    fout<<val<<" ";
}
void replacementSelection(const string& input,const string& output,int memorySize){//文件读取,输出通过文件
    ifstream fin(input);
    ofstream fout(output);
    ios::sync_with_stdio(false);//关闭C输入同步,可以提高读取速度
    vector<int> buffer;
    vector<int> nextbuffer;
    nextbuffer.reserve(memorySize);//开辟储存小值的缓冲区
    int value;
    for(int i=0;i<memorySize&&(fin>>value);i++){
        buffer.push_back(value);
    }//缓冲区读入memorySize个数据
    bool isnewRun=false;
    MinHeap mp;
    mp.builtHeap(buffer);
    while(!mp.empty()){
        int minVal=mp.top();
        mp.pop();
        sendToOutput(fout,minVal,isnewRun);
        if(fin>>value){
            if(value>=minVal){
                mp.insert(value);
            }else{
                nextbuffer.push_back(value);//规模递减
            }
        }
        
        if(mp.empty()&&!nextbuffer.empty()){//重新开下一轮
            isnewRun=true;
            mp.builtHeap(nextbuffer);
            nextbuffer.clear();
        }

    }
    
}
int min(int a,int b){
    return (a<=b)?a:b;
}
void replacementSelectionByinput(){//读取输入并将最终结果直接输出,不经过文件
    vector<int> buffer;//创建一个缓冲区,读取第一行的所有输入数据
    int memorysize;//读取输入第二行的内存大小
    int value;
    string line;
    if(getline(cin,line)){
        stringstream s(line);
        while(s>>value){
            buffer.push_back(value);
        }
    }
    if(getline(cin,line)){
        stringstream s(line);
        if(!(s>>memorysize)){
            memorysize=memorySize;//无输入用默认值
        }
    }
    int heapSize=min(memorysize,buffer.size());
    vector<int> firstrun;
    for(int i=0;i<heapSize;i++){
        firstrun.push_back(buffer[i]);//初始化第一轮待处理数据
    }
    size_t index=heapSize;//index指向buffer中下一个待处理数据
    vector<int> nextrun;
    vector<int> currentResult;
    MinHeap mp;
    mp.builtHeap(firstrun);
    while(true){
    while(!mp.empty()){
        int minVal=mp.top();
        mp.pop();
        currentResult.push_back(minVal);
        if(index<buffer.size()){//还能读取到值
            value=buffer[index];
            index++;
            if(value>=minVal){
                mp.insert(value);//又读取到的小,可以进入本轮排序
            }else{
                nextrun.push_back(value);//否则如果比上一个最小的还小,放到下一轮
            }
        }
       
    }
    for(size_t i=0;i<currentResult.size();i++){
        if(i>0) cout<<" ";
        cout<<currentResult[i];
    }
    cout<<endl;
    currentResult.clear();//清空上一轮的结果
     if(!(nextrun.empty())){
            mp.heap.clear();
            mp.builtHeap(nextrun);
            nextrun.clear();
        }else{
            break;
        }
}
}
int main(){
    //replacementSelection(input,output,memorySize);
    replacementSelectionByinput();
    return 0;
}
