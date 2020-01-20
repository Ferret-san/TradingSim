# TradingSim
Simple header and cpp files to back test strategies against 5 year data for stocks in the S&P500 (from 2013-2018). 
The data I used can be found here https://www.kaggle.com/camnugent/sandp500#AAPL_data.csv.
This is currently a work in progress with very few and basic strategies. I will be adding more strategies to backtest and a UI using the qt library.

The current strategies are:
1) A "Buy at Open, Sell at Close" strategy wich buys the stock if the opening price was lower than the close of the previous day and holds it untill close of the current day.

2) A "Volume Reversal" strategy which longs or shorts a stock if the current day volume is 10x higher than the avg volume in the last 5 trading days, and then proceeds to long if the opening price is lower than the previous day close (shorts if opening > closing of previous day).

3) A "Moving average reversal" strategy which longs the stock if the opening was lower than the 100-MA or shorts if it was higher. (Holds untill closing of execution day)

Improvements can be done with more data, more options for strategies or ideas to backtest, and data on stocks or other trading instruments outside of the S&P 500.
