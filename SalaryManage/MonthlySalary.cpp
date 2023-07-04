#include "pch.h"
#include "MonthlySalary.h"
int MonthlySalary::GetMonth() {
    return m_month;
}

void MonthlySalary::SetMonth(int month) {
    m_month = month;
}

double MonthlySalary::GetBaseSalary() {
    return m_baseSalary;
}

void MonthlySalary::SetBaseSalary(double baseSalary) {
    m_baseSalary = baseSalary;
}

double MonthlySalary::GetPositionSalary() {
    return m_positionSalary;
}

void MonthlySalary::SetPositionSalary(double positionSalary) {
    m_positionSalary = positionSalary;
}

double MonthlySalary::GetSenioritySalary() {
    return m_senioritySalary;
}

void MonthlySalary::SetSenioritySalary(double senioritySalary) {
    m_senioritySalary = senioritySalary;
}

double MonthlySalary::GetAllowance() {
    return m_allowance;
}

void MonthlySalary::SetAllowance(double allowance) {
    m_allowance = allowance;
}

double MonthlySalary::GetStatusAllowance()
{
    return m_StatusAllowance;
}

void MonthlySalary::SetStatusAllowance(double StatusAllowance)
{
    m_StatusAllowance = StatusAllowance;
}

double MonthlySalary::GetSubsidy() {
    return m_subsidy;
}

void MonthlySalary::SetSubsidy(double subsidy) {
    m_subsidy = subsidy;
}

double MonthlySalary::GetHouseSubsidy() {
    return m_houseSubsidy;
}

void MonthlySalary::SetHouseSubsidy(double houseSubsidy) {
    m_houseSubsidy = houseSubsidy;
}

double MonthlySalary::GetTrafficAllowance() {
    return m_trafficAllowance;
}

void MonthlySalary::SetTrafficAllowance(double trafficAllowance) {
    m_trafficAllowance = trafficAllowance;
}

void MonthlySalary::SetTax(double tax)
{
    m_tax = tax;
}

double MonthlySalary::GetTax()
{
    int t = m_baseSalary + m_positionSalary + m_senioritySalary + m_allowance + m_StatusAllowance + m_subsidy + m_houseSubsidy + m_trafficAllowance;
    if (t < 800)
    {
        m_tax = 0;
    }
    if ((t > 800) && (t < 1000))
    {
        m_tax = t * 0.05;
    }
    if ((t > 1000) && (t < 5000))
    {
        m_tax = t * 0.1;
    }
    if (t > 5000)
    {
        m_tax = t * 0.2;
    }
    return m_tax;
}

void MonthlySalary::SetTotal(double total)
{
    m_total = total;
}

double MonthlySalary::GetTotal()
{
    m_total =m_baseSalary + m_positionSalary + m_senioritySalary + m_allowance + m_StatusAllowance + m_subsidy + m_houseSubsidy + m_trafficAllowance - m_tax;

    return m_total;
}

/*double MonthlySalary::GetTotalSalary() {
    return m_baseSalary + m_positionSalary + m_senioritySalary + m_allowance + m_subsidy + m_houseSubsidy + m_trafficAllowance;
}*/