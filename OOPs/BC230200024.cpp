#include<iostream>
#include<conio.h>
using namespace std;

class TaxPayer
{
public:
    virtual double calculateTax() = 0;
    virtual ~TaxPayer() {}
};

class SalariedPerson : public TaxPayer
{
private:
    double annualIncome;
public:
    SalariedPerson(double income) : annualIncome(income) {}

    double calculateTax()
    {
        double tax = 0;
        if(annualIncome <= 600000)
        {
            tax = 0;
        }
        else if(annualIncome <=1200000)
        {
            tax = annualIncome * 0.05;
        }
        else if(annualIncome <= 2400000)
        {
            tax = annualIncome * 0.10;
        }
        else if(annualIncome <= 4800000)
        {
            tax = annualIncome * 0.15;
        }
        else if(annualIncome <= 9600000)
        {
            tax = annualIncome * 0.25;
        }

        return tax;
    }
};



class BusinessPerson : public TaxPayer
{
private: 
    double annualIncome;
    double allowedExpenses;
public:
    BusinessPerson(double income) : annualIncome(income), allowedExpenses(income * 0.60) {}

    double calculateTax()
    {
        if(annualIncome < 1000000)
        {
            return 0;
        }
        double taxedAmount = annualIncome - allowedExpenses;
        return taxedAmount * 0.29;
    }
};


int main()
{
    TaxPayer *taxPayers[2];
    cout<<"Student ID: BC230200024\n\n";
    cout<<"-----------------------------------------------";
    cout<<"\n-----------------TAX CALCULATOR----------------";
    cout<<"\n-----------------------------------------------";

    int income;

    cout<<"\n\nEnter Annual Income: ";
    cin>> income;

    taxPayers[0] = new BusinessPerson(income);
    taxPayers[1] = new SalariedPerson(income);

    if(income < 1000000)
    {
        cout<<"\n\nFor Business Person, Minimun Annual Income is 1, 000, 000";
        cout<<"\nTax Payable Amount = " <<taxPayers[0]->calculateTax();
        cout<<"\n\nFor Salaried Person, Tax Payable Amount = " << taxPayers[1]->calculateTax();
    }
    else
    {
        cout<<"\n\nFor Business Person, Tax Payable Amount = " << taxPayers[0]->calculateTax();
        cout<<"\n\nFor Salaried Person, Tax Payable Amount = " << taxPayers[1]->calculateTax();

    }

    for(int i = 0; i < 2; i++)
    {
        delete taxPayers[i];
    }

    getch();
    
    return 0;
}