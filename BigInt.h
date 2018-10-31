#ifndef BIGINT_H
#define BIGINT_H
#include<bits/stdc++.h>
using namespace std;

class BigInt
{
    public:BigInt(string digit);
        BigInt(int digit);
        BigInt();
        void del();
        void setsign(char sign);
        char getsign();
        string print();
        BigInt operator+(BigInt b);
        BigInt operator-(BigInt b);
        void setnum(string digit);
        string getnum();
        ~BigInt();
        friend ostream& operator<<(ostream &out,BigInt b);

    protected:

    private:
        char sign;
        bool check(string &digit);
        string num;
};

#endif // BIGINT_H
