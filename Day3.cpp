#include<iostream>
#include<vector>
using namespace std;

class Employee{
protected:
    int id;
    string name;

public:

    Employee(int i,string n){
        id=i;
        name=n;
    }

    virtual float calculateSalary()=0;

    virtual void display(){
        cout<<"\nID : "<<id;
        cout<<"\nName : "<<name;
        cout<<"\nTotal Salary : "<<calculateSalary()<<endl;
    }

    virtual ~Employee(){}
};

class FullTime : public Employee{

    float salary;
    float bonus;

public:

    FullTime(int i,string n,float s,float b) : Employee(i,n){
        salary=s;
        bonus=b;
    }

    float calculateSalary() override{
        return salary+bonus;
    }

    void display() override{

        cout<<"\n----- Full Time Employee -----";
        cout<<"\nID : "<<id;
        cout<<"\nName : "<<name;
        cout<<"\nBase Salary : "<<salary;
        cout<<"\nBonus : "<<bonus;
        cout<<"\nTotal Salary : "<<calculateSalary()<<endl;
    }
};

class PartTime : public Employee{

    int hours;
    float rate;
    float bonus;

public:

    PartTime(int i,string n,int h,float r,float b) : Employee(i,n){
        hours=h;
        rate=r;
        bonus=b;
    }

    float calculateSalary() override{
        return (hours*rate)+bonus;
    }

    void display() override{

        cout<<"\n----- Part Time Employee -----";
        cout<<"\nID : "<<id;
        cout<<"\nName : "<<name;
        cout<<"\nWorking Hours : "<<hours;
        cout<<"\nHourly Rate : "<<rate;
        cout<<"\nBonus : "<<bonus;
        cout<<"\nTotal Salary : "<<calculateSalary()<<endl;
    }
};

int main(){

    vector<Employee*> emp;

    int n;

    cout<<"Enter Number of Employees : ";
    cin>>n;

    for(int i=0;i<n;i++){

        int choice;

        cout<<"\n1. Full Time Employee";
        cout<<"\n2. Part Time Employee";
        cout<<"\nEnter Choice : ";
        cin>>choice;

        int id;
        string name;

        cout<<"Enter Employee ID : ";
        cin>>id;

        cout<<"Enter Employee Name : ";
        cin>>name;

        if(choice==1){

            float salary,bonus;

            cout<<"Enter Monthly Salary : ";
            cin>>salary;

            cout<<"Enter Bonus : ";
            cin>>bonus;

            emp.push_back(new FullTime(id,name,salary,bonus));
        }

        else if(choice==2){

            int hours;
            float rate,bonus;

            cout<<"Enter Working Hours : ";
            cin>>hours;

            cout<<"Enter Hourly Rate : ";
            cin>>rate;

            cout<<"Enter Bonus : ";
            cin>>bonus;

            emp.push_back(new PartTime(id,name,hours,rate,bonus));
        }

        else{
            cout<<"\nInvalid Choice";
            i--;
        }
    }

    int option;

    do{

        cout<<"\n\n===== EMPLOYEE SALARY SYSTEM =====";
        cout<<"\n1. Display All Employees";
        cout<<"\n2. Highest Paid Employee";
        cout<<"\n3. Exit";
        cout<<"\nEnter Option : ";
        cin>>option;

        if(option==1){

            for(auto e : emp){
                e->display();
            }
        }

        else if(option==2){

            Employee* highest=emp[0];

            for(auto e : emp){

                if(e->calculateSalary() > highest->calculateSalary()){
                    highest=e;
                }
            }

            cout<<"\n===== Highest Paid Employee =====";
            highest->display();
        }

        else if(option==3){

            cout<<"\nProgram Ended";
        }

        else{
            cout<<"\nInvalid Option";
        }

    }while(option!=3);

    for(auto e : emp){
        delete e;
    }

    return 0;
}
