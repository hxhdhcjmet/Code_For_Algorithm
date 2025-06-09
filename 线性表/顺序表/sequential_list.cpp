//顺序表及其基本操作实现，尝试使用C风格，即没有使用类，面向对象
#include<iostream>
#include<random>
#include<ctime>
using namespace std;
const int MAXSIZE=100;//定义最大大小
typedef struct{
    int data[MAXSIZE];
    int length;
}Sqlist;
bool empty(Sqlist& L){
    return L.length==0;
}
bool ListInsert(Sqlist& L,int i,int v){//要插入的顺序表L,位置i,值v
    if(i<1||i>L.length+1) return false;//判断插入的位置是否合法
    if(L.length>=MAXSIZE) return false;//已经无位置插入
    for(int j=L.length;j>=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=v;
    L.length++;
    return true;
}
bool ListDelete(Sqlist& L,int i,int& v){//删除第i个位置元素，其值赋值给v
    if(i<1||i>L.length) return false;//判断删除第i个元素是否合理
    v=L.data[i-1];
    for(int j=i;j<L.length;j++){
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}
int LocateElem(Sqlist& L,int v){//从L中查找元素v
    for(int i=0;i<L.length;i++){
        if(L.data[i]==v) return i+1;//目标元素在第i+1个位置上
    }
    return -1;//-1表示没有找到
}
void printSlist(Sqlist& L){
    for(int i=0;i<L.length;i++){
        cout<<L.data[i]<<" ";
    }
    cout<<endl;
}
void quickInit_random(Sqlist& L,int n){//初始化n个值
    L.length=n;
    srand(time(nullptr));
    for(int i=0;i<L.length;i++){
        L.data[i]=rand()%100;//范围定在0~99
    }
}
int main(){
    Sqlist sq;
    quickInit_random(sq,10);
    printSlist(sq);
    return 0;
}