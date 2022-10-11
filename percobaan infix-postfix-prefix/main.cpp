#include <iostream>
#include <string>
#define MAX 20

using namespace std;
int top = -1;
int stk [MAX];

int priority(char alpha){
    if(alpha == '+' || alpha == '-'){
        return 1;
    }

    if(alpha == '*' || alpha == '/'){
        return 2;
    }

    if(alpha == '$'){
        return 3;
    }
    return 0;
}

bool isFull(){
    if(top == MAX - 1 ){
        return true;
    }else {
        return false;
    }
}

bool isEmpty(){
    if(top == -1 ){
        return true;
    }else {
        return false;
    }
}

void push(char oper){
    if(isFull()){
        cout<<"sudah penuh";
    }
    else{
        top++;
        stk[top] = oper;
    }
}

char pop(){
    char ch;
    if(isEmpty()==true){
        cout<<"stack Kosong";
    }else{
        ch = stk[top];
        stk[top]=NULL;
        top--;
        return ch;
    }
    return 0;
}

//Konversi ke Postfix

string in2postfix(string infix){
    int i = 0;
    string pst = "";


    while(infix[i]!='\0'){

        if(infix[i]>='a' && infix[i] <= 'z'){
            pst.insert(pst.end(),infix[i]);
            i++;
        }
        //Jika menemukan bracket maka masukan dalam stack
        else if(infix[i]=='(' || infix[i]=='{' || infix[i]=='['){
            push(infix[i]);
            i++;
        }
        //jika bertemu kurung tutup maka pop
        else if(infix[i]==')' || infix[i]=='}' || infix[i]==']'){
            if(infix[i] == ')'){
                while(stk[top]!= '('){
                    pst.insert(pst.end(),pop());
                }
                pop();
                i++;
            }
            if(infix[i] == '}'){
                while(stk[top]!= '{'){
                    pst.insert(pst.end(),pop());
                }
                pop();
                i++;
            }
            if(infix[i] == ']'){
                while(stk[top]!= '['){
                    pst.insert(pst.end(),pop());
                }
                pop();
                i++;
            }
        }
        else{
            if(top == -1){
                push(infix[i]);
                i++;
            }
            //jika prioritas operator kuarng dari atau sma denan operat yang distack

            //pop operator diposisi top dan tamnbahkan ke pst;

            else if(priority(infix[i]) <= priority(stk[top])){
                pst.insert(pst.end(),pop());

                while(priority(infix[i]) == priority(stk[top])){
                    pst.insert(pst.end(),pop());
                    if(top<0){
                        break;
                    }
                }
                push(infix[i]);
                i++;
            }
            else if(priority(infix[i]) > priority(stk[top])){
                push(infix[i]);
                i++;
            }
        }
    }
    while(top != -1){
        pst.insert(pst.end(),pop());
    }
    cout<<"hasil konversi ke postfix: "<<pst;
    return pst;
}

//reverse

void reverseStr(string& str)
{
    int len = str.length();
    int n = len-1;
    int i = 0;
    while(i<=n){
        //Using the swap method to switch values at each index
        swap(str[i],str[n]);
        n = n-1;
        i = i+1;
  }

}

//Konversi ke prefix
string in2prefix(string infix){
    int i = 0;
    reverseStr(infix);
    string pst = "";

    //selama string ada isinya
    while(infix[i]!='\0'){

        //infix dibaca dari kanan ke kiri berarti braket tutup bernilai braket terbuka.

        //cek jika ketemu alfabet
        if(infix[i]>='a' && infix[i] <= 'z'){
            pst.insert(pst.begin(),infix[i]);
            i++;
        }
        //Jika menemukan bracket maka masukan dalam stack
        else if(infix[i]==')' || infix[i]=='}' || infix[i]==']'){
            push(infix[i]);
            i++;
        }
        //jika bertemu kurung buka maka pop
        else if(infix[i]=='(' || infix[i]=='{' || infix[i]=='['){
            if(infix[i] == '('){
                while(stk[top]!= ')'){
                    pst.insert(pst.begin(),pop());
                }
                pop();
                i++;
            }
            if(infix[i] == '{'){
                while(stk[top]!= '}'){
                    pst.insert(pst.begin(),pop());
                }
                pop();
                i++;
            }
            if(infix[i] == '['){
                while(stk[top]!= ']'){
                    pst.insert(pst.begin(),pop());
                }
                pop();
                i++;
            }
        }
        else{
            if(top== -1){
                push(infix[i]);
                i++;
            }
            //jika prioritas operator kuarng dari atau sma denan operat yang distack,
            //pop operator diposisi top dan tamnbahkan ke pst;

            else if(priority(infix[i]) <= priority(stk[top])){
                pst.insert(pst.begin(),pop());

                while(priority(infix[i]) == priority(stk[top])){
                    pst.insert(pst.begin(),pop());
                    if(top<0){
                        break;
                    }
                }
                push(infix[i]);
                i++;
            }
            else if(priority(infix[i]) > priority(stk[top])){
                push(infix[i]);
                i++;
            }
        }
    }
    while(top != -1){
        pst.insert(pst.begin(),pop());
    }
    cout<<"hasil konversi ke prefix: "<<pst;
    return pst;
}

int main()
{
    string infix,postfix,prefix,tukar;
    string tes;

    cin>>tes;
    postfix = in2postfix(tes);
    cout<<endl;

    prefix = in2prefix(tes);
    cout<<endl;

    return 0;
}





