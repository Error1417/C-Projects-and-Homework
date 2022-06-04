/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ismael Perez
 * Purpose: Giving the cards to the dealer and the player
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
    int dealer = 0,
        player = 0,
        balance = 0;
    
    //File I/O
    ofstream inFile;
    ifstream outFile;
    string filename;
    filename = "Cards.txt";
    
    cout << "|--WELCOME TO BLACK JACK--|" << endl;
    
    do 
    {
        cout << "Your cards are being handed out!" << endl;
        
        
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
        for(int i = 0; i < 2; i++){ // needed to make two for loops because functions cant be used.
            int shuffle = rand()% 14 + 1;
            switch(shuffle){
                case 1:
                    cout << card1 << endl;
                    if(card1 == "Ace") dealer += 11;
                    break;
                case 2:
                    cout << card2 << endl;
                    if(card2 == "King") dealer += 10;
                    break;
                case 3:
                    cout << card3 << endl;
                    if(card3 == "Queen") dealer += 10;
                    break;
                case 4:
                    cout << card4 << endl;
                    if(card4 == "Jack") dealer += 10;
                    break;
                case 5:
                    cout << card5 << endl;
                    if(card5 == "Ten") dealer += 10;
                    break;
                case 6:
                    cout << card6 << endl;
                    if(card6 == "Nine") dealer += 9;
                    break;
                case 7:
                    cout << card7 << endl;
                    if(card7 == "Eight") dealer += 8;
                    break;
                case 8:
                    cout << card8 << endl;
                    if(card8 == "Seven") dealer += 7;
                    break;
                case 9:
                    cout << card9 << endl;
                    if(card9 == "Six") dealer += 6;
                    break;
                case 10:
                    cout << card10 << endl;
                    if(card10 == "Five") dealer += 5;
                    break;
                case 11:
                    cout << card11 << endl;
                    if(card11 == "Four") dealer += 4;
                    break;
                case 12:
                    cout << card12 << endl;
                    if(card12 == "Three") dealer += 3;
                    break;
                case 13:
                    cout << card13 << endl;
                    if(card13 == "Two") dealer += 2;
                    break;
                case 14:
                    cout << card14 << endl;
                    if(card14 == "One") dealer += 1;
                    break;
            }
        }
        cout << "Dealer Cards = " << dealer << endl << endl; //dealers cards will be hidden in the final
                                                             //iteration of the game until the player 
                                                             //selects stand.
        
        //cards for the player
        for(int i = 0; i < 2; i++){
            int shuffle = rand()% 14 + 1;
            switch(shuffle){
                case 1:
                    cout << card1 << endl;
                    if(card1 == "Ace")player += 11;
                    break;
                case 2:
                    cout << card2 << endl;
                    if(card2 == "King")player += 10;
                    break;
                case 3:
                    cout << card3 << endl;
                    if(card3 == "Queen")player += 10;
                    break;
                case 4:
                    cout << card4 << endl;
                    if(card4 == "Jack")player += 10;
                    break;
                case 5:
                    cout << card5 << endl;
                    if(card5 == "Ten")player += 10;
                    break;
                case 6:
                    cout << card6 << endl;
                    if(card6 == "Nine")player += 9;
                    break;
                case 7:
                    cout << card7 << endl;
                    if(card7 == "Eight")player += 8;
                    break;
                case 8:
                    cout << card8 << endl;
                    if(card8 == "Seven")player += 7;
                    break;
                case 9:
                    cout << card9 << endl;
                    if(card9 == "Six")player += 6;
                    break;
                case 10:
                    cout << card10 << endl;
                    if(card10 == "Five")player += 5;
                    break;
                case 11:
                    cout << card11 << endl;
                    if(card11 == "Four")player += 4;
                    break;
                case 12:
                    cout << card12 << endl;
                    if(card12 == "Three")player += 3;
                    break;
                case 13:
                    cout << card13 << endl;
                    if(card13 == "Two")player += 2;
                    break;
                case 14:
                    cout << card14 << endl;
                    if(card14 == "One")player += 1;
                    break;
            }
        }
        cout << "Player Cards = " << player << endl << endl; // displays the cards the player got 
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        inFile.close();
        outFile.close();
        
        cout << "Play again?" << endl;
        cin >> resp;
        cout << endl;
        
        if(resp == 'y' || resp =='Y'){ // card values get reset to zero every time the player plays again.
            dealer = 0;                // balance will be staying the same until game is exited
            player = 0;
        }
        
    }while(resp == 'y' || resp =='Y');
    
    

    return 0;
}

