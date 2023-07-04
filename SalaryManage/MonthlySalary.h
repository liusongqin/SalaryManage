#pragma once
class MonthlySalary
{
public:MonthlySalary()
    {
    m_month = 0;
    m_baseSalary = 0;
    m_positionSalary = 0;
    m_senioritySalary = 0;
    m_allowance = 0;
    m_subsidy = 0;
    m_houseSubsidy = 0;
    m_trafficAllowance = 0;
    }
    MonthlySalary(int month, 
        double baseSalary,
        double positionSalary, 
        double senioritySalary, 
        double allowance, 
        double StatusAllowance,
        double subsidy, 
        double houseSubsidy,
        double trafficAllowance,
        double tax
    )
    {
         m_month = month;
         m_baseSalary= baseSalary;
         m_positionSalary= positionSalary;
         m_senioritySalary= senioritySalary;
         m_allowance= allowance;
         m_StatusAllowance = StatusAllowance;
         m_subsidy= subsidy;
         m_houseSubsidy= houseSubsidy;
         m_trafficAllowance= trafficAllowance;
         m_tax = tax;
         int t= baseSalary + positionSalary + senioritySalary + allowance + StatusAllowance + subsidy + houseSubsidy + trafficAllowance;
         if (t < 800)
         {
             m_tax = t;
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
         m_total = baseSalary+ positionSalary+ senioritySalary+ allowance+ StatusAllowance+ subsidy+ houseSubsidy+ trafficAllowance- tax;
    }
    int GetMonth() ;
    void SetMonth(int month);
    double GetBaseSalary() ;
    void SetBaseSalary(double baseSalary);
    double GetPositionSalary() ;
    void SetPositionSalary(double positionSalary);
    double GetSenioritySalary()  ;
    void SetSenioritySalary(double senioritySalary);
    double GetAllowance() ;
    void SetAllowance(double allowance);
    double GetStatusAllowance();
    void SetStatusAllowance(double StatusAllowance);
    double GetSubsidy() ;
    void SetSubsidy(double subsidy);
    double GetHouseSubsidy() ;
    void SetHouseSubsidy(double houseSubsidy);
    double GetTrafficAllowance() ;
    void SetTrafficAllowance(double trafficAllowance);
    void SetTax(double tax);
    double GetTax();
    void SetTotal(double total);
    double GetTotal();
private:
    int m_month;
    double m_baseSalary;
    double m_positionSalary;
    double m_senioritySalary;
    double m_allowance;
    double m_StatusAllowance;
    double m_subsidy;
    double m_houseSubsidy;
    double m_trafficAllowance;
    double m_tax;
    double m_total;
};

