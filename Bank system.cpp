#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N =1e5+5;

ll number, year, month, day, num, money, tmpmoney, months[]={0,31,29,31,30,31,30,31,31,30,31,30,31};

bool yes, cur, valid;

string s, name, password, pass;

string monthstr[]={"n","January","February","Mars","April","May","June",
                   "Julie","August","September","November","December"};

struct client {
    string name, password, month, day, year, money, num;
};


pair<ll,bool> str_to_int(string s) {
    ll ret = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            return {0, 0};
        }
        ret = ret * 10 + s[i] - '0';
        if (ret >= 1000000000) return {0, 0};
    }
    return {ret, 1};
}

string int_to_str(ll num) {
    string ret = "";
    while (num) {
        ret += (char) (num % 10 + '0');
        num /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

client trans(string s) {
    client ret;
    int i = 0;
    ret.num = "";
    while (s[i] != ' ') ret.num += s[i++];
    i++;
    ret.name = "";
    while (s[i] != ' ') ret.name += s[i++];
    i++;
    ret.password = "";
    while (s[i] != ' ') ret.password += s[i++];
    i++;
    ret.year = "";
    while (s[i] != ' ') ret.year += s[i++];
    i++;
    ret.month = "";
    while (s[i] != ' ') ret.month += s[i++];
    i++;
    ret.day = "";
    while (s[i] != ' ') ret.day += s[i++];
    i++;
    ret.money = "";
    while (i < s.size() && s[i] != ' ') ret.money += s[i++];
    return ret;
}

string transrev(client me) {
    string ret = "";
    for (auto i:me.num) ret += i;
    ret += ' ';
    for (auto i:me.name) ret += i;
    ret += ' ';
    for (auto i:me.password) ret += i;
    ret += ' ';
    for (auto i:me.year) ret += i;
    ret += ' ';
    for (auto i:me.month) ret += i;
    ret += ' ';
    for (auto i:me.day) ret += i;
    ret += ' ';
    for (auto i:me.money) ret += i;
    return ret;
}

void update(string del,string nu) {
    ifstream old;
    old.open("data.txt");
    ofstream cur;
    cur.open("tmpdata.txt");
    if (nu != "0") cur << nu << endl;
    while (getline(old, s)) {
        if (s == del) continue;
        cur << s << endl;
    }
    old.close();
    cur.close();
    remove("data.txt");
    rename("tmpdata.txt", "data.txt");
}

string check() {
    system("CLS");
    ifstream clientsin;
    clientsin.open("data.txt");

    n:
    cout << "Enter account number" << endl;
    cin >> s;
    if (str_to_int(s).second == 0) {
        cout << "Account number must be a positive integer less than 1000000000" << endl;
        goto n;
    }
    string s2, tmpnum, tmppass;
    string ret;
    while (getline(clientsin, s2)) {
        tmpnum = "";
        for (int i = 0; i < s2.size(); i++) {
            if (s2[i] == ' ') {
                tmppass = "";
                i++;
                while (s2[i] != ' ') tmppass += s2[i++];
                break;
            }
            tmpnum += s2[i];
        }
        if (tmpnum == s) {
            ret = s2;
            break;
        }
    }
    clientsin.close();
    if (tmpnum != s) {
        cout << "Account number is not exist" << endl;
        return "0";
    }

    p:
    cout << "Enter account password" << endl;
    cin >> pass;
    if (tmppass != pass) {
        cout << "Account password is not valid" << endl;
        goto p;
    }
    return ret;
}

void create() {
    system("CLS");
    ifstream clientsin;
    clientsin.open("data.txt");
    string tmp, tmp2;
    nu:
    cout << "Enter account number" << endl;
    cin >> s;
    if (str_to_int(s).second == 0) {
        cout << "Account number must be a positive integer less than 1000000000" << endl;
        goto nu;
    }
    string num = s;
    while (getline(clientsin, tmp)) {
        tmp2 = "";
        for (auto x:tmp) {
            if (x == ' ') break;
            tmp2 += x;
        }
        if (s == tmp2) {
            cout << "There is another account with this account number" << endl;
            goto nu;
        }
    }
    clientsin.close();

    n:
    cout << "Enter your name" << endl;
    cin >> name;
    for (int i = 0; i < name.size(); i++) {
        if (!(name[i] >= 'A' && name[i] <= 'Z')
            && !(name[i] >= 'a' && name[i] <= 'z')) {
            cout << "Account name must have only latin letters" << endl;
            goto n;
        }
    }

    cout << "Enter a password" << endl;
    cin >> password;

    y:
    cout << "Enter your birth year" << endl;
    cin >> s;
    if (str_to_int(s).second == 0) {
        cout << "Year must be integer" << endl;
        goto y;
    }
    year = str_to_int(s).first;
    if (year > 2010 || year < 1900) {
        cout << "Year must be between 1900 and 2010" << endl;
        goto y;
    }

    m:
    cout << "Enter your birth month" << endl;
    cin >> s;
    if (str_to_int(s).second == 0) {
        cout << "Month must be integer" << endl;
        goto m;
    }
    month = str_to_int(s).first;

    if (month > 12 || month < 1) {
        cout << "Month must be between 1 and 12" << endl;
        goto m;
    }

    d:
    cout << "Enter your birth day" << endl;
    cin >> s;
    if (str_to_int(s).second == 0) {
        cout << "Day must be integer" << endl;
        goto d;
    }
    day = str_to_int(s).first;

    if (day > months[month] || (day > 28 && month == 2 && year % 4 == 0)) {
        cout << "This day is not valid in " << monthstr[month] << endl;
        goto d;
    }

    de:
    cout << "Enter amount of money to deposit" << endl;
    cin >> s;
    if (str_to_int(s).second == 0) {
        cout << "Amount of money must be a positive integer less than 1000000000" << endl;
        goto de;
    }
    tmpmoney = str_to_int(s).first;
    money += tmpmoney;
    cout << "Account is created" << endl;
    ofstream clientsout;
    clientsout.open("data.txt", ios::app);
    clientsout << num << " " << password << " " << name << " " << year << " " << month << " " << day << " " << money
               << endl;
    _sleep(2000);

}

void show() {
    system("CLS");
    string cli = check();
    if (cli == "0") return;
    client me = trans(cli);
    cout << "Account number: " << me.num << endl;
    cout << "Account name: " << me.name << endl;
    cout << "Account password: " << me.password << endl;
    cout << "Account birth day: " << me.day << "/" << me.month << "/" << me.year << endl;
    cout << "Account amount money: " << me.money << endl;
    _sleep(2000);
}

void withdraw() {
    system("CLS");
    string cli = check();
    if (cli == "0") return;
    client me = trans(cli);

    w:
    cout << "Enter amount of money to withdraw" << endl;
    string s;
    cin >> s;
    if (str_to_int(s).second == 0) {
        cout << "Amount of money must be a positive integer less than 1000000000" << endl;
        goto w;
    }
    money = str_to_int(s).first;

    if (str_to_int(me.money).first < money) {
        cout << "Account money is not enough" << endl;
        goto w;
    }
    ll newmoney = str_to_int(me.money).first - money;
    me.money = int_to_str(newmoney);
    string newclient = transrev(me);
    update(cli, newclient);

    cout << "Successful withdraw" << endl;
    cout << "Your current money : " << newmoney << endl;
    _sleep(1000);
}

void deposit() {
    system("CLS");
    string cli = check();
    if (cli == "0") return;
    client me = trans(cli);
    d:
    cout << "Enter amount of money to deposit" << endl;
    string s;
    cin >> s;
    if (str_to_int(s).second == 0) {
        cout << "Amount of money must be a positive integer less than 1000000000" << endl;
        goto d;
    }

    money = str_to_int(s).first;
    ll newmoney = str_to_int(me.money).first + money;
    me.money = int_to_str(newmoney);
    string newclient = transrev(me);
    update(cli, newclient);
    cout << "Successful withdraw" << endl;
    cout << "Your current money : " << newmoney << endl;
    _sleep(1000);
}

void change() {
    system("CLS");
    string cli = check();
    if (cli == "0") return;
    client me = trans(cli);
    cout << "If you want to change account name enter 1" << endl;
    cin >> s;
    if (s == "1") {
        n:
        cout << "Enter new account name" << endl;
        cin >> name;
        for (int i = 0; i < name.size(); i++) {
            if (!(name[i] >= 'A' && name[i] <= 'Z')
                && !(name[i] >= 'a' && name[i] <= 'z')) {
                cout << "Account name must have only latin letters" << endl;
                goto n;
            }
        }
        me.name = name;
        cout << "Account name is updated" << endl;
    }

    cout << "If you want to change account password enter 2" << endl;
    cin >> s;
    if (s == "2") {
        cout << "Enter new account password" << endl;
        cin >> s;
        me.password = s;
        cout << "Account password is updated" << endl;
    }

    cout << "If you want to change account birth day enter 3" << endl;
    cin >> s;
    if (s == "3") {
        y:
        cout << "Enter your birth year" << endl;
        cin >> s;
        if (str_to_int(s).second == 0) {
            cout << "Year must be integer" << endl;
            goto y;
        }
        year = str_to_int(s).first;
        if (year > 2010 || year < 1900) {
            cout << "Year must be between 1900 and 2010" << endl;
            goto y;
        }
        me.year = s;

        m:
        cout << "Enter your birth month" << endl;
        cin >> s;
        if (str_to_int(s).second == 0) {
            cout << "Month must be integer" << endl;
            goto m;
        }
        month = str_to_int(s).first;

        if (month > 12 || month < 1) {
            cout << "Month must be between 1 and 12" << endl;
            goto m;
        }
        me.month = s;

        d:
        cout << "Enter your birth day" << endl;
        cin >> s;
        if (str_to_int(s).second == 0) {
            cout << "Day must be integer" << endl;
            goto d;
        }
        day = str_to_int(s).first;

        if (day > months[month] || (day > 28 && month == 2 && year % 4 == 0)) {
            cout << "This day is not valid in " << monthstr[month] << endl;
            goto d;
        }
        me.day = s;
        cout << "Birth day is updated" << endl;
    }
    cout << "Changes are done" << endl;
    string newclient = transrev(me);
    update(cli, newclient);
    _sleep(1000);
}

void del() {
    system("CLS");
    string cli = check();
    if (cli == "0") return;
    client me = trans(cli);
    update(cli, "0");
    cout << "Account is deleted" << endl;
    _sleep(1000);
}

//#define endl "\n"
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    yes = 1;
    while (yes) {
        system("CLS");
        cur = 1;
        cout << "---- Welcome to our bank ----" << endl << endl;
        cout << "Please enter your choice" << endl << endl;
        cout << "1 - Create new account" << endl;
        cout << "2 - Withdraw money" << endl;
        cout << "3 - Deposit money" << endl;
        cout << "4 - Show account information" << endl;
        cout << "5 - Change account information" << endl;
        cout << "6 - Delete account" << endl;
        cout << "7 - Exit" << endl;

        string c;
        cin >> c;
        if (c == "1"){
            create();
        }
        else if (c == "2"){
            withdraw();
        }
        else if (c == "3"){
            deposit();
        }
        else if (c == "4"){
            show();
        }
        else if (c == "5"){
            change();
        }
        else if (c == "6"){
            del();
        }
        else if (c == "7"){
            yes = 0;
        }
        else{
            cout << "Invalid entry" << endl;
        }
        cout << "Thanks for using our bank" << endl << endl << endl << endl;
        _sleep(1000);
    }
    return 0;
}
