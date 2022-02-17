#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N =1e5+5;

int number,year,month,day,num,money,tmpmoney,months[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
bool yes,cur,valid;
string s,name,password,pass;
string monthstr[]={"n","January","February","Mars","April","May","June",
                          "Julie","August","September","November","December"};


pair<ll,bool> str_to_int(string s) {
    ll ret = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            return {0,0};
        }
        ret = ret * 10 + s[i] - '0';
        if(ret>=1000000000) return {0,0};
    }
    return {ret,1};
}

void check() {
    system("CLS");
    cout << "Enter account number" << endl;
    cin >> num;
    if (!a[num].valid) {
        cout << "Account number is not valid" << endl;
        cur = 0;
        return;
    }
    cout << "Enter account password" << endl;
    cin >> pass;
    if (a[num].password != pass) {
        cout << "Account password is not valid" << endl;
        cur = 0;
        return;
    }
    _sleep(1000);
}


void create() {
    system("CLS");
    ifstream clientsin;
    clientsin.open("data.txt");
    string tmp,tmp2;
    nu:
    cout<<"Enter account number"<<endl;
    cin>>s;
    if(str_to_int(s).second==0){
        cout<<"Account number must be a positive integer less than 1000000000"<<endl;
        goto nu;
    }
    num=str_to_int(s).first;

    while(getline(clientsin,tmp)){
        tmp2="";
        for(auto x:tmp){
            if(x==' ') break;
            tmp+=x;
        }
        if(s==tmp2){
            cout<<"There is another account with this account number"<<endl;
            _sleep(1000);
            goto nu;
        }
    }
    clientsin.close();

    n:
    cout << "Enter your name" << endl;
    cin >> name;
    for(int i=0;i<name.size();i++){
        if(!(name[i]>='A' && name[i]<='Z')
        && !(name[i]>='a' && name[i]<='z')){
            cout<<"Account name must have only latin letters"<<endl;
            _sleep(1000);
            goto n;
        }
    }

    cout << "Enter a password" << endl;
    cin >> password;

    y:
    cout << "Enter your birth year" << endl;
    cin>>s;
    if(str_to_int(s).second==0){
        cout<<"Year must be integer"<<endl;
        _sleep(1000);
        goto d;
    }
    year=str_to_int(s).first;
    if (year > 2010 || year < 1900) {
        cout << "Year must be between 1900 and 2010" << endl;
        _sleep(1000);
        goto y;
    }

    m:
    cout << "Enter your birth month" << endl;
    cin>>s;
    if(str_to_int(s).second==0){
        cout<<"Month must be integer"<<endl;
        _sleep(1000);
        goto m;
    }
    month=str_to_int(s).first;

    if (month > 12 || month < 1) {
        cout << "Month must be between 1 and 12" << endl;
        _sleep(1000);
        goto m;
    }

    d:
    cout << "Enter your birth day" << endl;
    cin>>s;
    if(str_to_int(s).second==0){
        cout<<"Day must be integer"<<endl;
        _sleep(1000);
        goto d;
    }
    day=str_to_int(s).first;

    if (day > months[month] || (day > 28 && month == 2 && year % 4 == 0)) {
        cout << "This day is not valid in "<<monthstr[month] << endl;
        _sleep(1000);
        goto d;
    }

    de:
    cout << "Enter amount of money to deposit" << endl;
    cin>>s;
    if(str_to_int(s).second==0){
        cout<<"Amount of money must be a positive integer less than 1000000000"<<endl;
        _sleep(1000);
        goto de;
    }
    tmpmoney=str_to_int(s).first;
    money += tmpmoney;
    cout << "Account is created" << endl;
    ofstream clientsout;
    clientsout.open("data.txt",ios::app);
    clientsout<<number<<" "<<password<<" "<<name<<" "<<money<<" "<<year<<" "<<month<<" "<<day<<endl;
    _sleep(1000);

}

void withdraw() {
    check();
    if (!cur) return;
    w:
    cout << "Enter amount of money to withdraw" << endl;
    string s;
    cin>>s;
    if(str_to_int(s).second==0){
        cout<<"Amount of money must be a positive integer less than 1000000000"<<endl;
        goto w;
    }
    money=str_to_int(s).first;

    if (a[num].money < money) {
        cout << "Account money is not enough" << endl;
        goto w;
    }
    a[num].money -= money;
    cout << "Successful withdraw" << endl;
    cout << "Your current money : " << a[num].money << endl;
    _sleep(1000);
}

void deposit() {
    check();
    if (!cur) return;
    d:
    cout << "Enter amount of money to deposit" << endl;
    string s;
    cin>>s;
    if(str_to_int(s).second==0){
        cout<<"Amount of money must be a positive integer less than 1000000000"<<endl;
        goto d;
    }
    money=str_to_int(s).first;

    a[num].money += money;
    cout << "Successful deposit" << endl;
    cout << "Your current money : " << a[num].money << endl;
    _sleep(1000);
}

void show() {
    check();
    if (!cur) return;
    cout << "Account name: " << a[num].name << endl;
    cout << "Account password: " << a[num].password << endl;
    cout << "Account number: " << a[num].number << endl;
    cout << "Account money: " << a[num].money << endl;
    _sleep(1000);
}


void change(){
    check();
    if(!cur) return;
    cout<<"If you want to change account name enter 1"<<endl;
    cin>>s;
    if(s=="1"){
        n:
        cout<<"Enter new account name"<<endl;
        cin >> a[num].name;
        for(int i=0;i<a[num].name.size();i++){
        if(!(a[num].name[i]>='A' && a[num].name[i]<='Z')
        && !(a[num].name[i]>='a' && a[num].name[i]<='z')){
            cout<<"Account name must have only latin letters"<<endl;
            goto n;
        }
    }
        cout<<"Account name is updated"<<endl;
    }

    cout<<"If you want to change account password enter 2"<<endl;
    cin>>s;
    if(s=="2"){
        cout<<"Enter new account password"<<endl;
        cin>>s;
        a[num].password=s;
        cout<<"Account password is updated"<<endl;

    }

    cout<<"If you want to change account birth day enter 3"<<endl;
    cin>>s;
    if(s=="3") {
        y:
        cout << "Enter your birth year" << endl;
        cin >> a[id].year;
        if (a[id].year > 2010 || a[id].year < 1900) {
            cout << "Year must be integer between 1900 and 2010" << endl;
            goto y;
        }

        m:
        cout << "Enter your birth month" << endl;
        cin >> a[id].month;
        if (a[id].month > 12 || a[id].month < 1) {
            cout << "Month must be integer between 1 and 12" << endl;
            goto m;
        }

        d:
        cout << "Enter your birth day" << endl;
        cin >> a[id].day;
        if (a[id].day > months[a[id].month] || (a[id].day > 28 && a[id].month == 2 && a[id].year % 4 == 0)) {
            cout << "This day is not valid in "<<monthstr[a[id].month] << endl;
            goto d;
        }
        cout<<"Birth day is updated"<<endl;
    }
    cout<<"Changes are done"<<endl;
    _sleep(1000);
}

void del(){
    check();
    if(!cur) return;
    a[num].valid=0;
    cout<<"Account is deleted"<<endl;
    _sleep(1000);
}

//#define endl "\n"
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("triangles.in","r",stdin);
    //memset(dp,-1,sizeof dp);
    yes=1;
    while(yes){
        system("CLS");
        cur=1;
        cout<<"Welcome to our bank"<<endl;
        cout<<"Please enter your choice"<<endl;
        cout<<"1 - Create new account"<<endl;
        cout<<"2 - Withdraw money"<<endl;
        cout<<"3 - Deposit money"<<endl;
        cout<<"4 - Show account information"<<endl;
        cout<<"5 - Change account information"<<endl;
        cout<<"6 - Delete account"<<endl;
        cout<<"7 - Exit"<<endl;
        string c;
        cin>>c;
        if(c=="1") create();
        else if(c=="2") withdraw();
        else if(c=="3") deposit();
        else if(c=="4") show();
        else if(c=="5") change();
        else if(c=="6") del();
        else if(c=="7") yes=0;
        else cout<<"Invalid entry"<<endl;
        cout<<"Thanks for using our bank"<<endl<<endl<<endl<<endl;
        _sleep(1000);
    }

    return 0;
}
