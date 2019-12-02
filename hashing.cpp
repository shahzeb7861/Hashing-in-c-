#include <iostream>

using namespace std;
class hashing{
public:
    int key;
    int array[100];
    int i=0;
    int counter=0;

    hashing()
    {
        for(int i=0;  i<100; i++)
        {
            array[i]=0;
        }
    }

    int hash(int key)
    {
        return key%100;
    }
/*
int linear_probing(int key)
{
    int i=1;
    while(array[i]!=0)
    {
            i=(hash(key)+i)%10;
            i++;

    }
    return i;
}
*/
void addelement(int value)
{
if(counter==100)
{
    cout<<"array is full"<<endl;
    return;

}
else{

    i=hash(value);
    if(array[i]==0)
    {
        array[i]=value;
        counter++;
        return;
    }
    else

    {
        int j=1;
    //cout<<"collision reesolving method: "<<endl;
         while(array[i]!=0)
    {
            i=(hash(value)+j*j)%100;
            j++;

    }
    array[i]=value;
    counter++;

    }

}

}

void search(int value)
{
    i=hash(value);
    if(array[i]==value)
    {
        cout<<"Value is present at index: "<<i<<endl;
        return;
    }
    else
    {
           int ind=i-1;
             int loc_ind=ind*ind;
        int j=1;
        while(i!= loc_ind)
        {
            i=(hash(value)+(j*j)%100);

            if(array[i]==value)
            {
                cout<<"value is present at index: "<<i<<endl;
                return;
            }
            else if(array[i]==0)
            {
                cout<<"your data iS not present:  "<<endl;
                return;
            }


            j++;
        }
        cout<<"Value is not present"<<endl;

        }

}

void delete_n(int value)
{
        i=hash(value);

    if(array[i]==value)
    {
        array[i]=0;
        counter--;
    }
    else{


        if(i!=0)
        {
             int loc_ind=i-1;
        int j=1;
        while(i!= loc_ind)
        {
            i=(hash(value)+(j*j))%100;

            if(array[i]==value)
            {
                //cout<<"value is present at index: "<<i<<endl;
                array[i]=0;
                counter--;
                return;
            }


            j++;
        }
        cout<<"Value is not present"<<endl;
    }

    }
}
void isfull()
{
    if(counter==100)
        cout<<"hash table is full:"<<endl;
    else
        cout<<"hash table is not full;"<<endl;
}
void isempty()
{
    if(counter==0)
        cout<<"hash table is completely empty:"<<endl;
    else
        cout<<"hash table is not empty:"<<endl;
}
void display()
{
    for(int i=0; i<100; i++)
    {
        cout<<"values are:  "<<array[i]<<" , "<<endl;
         //cout<<"counter value is:"  <<counter<<endl;
    }
}


};
int main()
{
    hashing obj;
    char c='b';

    while(c!='N')
    {
        cout<<"press A: if you want to insert:  "<<endl;
        cout<<"press S: if you want to SEARCH:  "<<endl;
        cout<<"press R: if you want to DELETE:  "<<endl;
        cout<<"press E: if you want to check hash table EMPTY:  "<<endl;
        cout<<"press F: if you want to check hash table is FULL:  "<<endl;
        cout<<"press S: if you want to DISPLAY:  "<<endl;
        cout<<"press N: if you want to STOP PROGRAME:  "<<endl;
        cout<<"------------------------------------------------- "<<endl;
        cout<<"enter character which you want to perform:"<<endl;
    cin>>c;
        if(c=='A')
        {
                 int value;
        cout<<"enter value for insertion:"<<endl;
        cin>>value;
        obj.addelement(value);

        }


    else if(c=='S')
    {
         int value;
        cout<<"enter value for search:"<<endl;
        cin>>value;
        obj.search(value);

    }
    else if(c=='R')
    {
         int value;
        cout<<"enter value which you want to delete:"<<endl;
        cin>>value;
        obj.delete_n(value);

    }
    else if(c=='D')
    {
         obj.display();
    }
    else if(c=='F')
    {

        obj.isfull();

    }
    else if(c=='E')
    {

        obj.isempty();

    }
    else if(c=='N')
    {

        break;

    }

    /*obj.addelement(12);

obj.addelement(40);
obj.addelement(41);
obj.addelement(33);
obj.addelement(32);
obj.addelement(20);
obj.addelement(22);
obj.addelement(34);
obj.addelement(3);
     // obj.addelement(300);
    // obj.addelement(44);
//obj.addelement(25);

       //obj.addelement(22);

   // obj.addelement(35);

    cout << "Hello world!" << endl;
//obj.search(25);
obj.search(33);
obj.search(12);
 obj.delete_n(20);

//obj.delete_n(33);
obj.isempty();
obj.isfull();
    obj.display();
    */
    }
    return 0;
}

