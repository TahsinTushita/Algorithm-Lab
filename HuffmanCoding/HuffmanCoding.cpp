#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode{
    char data;
    unsigned freq;

    MinHeapNode *left,*right;

    MinHeapNode(char data,unsigned freq){
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare{
    bool operator() (MinHeapNode* l,MinHeapNode* r){
        return (l->freq > r->freq);
    }
};


void printCodes(MinHeapNode* root,string str){
    if(!root)
        return;

    if(root->data!='$')
        cout<<root->data<<": "<<str<<"\n";

    printCodes(root->left,str+'0');
    printCodes(root->right,str+'1');
}



void HuffmanCodes(char data[],int freq[],int size){

    struct MinHeapNode *left,*right,*top;

    priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare> huffmanQueue;

    for(int i=0;i<size;i++){
        huffmanQueue.push(new MinHeapNode(data[i],freq[i]));
    }

    while(huffmanQueue.size()!=1){
        left = huffmanQueue.top();
        huffmanQueue.pop();

        right=huffmanQueue.top();
        huffmanQueue.pop();

        top=new MinHeapNode('$',left->freq+right->freq);

        top->left = left;
        top->right = right;

        huffmanQueue.push(top);
    }

    printCodes(huffmanQueue.top(),"");
}


int main()
    {
        char data[] = {'a','b','c','d','e','f'};
        int freq[] = {5,9,12,13,16,45};

        int size = sizeof(data)/sizeof(data[0]);

        HuffmanCodes(data,freq,size);
        return 0;
    }
