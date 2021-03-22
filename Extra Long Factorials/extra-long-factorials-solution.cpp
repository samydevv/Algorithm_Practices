#include <bits/stdc++.h>
using namespace std;


#define MAX_NUMBER 1000
int factorial(vector<int>& answer , int answer_size, int n);

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    vector<int> answer(MAX_NUMBER);
    int answer_size=1,i;
    answer[0]=1;

    while(n>1){
        answer_size=factorial(answer ,answer_size,n);
        n--;
    }
    i=answer_size-1;
    while(i>=0){
        cout<<answer[i];
        i--;
    }
}

int factorial(vector<int>& answer , int answer_size, int n){
    int product,carry=0,i=0;
    while(answer_size>i){
        product=answer[i]*n+carry;
        answer[i]= product%10;
        carry=product/10;
        i++;
    }
    while (carry)
    {
        answer[answer_size]=carry%10;
        carry = carry/10;
        answer_size++;
    }
    return answer_size;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}

