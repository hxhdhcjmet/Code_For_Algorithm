#include<iostream> 
#include<stack>
#include<vector>
using namespace std;
int RainSquare(vector<int>& height){
	if(height.size()==0) return 0;
	stack<int> st;
	int S=0,left=0,right=0, high=0;
	for(int i=0;i<height.size();i++){
		while(!st.empty()&&height[i]>height[st.top()]){
			int current=height[st.top()];
			st.pop();
			if(st.empty()) break;
			left=st.top();
			right=i;
			high=min(height[right],height[left])-current;
			S+=(right-left-1)*high;
		}
		st.push(i);
	}
	return S;
}
int main(){
	vector<int> height={0,1,0,2,1,0,1,3,2,1};
	int result=RainSquare(height);
	cout<<result<<endl;
	return 0;
	
}
