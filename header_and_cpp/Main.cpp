#include "Stock.h"
#include "AlgoLib.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <locale>

using namespace std;
int main() 
{
    bool runProgram = true;
    while (runProgram == true)
    {
        string symbol;
        std::locale loc;
        cout << "Please select a stock from the S&P500 (Enter ticker Symbol): " << endl;
        cin >> symbol;
        transform(symbol.begin(), symbol.end(), symbol.begin(), toupper);
        Stock backtest_Stock(symbol);
        cout << "Enter your initial capital: " << endl;
        double capital;
        cin >> capital;
        double initialBalance = capital;
        cout << "Select a strategy to backtest (Enter the corresponding number): " << endl;
        cout << "1) BOSC" << endl;
        cout << "2) Volume Reversal" << endl;
        cout << "3) MA Reversal" << endl;
        string strategy;
        cin >> strategy;
        if (strategy == "1")
        {
            capital = BOSC(backtest_Stock, capital);
            cout << "Your balance is now: " << capital << endl;
            double profOrLoss = (capital - initialBalance) / (backtest_Stock.close.size());
            cout << "Your average daily P/L is: " << profOrLoss << endl;
            cout << "Your ROI is: " << (capital - initialBalance) / (initialBalance) * 100 << endl;

        }
        else if (strategy == "2")
        {
            int balance = VolumeReversal(backtest_Stock, capital);
            cout << "Your balance is now: " << balance << endl;
            double profOrLoss = (capital - initialBalance) / (backtest_Stock.close.size());
            cout << "Your average daily P/L is: " << profOrLoss << endl;
            cout << "Your ROI is: " << (capital - initialBalance) / (initialBalance) * 100 << endl;
        }
        else if (strategy == "3")
        {
            int balance = MAreversal(backtest_Stock, capital);
            cout << "Your balance is now: " << balance << endl;
            double profOrLoss = (capital - initialBalance) / (backtest_Stock.close.size());
            cout << "Your average daily P/L is: " << profOrLoss << endl;
            cout << "Your ROI is: " << (capital - initialBalance) / (initialBalance) * 100 << endl;
        }
        cout << "Would you like to run another backtest? (Y/N)" << endl;
        string answer;
        cin >> answer;
        while (answer == "Y" || answer == "N")
        {
            if (answer == "Y")
            {
                runProgram = true;
                break;
            }
            else if (answer == "N")
            {
                runProgram = false;
                break;
            }
        }
        
        
    }
    
        

   
    
}