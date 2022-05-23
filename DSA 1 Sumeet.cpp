#include<iostream>
#include<string.h>
using namespace std;

struct tdirect
{
    int tnum;
    string tname;
};

tdirect td[10];

int hashing(int num)
{
    return num%10;
}

int display()
{
    for (int i = 0; i <= 10; i++)
    {
        if (td[i].tname != "")
        {
            cout<<"Location = "<<i<<endl;
            cout<<"Name = "<<td[i].tname<<endl;
            cout<<"Number = "<<td[i].tnum<<endl;
            cout<<endl;        
        }
    }
    
    
    return 0;
}

int LinearProb(int pos,int tel , string sname){
    

    if (td[pos].tnum == 0)
    {
        td[pos].tnum = tel;
        td[pos].tname = sname;
    }
    else{
        LinearProb(pos + 1, tel, sname);
    }
    
    return 0;
}

int QuadraticProb(int pos, int tel, string sname){

    if( td[pos].tnum  == 0)
    {
        td[pos].tnum = tel;
        td[pos].tname = sname;
    }
    else
    {
        int i = 1;
        while (td[pos].tnum != 0)
        {
            int sq = i*i;
            pos = pos + sq;
            i++;

            if(td[pos].tnum == 0)
            {
                td[pos].tnum = tel;
                td[pos].tname = sname;
                break;
            }
        }
        

    }
    return 0;
}

int main()
{
    int tel,pos,n;
    string sname;

    cout<<"Enter number of records to be registered"<<endl;
    cin>>n;

    
        cout<<""<<endl;
        cout<<"Enter your choice \n1. Linear Probing\n2. Quadratic Probing"<<endl;
        int ch;
        cin>> ch;

        switch (ch)
        {
            
        case 1: for (int i = 0; i < n; i++)
            {
                cout<<"Enter number"<<endl;
                cin>>tel;
                cout<<"Enter name"<<endl;
                cin>>sname;
                pos = hashing(tel);
		        LinearProb(pos, tel, sname);
            }
                break;
        
        case 2: for (int i = 0; i < n; i++)
            {
                cout<<"Enter number"<<endl;
                cin>>tel;
                cout<<"Enter name"<<endl;
                cin>>sname;
                pos = hashing(tel);
	        	QuadraticProb(pos, tel, sname);
                
                break;
            }
    }
    
    
    display();    

}


