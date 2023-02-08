#include <iostream>
#include "./pokemon.h"
#include "./pokedex.h"
#include "./Tools.h"
#include <fstream>
using namespace std;
//Compile using: g++ pokemon.cpp pokedex.cpp driver.cpp-o lab2 ./lab2

int main(){
    Tools T;
    fstream f;
    ifstream fin("inputs.txt");
    Pokedex inputs(fin);
    inputs.get_pokemon_info(fin);
    string outputfile;
    cout << "What is the name of the output file? (file name(.txt) ";
    cin >> outputfile;
    //fin.open(outputfile.c_str(), ios::app);
    ofstream fout(outputfile.c_str(), ios::app);
    /*
    while(!fout.is_open()){
        cout << "What is the name of the output file? (file name(.txt) ";
        cin >> outputfile;
        ofstream fout(outputfile.c_str(), ios::app);
    }
    
    /*
    
    while (outputfile_truth==false){
        try {
            
            outputfile_truth==true;
            }
           
    }
    */
    


    //inputs.setFilename("outputs.txt");
    //for (int i = 0; i<inputs.get_num_pokemon(); i++){
        //inputs.dex[i].print_info();
    //}
    bool run;
    run = true;
    while (run==true){
        cout << "Would you like to search for Pokemon? (Y/N) ";
        string answer;
        cin >> answer;
        if (answer=="Y"){
            cout << "Would you like to search for a Pokemon by dex number(1) or by type(2)?"<<endl;
            int searchoption;
            cin >> searchoption;
            if (searchoption == 1){
                cout <<"Whats the dex number of Pokemon are you looking for: ";
                int searchdex;
                cin >> searchdex;
                inputs.search_by_dex_number(fout, searchdex);
                
            }   

            if (searchoption == 2){
                cout <<"Whats the type of Pokemon are you looking for: ";
                string searchtype;
                cin >> searchtype;
                inputs.search_by_type(fout, searchtype);
            }

        }
        if (answer=="N"){
            run = false;
        }


        
    }
    
    
    


    


    



    
    
    
    return 0;
}