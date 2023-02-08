#include "Tools.h"
#include <stdlib.h>
#include <iostream>
#include <string>

bool Tools::canStringToInt(std::string testString){
    bool isPossible = false;
    int testStringLen = testString.length();
    char *tempString = new char[testStringLen];
    for(int i = 0; i < testStringLen; i++){
        tempString[i] = testString.at(i);
    }
    if(atoi(tempString)){
        isPossible = true;
    }
    delete tempString;
    return isPossible;

}

int Tools::stringToInt(std::string testString){

    if(Tools::canStringToInt(testString)){
        int testStringLen = testString.length();
        char *tempString = new char[testStringLen];
        for(int i = 0; i < testStringLen; i++){
            tempString[i] = testString.at(i);
        }
        int returnInt = atoi(tempString);
        delete tempString;
        return returnInt;

    } else {
        return NULL;
    }

}

int Tools::getUserInputAsInt(){
    std::string userInput;
    std::cin >> userInput;
    if(Tools::canStringToInt(userInput)){
        return stringToInt(userInput);
    }else{
        return NULL;
    }
}

int Tools::questionAsInt(std::string questionString){

    std::cout << questionString << std::endl;

    bool askQuestion = true;
    int userAnswer;

    do{

        int checkNum = Tools::getUserInputAsInt();

        if(checkNum != NULL){
            userAnswer = checkNum;
            askQuestion = false;
        } else {
            std::cout << "Please enter your answer in Integer form." << std::endl;
            std::cout << questionString << std::endl;
        }


    }while(askQuestion);
    


}