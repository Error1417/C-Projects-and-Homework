/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ismael Perez
 * Purpose: Randomize the cards the person gets for black jack
 * Goal: This program should output two cards for the player and the AI(Dealer)
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
 * Make the cards in a file
 */
int main(int argc, char** argv) 
{
    srand(static_cast<unsigned int>(time(0)));
    
    char resp;
    
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
        for(int i = 0; i <= 13; i++){
        string card1;
        outFile >> card1;
        cout << card1 << endl;
        }
        
        
        
        inFile.close();
        outFile.close();
        
        cout << "Play again?" << endl;
        cin >> resp;
        
    }while(resp == 'y' || resp =='Y');

    return 0;
}

