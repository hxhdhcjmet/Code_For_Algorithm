#include<iostream>
#include<stack>
using namespace std;
bool isValid(){
    char par;
    stack<char> st;
    while(cin>>par&&par!='#'){
        if(par=='{'||par=='['||par=='('){
            st.push(par);//左括号入栈
        }else{
            if(st.empty()){
            return false;
        }
            if((par=='}'&&st.top()!='{')||(par==']'&&st.top()!='[')||(par==')'&&st.top()!='(')){
                return false;
            }else{
                st.pop();
            }
    }
    }
    if(!st.empty()){
        return false;
    }
    return true;
}
void printResult(bool isvalid){
    if(isvalid){
        cout<<"Valid!"<<endl;
        return;
    }
    cout<<"Invalid!"<<endl;
}
int main(){
    bool result=isValid();
    printResult(result);
    return 0;
}