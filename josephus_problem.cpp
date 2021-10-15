//There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. 
//In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller 
//as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of persons n and a number k which indicates that 
//k-1 persons are skipped and k-th person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.
//( 0 based indexing) .



#include <iostream>
using namespace std;
 
int josephus(int n, int k)
{
    if (n == 1)
        return 1;
    else
        /* The position returned by josephus(n - 1, k)
        is adjusted because the recursive call
        josephus(n - 1, k) considers the
        original position k % n + 1 as position 1 */
        return (josephus(n - 1, k) + k - 1) % n + 1;
}
 
// Driver Program to test above function
int main()
{
    int n = 14;
    int k = 2;
    cout << "The chosen place is " << josephus(n, k);
    return 0;
}
