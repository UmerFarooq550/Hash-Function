/*
CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name(s): Umer Abbasi, Zaha Abbasi
Your team alias: SCNZCREW
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "hash.h"
using namespace std;

extern int g_k;
struct Node {
    string key;
    Node* next;
};

int main() {

    int k = 0;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

     // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // The template is able to be compiled by running 
    //   make
    //   ./encoder < inputs/sample_input.txt
    // which puts out the placeholders only.

    // Your time to shine starts now
    g_k = k;
    Node** table=new Node*[k];
    for (int i=0;i<k;i++) {
        table[i]=nullptr;
    }

    for (int i=0;i<n;i++) {
        int slot=hash_function(texts[i]);
        Node* newNode=new Node();
        newNode->key=texts[i];
        newNode->next=table[slot];
        table[slot]=newNode;
    }

    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    int limit=(k<5)?k:5;
    for (int i=0;i<limit;i++) {
        cout<<"Slot "<<i<<":";
        Node* cur=table[i];
        while (cur!=nullptr) {
            cout<<" "<<cur->key;
            cur=cur->next;
        }
        cout << endl;
    }
    cout << "==== Printing the slot lengths ====" << endl;
    int* lengths=new int[k];
    for (int i=0;i<k;i++) {
        int len=0;
        Node* cur=table[i];
        while (cur!=nullptr) {
            len++;
            cur=cur->next;
        }
        lengths[i]=len;
        cout<<"Slot "<<i<<": "<<len<<endl;
    }
    cout<< "==== Printing the standard deviation ====" << endl;
    double sum=0.0;
    for (int i=0;i<k;i++)sum+=lengths[i];
    double mean=sum/k;

    double variance=0.0;
    for (int i=0;i<k;i++) {
        double diff=lengths[i]-mean;
        variance+=diff*diff;
    }
    variance/=k;
    double stddev=sqrt(variance);
    cout<<fixed<<setprecision(4)<<stddev<<endl;
    for (int i=0;i<k;i++) {
        Node* cur=table[i];
        while (cur!=nullptr) {
            Node* tmp=cur;
            cur=cur->next;
            delete tmp;
        }
    }
    delete[] table;
    delete[] lengths;
    return 0;
}
