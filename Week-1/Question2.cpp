#include<bits/stdc++.h>
using namespace std;
int main(){
    int i=0,initial = 0,n,state=0;
    char current,input[20];
    cout<<"Enter value of string(only a's and b's): ";
    cin>>input;
    while((current=input[i++])!='\0'){
        switch(state){
            case 0:
            if(current=='a'){
                state=1;
            }
            else if(current=='b'){
                state=3;
            }
            else{
                cout<<"Invalid Input!";
                exit(0);
            }
            break;
            case 1: 
            if(current=='a'){
                state=1;
            }
            else if(current=='b'){
                state=2;
            }
            else{
                cout<<"Invalid Input";
                exit(0);
            }
            break;
            case 2: 
            if(current=='a'){
                state=1;
            }
            else if(current=='b'){
                state=2;
            }
            else{
                cout<<"Invalid Input";
                exit(0);
            }
            break;
            case 3: 
            if(current=='a'){
                state=4;
            }
            else if(current=='b'){
                state=3;
            }
            else{
                cout<<"Invalid Input";
                exit(0);
            }
            break;
            case 4: 
            if(current=='a'){
                state=4;
            }
            else if(current=='b'){
                state=3;
            }
            else{
                cout<<"Invalid Input";
                exit(0);
            }
            break;
        }
    }
    if(state==1 || state==3){
        cout<<"String Accepted!!"<<endl;
    }
    else{
        cout<<"String Not Accepted!!"<<endl;
    }
    return 0;
}