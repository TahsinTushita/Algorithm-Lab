#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

#define SIZE 20

struct DataElements
    {
        int key;
        int data;
    };

struct DataElements* itemList[SIZE];
struct DataElements* singleItem;
struct DataElements* item;

int hashFunction(int key)
    {
        return key%SIZE;
    }

void insertElement(int key,int data)
    {
        struct DataElements *item = (struct DataElements*) malloc(sizeof(struct DataElements));
        item->key = key;
        item->data = data;

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

                cout<<"Deleted item: "<<temp->key<<","<<temp->data<<"\n";
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
                cout<<"("<<itemList[i]->key<<","<<itemList[i]->data<<")"<<" ";
            else
                cout<<" --- ";
        }
        cout<<"\n";
    }

int main()
    {
        singleItem = (struct DataElements*) malloc(sizeof(struct DataElements));
        singleItem->key = -1;
        singleItem->data = -1;

        insertElement(1,20);
        insertElement(2,70);
        insertElement(10,80);
        insertElement(20,25);
        insertElement(12,44);
        insertElement(14,32);
        insertElement(17,11);
        insertElement(13,78);
        insertElement(37,97);
        insertElement(78,54);

        show();
        item = find(37);

        if(item!=NULL)
            cout<<"Item found: "<<item->data<<"\n";
        else
            cout<<"Item not found\n";

        del(item);
        show();

        return 0;
    }
