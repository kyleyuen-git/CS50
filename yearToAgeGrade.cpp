#include <vector>
#include <string>
#include <iostream>
using namespace std;



int yearToGrade(int year);

int main(){
    int year;
    cout<<"What year? ";
    cin>>year;
    
    cout<< "In "<<year<< ", you completed the "<<yearToGrade(year)<<"th grade, and started the "<<yearToGrade(year)+1<<"th grade"<<endl;
}

int yearToGrade(int year){
    int difference = 2026 - year;
    return 14 - difference;
}