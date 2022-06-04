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
    
    char resp,    // multiple inputs for the game
         resp2,
         resp3,
         resp4;
    
    int dealer = 0, // card value for dealer
        player = 0, // card value for player
        balance = 0; // balance of the player - might make this a float and let the player bet what they want
    
    bool plyAce = false, // checks if player has ace
         delAce = false; // checks if dealer has ace
    
    
    //File I/O
    ofstream inFile; // goes in the file
    ifstream outFile; // comes out the file
    string filename; // string for the name of the file
    filename = "Cards.txt"; // file name
    
    cout << "|--WELCOME TO BLACK JACK--|" << endl;
    
    do 
    {
        cout << "Your cards are being handed out!" << endl << endl;
        
        
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
        
        
        
        cout << "--Dealer--" << endl;
        //cards for the dealer
        for(int i = 0; i < 2; i++){ // needed to make two for loops because functions cant be used.
            int shuffle = rand()% 14 + 1;
            switch(shuffle){
                case 1:
                    cout << card1 << endl;
                    if(card1 == "Ace") dealer += 11;
                    delAce = true;
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
        cout << "Dealer Card Values = " << dealer << endl << endl; //dealers cards will be hidden in the final
                                                             //iteration of the game until the player 
                                                             //selects stand.
        
        cout << "--Player--" << endl;
        //cards for the player
        for(int i = 0; i < 2; i++){
            int shuffle = rand()% 14 + 1;
            switch(shuffle){
                case 1:
                    cout << card1 << endl;
                    if(card1 == "Ace")player += 11;
                    plyAce = true;
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
        cout << "Player Card Values = " << player << endl << endl; // displays the cards the player got 
        
        
        
        // Logic of the Game
        if(player > 21 && plyAce == true){ //checks if player is over 21 and has an ace to change to a 1
            player = player - 10;
        }
        if(dealer > 21 && delAce == true){ //checks if dealer is over 21 and has an ace to change to a 1
            dealer = dealer - 10;
        }
        
        
        if(dealer == 21 && player == 21){       //checks if at the beginning of the game
            cout << "Draw-No winner"<< endl;    //both player and dealer have 21
        }                                       //If they do, then it draws
        else if(player == 21 && dealer < 21){   
            cout << "Player wins" << endl;      //if player is at 21 and dealer is less than that, player wins
            resp2 = 'x';                        // add reward for player
        }
        else if(dealer == 21 && player < 21){
            cout << "Dealer wins" << endl;      //if dealer is at 21 and player is less than that, dealer wins
            resp2 = 'x';
        }
        
        
        if(resp2 != 'x'){
            if(player > 21 && plyAce == false){  // if player is over 21 and doesn't have an ace, player loses
                cout << "Player Bust - Dealer Wins!" << endl; // add penalty for player
            }
            else{
                cout << "-Would you like to Stand or Hit-" << endl;
                cout << "Type S for stand and H for Hit" << endl;
                cin >> resp2;
            
            }
        }
        
        
        
        //Player logic
        if(resp2 == 'h' || resp2 == 'H'){
            do //runs a loop until player stops pressing hit
            {
                cout << endl;
                //cards for the player
                for(int i = 0; i < 1; i++){
                    int shuffle = rand()% 14 + 1;
                    switch(shuffle){
                        case 1:
                            cout << card1 << endl;
                            if(card1 == "Ace")player += 11;
                            plyAce = true;
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
       
                cout << "Player Card Value = " << player << endl << endl;       
                
                
                if(player < 21){
                    cout << "Would you like to Hit again or Stand?" << endl;
                    cout << "S for Stand and H for Hit!" << endl;
                    cin >> resp3;
                }
                else if(player>21){
                    cout << "Player Bust - Dealer Wins!" << endl; // add penalty for losing
                    resp3 = 'x';
                }
            
            }while(resp3 == 'h' || resp3 == 'H');
        }
        
        
        
        //Dealer Logic
        if(dealer < 21 && player < 21){
             do
             {
                for(int i = 0; i < 1; i++){ // needed to make two for loops because functions cant be used.
                    int shuffle = rand()% 14 + 1;
                    switch(shuffle){
                        case 1:
                            cout << card1 << endl;
                            if(card1 == "Ace") dealer += 11;
                            delAce = true;
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
                cout << "Dealer Card Values = " << dealer << endl << endl; //dealers cards will be hidden in the final


                if(dealer < 16){
                    resp4 = 'H';
                }
                else if(dealer > 21){
                    cout << "Dealer Bust- Player Wins!" << endl; // give player a reward
                }
                else if(dealer > 17){
                    resp4 = 'x';
                }
                else if(dealer == 21 && player < 21){
                    cout << "Dealer Wins" << endl; // add penalty for player
                }

             }while(resp4 == 'h' || resp4 == 'H');
        }

        
        
        if(player <= 21 && dealer <= 21){
            if(dealer > player){
                cout << "Dealer Wins!"  << endl; // add penalty
            }
            else if(player > dealer){
                cout << "Player Wins!" << endl; // add reward
            }
        }
        
        
        
        
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