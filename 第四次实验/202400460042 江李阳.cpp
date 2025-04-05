#include<iostream>
#include<cstring>
using namespace std;
class KMP {
private:
	string target;
	string pattern;
	int len_p;
	int len_t;
public:
	KMP(string target, string pattern) :
		target(target), pattern(pattern),
		len_p(static_cast<int>(pattern.size())),
		len_t(static_cast<int>(target.size()))
	{};
	KMP() :target(" "), pattern(" ") {};
	int* getNext() {
		int len_p = static_cast<int>(pattern.size());//��pattern�ĳ�����ʾת��Ϊ�з�������
		int* next = new int[len_p]();
		next[0] = -1;
		int i = -1;
		int j = 0;
		while (j < len_p-1) {
			if (i == -1 || pattern[i] == pattern[j]) {
				next[++j] = ++i;
			}
			else {
				i = next[i];
			}
		}
		return next;
	}
	int* getNextval() {
		int* nextval = new int[len_p]();
		nextval[0] = -1;
		int i = -1;
		int j = 0;
		while (j < len_p - 1) {
			if (i == -1 || pattern[i] == pattern[j]) {
				i++;
				j++;
				if (pattern[i] == pattern[j]) {
					nextval[j] = nextval[i];
				}
				else {
					nextval[j] = i;
				}
			}
			else {
				i = nextval[i];
			}
		}
		return nextval;
	}
	int findpos() {
		int* next = getNextval();
		int i = 0;
		int j = 0;
		while (i < len_t && j < len_p) {//���������ת�����ͻᵼ��ѭ�������˳���j=-1ʱ�� 
			if (j==-1||target[i] == pattern[j]) {
				i++;
				j++;
			}
			else {
				j = next[j];
			}
		}
		return (j == len_p) ? i - j : -1;
	}
};
int main() {
	string target = "abcddabcababcdaabcababcdaabcabaa";
	string pattern = "abcdaabcab";
	KMP p = KMP(target, pattern);
	cout << p.findpos() << endl;
	return 0;
}
