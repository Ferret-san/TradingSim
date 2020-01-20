#include "AlgoLib.h"
#include "Stock.h"
using namespace std;
int BOSC(Stock& stock, double& capital) //If a stock was lower compared to the day before, buy at open and sell at close
{
	for (int i = 1; i < stock.open.size(); i++)
	{
		if (stock.open[i] < stock.close[i - 1])
		{
			capital /= stock.open[i]; //number of shares bought at open price
			capital *= stock.close[i]; //capital after selling at close
		}
	}
	
	
	int newCapital = capital;
	return newCapital;
}
int VolumeReversal(Stock& stock, double& capital)
{
	
	for (int i = 5; i < stock.open.size(); i++)
	{
		int avgVolume = 0;
		for (int j = (i - 5); j < i; j++)
		{
			avgVolume += stock.volume[j];
		}
		avgVolume /= 5;


		if ((stock.volume[i] * 10) > avgVolume)
		{
			if (stock.open[i] < stock.close[i - 1])
			{
				capital /= stock.open[i]; //number of shares bought at open price
				capital *= stock.close[i]; //capital after selling at close
			}
			else if (stock.open[i] > stock.close[i - 1])
			{
				capital /= stock.open[i]; //number of shares shorted
				double shortSale = capital * (stock.open[i] - stock.close[i]); //P/L per share
				capital = capital * stock.open[i] + shortSale;
			}
		}

	}
	
	
	int newCapital = capital;
	return newCapital;

}
int MAreversal(Stock& stock, double& capital)
{
	for (int i = 100; i < stock.open.size(); i++)
	{
		double movingAverage = 0;
		for (int j = (i - 100); j < i; j++)
		{
			movingAverage += stock.close[j];
		}
		movingAverage /= 100;

		if (stock.open[i] < movingAverage)
		{
			capital /= stock.open[i]; //number of shares bought at open price
			capital *= stock.close[i]; //capital after selling at close
		}
		else if (stock.open[i] > movingAverage)
		{
			capital /= stock.open[i]; //number of shares shorted
			double shortSale = capital * (stock.open[i] - stock.close[i]); // P/L per share
			capital = capital * stock.open[i] + shortSale;
		}
		

	}


	int newCapital = capital;
	return newCapital;
}

