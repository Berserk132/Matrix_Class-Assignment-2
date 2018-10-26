#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class bigint{
    string num;
public:
    bigint(){}
    void del(bigint b){}
    bigint(string x){
        num=x;
    }
    void del(){
        for(int i=0;i<num.size();++i){
            if(num[i]=='0') num.erase(num.begin()),i--;
            else break;
        }
    }
    string print(){
        return num;
    }
   bigint operator-(bigint b){
       this->del();
       b.del();
       string bigNum,smalNum,subtract;
       bigint tmp;
       bool sign;
       if(b.num.size()>this->num.size()){
            bigNum=b.num;
            smalNum=this->num;
            sign=0;
       }
       else if(b.num.size()<this->num.size()){
            bigNum=this->num;
            smalNum=b.num;
            sign=1;
       }
       else{
        for(int i=0;i<b.num.size();++i)
            if(b.num[i]>this->num[i]) {bigNum=b.num,smalNum=this->num,sign=0;break;}
            else if(b.num[i]<this->num[i]) {bigNum=this->num,smalNum=b.num,sign=1;break;}
       }
       int i;
       reverse(smalNum.begin(),smalNum.end());
       reverse(bigNum.begin(),bigNum.end());
       for(i=0;i<smalNum.size();++i){
        if(bigNum[i]-'0'<smalNum[i]-'0') bigNum[i+1]-=1,subtract.push_back((int(bigNum[i])+10-int(smalNum[i]))+'0');
        else subtract.push_back((int(bigNum[i])-int(smalNum[i]))+'0');
       }
       reverse(subtract.begin(),subtract.end());
       tmp.num=subtract;
       tmp.del();
       if(sign ==0) tmp.num.insert(0,"-",1);
       return tmp;


   }
};
    void del(bigint b){
        for(int i=0;i<b.num.size();++i){
            if(b.num[i]=='0') num.erase(b.num.begin()),i--;
            else break;
        }
    }
int main()
{
    bigint b("12");
    bigint b2("11");
    bigint c;
    c=b-b2;
    cout<<c.print();



}
