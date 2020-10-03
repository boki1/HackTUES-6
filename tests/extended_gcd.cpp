#include <iostream>
#include <math.h>

using namespace std;

int BruteForceModMult(int num1, int num2)
{
    int curr = 1;

    while(num1 * curr % num2 != 1)
    {
        curr++;
    }
    
    return curr;
}

int EuclideanGCD(int num1, int num2)
{
    if(num1 == 0)
    {
        return num2;
    }

    return EuclideanGCD(num2 % num1, num1);
}


int main()
{
    int q = 47903;
    int k = rand() % (q - 1) + 1;

    int i = EuclideanGCD(k, q);

    cout << i*k % q << endl;
    

    return 0;
}
