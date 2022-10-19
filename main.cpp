#include <iostream>

using namespace std;

#define MAX_STACK 30
char stacklama[MAX_STACK]{'H','A','*','*','*','L','*','O','A','P','*','*','*','A','*','K','*','A','*','B','*','A','R'};
char stackbaru[MAX_STACK]{};
char isi;
int top=-1;

bool isFull(){
    if(top >= MAX_STACK){
        return true;
    }else{
        return false;
    }
}

bool isEmpty(){
    if(top == -1){
        return true;
    }else{
        return false;
    }
}

void push(){
    if(!isFull()){
        top++;
        stackbaru[top]=isi;
    }
}

void proses(){
    for(int i=0; i<MAX_STACK; i++){
        if(stacklama[i]=='*'){

        }else{
            isi=stacklama[i];
            push();
        }
    }
}


int main()
{
    for(int s=0; s<MAX_STACK; s++){
        cout<<stacklama[s];
    }
    cout << endl;

    proses();
    for(int t=0; t<MAX_STACK; t++){
        cout <<stackbaru[t];
    }
    cout << endl;


    return 0;
}




