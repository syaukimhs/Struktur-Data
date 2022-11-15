#include <iostream>

using namespace std;

struct pln{
    //data
    int nomorplg;
    string namaplg;
    int tagihan;

    //pointer
    pln *next;
};

 pln *pelanggan,*cur, *head;

 void cetak(){
    cur = head;
    while(cur!=NULL)
    {
        cout <<"nomor \t:"<< cur->nomorplg<<endl;
        cout <<"nama \t:"<< cur->namaplg<<endl;
        cout <<"tagihan :"<< cur->tagihan<<endl;
        cout << endl;
        cur = cur->next;
    }
 }

 void buatNode(int nmr, string nm, int tghn){
   pelanggan = new pln();
   pelanggan -> nomorplg = nmr;
   pelanggan -> namaplg = nm;
   pelanggan -> tagihan = tghn;
   pelanggan -> next = NULL;
   head = pelanggan;
 }

 void tambahDepan(int nmr, string nm, int tghn){
   pelanggan = new pln();
   pelanggan -> nomorplg = nmr;
   pelanggan -> namaplg = nm;
   pelanggan -> tagihan = tghn;
   pelanggan -> next = head;
   head = pelanggan;
 }

  void tambahBelakang(int nmr, string nm, int tghn){
    cur = head;
    while(cur->next!=NULL){
        cur = cur->next;
    }
   pelanggan = new pln();
   pelanggan -> nomorplg = nmr;
   pelanggan -> namaplg = nm;
   pelanggan -> tagihan = tghn;
   //pelanggan -> next = NULL;
   cur->next = pelanggan;
   pelanggan -> next = NULL;
 }

 void menu (int pil){
    int nomor, tagihan;
    string nama;
    switch(pil){
    case 1:
        cout << "Masukan Nomor Pelanggan : ";
        cin >> nomor;
        cout << "Masukan Nama Pelanggan : ";
        cin >> nama;
        cout << "Masukan Tagihan Pelanggan : ";
        cin >> tagihan;
        buatNode(nomor, nama, tagihan);
        break;

    case 2:
        cout << "Masukan Nomor Pelanggan : ";
        cin >> nomor;
        cout << "Masukan Nama Pelanggan : ";
        cin >> nama;
        cout << "Masukan Tagihan Pelanggan : ";
        cin >> tagihan;
        tambahDepan(nomor, nama, tagihan);
        break;

    case 3:
        cout << "Masukan No Pelanggan : ";
        cin >> nomor;
        cout << "Masukan Nama Pelanggan : ";
        cin >> nama;
        cout << "Masukan Tagihan Pelanggan : ";
        cin >> tagihan;
        tambahBelakang(nomor, nama, tagihan);
        break;

    case 4:
        cetak();
        break;

    default :
        cout << "Inputan Tidak Valid"<<endl;
        break;
    }
 }

int main()
{
    int pilih;
    do{
        cout << "1. Buat Node"<<endl;
        cout << "2. Tambah Depan"<<endl;
        cout << "3. Tambah Belakang"<<endl;
        cout << "4. Tampilkan"<<endl;
        cout << "Masukkan Pilihan Anda : ";
        cin >> pilih;
        cout << endl;
        menu(pilih);
        cout <<endl;
    } while(pilih != 0);










    /*buatNode(8795,"Damian",10000);
    tambahDepan(1234,"wulan",15000);
    tambahDepan(5678,"Dirga",20000);
    tambahBelakang(4567,"Mulyana",25000);
    tambahBelakang(4567,"Dania",30000);
    cetak();
   /*pelanggan = new pln();
   pelanggan -> nomorplg = 1234;
   pelanggan -> namaplg = "dia";
   pelanggan -> tagihan = 1000;
   pelanggan2 = new pln();
   pelanggan2 -> nomorplg = 5678;
   pelanggan2 -> namaplg = "kamu";
   pelanggan2 -> tagihan = 1500;
   pelanggan3 = new pln();
   pelanggan3 -> nomorplg = 9098;
   pelanggan3 -> namaplg = "aku";
   pelanggan3 -> tagihan = 2000;
    /*cout << pelanggan -> nomorplg <<endl;
    cout << pelanggan -> namaplg <<endl;
    cout << pelanggan -> tagihan <<endl;
    //cout << pelanggan -> next << endl;
    cout << endl;
    cout << pelanggan2 -> nomorplg <<endl;
    cout << pelanggan2 -> namaplg <<endl;
    cout << pelanggan2 -> tagihan <<endl;
    //cout << pelanggan2 -> next << endl;
    cout << endl;
    cout << pelanggan3 -> nomorplg <<endl;
    cout << pelanggan3 -> namaplg <<endl;
    cout << pelanggan3 -> tagihan <<endl;
    //cout << pelanggan3 -> next << endl;
    cout << endl;


    pelanggan -> next = pelanggan2;
    pelanggan2 -> next = pelanggan3;
    pelanggan3 -> next = NULL;

    cur = pelanggan;
    while(cur!=NULL)
    {
        cout << cur->nomorplg<<endl;
        cout << cur->namaplg<<endl;
        cout << cur->tagihan<<endl;
        cur = cur->next;
    }*/




    return 0;
}
