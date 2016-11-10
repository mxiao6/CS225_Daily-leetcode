#include <iostream>
#include <stdio.h>
using namespace std;

// void getInput(int playerid, int *arr, int SIZE){
//     // get user choice
//     char token = (playerid == 1) ? 'X' : 'O';
//     int row, col;
//     cout << "Player " << playerid << ", it's your turn." << endl;
//     do{
//         cout << "Where would you like to place an " << token << "? Row (1, 2...): ";
//         cin >> row;
//         cout << "Col (1, 2...): ";
//         cin >> col;
//         if(col < 1 || col > SIZE)
//             cout << "Column must be between 1 and " << SIZE << endl;
//         if(row < 1 || row > SIZE)
//             cout << "Row must be between 1 and " << SIZE << endl;
//         if(arr[(row - 1) * SIZE + (col - 1)] != 0)
//             cout << "That square is already occupied" << endl;
//     } while( row < 1 || row > SIZE || col < 1 || col > SIZE || arr[(row - 1) * SIZE + (col - 1)] != 0);
    
//     // store in data structure
//     arr[(row - 1) * SIZE + (col - 1)] = playerid;
// }

void getInput(int playerid, int *arr, int SIZE){
    // get user choice
    int choice = -1;
    while (choice < 0 || choice > SIZE*SIZE) {
        cout << "Choose a number on the board: ";
        cin >> choice;
        if(arr[choice-1] == -1 || arr[choice-1] == -2) {
            cout << "That square is already occupied" << endl;
            choice = -1;
        }
    }
    if (playerid == 1) {
        arr[choice-1] = -1;
    } else {
        arr[choice-1] = -2;
    }
}

void printBoard(int *arr, int SIZE){
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            int num = arr[i * SIZE + j];
            if (num == -1) {
                cout << " X " << "|";
            } else if (num == -2) {
                cout << " O " << "|";
            } else {
                printf("%2d |", num);
            } 
        }
        cout << endl;
        for(int j = 0; j < SIZE; j++) {
            cout << "___|";
        }
        cout << endl;
    }
}

bool equal(int* arr, int a, int b, int c) {
    if (arr[a] == arr[b] && arr[b] == arr[c] && arr[a] < 0)
        return true;
    else
        return false;
}

int check(int *arr, int SIZE){
    // Your code here!
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int pos = SIZE*i + j;
            if (pos+2 < (i+1)*SIZE && (equal(arr, pos, pos+1, pos+2) || equal(arr, pos, pos+SIZE+1, pos+2*SIZE+2))) 
                return arr[pos];

            if (pos+2*SIZE < SIZE*SIZE && equal(arr, pos, pos+SIZE, pos+2*SIZE)) 
                return arr[pos];

            if (pos-2 >= i*SIZE && equal(arr, pos, pos+SIZE-1, pos+2*SIZE-2))
                return arr[pos];
        }
    }
    return 0;
}

int main(){
    int size;
    int *arr;
    cout << "WElCOME TO TIC-TAC-TOE 5000\nHow large would you like the nxn board to be? n=";
    cin >> size;
    arr = new int[size*size];
    // initialize board
    for(int i = 0; i < size*size; i++){
        arr[i] = i+1;
    }
    cout << "LET'S BEGIN!" << endl;
    int turn = 0;
    int player = 1;
    int winner;
    while(turn < size*size){
        printBoard(arr, size);
        cout << "PLAYER " << player << " it's your move.";
        getInput(player, arr, size);
        if((winner = check(arr, size))){
            printBoard(arr, size);
            cout << "PLAYER " << (winner == -1 ? 1:2) << " WINS!" << endl;
            delete [] arr;
            return 0;
        }
        player = (player == 1) ? 2 : 1;
        turn++;
    }
    printBoard(arr, size);
    cout << "Cat's game." << endl;
    delete [] arr;
    return 0;
}