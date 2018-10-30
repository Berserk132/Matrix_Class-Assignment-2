#include "BigInt.h"

BigInt::BigInt(string digit)
{
    bool b=1;
    if(!check(digit)) b=0;
    while (b==0){
        cout<<"invalid input enter another one: ";
        cin>>digit;
        if(check(digit)) b=1;
    }
    if(digit[0]=='-') digit.erase(digit.begin()),sign='-';
    else sign='+';
    num=digit;
}
BigInt::BigInt(int digit){
    if (digit<0) sign='-';
    else sign='+';
    stringstream ss;
    ss<<digit;
    num=ss.str();

}
BigInt::BigInt(){

}

bool BigInt::check(string &digit){
    bool b=0;
    if(digit[0]=='-' || digit[0] =='+' || (digit[0]>'0' && digit[0]<'9')) b=1;
    if (b==0) return 0;
    for(int i=1;i<digit.size();++i){
        if(digit[i]<'0' || digit[i]>'9'){cout<<"there";return 0;}
    }
    return 1;
}

void BigInt::del(){
    for(int i=0;i<num.size();++i){
        if(num[i]=='0') num.erase(num.begin()),i--;
        else if(num[i]=='-') continue;
    else break;
    }
}

void BigInt::setsign(char sign){
    this->sign=sign;
}
char BigInt::getsign(){
    return sign;
}

void BigInt::setnum(string digit){
    if(digit[0]=='-') this->sign='-',digit.erase(digit.begin());
    else this->sign='+';
    this->num=digit;
}
string BigInt::getnum(){
    return num;
}
    string BigInt::print(){
        return num;
    }


    BigInt BigInt::operator+(BigInt b)
    {
    if(this->sign != b.sign){
        if(this->sign=='-'){
            BigInt tmp=*this;
            tmp.sign='+';
            return b-tmp;
        }
        if(b.sign=='-'){
            BigInt tmp=b;
            tmp.sign='+';
            return *this-tmp;
        }
    }
    BigInt num1,num2;
    num1=*this;
    num2=b;

     BigInt c;
    c.num = "";

    reverse(num1.num.begin(),num1.num.end());
    reverse(num2.num.begin(),num2.num.end());

    if (num1.num.size() > num2.num.size())
    {
        for (int i=num2.num.length(); i<num1.num.length(); i++)
        {
            num2.num+="0";
        }
    }
    else
    {
        for (int i=num1.num.length(); i<num2.num.length(); i++)
        {
            num1.num+="0";
        }
    }
    int carry = 0;
    for (int i=0; i<num1.num.length(); i++)
    {
        int sum = 0,tmp = 0,tmp1 = 0;
        tmp  = num1.num[i] - 48;
        tmp1 = num2.num[i] - 48;
        sum = tmp + tmp1 + carry;
        carry = sum / 10;
        sum = sum % 10;
        c.num +=(char)sum+48;
    }
    reverse(c.num.begin(),c.num.end());
    c.sign=b.sign;
    return c;
}



   BigInt BigInt::operator-(BigInt b){
       if(this->sign != b.sign){
        if (this->sign=='-'){
            BigInt tmp;
            tmp=b;
            tmp.sign='-';
            return *this+tmp;
        }
        if (this->sign!='-'){
            BigInt tmp;
            tmp=b;
            tmp.sign='+';
            return *this+tmp;
        }
       }
       (b.sign=='-')?b.sign='+':b.sign='-';
       this->del();
       b.del();
       BigInt bigNum,smalNum,tmp;
       string subtract;
       if(b.num.size()>this->num.size()){
            bigNum=b;
            smalNum=*this;
       }
       else if(b.num.size()<this->num.size()){
            bigNum=*this;
            smalNum=b;
       }
       else{
        for(int i=0;i<b.num.size();++i)
            if(b.num[i]>this->num[i]) {
                bigNum=b,smalNum=*this;
                break;
            }
            else if(b.num[i]<this->num[i]) {
                bigNum=*this,smalNum=b;
                break;
            }
       }
       reverse(smalNum.num.begin(),smalNum.num.end());
       reverse(bigNum.num.begin(),bigNum.num.end());
        int i;
       for(i=0;i<smalNum.num.size();++i){
            if(bigNum.num[i]-'0'<smalNum.num[i]-'0')
                bigNum.num[i+1]-=1,subtract.push_back((int(bigNum.num[i]-'0')+10-int(smalNum.num[i]-'0'))+'0');
            else subtract.push_back((int(bigNum.num[i]-'0')-int(smalNum.num[i]-'0'))+'0');
       }
       for(;i<bigNum.num.size();++i){
        subtract.push_back(bigNum.num[i]);
       }
       reverse(subtract.begin(),subtract.end());
       tmp.num=subtract;
       tmp.del();
       tmp.sign=bigNum.sign;
       (b.sign=='-')?b.sign='+':b.sign='-';
       return tmp;
   }



BigInt::~BigInt()
{
    //dtor
}
