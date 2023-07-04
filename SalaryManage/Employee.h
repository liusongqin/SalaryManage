#pragma once
#include <string>
#include "MonthlySalary.h"
#include<vector>
using namespace std;

class Employee
{
public:
    Employee()
    {
         m_id=0;
         m_name = "无";
         m_age=1;
         m_hireDate= "无";
         m_phone= "无";
         m_address= "无";
         m_yearlySalary=1;
        
         int i = 0;
         
         MonthlySalary a_CMonthlySalary(i, 0, 0, 0, 0, 0, 0, 0, 0, 0);
         for (i = 0; i < 12; i++)
         {
             
             CMonthlySalary.push_back(a_CMonthlySalary);
         }
    }
    Employee(int id, string& name, int age, string& hireDate, string& phone, string& address, double monthlySalary, string tag)
        : m_id(id), m_name(name), m_age(age), m_hireDate(hireDate), m_phone(phone), m_address(address), m_yearlySalary(monthlySalary), m_tag(tag)
    {
        int i = 0;


        MonthlySalary a_CMonthlySalary(i, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        for (i = 0; i < 12; i++)
        {

            CMonthlySalary.push_back(a_CMonthlySalary);
        }
    }
    long long GetId() ;
    void SetId(long long id);
    string& GetName() ;
    void SetName( std::string& name);
    int GetAge() ;
    void SetAge(int age);
    string& GetHireDate() ;
    void SetHireDate( std::string& hireDate);
    string& GetPhone() ;
    void SetPhone( std::string& phone);
    string& GetAddress() ;
    void SetAddress( std::string& address);
    double GetYearlySalary() ;
    double GetDirtyYearlySalary();
    void SetMonthlySalary(double monthlySalary);
    string& GetTag();
    void SetTag(std::string& tag);

    vector<MonthlySalary>& GetCMonthlySalary();
private:
    long long m_id;
    string m_name;
    int m_age;
    string m_hireDate;
    string m_phone;
    string m_address;
    double m_yearlySalary;
    string m_tag;
    vector<MonthlySalary> CMonthlySalary;
};

