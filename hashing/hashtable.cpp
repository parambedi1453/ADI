// Implementation of hash table with collision handling 
// using linklist and hash

#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class node
{
    public :
    string key;
    T value;
    node<T> *next;

    node(string key,T v)
    {
        this->key = key;
        value = v;
    }
};
template<typename T>
class HashTable
{
    
    int cs;//current size
    int ts;//table size
    node<T> ** b;

public :
    HashTable(int s=7)
    {
        cs =0;
        ts=s;
        b = new node<T>*[ts];
        // make all adresses NULL
        for(int i=0;i<ts;i++){
            b[i]=NULL;
        }
    }
    int hashfunction(string key)
    {
        int l = key.length();
        int a = 0;
        int p = 1;
        for(int i=0;i<l;i++)
        {
            a+=key[l-i-1]*p;
            p=p*37;
            p=p%ts;//so that not oversize because due to oversize -ve ho je ga
            a=a%ts;
        }
        return a;
    }
    void insert(string key,T value)
    {
        int i = hashfunction(key);

        node<T> *n = new node<T>(key,value);
        n->next = b[i];
        b[i]=n;//insertion at head
    }
    void print()
    {
        for(int i=0;i<ts;i++)
        {
            node<T> *temp = b[i];
            cout<<"Pointer array = "<<i<<"--->";
            while(temp)
            {
                cout<<temp->key<<" ->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    node<T> * search (string key)
    {
        int k = hashfunction(key);
        node<T> *temp = b[k];
        while(temp)
        {
            if(key==temp->key)
            {
               return temp;
                // return &(temp->value);//if want to return addresss of value &(temp->value)
            }
            temp=temp->next;
        }
        return NULL;
    }
};
int main()
{
    HashTable<int> h(15);
    h.insert("Mango",100);
    h.insert("Apple",50);
    h.insert("Banana",850);
    h.insert("Guava",1056);
    h.insert("Chiku",80);
    h.print();

    string f;
    cin>>f;

    node<int> *p = h.search(f);
    if(p==NULL)
    cout<<"NOT FOUND"<<endl;
    else
    cout<<p->value<<endl;
    return 0;
}