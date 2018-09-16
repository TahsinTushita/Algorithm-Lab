#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

#define SIZE 20

struct DataElements
    {
        struct Data{
            int n;
            double d;
            string s;
        };
        Data data;
        int key;
    };

struct DataElements* itemList[SIZE];
struct DataElements* singleItem;
struct DataElements* item;

int hashFunction(int key)
    {
        return key%SIZE;
    }

void insertElement(int key,int n,double d,string s)
    {
        struct DataElements *item = (struct DataElements*) malloc(sizeof(struct DataElements));
        item->key = key;
        item->data.n = n;
        item->data.d = d;
        item->data.s = s;

        int hashIndex = hashFunction(key);

        while(itemList[hashIndex]!=NULL && itemList[hashIndex]->key!=-1){
            ++hashIndex;
            hashIndex%=SIZE;
        }
        itemList[hashIndex] = item;
    }


struct DataElements *find(int key)
    {
        int hashIndex = hashFunction(key);

        while(itemList[hashIndex]!=NULL){
            if(itemList[hashIndex]->key==key)
                return itemList[hashIndex];
            ++hashIndex;
            hashIndex%=SIZE;
        }
        return NULL;
    };

struct DataElements* del(struct DataElements* item)
    {
        int key = item->key;
        int hashIndex = hashFunction(key);

        while(itemList[hashIndex]!=NULL){
            if(itemList[hashIndex]->key==key){
                struct DataElements* temp = itemList[hashIndex];
                itemList[hashIndex] = singleItem;

                cout<<"Deleted item: "<<temp->key<<","<<temp->data.n<<","<<temp->data.d<<","
                        <<temp->data.s<<"\n";
                return temp;
            }
            ++hashIndex;
            hashIndex%=SIZE;
        }
        return NULL;
    };

void show()
    {
        for(int i=0;i<SIZE;i++){
            if(itemList[i]!=NULL)
                cout<<"("<<itemList[i]->key<<","<<itemList[i]->data.n<<","<<itemList[i]->data.d<<","
                    <<itemList[i]->data.s<<")"<<" ";
            else
                cout<<" --- ";
        }
        cout<<"\n";
    }

int main()
    {
        singleItem = (struct DataElements*) malloc(sizeof(struct DataElements));
        singleItem->key = -1;
        singleItem->data.n = -1;
        singleItem->data.d = -1;
        singleItem->data.s = "null";

        insertElement(10,20,2.5,"hi");
        insertElement(5,55,20.8,"hey");
        insertElement(485,85,9.6,"how are you?");
        insertElement(88,47,6.69,"string");

        show();
        item = find(5);

        if(item!=NULL)
            cout<<"Item found: "<<item->data.n<<","<<item->data.d<<","<<item->data.s<<"\n";
        else
            cout<<"Item not found\n";

        del(item);
        show();

        return 0;
    }
