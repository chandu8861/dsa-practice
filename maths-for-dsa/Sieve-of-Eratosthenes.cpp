// Count Prime
// Given an integer n, return the number of prime numbers that are strictly less than n.

// Principle : First you define a range that is from 2 to n
// We will assume that all the numbers between this range are prime. 
// We'll go on checking from the first number two assuming its prime.
// Next we will eliminate all the multiples of the first number and we will move on to the next number and we will again eliminate all the multiples of the that number.
//This way at the end we will be only left with those numbers who doesn't have any multiples in other words which are prime

#include<iostream>
#include<vector>
using namespace std;

int countPrime (int n){

    if (n <= 2) return 0;

    vector<bool> isPrime(n,true);
    int count = 0;

    for (int i = 2; i < n; i++){

        if (isPrime[i]){
            count++;

            // eliminating all the multiples of i by assigning them false

            // By writing 1LL * i * i, we:

            // Convert i to a long long first (because 1LL is a long long literal).
            // Do the multiplication in 64-bit safe range.
            // Store the result in long long j.
            // This guarantees correctness even for large n.

            for (long long  j = 1LL* i*i; j < n; j = j+i){
                isPrime[j] = false;
            }

            // In the sieve, multiples before i*i would already be marked by smaller primes.
            // So, you can safely start the loop from i*i, reducing redundant work.
        }
    }

    return count;
}

int main(){

    int n;
    cout << "Enter the range to find number of prime numbers between the range : ";
    cin >> n;

    cout << "Number of prime numbers between " << "2 to " << n << " is " << countPrime(n) << endl;
    return 0;
}

// Enter the range to find number of prime numbers between the range : 50
// Number of prime numbers between 2 to 50 is 15