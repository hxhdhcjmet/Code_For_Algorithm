//shell sort,heapsort,quicksort
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int size=1000;//测试数据大小定义为1000
void modInsertSort(int record[],int n,int dealt){//传入数组，最大长度，步长
    int i,j;
    for(i=dealt;i<n;i+=dealt){
        for(j=i;j>=dealt;j-=dealt){
            if(record[j]<record[j-dealt]){
                swap(record[j],record[j-dealt]);//修改版insertSort与原版类似，但是每次移动不再是1而是dealt
            }
        }
    }
}
void shellSort(int record[],int n){
    for(int dealt=n/2;dealt>0;dealt/=2){
        for(int i=0;i<dealt;i++){
            modInsertSort(&record[i],n-i,dealt);
        }
    }
    modInsertSort(record,n,1);//最后再来一次插入排序，保证最终结果正确
}
void printResult(int record[],int n){
    for(int i=0;i<n;i++){
        cout<<record[i]<<"\t";
    }
    cout<<endl;
}
class HeapSort{//从小到大排序需要大顶堆
    private:
    int* record;//不知道大小，到时候开辟去
    int n;
    void siftUp(int index){
        while(index>=0){
            int parrent=(index-1)/2;
            if(record[parrent]>=record[index]) break;//parrent确实比index大，不用交换
            swap(record[parrent],record[index]);
            index=parrent;
        }
    }
    void siftDown(int index){
        while(true){
            int left=2*index+1;
            int right=2*index+2;
            int biggest=index;
            if(left<n&&record[left]>record[biggest]){
                biggest=left;
            }
            if(right<n&&record[right]>record[biggest]){
                biggest=right;
            }
            if(biggest!=index){//发生了交换
                swap(record[index],record[biggest]);
                index=biggest;
            }else{
                break;
            }
        }
    }
    public:
    void moveTop(){
        swap(record[n-1],record[0]);
        n--;//排好序的那个不算在堆里面了
        siftDown(0);
    }
        
    HeapSort(int record[],int n):record(record),n(n){//建堆，从第一个非叶子节点开始调整
        for(int i=(n/2)-1;i>=0;i--){
            siftDown(i);
        }
    };
};
void heapsort(int record[],int n){
    HeapSort hs(record,n);
    for(int i=0;i<n-1;i++){//n-1次循环即可
        hs.moveTop();
    }
}
// int Partition(int record[],int left,int right){
//     int pivot_index=(left+right)/2;//轴值选左右边界点的中间值
//     swap(record[right],record[pivot_index]);//将右边界值与pivot交换
//     int l=left,r=right;
//     int tempelement=record[r];//获得右边界值，其实是轴值
//     while(r>=l){
//         while(record[l]<=tempelement&&l<r){
//             l++;
//         }
//         if(l<r){//这里找到左边不符合的一个值
//             record[r]=record[l];//换到最右边
//             r--;
//         }
//         while(record[r]>=tempelement&&l<r){
//             r--;
//         }
//         if(l<r){//找到右边部分不符合要求的值
//             record[l]=record[r];
//             l++;
//         }
//     }
//     //最后结束l=r
//     record[l]=tempelement;
//     return l;
// }
// void quickSort(int record[],int left,int right){
//     if(right<=left) return;//右边界大于左边界，直接退出
//     int pivot=Partition(record,left,right);
//     quickSort(record,left,pivot-1);//左边部分递归
//     quickSort(record,pivot+1,right);//右边部分递归
// }
int partition(int record[],int left,int right){
    int l=left,r=right;
    int piovt_index=(l+r)/2;
    swap(record[r],record[piovt_index]);//将轴值换到最右端
    int piovt=record[r];//存下轴值
    while(l<r){
        while(l<r&&record[l]<=piovt){
            l++;
        }
        if(l<r){
            record[r]=record[l];
            r--;
        }
        while(l<r&&record[r]>=piovt){
            r--;
        }if(l<r){
            record[l]=record[r];
            l++;
        }
    }
    record[l]=piovt;
    return l;
}
void quickSort(int record[],int left,int right){
    if(right<=left) return;
    int piovt_index=partition(record,left,right);
    quickSort(record,left,piovt_index-1);
    quickSort(record,piovt_index+1,right);

}
int main(){
    int record[6]={2,4,1,2,0,8};
    quickSort(record,0,5);
    printResult(record,6);
    return 0;
}