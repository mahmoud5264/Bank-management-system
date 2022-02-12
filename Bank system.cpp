#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
int di[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dj[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const ll N =1e5+5 , M = 505 , MOD = 998244353 , oo = 1e18;

struct client{
    string name,password;
    int number,money,year,month,day;
    bool valid;
}a[N];

int id,num,money,months[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};
bool yes,cur;
string pass;


void check() {
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
}

void withdraw() {
    check();
    if (!cur) return;
    w1:
    cout << "Enter amount of money to withdraw" << endl;
    cin >> money;
    if (a[num].money < money) {
        cout << "Account money is not enough" << endl;
        goto w1;
        return;
    }
    a[num].money -= money;
    cout << "Successful withdraw" << endl;
    cout << "Your current money : " << a[num].money << endl;
}

void deposit() {
    check();
    if (!cur) return;
    cout << "Enter amount of money to deposit" << endl;
    cin >> money;
    a[num].money += money;
    cout << "Successful deposit" << endl;
    cout << "Your current money : " << a[num].money << endl;

}

void create() {
    id++;
    a[id].valid = 1;
    a[id].number = id;
    cout << "Enter your name" << endl;
    cin >> a[id].name;
    cout << "Enter a password" << endl;
    cin >> a[id].password;

    y:
    cout << "Enter your birth year" << endl;
    cin >> a[id].year;
    if (a[id].year > 2012 || a[id].year < 1900) {
        cout << "Invalid entry" << endl;
        goto y;
    }

    m:
    cout << "Enter your birth month" << endl;
    cin >> a[id].month;
    if (a[id].month > 13 || a[id].month < 1) {
        cout << "Invalid entry" << endl;
        goto m;
    }

    d:
    cout << "Enter your birth day" << endl;
    cin >> a[id].day;
    if (a[id].day > months[a[id].month] || (a[id].day > 28 && a[id].month == 2 && a[id].year % 4 == 0)) {
        cout << "Invalid entry" << endl;
        goto d;
    }

    cout << "Enter amount of money to deposit" << endl;
    cin >> money;
    a[id].money += money;
    cout << "Account is created" << endl;

}

void show() {
    check();
    if (!cur) return;
    cout << "Account name: " << a[num].name << endl;
    cout << "Account password: " << a[num].password << endl;
    cout << "Account number: " << a[num].number << endl;
    cout << "Account money: " << a[num].money << endl;
}


void change(){
    check();
    if(!cur) return;
    cout<<"If you want to change account name enter 1"<<endl;
    string s;
    cin>>s;
    if(s=="1"){
        cout<<"Enter new account name"<<endl;
        cin>>s;
        a[num].name=s;
    }

    cout<<"If you want to change account password enter 2"<<endl;
    cin>>s;
    if(s=="2"){
        cout<<"Enter new account password"<<endl;
        cin>>s;
        a[num].password=s;
    }

    cout<<"If you want to change account birth day enter 3"<<endl;
    cin>>s;
    if(s=="3") {
        y:
        cout << "Enter your birth year" << endl;
        cin >> a[id].year;
        if (a[id].year > 2012 || a[id].year < 1900) {
            cout << "Invalid entry" << endl;
            goto y;
        }

        m:
        cout << "Enter your birth month" << endl;
        cin >> a[id].month;
        if (a[id].month > 13 || a[id].month < 1) {
            cout << "Invalid entry" << endl;
            goto m;
        }

        d:
        cout << "Enter your birth day" << endl;
        cin >> a[id].day;
        if (a[id].day > months[a[id].month] || (a[id].day > 28 && a[id].month == 2 && a[id].year % 4 == 0)) {
            cout << "Invalid entry" << endl;
            goto d;
        }
    }
    cout<<"Changes are done"<<endl;
}

void del(){
    check();
    if(!cur) return;
    a[num].valid=0;
    cout<<"Account is deleted"<<endl;
}

//#define endl "\n"
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("triangles.in","r",stdin);
    //memset(dp,-1,sizeof dp);
    yes=1;
    while(yes){
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
        int c;
        cin>>c;
        if(c==1) create();
        else if(c==2) withdraw();
        else if(c==3) deposit();
        else if(c==4) show();
        else if(c==5) change();
        else if(c==6) del();
        else if(c==7) yes=0;
        else cout<<"Invalid entry"<<endl;
        cout<<"Thanks for using our bank"<<endl<<endl<<endl<<endl;
    }

    return 0;
}
