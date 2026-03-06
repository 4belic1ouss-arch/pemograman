#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};

node *head = NULL;

void show(){
    node *p = head;

    cout<<"Data : ";
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void addDepan(int x){
    node *baru = new node;

    baru->data = x;
    baru->prev = NULL;
    baru->next = head;

    if(head!=NULL){
        head->prev = baru;
    }

    head = baru;
}

void addBelakang(int x){
    node *baru = new node;
    node *p = head;

    baru->data = x;
    baru->next = NULL;

    if(head==NULL){
        baru->prev = NULL;
        head = baru;
        return;
    }

    while(p->next!=NULL){
        p = p->next;
    }

    p->next = baru;
    baru->prev = p;
}

void addSetelah(int cari, int x){
    node *p = head;

    while(p!=NULL){
        if(p->data==cari){

            node *baru = new node;
            baru->data = x;

            baru->next = p->next;
            baru->prev = p;

            if(p->next!=NULL){
                p->next->prev = baru;
            }

            p->next = baru;
            return;
        }

        p = p->next;
    }

    cout<<"Data tidak ada"<<endl;
}

void hapusDepan(){
    if(head==NULL){
        cout<<"List kosong"<<endl;
        return;
    }

    node *del = head;
    head = head->next;

    if(head!=NULL){
        head->prev = NULL;
    }

    delete del;
}

void hapusBelakang(){
    if(head==NULL){
        cout<<"List kosong"<<endl;
        return;
    }

    node *p = head;

    if(p->next==NULL){
        delete p;
        head = NULL;
        return;
    }

    while(p->next!=NULL){
        p = p->next;
    }

    p->prev->next = NULL;
    delete p;
}

int main(){

    addDepan(10);
    addDepan(5);
    addBelakang(20);
    addSetelah(10,15);

    show();

    hapusDepan();
    show();

    hapusBelakang();
    show();

    return 0;
}