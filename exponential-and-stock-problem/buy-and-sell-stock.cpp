// Best time to buy and sell stock.
// You are given an array called prices, where prices[i] is the price of the stock at the ith day.
// You have to maximize your profit by selecting a day to buy a stock and choosing a different day in the future to sell that stock.
// Return the maximum profit to can achieve from this transaction, if you cannot achieve any profit return 0.

#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices){

    int maxProfit = 0; 
    int bestBuy = prices[0];

    for(int i = 1; i < prices.size(); i++){

        // Update maxProfit if selling today yields more profit
        if(prices[i] > bestBuy){
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }

        // Update bestBuy if today's price is lower
        bestBuy = min(bestBuy, prices[i]);

    }

    return maxProfit;

}

int main(){

    int n;
    cout << "Enter the total number of days : ";
    cin >> n;
    
    vector<int> stock(n);

    cout << "Enter the stock price of : " << endl;
    for (int i = 0; i < stock.size(); i++){
        cout << "Day " << i+1 << ": ";
        cin >> stock[i];
    }

    cout << "Maximum Profit that can be obtained from the provided data : " << maxProfit(stock) << endl;

    return 0;
}

// Enter the total number of days : 6
// Enter the stock price of : 
// Day 1: 7
// Day 2: 1
// Day 3: 5
// Day 4: 3
// Day 5: 6
// Day 6: 4
// Maximum Profit that can be obtained from the provided data : 5