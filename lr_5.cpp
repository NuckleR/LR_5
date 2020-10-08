#include <iostream>
#include <string>
#include <Windows.h>
#include <limits>

using namespace std;

class Casino {
private:
	std::string name;
protected:
	double money;
	int players;
	int workers;
public:
	Casino() {
		std::cout << "��������� ����������� �� ��������� (Casino)!\n";
		money = 0;
		players = 0;
		workers = 0;
		name = "�����";
	}
	Casino(double mon, int play,
		int work, std::string h) {
		std::cout << "��������� ����������� ������������� (Casino)!\n";
		money = mon;
		players = play;
		workers = work;
		name = h;
	}
	Casino(Casino& one) : money(one.money),
		players(one.players), workers(one.workers),
		name(one.name) {
		std::cout << "��������� ����������� ����������� (Casino)!\n";
	}
	virtual ~Casino() {
		std::cout << "��������� ���������� (Casino)!\n";
	}
	virtual void profit() {

	}
	virtual void info() {
	}
};

class Cards : virtual public Casino {
protected:
	int amnt_of_tables;
	double play_payment;
public:
	Cards() {
		std::cout << "��������� ����������� �� ��������� (Cards)!\n";
		play_payment = 0;
		amnt_of_tables = 0;
	}
	Cards(double pay, int amnt, double mon, int wor, int pl) {
		std::cout << "��������� ����������� ������������� (Cards)!\n";
		play_payment = pay;
		amnt_of_tables = amnt;
		money = mon;
		workers = wor;
		players = pl;
	}
	Cards(Cards& one) : amnt_of_tables(one.amnt_of_tables), 
		play_payment(one.play_payment) {
		std::cout << "��������� ����������� ����������� (Cards)!\n";
	}
	~Cards() {
		std::cout << "��������� ���������� (Card)!\n";
	}
	void profit() {
		int prof;
		prof = players * play_payment;
		std::cout << "\n\n������ ����: " << prof;
	}
	void info() {
		std::cout << "\n\n���-�� �������: " << players
			<< "\n���-�� �������: " << workers << "\n����� � �����: " << money
			<< "\n���-�� ������ � ��������� ������: " << amnt_of_tables
			<< "\n����� �� ����������� �������������: " << play_payment << "\n\n";
	}
};

class Poker : public Cards {
protected:
	double win_rate;
	int table_id;
public:
	Poker() {
		std::cout << "��������� ����������� �� ��������� (Cards)!\n";
		table_id = 0;
	}
	Poker(int Id, double wn, double mon, int wor, int pl, int amnt) {
		std::cout << "��������� ����������� ������������� (Cards)!\n";
		table_id = Id;
		win_rate = wn;
		money = mon;
		workers = wor;
		players = pl;
		amnt_of_tables = amnt;
	}
	Poker(Poker& one) : table_id(one.table_id) {
		std::cout << "��������� ����������� ����������� (Cards)!\n";
	}
	~Poker() {
		std::cout << "��������� ���������� (Card)!\n";
	}
	void profit() {
		double prof = 0;
		prof = (players * win_rate) / amnt_of_tables;
		std::cout << "\n\n������� ������� � ������: "
			<< prof << "%\n";
	}
	void info() {
		std::cout << "\n\n����� �����: " << table_id
			<< "\n���-�� ������" << amnt_of_tables
			<< "\n���-�� ������� �� ������: " << players
			<< "\n���-�� ������� �� ������: " << workers << "\n����� ����� � ����� �� ������: " << money
			<< "\nWIN_RATE: " << win_rate << "\n\n";
	}
};

class Slots : virtual public Casino {
protected:	
	int amount_of_playgrounds;
	double chance_to_lose_money;
	double chance_to_win_money;
public:
	Slots() {
		std::cout << "��������� ����������� �� ��������� (Slots)!\n";
		chance_to_lose_money = 0;
		chance_to_win_money = 0;
		amount_of_playgrounds = 0;
	}
	Slots(double ch_1, double ch_2, int set, double mon, int wor, int pl) {
		std::cout << "��������� ����������� ������������� (Slots)!\n";
		chance_to_lose_money = ch_1;
		chance_to_win_money = ch_2;
		amount_of_playgrounds = set;
		money = mon;
		workers = wor;
		players = pl;
	}
	~Slots() {
		std::cout << "��������� ���������� (Slots)!\n";
	}
	void profit() {
		double precent_of_profit;
		precent_of_profit = (chance_to_lose_money * chance_to_win_money) / 200;
		std::cout << "\n\n������� ������� ������� ���������: "
			<< precent_of_profit <<"%\n";
	}

	void info() {
		std::cout  << "\n\n���-�� ������� �� ������: " << players
			<< "\n���-�� ������� �� ������: " << workers << "\n����� ����� � ����� �� ������: " << money
			<< "\n���-�� ����� �������: " << amount_of_playgrounds
			<< "\n���� �������: " << chance_to_win_money << "%"
			<< "\t\t���� �����: " << chance_to_lose_money << "%" << "\n\n";
	}
};

void enter_base(int seet, int& players, int& workers, double& money,
	int& amnt_of_tables, double& p_payment, double& win_rt, int& id,
	double& ch_to_lose, double& ch_to_win, int& amnt_of_pg);

int main() {
	system("chcp 1251");
	system("CLS");

	int players, workers, amnt_of_tables,
		amnt_of_pg, id, set;
	double money, ch_to_lose, ch_to_win, win_rt, p_payment;

	enter_base(1, players, workers, money,
		amnt_of_tables, p_payment, win_rt, id,
		ch_to_lose, ch_to_win, amnt_of_pg);

	Cards c(p_payment, amnt_of_tables, money, workers, players);
	
	enter_base(2, players, workers, money,
		amnt_of_tables, p_payment, win_rt, id,
		ch_to_lose, ch_to_win, amnt_of_pg);

	Poker p(id, win_rt, money, workers, players, amnt_of_tables);

	enter_base(3, players, workers, money,
		amnt_of_tables, p_payment, win_rt, id,
		ch_to_lose, ch_to_win, amnt_of_pg);
	Slots s(ch_to_lose, ch_to_win, amnt_of_pg, money, workers, players);

	Casino** cas = new Casino * [3];
	cas[0] = &c;
	cas[1] = &p;
	cas[2] = &s;
	for (int i = 0; i < 3; i++) {
		cas[i]->info();
		cas[i]->profit();
	}
}

void enter_base(int seet, int &players, int &workers, double &money, 
	int &amnt_of_tables, double &p_payment, double &win_rt, int &id,
	double &ch_to_lose, double &ch_to_win, int &amnt_of_pg) {
	if (seet == 1 || seet == 2 || seet == 3) {

		std::cout << "\n\n������� ���-�� �����������: ";
		while (!(std::cin >> players)) {
			std::cout << "\n������! ���������: ";
			std::cin.clear();
			rewind(stdin);
		} std::cin.clear(); rewind(stdin);

		std::cout << "\n\n������� ���-�� �������: ";
		while (!(std::cin >> workers)) {
			std::cout << "\n������! ���������: ";
			std::cin.clear(); std::cin.get();
			rewind(stdin);
		} std::cin.clear(); rewind(stdin);

		std::cout << "\n\n������� ���-�� �����: ";
		while (!(std::cin >> money)) {
			std::cout << "\n������! ���������: ";
			std::cin.clear();
			rewind(stdin);
		} std::cin.clear(); rewind(stdin);
	}
	if (seet == 1) {
		std::cout << "\n\n������� ���-�� ������: ";
		while (!(std::cin >> amnt_of_tables)) {
			std::cout << "\n������! ���������: ";
			std::cin.clear();
			rewind(stdin);
		} std::cin.clear(); rewind(stdin);

		std::cout << "\n\n������� c�������� ����: ";
		while (!(std::cin >> p_payment)) {
			std::cout << "\n������! ���������: ";
			std::cin.clear();
			rewind(stdin);
		} std::cin.clear(); rewind(stdin);
	}
	if (seet == 2) {
		std::cout << "\n\n������� win_rate: ";
		while (!(std::cin >> win_rt)) {
			if (win_rt < 0 || win_rt>100) {
				std::cout << "\n������! ���������: ";
				std::cin.clear();
				rewind(stdin);
				continue;
			}
			std::cout << "\n������! ���������: ";
			std::cin.clear();
			rewind(stdin);
		} std::cin.clear(); rewind(stdin);

		std::cout << "\n\n������� �����: ";
		while (!(std::cin >> id)) {
			std::cout << "\n������! ���������: ";
			std::cin.clear();
			rewind(stdin);
		} std::cin.clear(); rewind(stdin);

		std::cout << "\n\n������� ���-�� ������: ";
		while (!(std::cin >> amnt_of_tables)) {
			std::cout << "\n������! ���������: ";
			std::cin.clear();
			rewind(stdin);
		} std::cin.clear(); rewind(stdin);
	}
	if (seet == 3) {
		std::cout << "\n\n������� ���� ���������: ";
		while (!(std::cin >> ch_to_lose) 
			|| (ch_to_lose < 0 || ch_to_lose > 100)) {
			std::cout << "\n������! ���������: ";
			std::cin.clear();
			rewind(stdin);
		} std::cin.clear(); rewind(stdin);

		std::cout << "\n\n������� ���� ��������: ";
		while (!(std::cin >> ch_to_win)
			|| (ch_to_win < 0 || ch_to_win>(100 - ch_to_lose))) {
			std::cout << "\n������! ���������: ";
			std::cin.clear();
			rewind(stdin);
		} std::cin.clear(); rewind(stdin);

		std::cout << "\n\n������� ���-�� ������� ��������: ";
		while (!(std::cin >> amnt_of_pg)) {
			std::cout << "\n������! ���������: ";
			std::cin.clear();
			rewind(stdin);
		} std::cin.clear(); rewind(stdin);

	}
}