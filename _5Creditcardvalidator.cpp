
#include <iostream>
#include<stdio.h>
#include <string>

using namespace std;

bool isNumberString(const string& s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main() {
    string CcNumber;
    while (true) {
        
        cout << "Please enter a CC number to validate: ";
        cin >> CcNumber;
        
        if (CcNumber == "exit")
            break;
        
        else if (!isNumberString(CcNumber)) {
            cout << "Please Input a valid credit card number ";
            continue;
        }  
        int len = CcNumber.length();
        int SumevenDouble = 0;
        for (int i = len - 2; i >= 0; i = i - 2) {
            int dubl = ((CcNumber[i] - '0') * 2);
            if (dubl > 9) {
                dubl = (dubl / 10) + (dubl % 10);
            }
            SumevenDouble += dubl;
        }
        
        for (int i = len - 1; i >= 0; i = i - 2) {
            SumevenDouble+= (CcNumber[i] - '0');
        }
        
        if(SumevenDouble % 10 == 0){
            cout<<"valid credit card number";
        }
        else{
            cout<<"Not a valid credit card";
        }
        cout<<endl;
        continue;        
    }

    return 0;
}