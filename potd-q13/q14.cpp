#include <cmath>

int * raise(int [] arr, int power){
    int count = 0;
    while(arr[count] >= 0){count++;}
    int * newarr = new int [count + 1];
    newarr[count] = arr[count];     // last element remains the same
    for(int i = 0; i < count; i++){
        newarr[i] = pow(arr[i], power);
    }
    return newarr;
}
