#include<iostream>  
#include<string>  
#include<cstring>  
#include<sstream>  
  
using namespace std;  
  
int hextoint(string input){  
    int output;  
    stringstream temp;  
    temp << hex << input;  
    temp >> output;  
    return output;  
}  
  
void run(string code, int P, int B, int judge){  
    string table[64] = {"LDA","LDX","LDL","STA",  
        "STX","STL","ADD","SUB",  
        "MUL","DIV","COMP","TIX",  
        "JEQ","JGT","JLT","J",  
        "AND","OR","JSUB","RSUB",  
        "LDCH","STCH","ADDF","SUBF",  
        "MULF","DIVF","LDB","LDS",  
        "LDF","LDT","STB","STS",  
        "STF","STT","COMPF","",  
        "ADDR","SUBR","MULR","DIVR",  
        "COMPR","SHIFTL","SHIFTR","RMO",  
        "SVC","CLEAR","TIXR","",  
        "FLOAT","FIX","NORM","",  
        "LPS","STI","RD","WD",  
        "TD","","STSW","SSK",  
        "SIO","HIO","TIO",""};  
      
    string mnemonic[10] = {"A", "X", "L", "B", "S", "T", "F", "", "PC", "SW"};  
  
    string temp;  
  
    if(code[0]=='C' || code[0]=='F'){  
        cout << table[judge/4] << endl;  
    }  
    else if(code[0]=='9' || code[0]=='A' || code[0]=='B'){  
        cout << table[judge/4];  
        if(code[0]=='B'){  
            int r1;  
            temp = code[2];  
            r1 = hextoint(temp);  
            cout << " " << mnemonic[r1] << endl;  
        }  
        else{  
            int r1, r2;  
            temp = code[2];  
            r1 = hextoint(temp);  
            temp = code[3];  
            r2 = hextoint(temp);  
            cout << " " << mnemonic[r1] << "," << mnemonic[r2] << endl;  
        }  
    }  
    else{  
        temp = code[2];  
        int n=0, i=0, x=0, b=0, p=0, e=0;  
        e = hextoint(temp);  
        if(e/8 == 1){  
            x=1;  
            e=e-8;}  
        if(e/4 == 1){  
            b=1;  
            e=e-4;}  
        if(e/2 == 1){  
            p=1;  
            e=e-2;}  
        if(e==1)  
            e=1;  
          
        temp = code[1];  
        i = hextoint(temp);  
        if(i/8 == 1)  
            i=i-8;  
        if(i/4 == 1)  
            i=i-4;  
        if(i/2 == 1){  
            n = 1;  
            i=i-2;}  
        if(i==1)  
            i=1;  
          
        cout << table[judge/4] << " ";  
  
        int three=0, four=0, five=0, six=0;  
        string num;  
        num=num.assign(code,3,3);  
        three = hextoint(num);  
        if(b==1)  
            three = three + B;  
        if(p==1)  
            three = three + P;  
        num=num.assign(code,2,4);  
        four = hextoint(num);  
        num=num.assign(code,3,5);  
        five = hextoint(num);  
        if(b==1)  
            five = five + B;  
        if(p==1)  
            five = five + P;  
        num=num.assign(code,2,6);  
        six = hextoint(num);  
  
        //format3  
        if(e==0){  
            if(n==0 && i==0){  
                temp = code[2];  
                if(x == 1)  
                    four = four - 32768;  
                cout << four;  
                if(x==1)  
                    cout << ",X";  
                cout << endl;  
            }  
            else if(n==0 && i==1){  
                if(judge == 81){  
                    temp = three;  
                    cout << temp;  
                    if(x==1)  
                        cout << ",X";  
                    cout << endl;  
                }  
                else{  
                    cout << "#" << three;  
                    if(x==1)  
                        cout << ",X";  
                    cout << endl;  
                }  
            }  
            else{  
                cout << three;  
                if(x==1)  
                    cout << ",X";  
                cout << endl;  
            }     
        }  
        //format4  
        else{  
            if(n==0 && i==0){  
                if(x == 1)  
                    six = six - 131072;  
                if(x==1)  
                    cout << six << ",X" << endl;  
                else  
                    cout << six << endl;  
            }  
            else if(n==0 && i==1){  
                if(judge==81){  
                    temp = five;  
                    cout << temp;  
                    if(x==1)  
                        cout << ",X";  
                    cout << endl;  
                }  
                else{  
                    cout << "#" << five;  
                    if(x==1)  
                        cout << ",X";  
                    cout << endl;  
                }  
            }  
            else{  
                cout << five;  
                if(x==1)  
                    cout << ",X";  
                cout << endl;  
            }  
        }  
    }  
}  
int main(){  
  
    char input;  
    string P, B;  
    int p, b;  
    cout << "hello:104703031" << endl;
    cin >> input >> P >> input >> B;  
  
    p=hextoint(P);  
    b=hextoint(B);  
  
    string code;  
  
    while(cin >> code){  
        string icode;  
        icode=icode.assign(code,0,2);  
        int judge;  
        judge = hextoint(icode);  
        run(code,p,b,judge);  
    }  
    return 0;  
} 
