/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ismael Perez
 * Purpose: Create functions for the cards 
 *
 * Created on may 31, 2022, 2:27 PM
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

const int PERCENT = 100; // percentage 

// card value makers, also example of overloading
int cardVal(string,string,string,string,string,string,string,string,string,string,string,string,string,string,int&,bool&);
int cardVal(string,string,string,string,string,string,string,string,string,string,string,string,string,string,int &);
//Empty balance function
void extFunc(float);

int main(int argc, char** argv) 
{
    srand(static_cast<unsigned int>(time(0)));
    
    char resp,    // multiple inputs for the game
         resp2,
         resp3,
         resp4;
    
    int dealer = 0, // card value for dealer
        player = 0, // card value for player
        holder = 0;
    
    float balance = 100, // balance of the player - might make this a float and let the player bet what they want
          bet = 0, // bet made by player
          ratio; // win ratio
        
    
    bool plyAce = false, // checks if ace has been pulled.
         delAce = false;
    
    
    //File I/O
    ofstream inFile; // goes in the file
    ifstream outFile; // comes out the file
    string filename; // string for the name of the file
    filename = "Cards.txt"; // file name
    
    cout << "|--WELCOME TO BLACK JACK--|" << endl;
    
    do 
    {
        extFunc(balance);
        
        cout << "Balance: $" << balance << endl << endl;
        cout << "How much would you like to bet? (ex. 12.50)" << endl; 
        cin >> bet; // takes in a bet
        
        while(bet > balance || bet < 0){ // if bet is over the amount in balance or bet is negative it loops
            cout << "Insufficient Funds or Negative Number" << endl;
            cout << "Try again!!" << endl << endl;
            cout << "How much would you like to bet? (ex. 12.50)" << endl;
            cin >> bet;
        }
        
        //uses iomanip
        cout << fixed << setprecision(2) << showpoint;
        cout << "Your bet is $" << bet << endl << endl;
        
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
        // function takes all the card names in the file and adds then in to the function in order to get card values back
        cardVal(card1,card2,card3,card4,card5,card6,card7,card8,card9,card10,card11,card12,card13,card14,holder,delAce);
        dealer = holder;
        cout << "Dealer Card Values = "<< dealer << endl << endl; //dealers cards will be hidden
        holder = 0;
        
        
        cout << "--Player--" << endl;
        //cards for the player
        // this does the same as the dealer one
        cardVal(card1,card2,card3,card4,card5,card6,card7,card8,card9,card10,card11,card12,card13,card14,holder,plyAce);
        player = holder;
        cout << "Player Card Values = " << player << endl << endl; // displays the cards the player got 
        
        holder = 0;
        
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
        
        
       
        if(player > 21 && plyAce == false){  // if player is over 21 and doesn't have an ace, player loses
            cout << "Player Bust - Dealer Wins!" << endl; 
            balance = balance - bet;//penalty for player
        }
        else{
            cout << "-Would you like to Stand or Hit-" << endl; // if they like a hit or stand with the cards they have
            cout << "Type S for stand and H for Hit" << endl;
            cin >> resp2;
        }
        
        //Player logic
        if(resp2 == 'h' || resp2 == 'H'){
            do //runs a loop until player stops pressing hit
            {
                cout << endl;
                //cards for the player
                cardVal(card1,card2,card3,card4,card5,card6,card7,card8,card9,card10,card11,card12,card13,card14,holder);
                player += holder;
                
                cout << "Player Card Value = " << player << endl << endl;       
                holder = 0;
                
                if(player < 21){
                    cout << "Would you like to Hit again or Stand?" << endl;
                    cout << "S for Stand and H for Hit!" << endl;
                    cin >> resp3;
                }
                else if(player>21){
                    cout << "Player Bust - Dealer Wins!" << endl;
                    resp3 = 'x'; // this is done so dealer doesn't go after the player has lost
                    balance = balance - bet;//penalty for player
                }
            
            }while(resp3 == 'h' || resp3 == 'H');
        }
        
        
        //Dealer Logic
        if(dealer < 21 && player != 21 && player < 21){ // only runs if the dealer is less than 21 and player isn't at 21
            if(dealer <= 16){ // since a while loop is needed it checks the dealers cards before hand
                resp4 = 'H';
            }
            else{ // else it skips this part
                resp4 = 'x';
            }
            while(resp4 == 'h' || resp4 == 'H'){
            cardVal(card1,card2,card3,card4,card5,card6,card7,card8,card9,card10,card11,card12,card13,card14,holder);
            
            dealer += holder;
            cout << "Dealer Card Values = " << dealer << endl << endl; //dealers cards will be hidden in the final
            holder = 0;

            if(dealer < 16){
                resp4 = 'H';
            }
            else{
                resp4 = 'x';
            }
            
            
            if(dealer > 21){
                cout << "Dealer Bust- Player Wins!" << endl;
                balance = balance + bet + (bet*1.5); // reward
            }
            else if(dealer > 17){
                resp4 = 'x';
            }
            else if(dealer == 21 && player < 21){
                cout << "Dealer Wins" << endl; 
                balance = balance - bet;//penalty for player
            }

            }
        }

        
        if(player <= 21 && dealer <= 21){
            if(dealer > player){
                cout << "Dealer Wins!"  << endl; 
                balance = balance - bet;//penalty for player
            }
            else if(player > dealer){
                cout << "Player Wins!" << endl; 
                balance = balance + bet + (bet*1.5); // reward
            }
            else if(player == dealer){
                cout << "Draw" << endl;
            }
        }
        
        cout << "New Balance = $" << balance << endl; // shows the new balance
        
        //closes the file that was opened
        inFile.close();
        outFile.close();
        
        //play again prompt
        cout << endl;
        cout << "Play again?" << endl;
        cin >> resp;
        cout << endl;
        
        if(resp == 'y' || resp =='Y'){ // card values get reset to zero every time the player plays again.
            dealer = 0;                // balance will be staying the same until game is exited
            player = 0;
        }
        
        cout << endl << endl << endl;
        
    }while(resp == 'y' || resp =='Y');

    return 0;
}





// this function if used to get the two cards to the player and dealer
int cardVal(string card1, string card2, string card3, string card4, string card5, string card6,string card7, 
        string card8,string card9,string card10,string card11,string card12, string card13, string card14, int &cardVal, bool &aceStat){

    aceStat = false;
    for(int i = 0; i < 2; i++){ // needed to make two for loops because functions cant be used.
        int shuffle = rand()% 14 + 1;
        switch(shuffle){
            case 1:
                if(card1 == "Ace") cardVal += 11;
                aceStat = true;
                break;
            case 2:
                if(card2 == "King") cardVal += 10;
                break;
            case 3:
                if(card3 == "Queen") cardVal += 10;
                break;
            case 4:
                if(card4 == "Jack") cardVal += 10;
                break;
            case 5:
                if(card5 == "Ten") cardVal += 10;
                break;
            case 6:
                if(card6 == "Nine") cardVal += 9;
                break;
            case 7:
                if(card7 == "Eight") cardVal += 8;
                break;
            case 8:
                if(card8 == "Seven") cardVal += 7;
                break;
            case 9:
                if(card9 == "Six") cardVal += 6;
                break;
            case 10:
                if(card10 == "Five") cardVal += 5;
                break;
            case 11:
                if(card11 == "Four") cardVal += 4;
                break;
            case 12:
                if(card12 == "Three") cardVal += 3;
                break;
            case 13:
                if(card13 == "Two") cardVal += 2;
                break;
            case 14:
                if(card14 == "One") cardVal += 1;
                break;
        }
    }
    return aceStat;
    return cardVal;
}



// This is to give one card to the player or dealer when they hit.
// I know I could have done these two functions in one function, but I needed and example of overloading
int cardVal(string card1, string card2, string card3, string card4, string card5, string card6,string card7, 
        string card8,string card9,string card10,string card11,string card12, string card13, string card14, int &cardVal){

    for(int i = 0; i < 1; i++){ // needed to make two for loops because functions cant be used.
        int shuffle = rand()% 14 + 1;
        switch(shuffle){
            case 1:
                cout << card1 << endl;
                if(card1 == "Ace") cardVal += 11;
                break;
            case 2:
                cout << card2 << endl;
                if(card2 == "King") cardVal += 10;
                break;
            case 3:
                cout << card3 << endl;
                if(card3 == "Queen") cardVal += 10;
                break;
            case 4:
                cout << card4 << endl;
                if(card4 == "Jack") cardVal += 10;
                break;
            case 5:
                cout << card5 << endl;
                if(card5 == "Ten") cardVal += 10;
                break;
            case 6:
                cout << card6 << endl;
                if(card6 == "Nine") cardVal += 9;
                break;
            case 7:
                cout << card7 << endl;
                if(card7 == "Eight") cardVal += 8;
                break;
            case 8:
                cout << card8 << endl;
                if(card8 == "Seven") cardVal += 7;
                break;
            case 9:
                cout << card9 << endl;
                if(card9 == "Six") cardVal += 6;
                break;
            case 10:
                cout << card10 << endl;
                if(card10 == "Five") cardVal += 5;
                break;
            case 11:
                cout << card11 << endl;
                if(card11 == "Four") cardVal += 4;
                break;
            case 12:
                cout << card12 << endl;
                if(card12 == "Three") cardVal += 3;
                break;
            case 13:
                cout << card13 << endl;
                if(card13 == "Two") cardVal += 2;
                break;
            case 14:
                cout << card14 << endl;
                if(card14 == "One") cardVal += 1;
                break;
        }
    }
    return cardVal;
}

void extFunc(float bal){
    if(bal <= 0){ // checks if balance is empty and kicks you if it is.
        cout << "You are out of money, We are kicking you out of the casino." << endl;
        exit(0);
    }
}