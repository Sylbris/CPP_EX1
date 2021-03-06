#include <iostream>
#include <string>
#include <stdexcept>
#include "snowman.hpp"
using namespace std;


    //////////////////////// ---------------HNLRXYTB------------////////////////////////////
    const char *Head[4] = { "       \n _===_ ", "  ___  \n ..... ", "   _   \n  /_\\  ", "  ___  \n (_*_) " };
    const char *Nose[4] = { ",", ".", "_", " " };
    const char *Eye[4] = { ".", "o", "O", "-" };
    const char *Left_hand_u[4] = { " ", "\\", " ", " " };
    const char *Left_hand[4] = { "<", " ", "/", " " };
    const char *Right_hand_u[4] = { " ", "/", " ", " " };
    const char *Right_hand[4] = { ">", " ", "\\", " " };
    const char *Torso[4] = { " : ", "] [", "> <", "   " };
    const char *Base[4] = { " : ", "\" \"", "___", "   " };

int char_to_dig(char a){
    return (a-'0')-1; 
}

namespace ariel 
{


    string snowman(int num){
        string sm = to_string(num);
        if(sm.size()!=8) throw "number is invalid";
        for (int i = 0; i < sm.size(); i++){ 
             if((int)(sm[i] - '0') > 4 || (int)(sm[i] - '0') < 1) throw "Number not good";
        }
        return 
        string(Head[char_to_dig(sm[0])]) + "\n"+ 
        string(Left_hand_u[char_to_dig(sm[4])])+ "(" +
        string(Eye[char_to_dig(sm[2])]) + 
        string(Nose[char_to_dig(sm[1])])+ 
        string(Eye[char_to_dig(sm[3])]) +   ")" + 
        string(Right_hand_u[char_to_dig(sm[5])]) + "\n" + 
        string(Left_hand[char_to_dig(sm[4])]) + "("+ 
        string(Torso[char_to_dig(sm[6])] ) + ")" + 
        string(Right_hand[char_to_dig(sm[5])]) + "\n" + " (" + 
        string(Base[char_to_dig(sm[7])]) + ") " ;

    };
};