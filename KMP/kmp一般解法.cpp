#include<iostream>
#include<string>
#include<vector>
using namespace std;
class KMP{
	private:
		string pattern,target;
		int len_p,len_t;
	public:
		KMP():pattern('\0'),target('\0'),len_p(0),len_t(0){};
		KMP(string pattern,string target):pattern(pattern),target(target),
		len_p(static_cast<int>(pattern.size())),len_t(static_cast<int>(target.size())){};
		vector<int> next(){
			int i=-1,j=0;
			vector<int> pi(len_p,0);
			pi[0]=-1;
			while(j<len_p-1){
				if(i==-1||pattern[i]==pattern[j]){
					pi[++j]=++i;
				}
				else{
					i=pi[i];
				}
			} 
			return pi;
		}
		vector<int> nextval(){
			int i=-1,j=0;
			vector<int> pi(len_p,0);
			pi[0]=-1;
			while(j<len_p-1){
				if(i==-1||pattern[i]==pattern[j]){
					i++;
					j++;
					if(pattern[i]==pattern[j]){
						pi[j]=pi[i];
					}else{
						pi[j]=i;
					}
				}
				else{
					i=pi[i];
				}
			}
			return pi;
		}
		int KMP_findpos(){
			int i=0,j=0;
			vector<int> pi=this->nextval();
			while(i<len_p&&j<len_t){
				if(i==-1||pattern[i]==target[j]){
					i++;
					j++;
				}
				else{
					i=pi[i];
				}
			}
			return (i==len_p)?j-i:-1;
		}
}; 
int main(){
	string target="Ilovemio",pattern="mio";
	KMP kmp(pattern,target);
	cout<<kmp.KMP_findpos()<<endl;
	return 0;
}


