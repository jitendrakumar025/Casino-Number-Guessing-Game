#include <bits/stdc++.h>
#include<windows.h> 
using namespace std;
 
void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << endl ;
}
 
void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(80,'=');
    cout << "\t\t                      RULES OF THE GAME                       "<<endl;
    drawLine(80,'=');
    cout << "\t 1. Choose any number between 1 to 10\n";
    cout << "\t 2. If you win you will get 10 times of money you bet\n";
    cout << "\t 3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}
 
int main()
{
    string playerName;
    int amount; // hold player's balance amount
    int bettingAmount; 
    int guess;
    int dice; // hold computer generated number
    char choice;
 

    string var="\n=========================================================================================="
 "\n   CCCCC      A        SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     "
 "\n CC          A  A      SS             III     NN N   NN   OO      OO    "
 "\nCC          A    A     SSSSSSSSS      III     NN  N  NN   OO      OO    "
 "\n CC        AAAAAAAA           SS      III     NN   N NN   OO      OO   " 
 "\n   CCCCC  A        A   SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO   "  
 "\n===============================================================================================\n";
 for(int i=0;i<var.size();i++)
 {
 	Sleep(10);
 	cout<<var[i];
 }
 
    cout << "\n\nEnter Your Name : ";
    getline(cin, playerName);
 
    cout << "\n\nEnter Deposit amount to play game : ";
    cin >> amount;
    
    do
    {
        system("cls");  /// for clearing screen 
        rules();
        cout << "\n\nYour current balance is Rs. " << amount << endl;
		
		// Get player's betting amount
        do
        {
            cout <<playerName<<", enter money to bet : Rs.";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout << "Your betting amount is more than your current balance\n"
                       <<"\nRe-enter data\n ";
        }while(bettingAmount > amount);
 
		// Get player's numbers
        do
        {
            cout << "Guess your number to bet between 1 to 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "Please check the number!! should be between 1 to 10\n"
                    <<"\nRe-enter data\n ";
        }while(guess <= 0 || guess > 10);
 
        dice = rand()%10 + 1; // it Will hold the randomly generated integer between 1 and 10
    
        if(dice == guess)
        {
            cout <<endl<<"Good Luck!! You won Rs." << bettingAmount * 10;
            amount = amount + bettingAmount * 10;
        }
        else
        {
            cout << "Bad Luck this time !! You lost Rs. "<< bettingAmount <<endl;
            amount = amount - bettingAmount;
        }
 
        cout <<endl<<"The winning number was : " << dice <<endl;
        cout << endl<<playerName<<", You have Rs. " << amount << endl;
        if(amount == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";		
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    
    cout << endl<<endl<<endl;
    drawLine(70,'=');
    cout << "\n\nThanks for playing game. Your balance amount is Rs. " << amount << "\n\n";
    drawLine(70,'=');
 
    return 0;
}
 

 
// END OF PROGRAM