#include<bits/stdc++.h>
using namespace std;
void result(int count,bool lowercase,bool uppercase,bool num,bool special,bool notpresent)
{
            if(count<6)
           cout<<" Failure Password must be at least 6 characters long.\n";
           else if(count>12)
            cout<<" Failure Password must be at max 12 characters long.\n";
           else if(!lowercase)
            cout<<" Failure Password must contain at least one letter from a-z.\n";
           else if(!uppercase)
           cout<<" Failure Password must contain at least one letter from A-Z.\n";
           else if(!num)
            cout<<" Failure Password must contain at least one letter from 0-9.\n";
           else if(!special)
            cout<<" Failure Password must contain at least one letter from *$_#=@.\n";
           else if(!notpresent)
            cout<<" Failure Password cannot contain %!)(.\n";
           else
            cout<<" Success\n";

}
int main()
{  // TAKING INPUT IN A STRING OF ALL THE PASSWORDS TO BE EVALUATED.
   string str;
   getline(std::cin,str);
   //BOOLEAN VARIABLES ACTING AS FLAG FOR EACH CONDITION
   bool lowercase=false,uppercase=false,num=false,special=false,notpresent=true;
   //COUNT IS THE LENGTH OF EACH INDIVIUAL PASSWORD
   int count=0;
   for(int i=0;i<str.length();i++)
   {
      //CHECK FOR ALL THE CONDITIONS BETWEEN COMMAS.
       if(str[i]==',')
       {   result(count,lowercase,uppercase,num,special,notpresent);
           count=0;
           lowercase=false;
           uppercase=false;
           num=false;
           special=false;
           notpresent=true;

       }
       // CHECK EACH CHARACTER FOR SPACE,LOWERCASE ALPHATBETS,UPPERCASE ALPHABETS,NUMBERS,SPECIAL CHARACTERS TO BR PRESENT AND SPECIAL CHARACTERS NOT TO BE PRESENT
       else
       {   count++;
            //FOR SPACE
           if(int(str[i])==32)
            cout<<" ";
            //FOR CHARACTERS NOT TO BE PRESENT %,!,(,)
           else if((int)str[i]==37||(int)str[i]==33||(int)str[i]==40||(int)str[i]==41)
            {notpresent=false;
              cout<<str[i];
            }
            //FOR LOWERCASE ALPHABETS a-z
            else if((int)str[i]>=97 &&(int)str[i]<=122)
            {
                lowercase=true;
                cout<<str[i];
            }
            //FOR NUMBERS 0-9
            else if((int)str[i]>=48&&(int)str[i]<=57)
            {

                num=true;
                cout<<str[i];
            }
            //FOR UPPERCASE ALPHABETS A-Z
            else if((int)str[i]>=65 &&(int)str[i]<=90)
            {
                uppercase=true;
                cout<<str[i];
            }
            //FOR SPECIAL CHARACTERS TO BE PRESENT *,$,_,#,=,@
            else if((int)str[i]==42||(int)str[i]==36||(int)str[i]==95||(int)str[i]==35||(int)str[i]==61||(int)str[i]==64)
            { special=true;
                cout<<str[i];
            }

       }
   }    //CHECK FOR LAST PASSWORD IN THE STRING
         result(count,lowercase,uppercase,num,special,notpresent);

    return 0;

}
