#include <iostream>
#include <string>
#include <Windows.h>
//#include "Header.h"

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
		//std::cout << "�������� ������: " << name << "\n\n���-�� �����������: " << players
		//	<< "\n���-�� �������: " << workers << "\n����� � �����: " << money
		//	<< "\n\n";
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
		/*tables = nullptr;*/
	}
	Cards(double pay, int amnt, double mon, int wor, int pl) {
		std::cout << "��������� ����������� ������������� (Cards)!\n";
		play_payment = pay;
		amnt_of_tables = amnt;
		money = mon;
		workers = wor;
		players = pl;
		/*tables = new int[amnt];*/
	}
	Cards(Cards& one) : amnt_of_tables(one.amnt_of_tables),
		/*tables(one.tables),*/ play_payment(one.play_payment) {
		std::cout << "��������� ����������� ����������� (Cards)!\n";
	}
	~Cards() {
		std::cout << "��������� ���������� (Card)!\n";
		/*delete tables;*/
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
	Poker(int Id, double wn, double mon, int wor, int pl) {
		std::cout << "��������� ����������� ������������� (Cards)!\n";
		table_id = Id;
		win_rate = wn;
		money = mon;
		workers = wor;
		players = pl;
	}
	Poker(Poker& one) : table_id(one.table_id) {
		std::cout << "��������� ����������� ����������� (Cards)!\n";
	}
	~Poker() {
		std::cout << "��������� ���������� (Card)!\n";
	}
	void profit() {
		double prof;
		prof = (players * win_rate) / amnt_of_tables;
		std::cout << "\n\n������� ������� � ������: "
			<< prof << "%";
	}
	void info() {
		std::cout << "\n\n����� �����: " << table_id
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
			<< precent_of_profit <<"%";
	}

	void info() {
		std::cout  << "\n\n���-�� ������� �� ������: " << players
			<< "\n���-�� ������� �� ������: " << workers << "\n����� ����� � ����� �� ������: " << money
			<< "\n���-�� ����� �������: " << amount_of_playgrounds
			<< "\n���� �������: " << chance_to_win_money << "%"
			<< "\t\t���� �����: " << chance_to_lose_money << "%" << "\n\n";
	}
};

using namespace std;
int main() {
	system("chcp 1251");
	system("CLS");

	int players, workers, amnt_of_tables,
		amnt_of_pg, id, set;
	double money, ch_to_lose, ch_to_win, win_rt, p_payment;

	std::cout << "\n\n������� ���-�� �����������: ";
	std::cin >> players;
	std::cout << "\n\n������� ���-�� �������: ";
	std::cin >> workers;
	std::cout << "\n\n������� ���-�� ������: ";
	std::cin >> amnt_of_tables;
	std::cout << "\n\n������� ���-�� �����: ";
	std::cin >> money;
	std::cout << "\n\n������� c�������� ����: ";
	std::cin >> p_payment;
	Cards c(p_payment, amnt_of_tables, money, workers, players);
	
	std::cout << "\n\n������� ���-�� �����������: ";
	std::cin >> players;
	std::cout << "\n\n������� ���-�� �������: ";
	std::cin >> workers;
	std::cout << "\n\n������� win_rate: ";
	std::cin >> win_rt;
	std::cout << "\n\n������� ���-�� �����: ";
	std::cin >> money;
	std::cout << "\n\n������� �����: ";
	std::cin >> id;
	Poker p(id, win_rt, money, workers, players);

	std::cout << "\n\n������� ���-�� �����������: ";
	std::cin >> players;
	std::cout << "\n\n������� ���-�� �������: ";
	std::cin >> workers;
	std::cout << "\n\n������� ���� ���������: ";
	std::cin >> ch_to_lose;
	std::cout << "\n\n������� ���-�� �����: ";
	std::cin >> money;
	std::cout << "\n\n������� ���� ��������: ";
	std::cin >> ch_to_win;
	std::cout << "\n\n������� ���-�� ������� ��������: ";
	std::cin >> amnt_of_pg;
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