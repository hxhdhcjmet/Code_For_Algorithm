#include<iostream>
#include<stack>
#include<vector>
#include<cmath>
using namespace std;
int MaxSquare(vector<int>& heights){
    if(heights.size()==0) return 0;
    int maxSquare=0;
    stack<int> st;
    for(int i=0;i<heights.size();i++){
        while(!st.empty()&&heights[i]<heights[st.top()]){
            int high=heights[st.top()];
            st.pop();
            int left=(st.empty())?-1:st.top();
            maxSquare=max(maxSquare,high*(i-left-1));
        }
        st.push(i);
    }
    while(!st.empty()){
        int high=heights[st.top()];
        st.pop();
        int left=(st.empty())?-1:st.top();
        maxSquare=max(maxSquare,(high*(static_cast<int>(heights.size())-left-1)));
    }
    return maxSquare;
}
int main(){
    vector<int> heights={2,4};
    int maxsquare=MaxSquare(heights);
    cout<<"the max square is:"<<maxsquare<<endl;
    return 0;
}