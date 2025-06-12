#include<iostream>
#include<vector>
#include<list>
#include<cmath>
#include<algorithm>
using namespace std;
class HashTable{
    private:
    int capacity;
    static const int INITIAL_CAPACITY=13;
    static const double LOAD_FACTOR_THRESHOLD;//定义负载因子
    vector<list<int>> hashTable;//创建哈希表,采用链接法解决冲突
    int scale;
    size_t hash(int value) const {
        size_t pos=(value*2654435761)%capacity;
        return pos;
    }
    bool isPrime(int n) const{//辅助函数，确认是否是质数
        if(n<=1) return false;
        if(n==2) return true;
        if(n%2==0) return false;
        int sqrtn=sqrt(n);
        for(int i=3;i<=sqrtn;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int getNextPrime(int value) const{//获取下一个质数
        int n=value;
        while(true){
            if(isPrime(n)) return n;
            n++;
        }
    }
    void rehash(){
        double currfactor=static_cast<double>(scale)/capacity;
        if(currfactor<LOAD_FACTOR_THRESHOLD) return;//检查当前负载因子是否超过阈值 
        cout<<"WARNNING!"<<endl<<"current load factor:"<<currfactor<<"over the LOAD_FACTOR_THRESHOLD:"<<LOAD_FACTOR_THRESHOLD<<endl
        <<"start to expand..."<<endl;//输出扩容信息
        int newcapacity=getNextPrime(capacity*2);//扩容为原来规模的两倍的一个更大质数
        vector<list<int>> newhashTable(newcapacity);
        //int oldcapacity=capacity;
        capacity=newcapacity;
        for(auto& bucket:hashTable){
            for(auto value:bucket){
                size_t newpos=hash(value);
                newhashTable[newpos].push_back(value);//计算每个值在新的哈希表中的位置并放到对应的位置上去
            }
        }
        hashTable=move(newhashTable);
        cout<<"expand success! new capacity is:"<<capacity<<endl;
    }
    bool contain(int value){
        size_t pos=hash(value);
        list<int>& cover=hashTable[pos];
        return find(cover.begin(),cover.end(),value)!=cover.end();//未找到就返回.end()相当于false，找到相当于返回true
    }
    public:
    HashTable():capacity(INITIAL_CAPACITY),hashTable(capacity,list<int>(0)){};
    void insert(int value){
        if(contain(value)){
            cout<<"the value has exist!"<<endl;
            return;
        }
        size_t pos=hash(value);
        hashTable[pos].push_back(value);
        scale++;
        rehash();//检查判断是否需要再更新
    }
    void remove(int value){
        size_t pos=hash(value);
        list<int>& cover=hashTable[pos];
        auto exactPos=find(cover.begin(),cover.end(),value);
        if(exactPos==cover.end()){//没有找到直接返回
            cout<<"value is not exist"<<endl;
            return;
        }
        cover.erase(exactPos);
        scale--;
        cout<<"remove success!"<<endl;
    }
    int getScale() const{
        return scale;//获取当前哈希表大小，即已有元素个数
    }
    int getCapacity() const{
        return capacity;//获取当前哈希表的容量
    }
    double getLoadFactor() const {
        return static_cast<double>(scale)/capacity;//获取当前负载因子
    }
    void printHashTable(){
        cout<<"-------------HashTable information--------------"<<endl;
        cout<<"scale:"<<scale<<endl;
        cout<<"capacity:"<<capacity<<endl;
        cout<<"LOAD_FACTOR_THRESHOLD:"<<LOAD_FACTOR_THRESHOLD<<endl;
        cout<<"detail information:"<<endl;
        cout<<"------each bucket value------"<<endl;
        for(list<int>& bucket:hashTable){
            if(!bucket.empty()){
            for(int v:bucket){
                cout<<v<<" ";
            }
        }
            cout<<endl;
        }
        cout<<"------endline------"<<endl;
    }
};
const double HashTable::LOAD_FACTOR_THRESHOLD=0.75;
int main(){
    HashTable ht;
    vector<int> testinput={200,400,500};
    for(int v:testinput){
        ht.insert(v);
    }
    ht.remove(200);
    ht.printHashTable();
    return 0;
}