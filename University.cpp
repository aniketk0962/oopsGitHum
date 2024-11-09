#include<iostream>
using namespace std;
//USING CONSTRUCTOR
class Employee{
    //public:
    protected://IT MEANS WE CAN ACCESS PROTECTED SPECIFIER IN THIS WAY.
    string name;
    int emp_id;
    double salary;
    public:
    Employee(){

    }    
    Employee(string name,int emp_id,double salary){
        this->name=name;
        this->emp_id=emp_id;
        this->salary=salary;
    }
    double CalculateMonthlyPay(){
        return salary;
    }
};
class Professor : public Employee {
    //public:
    protected://IF WE COMMENTED PROTECTED SPECIFIER AND ENABLE PUBLIC SPECIFIER,THEN ALSO CODE WILL BE RUN.
    string dept;
    public:
     Professor(string name, int emp_id, double salary, string dept) : Employee(name,emp_id,salary){
        this->dept=dept;
     }
    // void MonthlySalary(double s){
    //     s+=s/10;
    // }
    double get_MonthlySalary(){
        salary+=salary/10;
        return salary;
    }
};
class AdminStaff : public Professor{
    //public:
    protected:
    string position;
    public:
     AdminStaff(string name, int emp_id, double salary, string dept, string position ) : Professor(name,emp_id,salary,dept){
        this->position=position;
     }
    // void GiveSalary(double s){
    //     s+=s/20;
    // }
    double get_GiveSalary(){
        salary+=salary/20;
        return salary;
    }
};
class Janitor : public AdminStaff{
    //public:
    protected:
    float working_hour;
    public:
     Janitor(string name, int emp_id, double salary, string dept, string position, float working_hour) : AdminStaff(name,emp_id,salary,dept,position){
        this->working_hour=working_hour;
     }
    // void give_salary(float wh){
    //     salary=salary*wh;
    // }
    double get_give_salary(){
        salary=salary*working_hour;
        return salary;
    }
};
int main(){
    int salary;
    cout<<"Your salary is:"<< endl;
    cin>>salary;
    // Janitor J1;
    // // J1.salary;
    // // J1.give_salary(2.5);
    // J1.get_give_salary();
    Employee emp("Employee 1", 1, salary);
    Professor prof("Professor 1", 2, salary, "Computer Science");
    AdminStaff admin("Admin Staff 1", 3, salary, "Administration", "Manager");
    Janitor janitor("Janitor 1", 4, salary, "Maintenance", "Cleaner", 2.5);
    // prof.get_MonthlySalary();
    // admin.get_GiveSalary();
    // janitor.get_give_salary();
    cout << "Employee salary: " << emp.CalculateMonthlyPay() << endl;
    cout << "Professor salary: " << prof.get_MonthlySalary() << endl;
    cout << "Admin Staff salary: " << admin.get_GiveSalary() << endl;
    cout << "Janitor salary: " << janitor.get_give_salary() << endl;
    return 0;
}
