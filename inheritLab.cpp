#include <iostream>
using namespace std;
class Employee{
    public:
    Employee(){
    name=" ";
    salary=0;
    percent=0;
    }
    void showInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
     void calculateBonus(){
      cout<<"Bonus: "<<salary*percent<<endl;
    }
    protected:
    string name;
    double salary;
    double percent;
};
class Manager: public Employee{
  public:
  Manager(string s, int m){
    name=s;
    salary=m;
  }
    void calculateBonus() {
    double bonus;
    percent=0.2;
     bonus=salary*percent;
     cout<<"Bonus Amount: "<<bonus<<endl;
    }
};
class Developer: public Employee{
  public:
  Developer(string s, int m){
    name=s; 
    salary=m;
  }
    void calculateBonus()  {
    double bonus;
    percent=0.1;
     bonus=salary*percent;
     cout<<"Bonus Amount: "<<bonus<<endl;
    }
};
int main(){
    Employee * myManager=new Manager("tiffany",90000);
    myManager->calculateBonus();
    Employee *me= new Developer("Abby",100000);
    me->calculateBonus();
    /*Output:
    Bonus Amount: 14000
    Bonus Amount: 10000
*/
  
}
/*Virtual Employee calculateBonus:
Bonus Amount: 18000
Bonus Amount: 10000

No Virtual command or override:
Bonus: 0
Bonus: 0
*/