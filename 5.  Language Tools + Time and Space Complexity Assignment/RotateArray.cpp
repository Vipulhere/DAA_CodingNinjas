// void rotator(int *arr, int n)
// {
//     for(int i=0, j=n-1; i<=j; i++, j--)
//     {
//         int temp=arr[i];
//         arr[i]=arr[j];
//         arr[j]=temp;
//     }
// }
// void Rotate(int arr[], int d, int n)
// {
//     rotator(arr, n);
//     rotator(arr+n-d, d);
//     rotator(arr, n-d);
// }

#include <bits/stdc++.h>

void rotate(int *input, int d, int n) {
    vector<int> t;
    
    for(int i = d ; i < n ; ++i) {
        t.push_back(input[i]);
    }
    for(int i = 0 ; i < d ; ++i) {
        t.push_back(input[i]);
    }
    
    for(int i = 0 ; i < n ; ++i) {
        input[i] = t[i];
    }
}