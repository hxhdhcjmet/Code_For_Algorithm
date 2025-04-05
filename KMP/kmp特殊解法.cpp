#include<iostream>
#include<string>
#include<vector>
using namespace std;
int KMP_Special(string pattern,string target){
	string str=pattern+'#'+target;
	vector<int> pi(str.size(),0);
	for(int i=1;i<str.size();i++){
		int current=pi[i-1];
		while(current!=0&&str[i]!=str[current]){
			current=pi[current-1];
		}
		if(str[i]==str[current]){
			pi[i]=current+1;
		}
		if(pi[i]==pattern.size()){
			return i-2*pattern.size();		
	 } 
	
   }
     return -1;
}
int main(){
	string pattern="mio",target="ILoVemio";
	cout<<KMP_Special(pattern,target)<<endl;
	return 0;
}
