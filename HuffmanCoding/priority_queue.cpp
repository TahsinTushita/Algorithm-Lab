#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node(int a) {
        key = a;
    }
};

struct compare{
    bool operator() (Node *a,Node *b){
        return a->key > b->key;
    }
};

int main()
    {
        Node *a = new Node(5);
        Node *b = new Node(4);
        Node *c = new Node(8);

        priority_queue<Node*,vector<Node*>,compare> myqueue;
        myqueue.push(a);
        myqueue.push(b);
        myqueue.push(c);
        while(!myqueue.empty()){
            Node *temp = myqueue.top();
            myqueue.pop();
            cout<<temp->key<<"\n";
        }
        return 0;
    }
