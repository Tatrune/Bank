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

    int getPhone()
    {
        return PhoneNo;
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
        setName("");
        setLocation("");
        setPhone(0);
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
    string Type;
    int AccountId;
    int CustomerId;

    public:
    Loan() : Customer()
    {
    }

    Loan(int id, string type, int AccountId, int CustomerId, string name, string location, int phone)
    {
        this -> Id = id;
        this -> Type = type;
        this -> AccountId = AccountId;
        this -> CustomerId = CustomerId;
        setName(name);
        setLocation(location);
        setPhone(phone);
    }

    void in(int accountId, int customerId)
    {
        cout << "Id: " << Id << endl;
        cout << "Name: " << getName() << endl;
        cout << "Address: " << getLocation() << endl;
        cout << "Money: " << getMoney() << endl;
        cout << "PhoneNo: " << getPhone() << endl;
        cout << "AccountId: " << accountId << endl;
        cout << "CustomerId: " << customerId << endl;

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
    Teller()
    {
    }

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
    int dem_account = 0;
    int dem_loan = 0;
    int dem_teller = 0;

    Customer Customer1(9000,"nu","hcm",2,8668);
    Account Acc_arr[10];
    Loan Loan_arr[10];
    Teller Teller[10];

    int choice;
    while(true)
    {
        cout << "nhap lua chon" << endl; cin >> choice;
        switch (choice)
        {
            case 1: // dang ky tai 1 tai khoan account
                cout << "Dang ky Account:" << endl;
                if(Customer1.OpenAccount(1000))
                {
                    Account Account1_tmp(1000, Customer1.getId()); // bo nho dem
                    cout << "Nhap thong tin account: " << endl;
                    Acc_arr[dem_account] = Account1_tmp; 
                    Acc_arr[dem_account].nhap(1000);
                }
                dem_account++; // moi lan dang ky 1 tai khoan bien dem cua account se tu tang len
            break;

            case 2:
            cout << "Nhap account id ma ban muon xoa: " << endl;
            int id; cin >> id;
            for(int i = 0; i < 10; ++i)
            {
                if(Acc_arr[i].getId() == id)
                {
                    Acc_arr[i].CleanAccount();
                }
            }
            Acc_arr[id].in();
                break;
            
            case 3: // Loan created by account
                if(Customer1.ApplyForLoans("nhap vao 1 type", Acc_arr[0].getId())) // Acc_arr[0].getId(): ID cua account can de tao ra 1 doi tuong Loan
                {
                    Loan Loan_tmp(1,"nhap vao 1 type",Acc_arr[0].getId(), Customer1.getId(),Acc_arr[0].getName(), Acc_arr[0].getLocation(),Acc_arr[0].getPhone());
                    Loan_arr[dem_loan] = Loan_tmp;
                    Loan_arr[dem_loan].in(Acc_arr[0].getId(),Customer1.getId()); //in thong tin cua 1 Loan
                }
                dem_loan++;
            break;

            case 4:


            break;
            default:
                
                break;
        }
    }
}
