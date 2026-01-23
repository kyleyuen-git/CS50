#include <vector>
#include <string>
#include <iostream>
using namespace std;

class course{
    public: 
    string name;
    float units;
    float grade;
    course(string name, float units, float grade){
        this->name = name;
        this->units = units;
        this->grade = grade;
    }
    /*
    course(float units, float grade){
        units = this->units;
        grade = this->grade;
    }
    This assigns uninitialized member variables into the parameters, which does nothing useful.

    You can also use:
    (preferred C++ style):
    course(float units, float grade) : units(units), grade(grade) {}
    */
};

char numToGrade(float grade);
float gpaCalculator(const vector<course> &totalCourses, float &totalUnits);
void printAllClasses(vector<course> totalCourses);

int main(){
    vector<course> totalCourses = {};

    /* 
    course* arthistory19th20th = new course(3,4); 
        this is dynamic allocation method to create an object but I don't want to deal with memory management 
        and I'd have to make the vector<*course>
    */

    // Irvine Valley College
    totalCourses.emplace_back("19TH/20TH CENTURY ART(I)", 3, 4);
    totalCourses.emplace_back("C PROGRAMMING(I)", 3, 4);
    totalCourses.emplace_back("C++ PROGRAMMING(I)", 3, 4);
    totalCourses.emplace_back("GENERAL PHYSICS(I) 4A", 4, 4);
    totalCourses.emplace_back("COM ORG/ASSM LANG I(I)", 3, 4);

    totalCourses.emplace_back("COMP ORG/ASSM LNG II(I)", 3, 4);
    totalCourses.emplace_back("COMPUTER MATH I(I) 6A", 3, 4);
    totalCourses.emplace_back("GENERAL PHYSICS(I) 4B", 4, 4);

    // Saddleback College
    totalCourses.emplace_back("AMERICAN SIGN LANG I(S)", 4, 3);
    totalCourses.emplace_back("AMERICAN SIGN LANG II(S)", 4, 4);
    totalCourses.emplace_back("CHICANX/LATINX STUDIE(S)", 3, 4);
    totalCourses.emplace_back("ANALYTIC GEOM/CALC(S) 3B", 5, 3);
    totalCourses.emplace_back("HONORS PRINC COMP II(S)", 3, 4);
    totalCourses.emplace_back("ANALYTIC GEOM/CALC(S) 3C", 5, 3);
    totalCourses.emplace_back("COMMUNICATION FUND(S)", 3, 4);
    totalCourses.emplace_back("INTRO TO COMP SCI II(S)", 3.5, 4);
    totalCourses.emplace_back("INTRO TO STATISTICS(S)", 3, 4);

    totalCourses.emplace_back("DATA STRUCTURES(S)", 3.5, 3);
    totalCourses.emplace_back("INTRO LINEAR ALGEBRA(S)", 4, 4);



    /*
    course arthistory19th20th("19TH/20TH CENTURY ART(I)",3,4);
    totalCourses.push_back(arthistory19th20th);

        this is a working but inefficient way of pushing an object to a vector
    
    Equivalent but slightly worse: totalCourses.push_back(course("19TH/20TH CENTURY ART(I)", 3, 4));
        This creates a temporary course, then copies/moves it.

    best way is the one used: totalCourses.emplace_back("19TH/20TH CENTURY ART(I)", 3, 4);
        Why this is better than push_back
        Constructs the course directly inside the vector
        Avoids a temporary object + copy
        Cleaner and idiomatic C++
    */


    float totalUnits = 0;
    
    printAllClasses(totalCourses);
    cout<<"GPA: " << gpaCalculator(totalCourses, totalUnits)<<"\nTotal Units:"<<totalUnits<<endl;

}

void printAllClasses(vector<course> totalCourses){
    for(course &i : totalCourses){
        cout<<"Class: "<< i.name<<"\nUnits: "<<i.units<<"\nGrade: "<<numToGrade(i.grade)<<endl<<endl;
    }
}

char numToGrade(float grade){
    if(grade>3){
        return 'A';
    }
    else if(grade>2){
        return 'B';
    }
    else{
        return 1;
    }
}

float gpaCalculator(const vector<course> &totalCourses, float &totalUnits){
    float totalGrade = 0;
    float gradePoints = 0;
    float totalGPA = 0;
    for(course i : totalCourses){
        totalUnits += i.units;
        totalGrade += i.grade;
        gradePoints += (i.units)*(i.grade);

    }
    return totalGPA = gradePoints/totalUnits;
}