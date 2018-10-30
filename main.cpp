#include <iostream>
#include "BigInt.h"
using namespace std;
ostream& operator<<(ostream &out,BigInt const b){
    (b.sign=='-')?out<<b.sign<<b.num<<endl:out<<b.num;
    return out;
}


int main()
{
    BigInt b("-510");
    BigInt b2("-20");
    cout<<b.getsign()<<endl<<b2.getsign()<<endl;
    BigInt c;
    c=b+b2;
    cout<<c.getsign()<<"\t"<<c<<endl;

    b.setnum("510");
    b2.setnum("-20");
    c=b+b2;
    cout<<b.getnum()<<"\t"<<b2.getsign()<<endl;
    cout<<c.getsign()<<"\t"<<c<<endl;

    b.setnum("-510");
    b2.setnum("20");
    c=b+b2;
    cout<<b.getnum()<<"\t"<<b2<<endl;
    cout<<c.getsign()<<"\t"<<c<<endl;

    b.setnum("510");
    b2.setnum("20");
    c=b+b2;
    cout<<b.getnum()<<"\t"<<b2<<endl;
    cout<<c.getsign()<<"\t"<<c<<endl;


}
