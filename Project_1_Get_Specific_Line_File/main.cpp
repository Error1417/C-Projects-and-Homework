/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ismael Perez
 * Purpose: Getting specific line from file
 *
 * Created on April 17, 2022, 6:15 PM
 */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    srand(static_cast<unsigned int>(time(0)));
    
    char resp;
    int dealer,
        player;
    
    //File I/O
    ofstream inFile;
    ifstream outFile;
    string filename;
    filename = "Cards.txt";

    do 
    {
        //This is whats in the file
        inFile.open(filename, ios::in);
        inFile << "Ace\n" << "King\n" << "Queen\n" << "Jack\n"
               << "Ten\n" << "Nine\n" << "Eight\n" << "Seven\n"
               << "Six\n" << "Five\n" << "Four\n" << "Three\n"
               << "Two\n" << "One\n";
        
        //What comes out of the file.
        outFile.open(filename, ios::in);
        string card1,card2,card3,card4,card5,card6,card7,card8,card9,card10,card11,card12,card13,card14;
        outFile>>card1>>card2>>card3>>card4>>card5>>card6>>card7>>card8>>card9>>card10>>card11>>card12>>card13>>card14;
        
        
        //cards for the dealer
        for(int i = 0; i < 2; i++){
            int shuffle = rand()% 14 + 1;
            switch(shuffle){
                case 1:
                    cout << card1 << endl;
                    break;
                case 2:
                    cout << card2 << endl;
                    break;
                case 3:
                    cout << card3 << endl;
                    break;
                case 4:
                    cout << card4 << endl;
                    break;
                case 5:
                    cout << card5 << endl;
                    break;
                case 6:
                    cout << card6 << endl;
                    break;
                case 7:
                    cout << card7 << endl;
                    break;
                case 8:
                    cout << card8 << endl;
                    break;
                case 9:
                    cout << card9 << endl;
                    break;
                case 10:
                    cout << card10 << endl;
                    break;
                case 11:
                    cout << card11 << endl;
                    break;
                case 12:
                    cout << card12 << endl;
                    break;
                case 13:
                    cout << card13 << endl;
                    break;
                case 14:
                    cout << card14 << endl;
                    break;
            }
        }
        
        
        //cards for the player
        for(int i = 0; i < 2; i++){
            int shuffle = rand()% 14 + 1;
            switch(shuffle){
                case 1:
                    cout << card1 << endl;
                    break;
                case 2:
                    cout << card2 << endl;
                    break;
                case 3:
                    cout << card3 << endl;
                    break;
                case 4:
                    cout << card4 << endl;
                    break;
                case 5:
                    cout << card5 << endl;
                    break;
                case 6:
                    cout << card6 << endl;
                    break;
                case 7:
                    cout << card7 << endl;
                    break;
                case 8:
                    cout << card8 << endl;
                    break;
                case 9:
                    cout << card9 << endl;
                    break;
                case 10:
                    cout << card10 << endl;
                    break;
                case 11:
                    cout << card11 << endl;
                    break;
                case 12:
                    cout << card12 << endl;
                    break;
                case 13:
                    cout << card13 << endl;
                    break;
                case 14:
                    cout << card14 << endl;
                    break;
            }
        }
        
        
        
        
        
        inFile.close();
        outFile.close();
        
        cout << "Play again?" << endl;
        cin >> resp;
        
    }while(resp == 'y' || resp =='Y');
    
    

    return 0;
}

