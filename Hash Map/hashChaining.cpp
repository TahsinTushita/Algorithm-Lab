#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

#define SIZE 20

struct DataElements
    {
        int key;
        int data;
    };

struct DataElements* itemList[SIZE][SIZE];
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
        int i = 0;

        while(itemList[hashIndex][i]!=NULL && itemList[hashIndex][i]->key!=-1){
            ++i;
            i%=SIZE;
        }
        itemList[hashIndex][i] = item;
    }


struct DataElements *find(int key)
    {
        int hashIndex = hashFunction(key);
        int i = 0;

        while(itemList[hashIndex][i]!=NULL){
            if(itemList[hashIndex][i]->key==key)
                return itemList[hashIndex][i];
            ++i;
            i%=SIZE;
        }
        return NULL;
    };

struct DataElements* del(struct DataElements* item)
    {
        int key = item->key;
        int hashIndex = hashFunction(key);
        int i = 0;

        while(itemList[hashIndex][i]!=NULL){
            if(itemList[hashIndex][i]->key==key){
                struct DataElements* temp = itemList[hashIndex][i];
                itemList[hashIndex][i] = singleItem;

                cout<<"Deleted item: "<<temp->key<<","<<temp->data<<"\n";
                return temp;
            }
            ++i;
            i%=SIZE;
        }

//        for(int i=0;i<SIZE;i++){
//            while(itemList[hashIndex][i]!=NULL){
//                if(itemList[hashIndex][i]->key==key){
//                    struct DataElements* temp = itemList[hashIndex][i];
//                    itemList[hashIndex][i] = singleItem;
//                    return temp;
//                }
//            }
//        }
        return NULL;
    };

void show()
    {
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                if(itemList[i][j]!=NULL)
                    cout<<"("<<itemList[i][j]->key<<","<<itemList[i][j]->data<<") ";
                else
                    cout<<" --- ";
            }
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
        insertElement(88,54);

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
