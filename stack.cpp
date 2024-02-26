#include <iostream>
#include <stack>
using namespace std;

class Book
{
    public:
    //member variables of class book...
    string Author;
    int id;

    //constructor of Book's instance...
    Book(string Author,int id)
    {
        this->Author = Author;
        this->id = id;
    }
};

int main(){
    //creating instances of Book class...
    Book b1("OpenGenus",125);
    Book b2("OpenSource",345);

    //initializing stack to store Book objects....
    stack <Book> container;

    //adding elements in stack using push method....
    container.push(b1);
    container.push(b2);
    
    //printing details of books in stack...
    while(!container.empty()){
        cout<<container.top().Author<<" "<<container.top().id<<endl;
        container.pop();
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    //initializing stacks to store vector and pair containers.....
    stack <vector<int>> vector_container;
    stack <pair<int,int>> pair_container;
    
    //initializing vectors
    vector<int> a,b;
    
    a.push_back(30);
    a.push_back(20);
    b.push_back(10);
    //inserting vectors in vector_container stack ....
    vector_container.push(a);
    vector_container.push(b);

    //inserting pairs in pair_container stack....
    //here we can either initialize pair
    //                or
    // we can directly call make_pair function in push() to create pair.
    pair_container.push(make_pair(1,10));
    pair_container.push(make_pair(2,20));
    //another approach to insert pair in pair_container stack...
    pair<int,int> c,d;
    
    //assigning values to  first and second member of pair....
    c.first=3; c.second=30;
    d.first=4; d.second=40;
    
    pair_container.push(c);
    pair_container.push(d);
    
    return 0;
}

