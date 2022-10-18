#include <iostream>

using namespace std;
#define MAX 8

struct Antrian {
    int data[MAX];
    int head;
    int tail;
};

Antrian antre;
void create();
bool isEmpty();
bool isFull();
void enqueue(int);
int dequeue();
void tampil();

int main()
{
    int pilih, data;

    queue :
        //system("cls");
        cout <<"1. Tambah Antrian "<<endl;
        cout <<"2. Panggil Antrian "<<endl;
        cout <<"3. Tampilkan Antrian "<<endl;
        cout <<"4. Keluar "<<endl;

        cout <<"pilih : ";
        cin >> pilih;
        cout <<endl;

        switch(pilih){
            case 1 : cout <<"Tambahkan data : ";
                     cin >> data;
                     enqueue(data);
                     goto queue;
            break;
            case 2 : cout <<"panggil data : "<<endl;
                     dequeue();
                     goto queue;
            break;
            case 3 : cout <<"Tampilkan data : "<<endl;
                     tampil();
                     goto queue;
            break;
            case 4 : cout <<"Keluar"<<endl;
                     goto queue;
            break;

            default : cout <<"Inpit Salah";
            break;
        }



    return 0;
}

void create(){
    antre.head = antre.tail = -1;
}

bool isEmpty(){
    if(antre.tail == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(){
    if(antre.tail == MAX)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(int data){
    if(isFull())
    {
        cout <<"Antrian penuh\n";
    }
    else
    {
        if(isEmpty())
        {
            antre.head = antre.tail = 0;
            antre.data[antre.tail] = data;
            antre.head++;
            antre.tail++;
        }
        else
        {
           antre.data[antre.tail] = data;
           antre.tail++;
           cout << data<<"\nmasuk ke dalam antrian\n";
        }
    }
}

int dequeue(){
    if(isEmpty())
    {
        cout <<"Antrian Kosong";
    }
    else
    {
        int i;
        int e = antre.data[antre.head];
        for(i = 0; i <= antre.tail; i++){
            antre.data[i] = antre.data[i+1];
        }
        antre.tail--;
        return e;
    }

}

void tampil(){
    cout <<"\nData antrian : \n";
    if(isEmpty()){
        cout  <<"Antrian Kosong\n";
    }
    else{
        for(int i = 0; i<MAX; i++){
            if(antre.data[i] == NULL){
                cout <<i+1<<". Data Kosong\n";
            }
            else{
                cout << i+1<<". "<<antre.data[i]<<endl;
            }
        }
    }
    cout<<endl<<endl;
}
