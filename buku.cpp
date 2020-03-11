#include <iostream>
#include "buku.h"

void buatList(list &L){
    first(L)=NULL;
    last(L)=NULL;
}
bool listKosong(list L){
    if (first(L)==NULL){
        return true;
    } else return false;
}
address cariElemen(list &L,string x){
    if (first(L)==NULL) {
        address Q;
        Q=first(L);
        while ((info(Q).penerbit!=x) && (next(Q)!=NULL)) {
            Q=next(Q);
        }
        if (Q==NULL){
            return NULL;
        } else return Q;
    }
}
void buatElemen(address &P,string ID,string judul,string pengarang,string penerbit,int tahun){
    P=new elmList;
    info(P).ID=ID;
    info(P).judul=judul;
    info(P).pengarang=pengarang;
    info(P).penerbit;
    info(P).Tahun=tahun;
    next(P)=NULL;
}
void tambahDataTerakhir(list &L, address P){
    if (first(L)==NULL) {
        next(P)=first(L);
        first(L)=P;
    } else {
        address Q=first(L);
        while (next(Q)!=NULL) {
            Q=next(Q);
        }
        next(Q)=P;
    }
}
void tambahDataSetelah(list &L,address prec,address P){
    if (prec!=NULL) {
        next(P)=next(prec);
        next(prec)=P;
    }
}
void hapusDataTerakhir(list &L,address P) {
    if (first(L)!=NULL) {
        address Q=first(L);
        while (next(next(Q))!=NULL) {
            Q=next(Q);
        }
        P=next(Q);
        next(Q)=NULL;
    }
}
void lihatList(list L){
    address P = first(L);
    while (P!=NULL) {
        cout<<info(P).ID<<"     "<<info(P).judul<<"     "<<info(P).pengarang<<"     "<<endl;
        P=next(P);
    }
    cout<<endl;
}
int jumBuku(list L,int thn){
    int i;
    i=0;
    address P=first(L);
    while (next(P)!=NULL){
        if (info(P).Tahun<=thn) {
            i=i+1;
        }
        P=next(P);
    }
    return i;
}
