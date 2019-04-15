#include <iostream>
#include "PhysicalNumber.h"
#include <iomanip>
using namespace std;
namespace ariel
{
#include "Unit.h"    
PhysicalNumber PhysicalNumber::convert(PhysicalNumber &Rhs)
{
if(u==Rhs.u)
{
    return Rhs;
}
switch (u)
{
    ///////////////////////////////////-----distance------//////////////////////////////////////////
    case CM: //convert to cm
    {
   ////for the badkan, i didnt put try and catch exeption////     
   // try{
    if(Rhs.u==M)
    {
         Rhs.num*=100;//from meter to cm
        return Rhs;
    }        

    if(Rhs.u==KM)
    {
        Rhs.num*=100000;//from Km to cm
        return Rhs;
    }
         throw "ERROR cannot convert";
     // }catch (int x){
     //  cout <<"cannot convert "<<*this<<" to "<< Rhs << " ERROR NUMBER: "<< x <<endl ;
     //  PhysicalNumber err(0,ERR);
     //   return err;
     //}
    }

    case M: //convert to meter
   {
   //    try{
    if(Rhs.u==CM)
    {
         Rhs.num/=100;//from cm to meter
        return Rhs;
    }        

    if(Rhs.u==KM)
    {
        Rhs.num*=1000;//from Km to meter
        return Rhs;
    }
            throw 99;
    // }catch (int x){
    //     cout <<"cannot convert "<<*this<<" to "<< Rhs << " ERROR NUMBER: "<< x <<endl ;
    //    PhysicalNumber err(0,ERR);
    //     return err;
    // }
    }

    case KM: //convert to Km
    {
      //  try{
    if(Rhs.u==CM)
    {
        Rhs.num/=100000;//from cm to Km
        return Rhs;
    }        
    if(Rhs.u==M)
    {
        Rhs.num/=1000;//from meter to Km
        return Rhs;
    }
       throw 99;
    // }catch (int x){
    //     cout <<"cannot convert "<<*this<<" to "<< Rhs << " ERROR NUMBER: "<< x <<endl ;
    //    PhysicalNumber err(0,ERR);
    //     return err;
    // }
    }

///////////////////////////////////-----Time------//////////////////////////////////////////

    case SEC: //convert to second
    {
        // try{
    if(Rhs.u==MIN)
    {
         Rhs.num*=60;//from min to second
        return Rhs;
    }        

    if(Rhs.u==HOUR)
    {
        Rhs.num*=3600;//from hour to second
        return Rhs;
    }
       throw 99;
    // }catch (int x){
    //     cout <<"cannot convert "<<*this<<" to "<< Rhs << " ERROR NUMBER: "<< x <<endl ;
    //    PhysicalNumber err(0,ERR);
    //     return err;
    // }
    }

    case MIN: //convert to minuts
   {
   //    try{
    if(Rhs.u==SEC)
    {
         Rhs.num/=60;//from sec to minuts
        return Rhs;
    }        

    if(Rhs.u==HOUR)
    {
        Rhs.num*=60;//from hour to minuts
        return Rhs;
    }
       throw 99;
    // }catch (int x){
    //     cout <<"cannot convert "<<*this<<" to "<< Rhs << " ERROR NUMBER: "<< x <<endl ;
    //    PhysicalNumber err(0,ERR);
    //     return err;
    // }
    }
    
    case HOUR: //convert to Hour
    {
     //   try{
    if(Rhs.u==SEC)
    {
         Rhs.num/=3600;//from sec to Hour
        return Rhs;
    }        

    if(Rhs.u==MIN)
    {
        Rhs.num/=60;//from min to Hour
        return Rhs;
    }
       throw 99;
    // }catch (int x){
    //     cout <<"cannot convert "<<*this<<" to "<< Rhs << " ERROR NUMBER: "<< x <<endl ;
    //    PhysicalNumber err(0,ERR);
    //     return err;
    // }
    }


///////////////////////////////////-----weight------//////////////////////////////////////////

    case G: //convert to gram
    {
   //     try{
    if(Rhs.u==KG)
    {
         Rhs.num*=1000;//from KG to gram
        return Rhs;
    }        

    if(Rhs.u==TON)
    {
        Rhs.num*=(double)1000000;//from Ton to gram
        return Rhs;
    }
       throw 99;
    // }catch (int x){
    //     cout <<"cannot convert "<<*this<<" to "<< Rhs << " ERROR NUMBER: "<< x <<endl ;
    //    PhysicalNumber err(0,ERR);
    //     return err;
    // }
    }

    case KG: //convert to KG
   {
   //    try{
    if(Rhs.u==G)
    {
         Rhs.num/=1000;//from gram to KG
        return Rhs;
    }        

    if(Rhs.u==TON)
    {
        Rhs.num*=1000;//from Ton to KG
        return Rhs;
    }
       throw 99;
    // }catch (int x){
    //     cout <<"cannot convert "<<*this<<" to "<< Rhs << " ERROR NUMBER: "<< x <<endl ;
    //    PhysicalNumber err(0,ERR);
    //     return err;
    // }
    }
    
    case TON: //convert to Ton
    {
     //   try{
    if(Rhs.u==G)
    {
        Rhs.num*=(double)1/1000000;//from gram to Ton
        return Rhs;
    }        

    if(Rhs.u==KG)
    {
        Rhs.num/=1000;//from Kg to Ton
        return Rhs;
    }
   throw 99;
    // }catch (int x){
    //     cout <<"cannot convert "<<*this<<" to "<< Rhs << " ERROR NUMBER: "<< x <<endl ;
    //    PhysicalNumber err(0,ERR);
    //     return err;
    // }   
    }
}

}
PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &Rhs)
{
    PhysicalNumber temp;
    temp.u=Rhs.u;
    temp.num=Rhs.num;
    temp=convert(temp);
    if(temp.u==9)//conv error
    {
        return temp;
    }
    else{
    PhysicalNumber help;// in order to return var of PhysicalNumber (new one)
    help.u = u;
    help.num=num+temp.num;
    return help;//this made leaking memory?????//////////////////////////////////
    }
}


PhysicalNumber PhysicalNumber::operator+=(const PhysicalNumber &Rhs)
{
    PhysicalNumber temp;
    temp.num=Rhs.num;
    temp.u=Rhs.u;
    temp=convert(temp);
     if(temp.u==9)//conv error
    {
        return *this;
    }
    num+=temp.num;
    return *this;
}

PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &Rhs)
{
    PhysicalNumber temp;
    temp.num=Rhs.num;
    temp.u=Rhs.u;
    temp=convert(temp);
    if(temp.u==9)
    {
        return temp;
    }
   else{
    PhysicalNumber help;// in order to return var of PhysicalNumber (new one)
    help.u = u;
    help.num=num-temp.num;
    return help;//this made leaking memory?????//////////////////////////////////
 }
}
PhysicalNumber PhysicalNumber::operator-=(const PhysicalNumber &Rhs)
{
     PhysicalNumber temp;
    temp.num=Rhs.num;
    temp.u=Rhs.u;
    temp=convert(temp);
    if(temp.u==9)
    {
        return *this;
    }
    num-=temp.num;
    return *this;
 }

PhysicalNumber PhysicalNumber::operator-()
{
    num=(-num);
    return *this;}

PhysicalNumber PhysicalNumber::operator+()
{
    num=(+num);
    return *this;
}

bool PhysicalNumber::operator<(const PhysicalNumber &Rhs)
{
    PhysicalNumber temp;
    temp.num=Rhs.num;
    temp.u=Rhs.u;
    temp=convert(temp);
    if(temp.u==9)
    {
        return false;
    }
    if(num<temp.num)
    {
        return true;
    }
    return false;
}

bool PhysicalNumber::operator>(const PhysicalNumber &Rhs)
{
    PhysicalNumber temp;
    temp.num=Rhs.num;
    temp.u=Rhs.u;
    temp=convert(temp);
    if(temp.u==9)
    {
        return false;
    }
    if(num>temp.num)
    {
        return true;
    }
    return false;
}

bool PhysicalNumber::operator>=(const PhysicalNumber &Rhs)
{
    PhysicalNumber temp;
    temp.num=Rhs.num;
    temp.u=Rhs.u;
    temp=convert(temp);
    if(temp.u==9)
    {
        return false;
    }
    if(num>=temp.num)
    {
        return true;
    }
    return false;
}

bool PhysicalNumber::operator<=(const PhysicalNumber &Rhs)
{
    PhysicalNumber temp;
    temp.num=Rhs.num;
    temp.u=Rhs.u;
    temp=convert(temp);
     if(temp.u==9)
    {
        return false;
    }
    if(num<=temp.num)
    {
        return true;
    }
    return false;
}

bool PhysicalNumber::operator==(const PhysicalNumber &Rhs)
{
    PhysicalNumber temp;
    temp.num=Rhs.num;
    temp.u=Rhs.u;
    temp=convert(temp);
    if(temp.u==9)
    {
       throw "error";
    }
    if(num==temp.num)
    {
        return true;
    }
    return false;
}

bool PhysicalNumber::operator!=(const PhysicalNumber &Rhs)
{
   {
    PhysicalNumber temp;
    temp.num=Rhs.num;
    temp.u=Rhs.u;
    temp=convert(temp);
     if(temp.u==9)
    {
        return false;
    }
    if(num!=temp.num)
    {
        return true;
    }
    return false;
}
}

PhysicalNumber PhysicalNumber::operator++(int)
{
    PhysicalNumber temp = *this;
    ++num;
    return temp;
}

PhysicalNumber PhysicalNumber::operator--(int)
{
    PhysicalNumber tmp = *this;
    --num;
    return tmp;
}

ostream &operator<<(ostream &out, const PhysicalNumber &x)
{
    int temp = x.u;
    string t="";
    switch (temp)
    {
        case 0: t="cm";break;
        case 1: t="m";break;
        case 2: t="km";break;
        
        case 3: t="sec";break;
        case 4: t="min";break;
        case 5: t="hour";break;

        case 6: t="g";break;
        case 7: t="kg";break;
        case 8: t="ton";break;
     
        default: throw invalid_argument("error"); 
     }
     out<< std::setprecision(8)<< x.num << "["<<t<<"]";//setprecision(8) in order to print x.xxxxxxxx 8 times
     return out;
}
istream& operator>>(istream& in,PhysicalNumber &a) {
    string s;
    in>>a.num;
    in>>s;
    string s2=s.substr(1,s.length()-2);
    if(s2=="cm")a.u=CM;
    else if(s2=="m")a.u=M;
    else if(s2=="km")a.u=KM;
    else if(s2=="sec")a.u=SEC;
    else if(s2=="min")a.u=MIN;
    else if(s2=="hour")a.u=HOUR;
    else if(s2=="g")a.u=G;
    else if(s2=="kg")a.u=KG;
    else if(s2=="ton")a.u=TON;
    else{
        throw invalid_argument("Not a unit in this program");
    } 
    return in;
}

} // namespace ariel
 