#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Student{
	int age;
};

class myComparator {
	public:
		bool operator() (const Student& s1, const Student& s2){
			return s1.age > s2.age;
		}
};

int main() {
	priority_queue<Student, vector<Student>, myComparator> student_heap;
	int n= 5;
	Student* s = new Student [n];
	for (int i =0; i< n;i++){
		cin>>s[i].age;
		student_heap.push(s[i]);
	}

        cout  <<  "value " << n <<"\n";

	for (int i = 0; i<n; i++){
		cout<<student_heap.top().age<<endl;
		student_heap.pop();
	}
	
	return 0;
}
