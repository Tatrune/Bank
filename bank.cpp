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
        // cout << "Id: "; cin >> tmp_int;
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
        setMoney(tien+getMoney());

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
        cout << "accountId: " << getAccountId() << endl;
        cout << "Money: " << getMoney() << endl;
        cout << "name: " << getName() << endl;
        cout << "address: " << getLocation() << endl;
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

    int getCustomerId()
    {
        return CustomerId;
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

void inMenu()
{
    cout << "==============================MENU==============================" << endl;
    cout << "1: Dang ky 1 tai khoan account" << endl;
    cout << "2: xoa account" << endl;
    cout << "3: Tao 1 Loan" << endl;
    cout << "4: Tao 1 teller" << endl;
    cout << "5: Them tien vao teller" << endl;
    cout << "6: Dong 1 tai khoan Teller"  << endl;
    cout << "7: Kiem tra Teller" << endl;
    cout << "8: In ra thong tin 1 teller" << endl;
    cout << "9: in ra thong tin cac account" << endl;
    cout << "10: Thoat chuong trinh" << endl;
    cout << "NHAP LUA CHON CUA BAN: " << endl;

}

int main()
{
    int dem_account = 0;
    int dem_loan = 0;
    int dem_teller = 0;

    Customer Customer1(9000,"nu","hcm",2,8668);
    Account Acc_arr[10];
    Loan Loan_arr[10];
    Teller Teller_arr[10];

    int choice;
    while(true)
    {
        inMenu();
        cin >> choice;
        switch (choice)
        {
            case 1: // dang ky tai 1 tai khoan account
                if(Customer1.OpenAccount(1000))
                {
                    Account Account1_tmp(1000, Customer1.getId()); // bo nho dem
                    cout << "Nhap thong tin account: " << endl;
                    Acc_arr[dem_account] = Account1_tmp; 
                    Acc_arr[dem_account].nhap(1000);
                    Acc_arr[dem_account].setId(dem_account);
                }
                dem_account++; // moi lan dang ky 1 tai khoan bien dem cua account se tu tang len
            break;

            case 2:
            cout << "Nhap accountid ma ban muon xoa: " << endl;
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
            int acc_id;
            cout << "Nhap ID cua account ma ban muon tao thanh Loan" << endl;
                if(Customer1.ApplyForLoans("nhap vao 1 type", Acc_arr[acc_id].getId())) // Acc_arr[0].getId(): ID cua account can de tao ra 1 doi tuong Loan
                {
                    // dem_loan la id cua Loan
                    // acc_id la id cua account 
                    Loan Loan_tmp(dem_loan,"nhap vao 1 type",Acc_arr[acc_id].getId(), Customer1.getId(),Acc_arr[acc_id].getName(), Acc_arr[acc_id].getLocation(),Acc_arr[acc_id].getPhone());
                    Loan_arr[dem_loan] = Loan_tmp;
                    Loan_arr[dem_loan].in(Acc_arr[acc_id].getId(),Customer1.getId()); //in thong tin cua 1 Loan
                }
                dem_loan++;
            break;

            case 4: // Open Teller
                Teller_arr[dem_teller].OpenAccount(Customer1.getId(), 1000);
                Teller_arr[dem_teller].setName(Customer1.getName()); // name of teller
                Teller_arr[dem_teller].setId(dem_teller); // Id of Teller
                dem_teller++;
            break;

            case 5: // + money for teller 
                int Teller_num;;
                int money;
                cout << "Nhap ID cua teller can them tien: " << endl; cin >> Teller_num;
                cout << "Nhap so tien can cam them vao: " << endl; cin >> money;
                Teller_arr[Teller_num].CollectMoney(Customer1.getId(), money, Acc_arr[0].getId());
            break;

            case 6: // Close account of teller
            int choice_teller;
            cout << "nhap ID tai khoan Teller can dong: " << endl; cin >> choice_teller;
            if(Teller_arr[choice_teller].CloseAccount(Customer1.getId()))
            {
                Teller_arr[choice_teller].CleanAccount();
            }     
            break;
            
            case 7: //
            cout << "Kiem tra 1 Teller: "<< endl; 
            int moneyTeller_check;
            cin >> choice_teller;
            cout << "So tien can kiem tra: " << endl; cin >> moneyTeller_check;
            if(Teller_arr[choice_teller].LoanRequest(Customer1.getId(), moneyTeller_check))
            {
                cout << "Tai Khoan Du Tien" << endl;
            }
            cout << "khong co tai khoan hoac tai khoan khong du tien" << endl;
            break;
            
            case 8:
            int check_teller;
            cout << "Nhap ID cua customer can kiem tra: "<< endl; cin >> check_teller;

            for (auto x : Teller_arr)
            {
                if(x.getCustomerId() == check_teller)
                {
                    x.ProvideInfo(x.getCustomerId());
                }
                else cout << "khong tim thay teller " << endl;
            }
            break;
            
            case 9:
            for(int i = 0; i < dem_account; i++)
            {
                Acc_arr[i].in();
            }
            break;

            case 10: 
            cout << "thoat";
            return 0;

            default:
            cout << "Nhap sai, Nhap lai" << endl;
            break;
        }
    }
    return 0;
}
