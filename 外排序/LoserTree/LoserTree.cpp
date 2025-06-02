#include<iostream>
#include<vector>
using namespace std;

const int INF=1e9;
class LoserTree{
    private:
    int k;//K路归并
    vector<int> tree;//存放内部输的索引
    vector<int> leaves;//叶子节点，存放八只队伍
    vector<size_t> indexs;//存放K路各自推进到哪里
    vector<vector<int>> data;//存放待归并数据
    int winner;
    public:
    LoserTree(vector<vector<int>>& input):k(8),tree(k-1,-1),leaves(k,0),indexs(k,0),data(input){};//未作输入数组检查,依赖输入的二维数组为8列
    int adjust(int index){//某一路有选手胜出,需要调整
        int winner=index;
        int parent=(index/2)+3;//获得父节点,计算来自(k-1+index-1)/2
        while(parent>=0){
            if(leaves[winner]>leaves[tree[parent]]){//新来的输了,父节点放新来的
                swap(winner,tree[parent]);
            }
            if(parent==0) break;
            parent=(parent-1)/2;//更新为上一个父节点
        }
        return winner;//调整后的胜者
    }
    vector<int> multiWayMerge(){//多路归并函数
        for(int i=0;i<k;i++){//初始化填值
            if(indexs[i]<data[i].size()){//储存每一路当前的值
                leaves[i]=data[i][indexs[i]];
                indexs[i]++;
            }else{
                leaves[i]=INF;
            }
        }
        vector<int> win(k-1,-1);
        for(int i=k-2;i>=0;i--){//从第一个非叶子节点开始
            if(i>=3){//3~6为叶子上第一层
                int left=(i-3)*2;//获得对应leaves中的下标
                int right=(i-3)*2+1;
                if(leaves[left]<=leaves[right]){
                    tree[i]=right;//树内节点放败者
                    win[i]=left;
                }else{
                    tree[i]=left;
                    win[i]=right;
                }
            }else{//上层节点0~2
                int lchild=2*i+1;
                int rchild=2*i+2;
                int lwinner=win[lchild];
                int rwinner=win[rchild];
                if(leaves[lwinner]<=leaves[rwinner]){
                    tree[i]=rwinner;
                    win[i]=lwinner;
                }else{
                    tree[i]=lwinner;
                    win[i]=rwinner;
                }
            }
        }
        winner=win[0];
        vector<int> result;
        while(leaves[winner]!=INF){
            result.push_back(leaves[winner]);//存入当前胜者
            if(indexs[winner]<data[winner].size()){
                leaves[winner]=data[winner][indexs[winner]];
                indexs[winner]++;//当前这一路推进
            }else{
                leaves[winner]=INF;
            }
            winner=adjust(winner);//winner这一路调整
        }
        return result;
    }
};
void printArr(vector<int>& result){
    for(int val:result){
        cout<<val<<" ";
    }
    cout<<endl;
}
int main(){
    vector<vector<int>> test{
        {1,3,5,6},
        {2,2,4,6,7,8},
        {3,4,5,},
        {1,1,7,9,23},
        {22,45,66,77},
        {144,155,200},
        {999,1000,5678},
        {0,160}
    };
    vector<int> result;
    LoserTree lt(test);
    result=lt.multiWayMerge();
    printArr(result);
    return 0;
}
