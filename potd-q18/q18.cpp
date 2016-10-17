#include <iostream>
using namespace std;

template <class T>
class BankAccount {
private:
	T balance;
public:
	BankAccount(T p_balance) {
		balance = p_balance;
	}

	T getBalance() {
		return balance;
	}

	void add(T amount) {
		balance += amount;
	}

	void remove(T amount) {
		balance -= amount;
	}
};

int main() {
	BankAccount<double> change(2000);
	BankAccount<int> nochange(2000);

	cout << "change: " << change.getBalance() << endl;
	cout << "nochange: " << nochange.getBalance() << endl;

	change.add(0.5);
	nochange.remove(50);

	cout << "change: " << change.getBalance() << endl;
	cout << "nochange: " << nochange.getBalance() << endl;
}