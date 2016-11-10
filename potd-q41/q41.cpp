#include <iostream>
using namespace std;


void getInput(int playerid, int *arr, int SIZE){
    // get user choice
    int choice = -1;
    while (choice < 0 || choice >= SIZE*SIZE) {
        cout << "Choose a number on the board: ";
        cin >> choice;
    }
    if (playerid == 1) {
        arr[choice] = -1;
    } else {
        arr[choice] = -2;
    }
}


int main(){
    int size;
    int *arr;
    cout << "WElCOME TO TIC-TAC-TOE 5000\nHow large would you like the nxn board to be? n=";
    cin >> size;
    arr = new int[size*size];
    // initialize board
    for(int i = 0; i < size*size; i++){
        arr[i] = i;
    }
    cout << "LET'S BEGIN!" << endl;
    int turn = 0;
    int player = 1;
    int winner;
    while(turn < size*size){
    //    You'll do this one tomorrow!
    //    printBoard(arr, size); 
        cout << "PLAYER " << player << " it's your move. ";
        getInput(player, arr, size);
        // You'll do this in two days!
    //    if(winner = check(arr, size)){
    //        printBoard(arr, size);
    //        cout << "PLAYER " << winner << " WINS!" << endl;
    //        delete [] arr;
    //        return 0;
    //    }
        player = (player == 1) ? 2 : 1;
        turn++;
    }
    // printBoard(arr, size);
    cout << "Cat's game." << endl;
    delete [] arr;
    return 0;
}
