#pragma once
#include "Employee.h"
#include<vector>
class Management
{
private:
    Management() {};
    vector<Employee> _EmployeeData;
    static Management* _Instance;

public:
    //Œ¥≤‚ ‘ 
    ~Management();
   
    void AddEmployee(Employee a);
    
    void ShowEmployee() {};
    
    static Management* getInstance();
    
    vector<Employee>& getEeVector() { return _EmployeeData; };
    
    bool SearchEmployeeId(int id);

    Employee& SeaGetEmployee(int id);
    size_t SeaGetEmployeeRow(int id);


};

