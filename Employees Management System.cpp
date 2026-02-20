#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <limits>
#include <iomanip>

using namespace std;

class clsString
{
public:
    
   static string UpperAllString(string S1)
   {
        for (int i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);     
        }
        
        return S1;
   }

    static vector<string> Split(string s, string delimiter)
    {
        vector<string> v;
        size_t pos = 0;
        string token;
        while ((pos = s.find(delimiter)) != string::npos)
        {
            token = s.substr(0, pos);
            v.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        v.push_back(s);
        return v;
    }

    static string NumberToText(int Number)
   {

       if (Number == 0)
       {
           return "";
       }

       if (Number >= 1 && Number <= 19)
       {
           string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
       "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
         "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

           return  arr[Number] + " ";

       }

       if (Number >= 20 && Number <= 99)
       {
           string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
           return  arr[Number / 10] + " " + NumberToText(Number % 10);
       }

       if (Number >= 100 && Number <= 199)
       {
           return  "One Hundred " + NumberToText(Number % 100);
       }

       if (Number >= 200 && Number <= 999)
       {
           return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
       }

       if (Number >= 1000 && Number <= 1999)
       {
           return  "One Thousand " + NumberToText(Number % 1000);
       }

       if (Number >= 2000 && Number <= 999999)
       {
           return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
       }

       if (Number >= 1000000 && Number <= 1999999)
       {
           return  "One Million " + NumberToText(Number % 1000000);
       }

       if (Number >= 2000000 && Number <= 999999999)
       {
           return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
       }

       if (Number >= 1000000000 && Number <= 1999999999)
       {
           return  "One Billion " + NumberToText(Number % 1000000000);
       }
       else
       {
           return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
       }


   }

};

class clsDate
{
private:
    short Day;
    short Month;
    short Year;

public:
    clsDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        Day = now->tm_mday;
        Month = now->tm_mon + 1;
        Year = now->tm_year + 1900;
    }


    short getDay() { return Day; }
    void setDay(short day) { Day = day; }

    short getMonth() { return Month; }
    void setMonth(short month) { Month = month; }

    short getYear() { return Year; }
    void setYear(short year) { Year = year; }

    void Print()
    {
        cout << DateToString() << endl;
    }

    static string GetSystemDateTimeString()
    {
        time_t t = time(0);
        tm* now = localtime(&t); 
        short Day, Month, Year, Second, Hour, Minute;
        Day = now ->tm_mday;
        Month = now -> tm_mon;
        Year = now -> tm_year;
        Second = now -> tm_sec;
        Hour = now -> tm_hour;
        Minute = now -> tm_min;

        return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " _ " 
        + to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second));
    }

    static string DateToString(clsDate Date)
    {
        return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }

    string DateToString()
    {
        return DateToString(*this);
    }

    static bool isLeapYear(short Year)
    {
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    bool isLeapYear()
    {
        return isLeapYear(Year);
    }

    static short NumberOfDaysInAYear(short Year)
    {
        return isLeapYear(Year) ? 366 : 365;
    }

    short NumberOfDaysInAYear()
    {
        return NumberOfDaysInAYear(Year);
    }

    static short NumberOfHoursInAYear(short Year)
    {
        return NumberOfDaysInAYear(Year) * 24;
    }

    short NumberOfHoursInAYear()
    {
        return NumberOfHoursInAYear(Year);
    }

    static int NumberOfMinutesInAYear(short Year)
    {
        return NumberOfHoursInAYear(Year) * 60;
    }

    int NumberOfMinutesInAYear()
    {
        return NumberOfMinutesInAYear(Year);
    }

    static int NumberOfSecondsInAYear(short Year)
    {
        return NumberOfMinutesInAYear(Year) * 60;
    }

    int NumberOfSecondsInAYear()
    {
        return NumberOfSecondsInAYear(Year);
    }

    static short NumberOfDaysInAMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12)
            return 0;
        int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
    }

};

class clsUtil
{
   
public:

    static string EncryptText(string Text, short EncryptionKey = 2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey = 2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }

};

class clsInputValidate 
{
public:
    static bool IsNumberBetween(int Number, int From, int To)
    {
        return (Number >= From) && (Number <= To);
    }
    
    static bool IsNumberBetween(double Number, double From, double To)
    {
        return (Number >= From) && (Number <= To);
    }

    static int ReadIntNumber(string ErrorMessage = "Invalid input, please enter an integer: ")
    {
        int Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return Number;
    }

    static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, enter again: ")
    {
        int Number = ReadIntNumber();
        
        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadIntNumber();
        }
        return Number;
    }

    static double ReadDblNumber(string ErrorMessage = "Invalid input, please enter a number: ")
    {
        double Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return Number;
    }
    
    static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, enter again: ")
    {
        double Number = ReadDblNumber();
        
        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadDblNumber();
        }
        return Number;
    }

    static string ReadString()
    {
        string S;
        getline(cin >> ws, S);
        return S;
    }

};

class clsPerson
{
private:
  
   string _FullName;
   string _Country;
   string _Email;
   string _PhoneNumber;

public:

   clsPerson(string FullName, string PhoneNumber,string Country, string Email)
   {
        _FullName  = FullName;
        _Country   =  Country;
        _PhoneNumber = PhoneNumber; 
        _Email = Email;   
   }

    
    void SetFullName(string FullName)
    {
        _FullName = FullName;
    }

    string GetFullName()
    {
        return _FullName;
    }

    void SetPhoneNumber(string PhoneNumber)
    {
        _PhoneNumber = PhoneNumber;
    }

    string GetPhoneNumber()
    {
        return _PhoneNumber;
    }

    void SetCountry(string Country)
    {
        _Country = Country;
    }

    string GetCountry()
    {
        return _Country;
    }

    void SetEmail(string Email)
    {
        _Email = Email;
    }
    
    string GetEmail()
    {
        return _Email;
    }
    
};

class clsEmployee : public clsPerson
{
private:
   string _EmployeeID;
   string _FullName;
   string _Departement;
   string _JobTitle;
   float _Deductions;
   float _Allowances;
   float _BasicSalary;
   float _NetSalary;
   float _Salary;
   bool _MarkForDelete = false;

   static clsEmployee _GetEmptyEmployeeObject()
   {
       return clsEmployee("", "", "", "", "", 0, "", "");
   }

    static clsEmployee _ConvertLineToEmployeeObject(string Line, string Separator = "#//#")
   {
       vector<string> _vEmployeeData = clsString::Split(Line, Separator);
       return clsEmployee(_vEmployeeData[0], _vEmployeeData[1], _vEmployeeData[2], _vEmployeeData[3]
                , _vEmployeeData[4],stof( _vEmployeeData[5]), _vEmployeeData[6], _vEmployeeData[7]);
   }

   static clsEmployee  _ConvertLineToMonthlyPayrollEmployeeObject(string Line, string Separator = "#//#")
   {
       vector<string> _vMonthlyPayrollEmployeeData = clsString::Split(Line, Separator);
       return clsEmployee(_vMonthlyPayrollEmployeeData[0], _vMonthlyPayrollEmployeeData[1], stof(_vMonthlyPayrollEmployeeData[2]),stof( _vMonthlyPayrollEmployeeData[3])
                , stof(_vMonthlyPayrollEmployeeData[4]),stof( _vMonthlyPayrollEmployeeData[5]));
   }
   
    static string _ConvertEmployeeObjectToRecordLine(clsEmployee Employee, string Separator = "#//#")
    {
        string stEmployeeRecord = "";
        stEmployeeRecord += Employee.GetEmployeeID() + Separator;
        stEmployeeRecord += Employee.GetFullName() + Separator;
        stEmployeeRecord += Employee.GetCountry() + Separator;
        stEmployeeRecord += Employee.GetDepartement() + Separator;
        stEmployeeRecord += Employee.GetJobTitle() + Separator;
        stEmployeeRecord += to_string(Employee.GetSalary()) + Separator;
        stEmployeeRecord += Employee.GetPhoneNumber() + Separator;
        stEmployeeRecord += Employee.GetEmail();
        
        return stEmployeeRecord;
    }

    static string _ConvertMonthlyPayrollEmployeeObjectToRecordLine(clsEmployee Employee, string Separator = "#//#")
    {
        string stMonthlyPayrollEmployeeRecord = "";
        stMonthlyPayrollEmployeeRecord += Employee.GetEmployeeID() + Separator;
        stMonthlyPayrollEmployeeRecord += Employee.GetFullName() + Separator;
        stMonthlyPayrollEmployeeRecord += to_string(Employee.GetBasicSalary()) + Separator;
        stMonthlyPayrollEmployeeRecord += to_string(Employee.GetAllowances()) + Separator;
        stMonthlyPayrollEmployeeRecord += to_string(Employee.GetDeductions()) + Separator;
        stMonthlyPayrollEmployeeRecord += to_string(Employee.GetNetSalary());
        
        return stMonthlyPayrollEmployeeRecord;
    }
    
    static vector<clsEmployee> _LoadEmployeesDataFromFile()
    {
        vector<clsEmployee> vEmployees;
        fstream MyFile;
        MyFile.open("Employees.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsEmployee Employee = _ConvertLineToEmployeeObject(Line);
                vEmployees.push_back(Employee);
            }
            
            MyFile.close();
        }

        return vEmployees; 
    }

    static vector<clsEmployee> _LoadEmployeesDataFromMonthlyPayrollFile()
    {
        vector<clsEmployee> vMonthlyPayrollEmployees;
        fstream MyFile;
        MyFile.open("MonthlyPayroll.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsEmployee MonthlyPayrollEmployee = _ConvertLineToMonthlyPayrollEmployeeObject(Line);
                vMonthlyPayrollEmployees.push_back(MonthlyPayrollEmployee);
            }
            
            MyFile.close();
        }

        return vMonthlyPayrollEmployees; 
    }
    
    static void _SaveEmployeesDataToFile(vector<clsEmployee>& vEmployees)
    {
        fstream MyFile;
        MyFile.open("Employees.txt", ios::out);

        if (MyFile.is_open())
        {
            string Line;
            for (const clsEmployee& Employee : vEmployees)
            {
                if (Employee._MarkForDelete == false)
                {        
                   Line = _ConvertEmployeeObjectToRecordLine(Employee);
                   MyFile << Line << endl;
                }
            }

            MyFile.close();
        }
    }

    static void _SaveEmployeesDataToMonthlyPayrollFile(vector<clsEmployee>& vEmployees)
    {
        fstream MyFile;
        MyFile.open("MonthlyPayroll.txt", ios::out);

        if (MyFile.is_open())
        {
            string Line;
            for (const clsEmployee& Employee : vEmployees)
            {
                if (Employee._MarkForDelete == false)
                {        
                   Line = _ConvertMonthlyPayrollEmployeeObjectToRecordLine(Employee);
                   MyFile << Line << endl;
                }
            }

            MyFile.close();
        }
    }
    
public:

   clsEmployee(string EmployeeID, string FullName, string Country, string Departement, string JobTitle, float Salary, string PhoneNumber, string Email): 
              clsPerson(FullName, PhoneNumber, Country,  Email)
   {
        _EmployeeID = EmployeeID;
        _Departement = Departement;
        _JobTitle = JobTitle;
        _Salary = Salary;
        _BasicSalary = 0;
        _Allowances = 0;
        _Deductions = 0;
        _NetSalary = 0;
   }

   clsEmployee(string EmployeeID, string FullName, float BasicSalary, float Allowances , float Deductions, float NetSalary): 
              clsPerson(FullName, "", "", "")
   {
        _EmployeeID = EmployeeID;
        _FullName = FullName;
        _BasicSalary = BasicSalary;
        _Allowances = Allowances;
        _Deductions = Deductions;
        _NetSalary = NetSalary;
        _Departement = "";
        _JobTitle = "";
        _Salary = 0;
   }
   
    void SetEmployeeID(string EmployeeID)
    {
        _EmployeeID = EmployeeID;
    }

    string GetEmployeeID()
    {
        return _EmployeeID;
    }
    
    void SetDepartement(string Departement)
    {
        _Departement = Departement;
    }

    string GetDepartement()
    {
        return _Departement;
    }

    void SetJobTitle(string JobTitle)
    {
        _JobTitle = JobTitle;
    }

    string GetJobTitle()
    {
        return _JobTitle;
    }

    void SetNetSalary(float NetSalary)
    {
        _NetSalary = NetSalary;
    }

    float GetNetSalary()
    {
        return _NetSalary;
    }

    void SetSalary(float Salary)
    {
        _Salary = Salary;
    }

    float GetSalary()
    {
        return _Salary;
    }

    void SetAllowances(float Allowances)
    {
        _Allowances = Allowances;
    }

    float GetAllowances()
    {
        return _Allowances;
    }
    
    void SetBasicSalary(float BasicSalary)
    {
        _BasicSalary = BasicSalary;
    }

    float GetBasicSalary()
    {
        return _BasicSalary;
    }

   void SetDeductions(float Deductions)
    {
        _Deductions = Deductions;
    }

    float GetDeductions()
    {
        return _Deductions;
    }

    static vector<clsEmployee> GetEmployeesData()
    {
        return _LoadEmployeesDataFromFile();
    }

    static vector<clsEmployee> GetEmployeesMonthlyPayrollData()
    {
        return _LoadEmployeesDataFromMonthlyPayrollFile();
    }
           
    static void SaveEmployeesData(vector<clsEmployee>& vEmployees)
    {
        _SaveEmployeesDataToFile(vEmployees);
    }

    static void SaveEmployeesMonthlyPayrollData(vector<clsEmployee>& vEmployees)
    {
        _SaveEmployeesDataToMonthlyPayrollFile(vEmployees);
    }

    static clsEmployee FindEmployeeByEmployeeID(string EmployeeID)
    {
        vector<clsEmployee> vEmployees = _LoadEmployeesDataFromFile();
        fstream MyFile;
        MyFile.open("Employees.txt", ios::in);
        if (MyFile.is_open())
        {
            for (clsEmployee& Employee : vEmployees)
            {
                if (Employee.GetEmployeeID() == EmployeeID)
                {
                    MyFile.close();
                    return Employee;
                }  
            }
        }
        
        return _GetEmptyEmployeeObject();
    }
    
    bool IsEmpty()
    {
        return _EmployeeID == "";
    }
    
    static bool IsEmployeeExistByEmployeeID(string EmployeeID)
    {
        clsEmployee Employee = clsEmployee::FindEmployeeByEmployeeID(EmployeeID);
        return (!Employee.IsEmpty());
    }
    
    static float CalculateTotalBalance()
    {
        vector<clsEmployee> vEmployees = _LoadEmployeesDataFromFile();
        float TotalBalance = 0;

        for (clsEmployee& Employee : vEmployees)
        {
            TotalBalance += Employee.GetSalary();
        }

        return TotalBalance;
        
    }
    
    static bool Delete(string EmployeeID)
    {
        vector<clsEmployee> vEmployees = _LoadEmployeesDataFromFile();

        for (clsEmployee& Employee : vEmployees)
        {
            if (Employee.GetEmployeeID() == EmployeeID)
            {
                Employee._MarkForDelete = true;
                SaveEmployeesData(vEmployees);
                return true;
            } 
        }
        
        return false;
    }
    
    static int CalculateTotalEmployees()
    {
        vector<clsEmployee> vEmployees = _LoadEmployeesDataFromMonthlyPayrollFile();
        int TotalEmployees = 0;

        for (clsEmployee& Employee : vEmployees)
        {
            TotalEmployees ++;
        }

        return TotalEmployees;
    }

    static float CalculateTotalGrossSalary()
    {
        vector<clsEmployee> vEmployees = _LoadEmployeesDataFromMonthlyPayrollFile();
        int TotalGrossSalary = 0;

        for (clsEmployee& Employee : vEmployees)
        {
            TotalGrossSalary += Employee.GetBasicSalary();
        }

        return TotalGrossSalary;
    }

    static float CalculateTotalAllowances()
    {
        vector<clsEmployee> vEmployees = _LoadEmployeesDataFromMonthlyPayrollFile();
        int TotalAllowances = 0;

        for (clsEmployee& Employee : vEmployees)
        {
            TotalAllowances += Employee.GetAllowances();
        }

        return TotalAllowances;
    }
    
    static float CalculateTotalDeductions()
    {
        vector<clsEmployee> vEmployees = _LoadEmployeesDataFromMonthlyPayrollFile();
        int TotalDeductions = 0;

        for (clsEmployee& Employee : vEmployees)
        {
            TotalDeductions += Employee.GetDeductions();
        }

        return TotalDeductions;
    }

    static float CalculateTotalNetPayable()
    {
        vector<clsEmployee> vEmployees = _LoadEmployeesDataFromMonthlyPayrollFile();
        int TotalNetPayable = 0;

        for (clsEmployee& Employee : vEmployees)
        {
            TotalNetPayable += Employee.GetNetSalary();
        }

        return TotalNetPayable;
    }

    static int CalculateTotalDepartments()
    {
        vector<string> vDepartements = {"Security", "HR", "Finance and Accounting", "IT Operations", "Software Development", "UI/UX Design", "Sales and Marketing"};
        vector<clsEmployee> vEmployees = _LoadEmployeesDataFromFile();
        int CountDepartements = 0;
        
        for (string& Departement : vDepartements)
        {
            for (clsEmployee& Employee : vEmployees)
            {
                if (Employee.GetDepartement() == Departement)
                {
                    CountDepartements++;
                }
                
            }
        }
        
        return CountDepartements;
    }

    




};

class clsMainScreen
{
    protected:
    
        static void _DrawScreenHeader(string Title, string SubTitle)
        {
            cout << string(85,'=') << endl;
            cout << Title << endl;

            if (!SubTitle.empty())
            {
               cout << SubTitle << endl;
            }
        
            cout << string(85,'=') << endl;
        }
    
};

class clsEmployeesListScreen : protected clsMainScreen
{
private:
    static void _PrintEmployeeData(clsEmployee Employee)
    {
        cout << left << setw(15) << Employee.GetEmployeeID() << "|";
        cout << left << setw(25) << Employee.GetFullName() << "|";
        cout << left << setw(30) << Employee.GetJobTitle() << "|";
        cout << left << setw(12) << Employee.GetSalary()   << "|";
    }

public:
    static void ShowEmployeesList()
    {
        vector<clsEmployee> vEmployees = clsEmployee::GetEmployeesData();
        string Title = "\t\t\t\tEmployees List";
        string SubTitle = "\t\t\t\tTotal: " + to_string(vEmployees.size()) + " employee(s)";
        
        _DrawScreenHeader(Title, SubTitle);
        
        if (vEmployees.empty())
        {
            cout << "\n  No employees found.\n\n";
            return;
        }
        
        cout << "\n";
        cout << left << setw(15) << "Employee ID" << "|"
             << left << setw(25) << "Full Name" << "|"
             << left << setw(30) << "Job Title" << "|"
             << left << setw(12) << "Salary ($)" << "|" << endl;
        
        cout << string(85, '=') << endl;
        
        for (clsEmployee& Employee : vEmployees)
        {
            _PrintEmployeeData(Employee);
            cout << endl;
        }
        
        cout << string(85, '=') << endl;
    }
};

class clsAddNewEmployeeScreen: protected clsMainScreen
{
private:
   static void _ReadEmployeeInfo(clsEmployee& Employee)
   {
        cout <<"Enter FullName: ";
        Employee.SetFullName(clsInputValidate::ReadString());
        cout <<"Enter Country: ";
        Employee.SetCountry(clsInputValidate::ReadString());
        cout <<"Enter Departement: ";
        Employee.SetDepartement(clsInputValidate::ReadString());
        cout <<"Enter JobTitle: " ;
        Employee.SetJobTitle(clsInputValidate::ReadString());
        cout <<"Enter Salary: ";
        Employee.SetSalary(clsInputValidate::ReadDblNumber());
        cout <<"Enter Email: ";
        Employee.SetEmail(clsInputValidate::ReadString());
        cout <<"Enter Phone Number: ";
        Employee.SetPhoneNumber(clsInputValidate::ReadString());
        cout << endl;
   }
   
   static void _PrintEmployeeData(clsEmployee Employee)
   {
        cout << "\tNew Employee Info Card:"                          << endl;
        cout << "==========================================="        << endl;
        cout <<"Employee ID           : " << Employee.GetEmployeeID()<< endl;
        cout <<"FullName              : " << Employee.GetFullName()  << endl;
        cout <<"Country               : " << Employee.GetCountry()   << endl;
        cout <<"Departement           : " << Employee.GetDepartement() << endl;
        cout <<"JobTitle              : " << Employee.GetJobTitle() << endl;
        cout <<"Salary                : " << Employee.GetSalary()      << endl;
        cout <<"Email                : " << Employee.GetEmail()       << endl;
        cout <<"Phone Number          : " << Employee.GetPhoneNumber() << endl;
        cout << "===========================================" << endl;
   }

public:
    static void AddNewEmployee()
    {
        vector<clsEmployee> vEmployees = clsEmployee::GetEmployeesData();
       _DrawScreenHeader("\t\t\t\tAdd New Employee Screen", "");
       char Answer = 'Y';
       do
       {
            string EmployeeID = "";
            cout << "Please, Enter ID For New Employee: ";
            EmployeeID = clsInputValidate::ReadString();

            while (clsEmployee::IsEmployeeExistByEmployeeID(EmployeeID))
            {
                cout << "\nEmployee ID Is Already used, Choose antother one: ";
                EmployeeID = clsInputValidate::ReadString();
            }
       
            clsEmployee NewEmployee(EmployeeID, "", "", "", "", 0, "", "");
            NewEmployee.SetEmployeeID(EmployeeID);

            _ReadEmployeeInfo(NewEmployee);
            _PrintEmployeeData(NewEmployee);

            vEmployees.push_back(NewEmployee);
            clsEmployee::SaveEmployeesData(vEmployees);

            cout << "\nEmployee Added Successfully :-)" << endl;
            cout << "Do you want to Add More Employees Y/N?: ";
            cin  >> Answer;    
            cin.ignore();        

       } while (Answer == 'Y' || Answer == 'y');
    }
};

class clsUpdateEmployeeInformationsScreen: protected clsMainScreen
{
private:
   static void _ReadEmployeeInfo(clsEmployee& Employee)
   {
        cout << "\n\t\tEnter New Information:"                          << endl;
        cout << "============================================="         << endl;
        cout <<"Enter Departement: ";
        Employee.SetDepartement(clsInputValidate::ReadString());
        cout <<"Enter JobTitle: " ;
        Employee.SetJobTitle(clsInputValidate::ReadString());
        cout <<"Enter Salary: ";
        Employee.SetSalary(clsInputValidate::ReadDblNumber());
        cout <<"Enter Email: ";
        Employee.SetEmail(clsInputValidate::ReadString());
        cout <<"Enter Phone Number: ";
        Employee.SetPhoneNumber(clsInputValidate::ReadString());
        cout << endl;
   }
   
   static void _PrintEmployeeData(clsEmployee& Employee)
   {
        cout << "============================================="         << endl;
        cout <<" Employee ID           : " << Employee.GetEmployeeID()  << endl;
        cout <<" FullName              : " << Employee.GetFullName()    << endl;
        cout <<" Country               : " << Employee.GetCountry()     << endl;
        cout <<" Departement           : " << Employee.GetDepartement() << endl;
        cout <<" JobTitle              : " << Employee.GetJobTitle()    << endl;
        cout <<" Salary                : " << Employee.GetSalary()      << endl;
        cout <<" Phone Number          : " << Employee.GetPhoneNumber() << endl;
        cout <<" Email                 : " << Employee.GetEmail()       << endl;
        cout << "============================================="         << endl;
   }

public:
    static void UpdateEmployeeInformations()
    {
            vector<clsEmployee> vEmployees = clsEmployee::GetEmployeesData();
            _DrawScreenHeader("\t\t\t\tUpdate Employee Screen", "");
            string EmployeeID = "";
            cout << "Please, Enter Employee ID to Update: ";
            EmployeeID = clsInputValidate::ReadString();

            while (!clsEmployee::IsEmployeeExistByEmployeeID(EmployeeID))
            {
                cout << "\nEmployee ID Is NOT Found, Choose antother one: ";
                EmployeeID = clsInputValidate::ReadString();
            }
            
            bool found = false;
            for (clsEmployee& Employee : vEmployees)
            {
                if (Employee.GetEmployeeID() == EmployeeID)
                {
                    cout << "\n\tCurrent Employee Information:" << endl;
                    _PrintEmployeeData(Employee);
                    _ReadEmployeeInfo(Employee);
                    
                    clsEmployee::SaveEmployeesData(vEmployees);
                    
                    cout << "\n Employee Updated Successfully :-)" << endl;
                    cout << "\n\tUpdated Employee Information:" << endl;
                    _PrintEmployeeData(Employee);
                    found = true;
                    break;
                }
            }
            
            if (!found)
               cout << "\nEmployee NOT Found!\n";       
    }
};

class clsDeleteEmployeeScreen: protected clsMainScreen
{
private:
   static void _PrintEmployeeData(clsEmployee& Employee)
   {
        cout << "============================================="         << endl;
        cout <<" Employee ID           : " << Employee.GetEmployeeID()  << endl;
        cout <<" FullName              : " << Employee.GetFullName()    << endl;
        cout <<" Country               : " << Employee.GetCountry()     << endl;
        cout <<" Departement           : " << Employee.GetDepartement() << endl;
        cout <<" JobTitle              : " << Employee.GetJobTitle()    << endl;
        cout <<" Salary                : " << Employee.GetSalary()      << endl;
        cout <<" Phone Number          : " << Employee.GetPhoneNumber() << endl;
        cout <<" Email                 : " << Employee.GetEmail()       << endl;
        cout << "============================================="         << endl;
   }

public:
    static void DeleteEmployee()
    {
        vector<clsEmployee> vEmployees = clsEmployee::GetEmployeesData();
        _DrawScreenHeader("\t\t\t\tDelete Employee Screen", "");
        string EmployeeID = "";
        cout << "\nPlease, Enter Employee ID to Delete: ";
        EmployeeID = clsInputValidate::ReadString();

        while (!clsEmployee::IsEmployeeExistByEmployeeID(EmployeeID))
        {
            cout << "\nEmployee ID Is NOT Found, Choose antother one: ";
            EmployeeID = clsInputValidate::ReadString();
        }
        
        clsEmployee Employee = clsEmployee::FindEmployeeByEmployeeID(EmployeeID);
        _PrintEmployeeData(Employee);

        cout << "\nAre you sure Do you want to delete this Employee Y/N? ";
        char Answer = 'Y';
        cin >> Answer;
        cin.ignore();

        if (toupper(Answer) == 'Y')
        {
            if (clsEmployee::Delete(EmployeeID))
               cout << "\nEmployee deleted Successfully :-)" << endl; 

            else
              cout << "\nError Employee Is NOT Found!" << endl; 
        }

        else
            cout << "\nOperation cancelled.\n"; 
        
    }
    
};

class clsTotalEmployeesBalanceScreen: protected clsMainScreen
{
private:
   static void _PrintEmployeeData(clsEmployee Employee)
   {
        cout << "|" << Employee.GetEmployeeID();
        cout << "|" << Employee.GetFullName();
        cout << "|" << Employee.GetDepartement();
        cout << "|" << Employee.GetJobTitle();
        cout << "|" << Employee.GetSalary() << "|" << endl;
   }
public:

    static void ShowTotalEmployeesBalance()
    {
        vector<clsEmployee> vEmployees;
        _DrawScreenHeader("Total Employees Balance Screen", "");
        cout << "=============================================================================================" << endl;
        cout << "|" << left << setw(5) << "ID"                    ;
        cout << "|" << left << setw(30) << "Full Name"            ;
        cout << "|" << left << setw(20) << "Departement"          ;
        cout << "|" << left << setw(20) << "Job Position"         ;
        cout << "|" << left << setw(12) << "Salary" << "|" << endl;
        cout << "=============================================================================================" << endl;
        for (clsEmployee& Employee: vEmployees)
        {
            _PrintEmployeeData(Employee);
        }
        
        float TotalBalance = clsEmployee::CalculateTotalBalance();
        cout << "Total Balance of Employees is: " << TotalBalance << endl;
        cout << "( " << clsString::NumberToText(TotalBalance) << " )" << endl;    
    } 
};

class  clsSearchEmployeeScreen: protected clsMainScreen
{
private:
   static void _PrintEmployeeData(clsEmployee& Employee)
   {
        cout << "============================================="         << endl;
        cout <<" Employee ID           : " << Employee.GetEmployeeID()  << endl;
        cout <<" FullName              : " << Employee.GetFullName()    << endl;
        cout <<" Country               : " << Employee.GetCountry()     << endl;
        cout <<" Departement           : " << Employee.GetDepartement() << endl;
        cout <<" JobTitle              : " << Employee.GetJobTitle()    << endl;
        cout <<" Salary                : " << Employee.GetSalary()      << endl;
        cout <<" Phone Number          : " << Employee.GetPhoneNumber() << endl;
        cout <<" Email                 : " << Employee.GetEmail()       << endl;
        cout << "============================================="         << endl;
   }

public:
    static void  SearchEmployee()
    {
        vector<clsEmployee> vEmployees = clsEmployee::GetEmployeesData();
        _DrawScreenHeader("\t\t\t\tSearch Employee Screen", "");
        string EmployeeID = "";
        cout << "\nPlease, Enter Employee ID to Delete: ";
        EmployeeID = clsInputValidate::ReadString();

        while (!clsEmployee::IsEmployeeExistByEmployeeID(EmployeeID))
        {
            cout << "\nEmployee ID Is NOT Found, Choose antother one: ";
            EmployeeID = clsInputValidate::ReadString();
        }
        
        clsEmployee Employee = clsEmployee::FindEmployeeByEmployeeID(EmployeeID);
        _PrintEmployeeData(Employee);
        
        cout << "Employee Found Successfully :-)" << endl;
    }
    
};

class  clsCalculateMonthlyPayrollScreen: protected clsMainScreen
{
private:
   static void _PrintEmployeeMonthlyPayrollData(clsEmployee& Employee)
   {
        cout << left << setw(15) << Employee.GetEmployeeID() << "|";
        cout << left << setw(25) << Employee.GetFullName() << "|";
        cout << left << setw(15) << Employee.GetBasicSalary() << "|";
        cout << left << setw(15) << Employee.GetAllowances()   << "|";
        cout << left << setw(15) << Employee.GetDeductions()   << "|";
        cout << left << setw(15) << Employee.GetNetSalary() << "|" << endl;
   }

   static void _SaveEmployeesDataToPayrollReportsFile(string& Line)
    {
        fstream MyFile;
        MyFile.open("PayrollReports.txt", ios::out);

        if (MyFile.is_open())
        {
            string DataLine = Line;
            MyFile << DataLine << endl;

            MyFile.close();
        }
    }
  
public:
    static void  CalculateMonthlyPayroll()
    {
        vector<clsEmployee> vEmployees = clsEmployee::GetEmployeesData();
        _DrawScreenHeader("\t\t\t\tCalculate Monthly Payroll", "");
   
        cout << string(105, '=') << endl;
        cout << "\t\t\t\tMonthly Payroll Report" << endl;
        cout << string(105, '=') << endl;
        cout << "\tGenerated on: " << clsDate::GetSystemDateTimeString();

        if (vEmployees.empty())
        {
            cout << "\n  No Employee Monthly Payroll available in the system!  .\n\n";
            return;
        }
        
        cout << "\n";
        cout << string(105, '=') << endl;
        cout << left << setw(15) << "Employee ID" << "|"
        << left << setw(25) << "Full Name" << "|"
        << left << setw(15) << "Basic Salary " << "|"
        << left << setw(15) << "Allowances " << "|"
        << left << setw(15) << "Deductions " << "|"
        << left << setw(15) << "Net Salary "<< "|" << endl;
        
        cout << string(105, '=') << endl;
        
        for (clsEmployee& Employee : vEmployees)
        {
            _PrintEmployeeMonthlyPayrollData(Employee);
            cout << endl;
        }
        

        cout << string(105, '=') << endl;
        string Line = "", Separator = "#//#";
        cout << "=== Summary ===" << endl;
        cout << "Total Employees: " << clsEmployee::CalculateTotalEmployees() << endl;
        Line += to_string(clsEmployee::CalculateTotalEmployees()) + Separator;
        cout << "Total Gross Salary: $" << clsEmployee::CalculateTotalGrossSalary() << endl;
        Line += to_string(clsEmployee::CalculateTotalGrossSalary()) + Separator;
        cout << "Total Allowances: $" << clsEmployee::CalculateTotalAllowances() << endl;
        Line += to_string(clsEmployee::CalculateTotalAllowances()) + Separator;
        cout << "Total Deductions: $" << clsEmployee::CalculateTotalDeductions() << endl;
        Line += to_string(clsEmployee::CalculateTotalDeductions()) + Separator;
        cout << "Total Net Payable: $" << clsEmployee::CalculateTotalNetPayable() << endl;
        Line += to_string(clsEmployee::CalculateTotalNetPayable()) + Separator + clsDate::GetSystemDateTimeString();
          
        cout << "Do you want to save this report to file? (Y/N): ";
        char Answer = 'Y';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            _SaveEmployeesDataToPayrollReportsFile(Line);
            cout << "Report Saved Successfully :-)" << endl;
        }
    }

};

class  clsSetSalaryDeductionsScreen: protected clsMainScreen
{
private:
  static void _PrintEmployeeData(clsEmployee& Employee)
   {
        cout << "============================================="         << endl;
        cout <<" Employee ID           : " << Employee.GetEmployeeID()  << endl;
        cout <<" FullName              : " << Employee.GetFullName()    << endl;
        cout <<" Departement           : " << Employee.GetDepartement() << endl;
        cout <<" JobTitle              : " << Employee.GetJobTitle()    << endl;
        cout <<" Base Salary           : " << Employee.GetBasicSalary()  << endl;
        cout << "============================================="         << endl;
   }
   
   static float _CalculateEmployeeTax(float TaxPercentage, float BaseSalary)
   {
        return (TaxPercentage * BaseSalary) / 100;
   }
   
   static float _CalculateEmployeeInsurance(float InsurancePercentage, float BaseSalary)
   {
        return (InsurancePercentage * BaseSalary) / 100;
   }


public:
    static void  SetSalaryDeductions()
    {
       vector<clsEmployee> vEmployees = clsEmployee::GetEmployeesMonthlyPayrollData();
        _DrawScreenHeader("\t\t\t\tSalary Deducations Screen", "");
        string EmployeeID = "";
        cout << "Please, Enter Employee ID: ";
        EmployeeID = clsInputValidate::ReadString();

        while (!clsEmployee::IsEmployeeExistByEmployeeID(EmployeeID))
        {
            cout << "\nEmployee ID Is NOT Found, Choose antother one: ";
            EmployeeID = clsInputValidate::ReadString();
        }
        
        clsEmployee Employee = clsEmployee::FindEmployeeByEmployeeID(EmployeeID);

        float TaxDeduction = _CalculateEmployeeTax(13, Employee.GetBasicSalary());
        float InsuranceDeduction = _CalculateEmployeeInsurance(3, Employee.GetBasicSalary());

        cout << "Enter Late Penalty Amount: ";
        float LatePenalty = clsInputValidate::ReadDblNumberBetween(0,Employee.GetBasicSalary(),"Enter Again! ");

        cout << "Enter Other Deductions Amount: ";
        float OtherDeductions = clsInputValidate::ReadDblNumberBetween(0,Employee.GetBasicSalary(),"Enter Again! ");

        float TotalDeductions = TaxDeduction + OtherDeductions + LatePenalty + InsuranceDeduction;
        Employee.SetNetSalary(Employee.GetBasicSalary() - TotalDeductions);

        _PrintEmployeeData(Employee);
        cout << "----------------------------------------"             << endl;
        cout << "TaxDeduction        :" << TaxDeduction << "$"         << endl;
        cout << "Insurance           :" << InsuranceDeduction << "$"   << endl;
        cout << "Late Penalty        :" << LatePenalty << "$"          << endl;
        cout << "Other Deductions    :" << OtherDeductions << "$"      << endl;
        cout << "Total Deductions    :" << OtherDeductions << "$"      << endl; 
        cout << "----------------------------------------"             << endl;
        cout << "Salary Dudecations completed successfully :-)"        << endl;
    }
    
};

class  clsCalculateBonusesScreen: protected clsMainScreen
{
private:
   static void _PrintEmployeeData(clsEmployee& Employee)
   {
        cout << "============================================="         << endl;
        cout <<" Employee ID           : " << Employee.GetEmployeeID()  << endl;
        cout <<" FullName              : " << Employee.GetFullName()    << endl;
        cout <<" Departement           : " << Employee.GetDepartement() << endl;
        cout <<" JobTitle              : " << Employee.GetJobTitle()    << endl;
        cout <<" Base Salary           : " << Employee.GetBasicSalary()  << endl;
        cout << "============================================="         << endl;
   }
   
   static float _CalculateEmployeeBonus(float BonusPercentage, float BaseSalary)
   {
        return (BonusPercentage * BaseSalary) / 100;
   }
   
public:
    static void  CalculateBonuses()
    {
        vector<clsEmployee> vEmployees = clsEmployee::GetEmployeesMonthlyPayrollData();
        _DrawScreenHeader("\t\t\t\tCalculate Employee Bonus Screen", "");
        string EmployeeID = "";
        cout << "Please, Enter Employee ID to Update: ";
        EmployeeID = clsInputValidate::ReadString();

        while (!clsEmployee::IsEmployeeExistByEmployeeID(EmployeeID))
        {
            cout << "\nEmployee ID Is NOT Found, Choose antother one: ";
            EmployeeID = clsInputValidate::ReadString();
        }
        
        clsEmployee Employee = clsEmployee::FindEmployeeByEmployeeID(EmployeeID);
        cout << "Enter Bonus Percentage between(0% To 100%): ";
        float BonusPercentage = clsInputValidate::ReadDblNumberBetween(0, 100, "Enter Bonus Percentage between(0% To 100%): ");
        float BonusAmount = _CalculateEmployeeBonus(BonusPercentage, Employee.GetBasicSalary());
        float TotalSalary = Employee.GetBasicSalary() + BonusAmount;

        _PrintEmployeeData(Employee);
        cout << "----------------------------------------"             << endl;
        cout << "Bonus Percentage         :" << BonusPercentage << "%" << endl;
        cout << "Bonus Percentage         :" << BonusAmount << "$"     << endl;
        cout << "Total Salary After Bonus :" << TotalSalary << "$"     << endl;
        cout << "----------------------------------------"             << endl;
        cout << "Bonus calculation completed successfully :-)"         << endl;
    }
    
};

class  clsTaxCalculationsScreen: protected clsMainScreen
{
private:
  static void _PrintEmployeeData(clsEmployee& Employee)
   {
        cout << "============================================="         << endl;
        cout <<" Employee ID           : " << Employee.GetEmployeeID()  << endl;
        cout <<" FullName              : " << Employee.GetFullName()    << endl;
        cout <<" Departement           : " << Employee.GetDepartement() << endl;
        cout <<" JobTitle              : " << Employee.GetJobTitle()    << endl;
        cout <<" Base Salary           : " << Employee.GetBasicSalary()  << endl;
        cout << "============================================="         << endl;
   }
   
   static float _CalculateEmployeeTax(float TaxPercentage, float BaseSalary)
   {
        return (TaxPercentage * BaseSalary) / 100;
   }

public:
    static void  TaxCalculations()
    {
        vector<clsEmployee> vEmployees = clsEmployee::GetEmployeesMonthlyPayrollData();
        _DrawScreenHeader("\t\t\t\tCalculate Employee Bonus Screen", "");
        string EmployeeID = "";
        cout << "Please, Enter Employee ID to Update: ";
        EmployeeID = clsInputValidate::ReadString();

        while (!clsEmployee::IsEmployeeExistByEmployeeID(EmployeeID))
        {
            cout << "\nEmployee ID Is NOT Found, Choose antother one: ";
            EmployeeID = clsInputValidate::ReadString();
        }
        
        clsEmployee Employee = clsEmployee::FindEmployeeByEmployeeID(EmployeeID);
        cout << "Enter Tax Percentage between(0% To 100%): ";
        float TaxPercentage = clsInputValidate::ReadDblNumberBetween(0, 100, "Enter Tax Percentage between(0% To 100%): ");
        float TaxAmount = _CalculateEmployeeTax(TaxPercentage, Employee.GetBasicSalary());
        float TotalSalary = Employee.GetBasicSalary() - TaxAmount;
        Employee.SetNetSalary(TotalSalary);

        _PrintEmployeeData(Employee);
        cout << "----------------------------------------"             << endl;
        cout << "Tax Percentage         :" << TaxPercentage << "%"     << endl;
        cout << "Tax Percentage         :" << TaxAmount << "$"         << endl;
        cout << "Total Salary After Tax :" << TotalSalary << "$"       << endl;
        cout << "----------------------------------------"             << endl;
        cout << "Tax calculation completed successfully :-)"           << endl;
    }
    
};

class  clsSalaryPayrollManagementScreen: protected clsMainScreen
{
private:
   enum enSalaryPayrollManagementOptions {enCalculateMonthlyPayroll = 1, 
    enSetSalaryDeductions = 2, enCalculateBonuses = 3, enTaxCalculations = 4,
        enBackToMainMenu = 5};

    static int _ReadChoice()
    {
        cout << "Choose what do you want to do? [1 to 5]? ";
        int Choice = clsInputValidate::ReadIntNumberBetween(1,5,"Enter Number between 1 to 5? ");
        return Choice;
    }
    
    static void _GoBackToMainMenu()
    {
        cout << "\nPress any Key to Go Back to Main Menu Screen..." << endl;
        system("pause>0");
    }

    static void _GoBackToSalaryPayrollManagement()
    {
        cout << "\nPress any Key to Go Back to Salary Payroll Management Screen..." << endl;
        system("pause>0");
        ShowSalaryPayrollManagementScreen();
    }
    
    static void _ShowCalculateMonthlyPayrollScreen()
    {
        clsCalculateMonthlyPayrollScreen::CalculateMonthlyPayroll();
    }
    
    static void _ShowSetSalaryDeductionsScreen()
    {
        clsSetSalaryDeductionsScreen::SetSalaryDeductions();
    }

    static void _ShowCalculateBonusesScreen()
    {
        clsCalculateBonusesScreen::CalculateBonuses();
    }

    static void  _ShowTaxCalculationsScreen()
    {
        clsTaxCalculationsScreen::TaxCalculations();
    }

    static void _PerformSalaryPayrollManagementOptions(enSalaryPayrollManagementOptions Choice)
    {
        switch (Choice)
        {
        case enSalaryPayrollManagementOptions::enCalculateMonthlyPayroll:
        {
            system("cls");
            _ShowCalculateMonthlyPayrollScreen();
            _GoBackToSalaryPayrollManagement();
            break;
        }

        case enSalaryPayrollManagementOptions::enSetSalaryDeductions:
        {
            system("cls");
            _ShowSetSalaryDeductionsScreen();
            _GoBackToSalaryPayrollManagement();
            break;
        }

        case enSalaryPayrollManagementOptions::enCalculateBonuses:
        {
            system("cls");
            _ShowCalculateBonusesScreen();
            _GoBackToSalaryPayrollManagement();
            break;
        }

        case enSalaryPayrollManagementOptions::enTaxCalculations:
        {
            system("cls");
            _ShowTaxCalculationsScreen();
            _GoBackToSalaryPayrollManagement();
            break;
        }

        case enSalaryPayrollManagementOptions::enBackToMainMenu:
        {
            system("cls");
            break;
        }

           
        default:
            break;
        }
    }

public:
    static void ShowSalaryPayrollManagementScreen()
    {
       system("cls");
       cout << "==================================================================" << endl;
       cout << "\t\t\t Salary & Payroll Management Screen                         " << endl;
       cout << "==================================================================" << endl;
       cout << "\t[1] Calculate Monthly Payroll                                   " << endl;
       cout << "\t[2] Set Salary Deductions                                       " << endl;
       cout << "\t[3] Calculate Bonuses                                           " << endl;
       cout << "\t[4] Tax Calculations                                            " << endl;
       cout << "\t[5] Back to Main Menu                                           " << endl;
       cout << "==================================================================" << endl;
       
       _PerformSalaryPayrollManagementOptions((enSalaryPayrollManagementOptions) _ReadChoice());
    } 

};

class clsPerformanceEvaluationScreen : protected clsMainScreen
{
private:
    struct stEvaluation
    {
        string EmployeeID;
        string FullName;
        string Department;
        string Position;
        float WorkQuality;
        float Productivity;
        float Teamwork;
        float Communication;
        float ProblemSolving;
        float OverallRating;
        string Comments;
    };
    
    static float _CalculateOverallRating(float WorkQuality, float Productivity, 
                                         float Teamwork, float Communication, 
                                         float ProblemSolving)
    {
        return (WorkQuality + Productivity + Teamwork + Communication + ProblemSolving) / 5;
    }
    
    static string _GetRatingText(float Rating)
    {
        if (Rating >= 4.5) return "Excellent";
        else if (Rating >= 3.5) return "Good";
        else if (Rating >= 2.5) return "Average";
        else if (Rating >= 1.5) return "Below Average";
        else return "Needs Improvement";
    }
    
    static void _PrintEvaluationCard(stEvaluation Eval)
    {
        cout << "\n=============================================" << endl;
        cout << "         EMPLOYEE PERFORMANCE EVALUATION       " << endl;
        cout << "=============================================" << endl;
        cout << "Employee ID     : " << Eval.EmployeeID << endl;
        cout << "Full Name       : " << Eval.FullName << endl;
        cout << "Department      : " << Eval.Department << endl;
        cout << "Position        : " << Eval.Position << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Evaluation Criteria    | Rating (1-5) | Status" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Work Quality           | " << setw(10) << Eval.WorkQuality << " | " << _GetRatingText(Eval.WorkQuality) << endl;
        cout << "Productivity           | " << setw(10) << Eval.Productivity << " | " << _GetRatingText(Eval.Productivity) << endl;
        cout << "Teamwork               | " << setw(10) << Eval.Teamwork << " | " << _GetRatingText(Eval.Teamwork) << endl;
        cout << "Communication          | " << setw(10) << Eval.Communication << " | " << _GetRatingText(Eval.Communication) << endl;
        cout << "Problem Solving        | " << setw(10) << Eval.ProblemSolving << " | " << _GetRatingText(Eval.ProblemSolving) << endl;
        cout << "---------------------------------------------" << endl;
        cout << "OVERALL RATING         | " << setw(10) << Eval.OverallRating << " | " << _GetRatingText(Eval.OverallRating) << endl;
        cout << "=============================================" << endl;
    }
    
    static void _PrintEmployeeListHeader()
    {
        cout << "\n";
        cout << left << setw(15) << "Employee ID" << "|"
             << left << setw(25) << "Full Name" << "|"
             << left << setw(20) << "Department" << "|"
             << left << setw(25) << "Job Title" << "|" << endl;
        cout << string(85, '-') << endl;
    }
    
    static void _PrintEmployeeRow(clsEmployee Employee)
    {
        cout << left << setw(15) << Employee.GetEmployeeID() << "|"
             << left << setw(25) << Employee.GetFullName() << "|"
             << left << setw(20) << Employee.GetDepartement() << "|"
             << left << setw(25) << Employee.GetJobTitle() << "|" << endl;
    }

public:

    static void PerformanceEvaluation()
    {
        _DrawScreenHeader("\t\t\tEmloyee Performance Evaluation", "");
        
        vector<clsEmployee> vEmployees = clsEmployee::GetEmployeesData();
        
        if (vEmployees.empty())
        {
            cout << "\n  No employees found in the system.\n\n";
            return;
        }
        
        cout << "\nSelect Employee to Evaluate:\n";
        _PrintEmployeeListHeader();
        
        for (clsEmployee& Employee : vEmployees)
        {
            _PrintEmployeeRow(Employee);
        }
        
        cout << "\n" << string(85, '-') << endl;
        
        string EmployeeID;
        cout << "\nEnter Employee ID to evaluate: ";
        EmployeeID = clsInputValidate::ReadString();
        
        bool found = false;
        for (clsEmployee& Employee : vEmployees)
        {
            if (Employee.GetEmployeeID() == EmployeeID)
            {
                found = true;
                stEvaluation Eval;
                
                Eval.EmployeeID = Employee.GetEmployeeID();
                Eval.FullName = Employee.GetFullName();
                Eval.Department = Employee.GetDepartement();
                Eval.Position = Employee.GetJobTitle();
                
                cout << "\nEnter Evaluation Ratings (1-5):\n";
                cout << "================================\n";
                
                cout << "Work Quality (1-5): ";
                Eval.WorkQuality = clsInputValidate::ReadDblNumberBetween(1, 5, "Please enter a number between 1 and 5: ");
                
                cout << "Productivity (1-5): ";
                Eval.Productivity = clsInputValidate::ReadDblNumberBetween(1, 5, "Please enter a number between 1 and 5: ");
                
                cout << "Teamwork (1-5): ";
                Eval.Teamwork = clsInputValidate::ReadDblNumberBetween(1, 5, "Please enter a number between 1 and 5: ");
                
                cout << "Communication (1-5): ";
                Eval.Communication = clsInputValidate::ReadDblNumberBetween(1, 5, "Please enter a number between 1 and 5: ");
                
                cout << "Problem Solving (1-5): ";
                Eval.ProblemSolving = clsInputValidate::ReadDblNumberBetween(1, 5, "Please enter a number between 1 and 5: ");
                
                Eval.OverallRating = _CalculateOverallRating(Eval.WorkQuality, Eval.Productivity, 
                                                              Eval.Teamwork, Eval.Communication, 
                                                              Eval.ProblemSolving);
                
                system("cls");
                _PrintEvaluationCard(Eval);
            }
        }
        
        if (!found)
        {
            cout << "\nEmployee with ID '" << EmployeeID << "' not found!\n";
        }
    }
};

class  clsReportsStatisticsScreen: protected clsMainScreen
{
private:
      
    static float _AverageSalary()
    {
       return clsEmployee::CalculateTotalGrossSalary()/clsEmployee::CalculateTotalEmployees();
    }
    
    static float _HighestSalary()
    {
        vector<clsEmployee> vEmployees = clsEmployee::GetEmployeesMonthlyPayrollData(); 
        float HighestSalary = vEmployees[0].GetBasicSalary();
        for (clsEmployee& Employee : vEmployees)
        {
            if (Employee.GetBasicSalary() > HighestSalary)
            {
                HighestSalary = Employee.GetBasicSalary();
            }
        }
        
        return HighestSalary;
    }

    static float _LowestSalary()
    {
        vector<clsEmployee> vEmployees = clsEmployee::GetEmployeesMonthlyPayrollData(); 
        float LowestSalary = vEmployees[0].GetBasicSalary();
        for (clsEmployee& Employee : vEmployees)
        {
            if (Employee.GetBasicSalary() < LowestSalary)
            {
                LowestSalary = Employee.GetBasicSalary();
            }
        }
        
        return LowestSalary;
    }

    static float _LowSalaryPercentage()
    {
        vector<clsEmployee> vEmployees = clsEmployee::GetEmployeesMonthlyPayrollData(); 
        int CountEmployees = 0;
        for (clsEmployee& Employee : vEmployees)
        {
            if (Employee.GetBasicSalary() < 50000)
            {
                CountEmployees++;
            }
        }
        
        return (CountEmployees * 100) / clsEmployee::CalculateTotalEmployees();
    }

    static float _MediumSalaryPercentage()
    {
        vector<clsEmployee> vEmployees = clsEmployee::GetEmployeesMonthlyPayrollData(); 
        int CountEmployees = 0;
        for (clsEmployee& Employee : vEmployees)
        {
            if (Employee.GetBasicSalary() >= 50000 && Employee.GetBasicSalary() < 70000)
            {
                CountEmployees++;
            }
        }
        
        return (CountEmployees * 100) / clsEmployee::CalculateTotalEmployees();
    }

    static float _HighSalaryPercentage()
    {
        vector<clsEmployee> vEmployees = clsEmployee::GetEmployeesMonthlyPayrollData(); 
        int CountEmployees = 0;
        for (clsEmployee& Employee : vEmployees)
        {
            if (Employee.GetBasicSalary() > 70000)
            {
                CountEmployees++;
            }
        }
        
        return (CountEmployees * 100) / clsEmployee::CalculateTotalEmployees();
    }

public:
    static void  ReportsStatistics()
    {
        _DrawScreenHeader("\t\t\t\tReports & Statistics Screen", "");
        cout << string(85,'=') << endl;
        cout << "Total Employees: " << clsEmployee::CalculateTotalEmployees()    << endl; 
        cout << "Departments    : " << clsEmployee::CalculateTotalDepartments()  << endl;
        cout << "Average Salary : $" << _AverageSalary()                         << endl;
        cout << "Highest Salary : $" << _HighestSalary()                         << endl;
        cout << "Lowest Salary  : $" << _LowestSalary()                          << endl;
        cout << endl<< "Salary Distribution: "                                   << endl;
        cout << "Low (<$50K)     : " << _LowSalaryPercentage()  << "%"           << endl;
        cout << "Medium ($50-70K): " << _MediumSalaryPercentage() << "%"         << endl;
        cout << "High (>$70K)    : " << _HighSalaryPercentage() << "%"           << endl;
        cout << string(85,'=') << endl;
    }

};

class clsMainMenuScreen
{
private:
    enum enMainMenuOptions {enEmployeesList = 1, enAddNewEmployee = 2, enUpdateEmployeeInfo = 3, enDeleteEmployee = 4,
        enSearchEmployee = 5, enSalaryPayrollManagement = 6, enPerformanceEvaluation = 7, enReportsStatistics = 8, enExit = 9};

    static int _ReadChoice()
    {
        cout << "Choose what do you want to do? [1 to 9]? ";
        int Choice = clsInputValidate::ReadIntNumberBetween(1,9,"Enter Number between 1 to 9? ");
        return Choice;
    }
    
    static void _GoBackToMainMenu()
    {
        cout << "\nPress any Key to Go Back to Main Menu Screen..." << endl;
        system("pause>0");
        ShowMainMenuScreen();
    }
    
    static void _ShowEmployeesListScreen()
    {
        clsEmployeesListScreen::ShowEmployeesList();
    }
    
    static void _ShowAddNewEmployeeScreen()
    {
        clsAddNewEmployeeScreen::AddNewEmployee();
    }

    static void _ShowUpdateEmployeeInformationsScreen()
    {
        clsUpdateEmployeeInformationsScreen::UpdateEmployeeInformations();
    }

    static void _ShowDeleteEmployeeScreen()
    {
        clsDeleteEmployeeScreen::DeleteEmployee();
    }

    static void  _ShowSearchEmployeeScreen()
    {
        clsSearchEmployeeScreen::SearchEmployee();
    }

    static void _ShowSalaryPayrollManagementScreen()
    {
        clsSalaryPayrollManagementScreen::ShowSalaryPayrollManagementScreen();
    }

    static void _ShowPerformanceEvaluationScreen()
    {
        clsPerformanceEvaluationScreen::PerformanceEvaluation();
    }

    static void _ShowReportsStatisticsScreen()
    {
        clsReportsStatisticsScreen::ReportsStatistics();
    }

    static void _PerformMainMenuOptions(enMainMenuOptions Choice)
    {
        switch (Choice)
        {
        case enMainMenuOptions::enEmployeesList:
        {
            system("cls");
            _ShowEmployeesListScreen();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenuOptions::enAddNewEmployee:
        {
            system("cls");
            _ShowAddNewEmployeeScreen();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenuOptions::enUpdateEmployeeInfo:
        {
            system("cls");
            _ShowUpdateEmployeeInformationsScreen();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenuOptions::enDeleteEmployee:
        {
            system("cls");
            _ShowDeleteEmployeeScreen();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenuOptions::enSearchEmployee:
        {
            system("cls");
            _ShowSearchEmployeeScreen();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenuOptions::enSalaryPayrollManagement:
        {
            system("cls");
            _ShowSalaryPayrollManagementScreen();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenuOptions::enPerformanceEvaluation:
        {
            system("cls");
            _ShowPerformanceEvaluationScreen();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenuOptions::enReportsStatistics:
        {
            system("cls");
            _ShowReportsStatisticsScreen();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenuOptions::enExit:
        {
            system("cls");
            cout << "thank you for using our Employees Management System :-)" << endl;
            cout << "Goodbye!" << endl;
            _GoBackToMainMenu();
            break;
        }
           
        default:
            break;
        }
    }

public:

    static void ShowMainMenuScreen()
    {
       system("cls");
       cout << "==================================================================" << endl;
       cout << "\t\t\t Employees Management System                                " << endl;
       cout << "==================================================================" << endl;
       cout << "\t[1] View All Employees                                          " << endl;
       cout << "\t[2] Add New Employee                                            " << endl;
       cout << "\t[3] Update Employee Information                                 " << endl;
       cout << "\t[4] Delete Employee                                             " << endl;
       cout << "\t[5] Search Employee                                             " << endl;
       cout << "\t[6] Salary & Payroll Management                                 " << endl;
       cout << "\t[7] Performance Evaluation                                      " << endl;
       cout << "\t[8] Reports & Statistics                                        " << endl;
       cout << "\t[9] Exit                                                        " << endl;
       cout << "==================================================================" << endl;
       
       _PerformMainMenuOptions((enMainMenuOptions) _ReadChoice());
    }
};

int main()
{
    while (true)
    {
        clsMainMenuScreen:: ShowMainMenuScreen();
    }
    
    
    return 0;
}