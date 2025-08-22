#include<iostream>
#include<string>
using namespace std;
class Student{
public:
    string name;
    int marks;
    Student(string s,int n){
        name=s;
        marks=n;
    }

    
    
};

void change(Student *s){
        s->marks=85;
    }

int main(){
    Student *s=new Student("Dhananjay",97);
    cout<<s->marks<<endl;
    change(s);
    cout<<s->marks;
}