#include "pch.h"
#include "Employee.h"
// 获取员工编号
long long Employee::GetId()
{
    return m_id;
}

void Employee::SetId(long long id)
{
    m_id = id;
}

 string& Employee::GetName() 
{
    return m_name;
}

void Employee::SetName( string& name)
{
    m_name = name;
}

int Employee::GetAge() 
{
    return m_age;
}

void Employee::SetAge(int age)
{
    m_age = age;
}

 string& Employee::GetHireDate() 
{
    return m_hireDate;
}

void Employee::SetHireDate( string& hireDate)
{
    m_hireDate = hireDate;
}

 string& Employee::GetPhone() 
{
    return m_phone;
}

void Employee::SetPhone( string& phone)
{
    m_phone = phone;
}

 string& Employee::GetAddress() 
{
    return m_address;
}

void Employee::SetAddress( string& address)
{
    m_address = address;
}

double Employee::GetYearlySalary() 
{
    double all_total=0;
    for (auto it : CMonthlySalary)
    {
        all_total += it.GetTotal();
    }
    return all_total;
}
double Employee::GetDirtyYearlySalary()
{
    return m_yearlySalary;
}

void Employee::SetMonthlySalary(double monthlySalary)
{
    m_yearlySalary = monthlySalary;
}

string& Employee::GetTag()
{
    // TODO: 在此处插入 return 语句
    return m_tag;
}

void Employee::SetTag(std::string& tag)
{
    m_tag = tag;
}

vector<MonthlySalary>& Employee::GetCMonthlySalary()
{
    // TODO: 在此处插入 return 语句
    return CMonthlySalary;
}
