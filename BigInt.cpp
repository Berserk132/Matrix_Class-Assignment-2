#include <bits/stdc++.h>
using namespace std;

class BigInt
{
public:
    string digit;

    BigInt() {}
    /*void setValue(string s)
    {
        digit = s;
    }
    string getValue()
    {
        return digit;
    }*/
};


ostream& operator<<(ostream &out, BigInt& val)
{
    out << val.digit;
    return out;
}

BigInt operator+(BigInt &a,BigInt &b)
{
    BigInt c;
    c.digit = "";
    reverse(a.digit.begin(),a.digit.end());
    reverse(b.digit.begin(),b.digit.end());
    if (a.digit.size() > b.digit.size())
    {
        for (int i=b.digit.length(); i<a.digit.length(); i++)
        {
            b.digit+="0";
        }
    }
    else
    {
        for (int i=a.digit.length(); i<b.digit.length(); i++)
        {
            a.digit+="0";
        }
    }
    int carry = 0;

    for (int i=0; i<a.digit.length(); i++)
    {
        int sum = 0;
        int tmp = 0;
        int tmp1 = 0;

        tmp  = a.digit[i] - 48;
        tmp1 = b.digit[i] - 48;
        sum = tmp + tmp1 + carry;
        carry = sum / 10;
        sum = sum % 10;
        c.digit +=(char)sum+48;

    }
    reverse(c.digit.begin(),c.digit.end());
    return c;

}

BigInt operator-(BigInt &a,BigInt &b)
{
    BigInt c;
    c.digit = "";
    bool flag = false;
    int length = b.digit.length();
    reverse(a.digit.begin(),a.digit.end());
    reverse(b.digit.begin(),b.digit.end());
    if (b.digit.length()>a.digit.length())
    {
        flag = true;
    }

    else if((a.digit.length() == b.digit.length()) && (b.digit[length-1] > a.digit[length-1]))
    {
        flag = true;
    }
    if (a.digit.size() > b.digit.size())
    {
        for (int i=b.digit.length(); i<a.digit.length(); i++)
        {
            b.digit+="0";
        }
    }
    else
    {
        for (int i=a.digit.length(); i<b.digit.length(); i++)
        {
            a.digit+="0";
        }
    }
    bool carry = false;
    if (flag == true)
    {
        for (int i=0; i<a.digit.length(); i++)
        {
            int sum = 0;
            int tmp = 0;
            int tmp1 = 0;
            if (carry == true)
            {
                b.digit[i]-=1;
                carry = false;
            }
            if ((int)b.digit[i] < (int)a.digit[i])
            {
                tmp  = (a.digit[i] - 48) ;
                tmp1 = (b.digit[i] - 48) + 10 ;
                sum = tmp1 - tmp;
                cout << tmp1 << " " << tmp << endl;
                c.digit +=(char)sum+48;
                carry = true;

            }
            else
            {
                tmp  = (a.digit[i] - 48);
                tmp1 = b.digit[i] - 48;
                sum = tmp1 - tmp;
                c.digit +=(char)sum+48;
            }

            cout << tmp1 << " " << tmp << endl;
        }
        c.digit+="-";
        reverse(c.digit.begin(),c.digit.end());
        return c;
    }
    else
    {
        for (int i=0; i<a.digit.length(); i++)
        {
            int sum = 0;
            int tmp = 0;
            int tmp1 = 0;
            if (carry == true)
            {
                a.digit[i]-=1;
                carry = false;
            }
            if ((int)a.digit[i] < (int)b.digit[i])
            {
                tmp  = (a.digit[i] - 48) + 10;
                tmp1 = b.digit[i] - 48;
                sum = tmp - tmp1;
                c.digit +=(char)sum+48;
                carry = true;

            }
            else
            {
                tmp  = (a.digit[i] - 48);
                tmp1 = b.digit[i] - 48;
                sum = tmp - tmp1;
                c.digit +=(char)sum+48;
            }


        }

        reverse(c.digit.begin(),c.digit.end());
        return c;
    }


}


int main()
{
    BigInt a;
    a.digit = "111111111111111111111111111111";
    BigInt b;
    b.digit = "333333333333333333333333333333";
    //try this 
    b.digit="000000001";
    a.digit="150";
    BigInt c;
    c = a-b;
    cout << c;
    return 0;
}
