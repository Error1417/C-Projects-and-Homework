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
 * Created on April 9, 2022, 10:05 PM
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
    int dealer = 0,
        player = 0;
    
    //File I/O
    fstream inFile("Cards.txt");
    
    
    //Cards and their values
    int Ace = 1, King, Queen, Jack, Ten = 10,
        Nine = 9, Eight = 8, Seven = 7, Six = 6,
        Five = 5, Four = 4, Three = 3, Two = 2, One = 1;            
    
    cout << "Welcome to one game casino!" << endl;
    cout << "You only have one choice: Black Jack" << endl << endl;
    cout << "We are currently under construction!!" << endl << endl;
    
    do 
    {
        
        inFile << "Ace\n" << "King\n" << "Queen\n" << "Jack\n"
               << "Ten\n" << "Nine\n" << "Eight\n" << "Seven\n"
               << "Six\n" << "Five\n" << "Four\n" << "Three\n"
               << "Two\n" << "One\n";
        
        for(int i = 0; i <= 14; i++){
            string content;
            inFile >> content;
            cout << content;
        }
        
        
        cout << "Play again?" << endl;
        cin >> resp;
        
    }while(resp == 'y' || resp =='Y');

    inFile.close();

    return 0;
}

