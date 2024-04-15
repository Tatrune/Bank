#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <iomanip>
// #include <bits/stdc++.h>

using namespace std;

int count = 0;

class bank
{
private:
    int Money;
    int BankId;
    string Name;
    string Location;
public:
    bank()
    {
    }
    bank(int tien, string name, string location)
    {
        Money = tien;
        Name = name;
        Location = location;   
    }
    int getBankId()
    {
        return BankId;
    }
    string getName()
    {
        return Name;
    }
    string getLocale()
    {
        return Location;
    }
    int setMoney(int tien)
    {
        Money = tien;
        return Money;
    }
    int getMoney()
    {
        return Money;
    }
    void setName(string name)
    {
        Name = name;
    }
    void setLocation(string location)
    {
        Location = location;
    }
    string getLocation()
    {
        return Location;
    }
};

class Customer : public bank
{
private:
    // Name
    int Id;
    int PhoneNo;
public:
    Customer()
    {
    }
    Customer(int tien, string name, string location, int id, int phone) : bank(tien,name,location)
    {
        setMoney(tien);
        setName(name);
        setLocation(location);
        Id = id;
        PhoneNo = phone;
        
    }
    void Generallnquiry()
    {
    }
    void DepositMonet()
    {
    }
    int WithdrawMoney(int tien)
    {
        int tienconlai;
        tienconlai = getMoney() - tien;
        setMoney(tienconlai);
        return tienconlai;
    }

    bool OpenAccount(int money)
    {
        if(money >0) return true;
        return false;
    }

    bool CloseAccount(int accountid)
    {
        if(accountid != 0 )
        {
            return true;
        }
        return false;
    }
    bool ApplyForLoans(string type, int accountid)
    {
        if(accountid < 0 )
        {
            return false;
        }
        return true;
    }

    void setId(int id)
    {
        Id = id;
    }

    int getId()
    {
        return Id;
    }
    int getAccountId()
    {
        return Id;
    }
    void setPhone(int phone)
    {
        PhoneNo = phone;
    }
    
    void nhap()
    {
        string tmp;
        int tmp1;
        cout << "Nhap thong tin"<<endl;
        cout << "Id: "; cin >> Id;
        cin.ignore();
        cout << "Name: "; getline(cin,tmp);
        setName(tmp);
        cout << "Address: "; getline(cin,tmp);
        setName(tmp);
        cout << "Money: "; cin >> tmp1;
        setMoney(tmp1);
        cout << "Phone: "; cin >> PhoneNo;

    }

    void in()
    {
        cout << "Id: " << Id << endl;
        cout << "Name: " << getName() << endl;
        cout << "Address: " << getLocation() << endl;
        cout << "Money: " << getMoney() << endl;
        cout << "PhoneNo: " << PhoneNo << endl;
    }

};

class Account : public Customer
{
    private:
    //Id
    int CustomerId = 0;

    public:
    Account()
    {
    }
    Account(int tien)
    {
        setMoney(tien);
    }
    Account(int tien, int customerId)
    {
        setMoney(tien);
        CustomerId = customerId;
    }
    Account(int tien, string name, string location, int id, int phone, int customerId)
    {
        setMoney(tien);
        setName(name);
        setLocation(location);
        CustomerId = id;
        setPhone(phone);
        setId(customerId);
    }
    void setCustomerId(int customerId)
    {
        CustomerId = customerId;
    }
    void nhap(int tien)
    {
        string tmp;
        int tmp_int;
        cout << "NHAP THONG TIN" << endl;
        cout << "Id: "; cin >> tmp_int;
        setId(tmp_int);
        cin.ignore();
        cout << "Name : "; getline(cin,tmp);
        setName(tmp);
        cout << "Address: "; getline(cin,tmp);
        setLocation(tmp);
        setMoney(tien);
        cout << "Phone: "; cin >> tmp_int;
        setPhone(tmp_int);
    }

    void CleanAccount()
    {
        setId(0);
        CustomerId = 0;
        setMoney(0);
    }

    void in()
    {
        cout << "In thong tin Account" << endl;
        Customer::in();
        cout << "CustomerId: " << getId() << endl;
    }
    
};

class Loan : public Customer
{
    private:
    int Id;
    string type;
    int AccountId;
    int CustomerId;

    public:
    Loan() : Customer()
    {
    }
    Loan(int Id, string type, int AccountId, int CustomerId)
    {
    }
};

class Teller : public Customer
{
	private: 
    int Id; 
    //name
    int CustomerId;
    int AccountId;

	public:
    Teller(){}
    void CollectMoney(int customerid, int tien, int accountid)
    {
        this -> CustomerId = customerid;
        this -> AccountId = accountid;
        setMoney(tien);
    }

    bool OpenAccount(int customerid, int money)
    {
        if (customerid > 0 && money > 0)
        {
            return true;
        }
        return false;
    }

    bool CloseAccount(int customerid)
    {
        if(customerid > 0)
        {
            return true;
        }
        return false;
    }

    bool LoanRequest(int customerid, int loanMoney)
    {
        if(customerid > 0 && loanMoney > 0)
        {
            return true;
        }
        return false;
    }

    void ProvideInfo(int customerid)
    {
        cout << "CustomerId: " << customerid << endl;
    }
    
    void in()
    {
        cout << "================================================================" << endl;
        cout << "Teller" << endl;
        cout << "CustomerId: " << CustomerId << endl;
        cout << "AccountId: " << AccountId << endl;
        cout << bank::getMoney();
    }
    ~Teller(){}

};

int main()
{
    Customer Customer1(9000,"nu","hcm",2,8668);
    Account *Account1 = new Account();
    if(Customer1.OpenAccount(1000))
    {
        Account Account1_tmp(1000, Customer1.getId());
        cout << "Account1_tmp: " << Account1_tmp.getId() << endl;
        cout << "Nhap thong tin account: " << endl;
        Account1 = &Account1_tmp;
        cout << "Account1: " << Account1 << endl;
        Account1_tmp.nhap(1000);
    }
    Account1->in();
    // Account1 -> in();
    // if(Customer1.CloseAccount(Account1->getId()))
    // {
    //     delete Account1;
    // }

    // Loan Loan1;
    // if(Customer1.ApplyForLoans("Customer1",1))
    // {
    //     Loan tmp(1, "Customer1", Account1->getId(), Customer1.getId());
    //     Loan1 = tmp;
    // }

}
