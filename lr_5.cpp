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
		std::cout << "Заработал конструктор по умолчанию (Casino)!\n";
		money = 0;
		players = 0;
		workers = 0;
		name = "Пусто";
	}
	Casino(double mon, int play,
		int work, std::string h) {
		std::cout << "Заработал конструктор инициализации (Casino)!\n";
		money = mon;
		players = play;
		workers = work;
		name = h;
	}
	Casino(Casino& one) : money(one.money),
		players(one.players), workers(one.workers),
		name(one.name) {
		std::cout << "Заработал конструктор копирования (Casino)!\n";
	}
	virtual ~Casino() {
		std::cout << "Заработал деструктор (Casino)!\n";
	}
	virtual void profit() {

	}
	virtual void info() {
		//std::cout << "Название казино: " << name << "\n\nКол-во посетителей: " << players
		//	<< "\nКол-во рабочих: " << workers << "\nДенег в кассе: " << money
		//	<< "\n\n";
	}
};

class Cards : virtual public Casino {
protected:
	int amnt_of_tables;
	double play_payment;
public:
	Cards() {
		std::cout << "Заработал конструктор по умолчанию (Cards)!\n";
		play_payment = 0;
		amnt_of_tables = 0;
		/*tables = nullptr;*/
	}
	Cards(double pay, int amnt, double mon, int wor, int pl) {
		std::cout << "Заработал конструктор инициализации (Cards)!\n";
		play_payment = pay;
		amnt_of_tables = amnt;
		money = mon;
		workers = wor;
		players = pl;
		/*tables = new int[amnt];*/
	}
	Cards(Cards& one) : amnt_of_tables(one.amnt_of_tables),
		/*tables(one.tables),*/ play_payment(one.play_payment) {
		std::cout << "Заработал конструктор копирования (Cards)!\n";
	}
	~Cards() {
		std::cout << "Заработал деструктор (Card)!\n";
		/*delete tables;*/
	}
	void profit() {
		int prof;
		prof = players * play_payment;
		std::cout << "\n\nПрофит карт: " << prof;
	}
	void info() {
		std::cout << "\n\nКол-во игроков: " << players
			<< "\nКол-во рабочих: " << workers << "\nДенег в кассе: " << money
			<< "\nКол-во столов с карточнми играми: " << amnt_of_tables
			<< "\nПлата за возможность присоединится: " << play_payment << "\n\n";
	}
};

class Poker : public Cards {
protected:
	double win_rate;
	int table_id;
public:
	Poker() {
		std::cout << "Заработал конструктор по умолчанию (Cards)!\n";
		table_id = 0;
	}
	Poker(int Id, double wn, double mon, int wor, int pl) {
		std::cout << "Заработал конструктор инициализации (Cards)!\n";
		table_id = Id;
		win_rate = wn;
		money = mon;
		workers = wor;
		players = pl;
	}
	Poker(Poker& one) : table_id(one.table_id) {
		std::cout << "Заработал конструктор копирования (Cards)!\n";
	}
	~Poker() {
		std::cout << "Заработал деструктор (Card)!\n";
	}
	void profit() {
		double prof;
		prof = (players * win_rate) / amnt_of_tables;
		std::cout << "\n\nПроцент профита в покере: "
			<< prof << "%";
	}
	void info() {
		std::cout << "\n\nНомер стола: " << table_id
			<< "\nКол-во игроков на картах: " << players
			<< "\nКол-во рабочих на картах: " << workers << "\nВсего денег в кассе на картах: " << money
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
		std::cout << "Заработал конструктор по умолчанию (Slots)!\n";
		chance_to_lose_money = 0;
		chance_to_win_money = 0;
		amount_of_playgrounds = 0;
	}
	Slots(double ch_1, double ch_2, int set, double mon, int wor, int pl) {
		std::cout << "Заработал конструктор инициализации (Slots)!\n";
		chance_to_lose_money = ch_1;
		chance_to_win_money = ch_2;
		amount_of_playgrounds = set;
		money = mon;
		workers = wor;
		players = pl;
	}
	~Slots() {
		std::cout << "Заработал деструктор (Slots)!\n";
	}
	void profit() {
		double precent_of_profit;
		precent_of_profit = (chance_to_lose_money * chance_to_win_money) / 200;
		std::cout << "\n\nПроцент профита игровых автоматов: "
			<< precent_of_profit <<"%";
	}

	void info() {
		std::cout  << "\n\nКол-во игроков на слотах: " << players
			<< "\nКол-во рабочих на слотах: " << workers << "\nВсего денег в кассе на слотах: " << money
			<< "\nКол-во колес фортуны: " << amount_of_playgrounds
			<< "\nШанс прибыли: " << chance_to_win_money << "%"
			<< "\t\tШанс убыли: " << chance_to_lose_money << "%" << "\n\n";
	}
};

using namespace std;
int main() {
	system("chcp 1251");
	system("CLS");

	int players, workers, amnt_of_tables,
		amnt_of_pg, id, set;
	double money, ch_to_lose, ch_to_win, win_rt, p_payment;

	std::cout << "\n\nВведите кол-во посетителей: ";
	std::cin >> players;
	std::cout << "\n\nВведите кол-во рабочих: ";
	std::cin >> workers;
	std::cout << "\n\nВведите кол-во столов: ";
	std::cin >> amnt_of_tables;
	std::cout << "\n\nВведите кол-во денег: ";
	std::cin >> money;
	std::cout << "\n\nВведите cтоимость игры: ";
	std::cin >> p_payment;
	Cards c(p_payment, amnt_of_tables, money, workers, players);
	
	std::cout << "\n\nВведите кол-во посетителей: ";
	std::cin >> players;
	std::cout << "\n\nВведите кол-во рабочих: ";
	std::cin >> workers;
	std::cout << "\n\nВведите win_rate: ";
	std::cin >> win_rt;
	std::cout << "\n\nВведите кол-во денег: ";
	std::cin >> money;
	std::cout << "\n\nВведите номер: ";
	std::cin >> id;
	Poker p(id, win_rt, money, workers, players);

	std::cout << "\n\nВведите кол-во посетителей: ";
	std::cin >> players;
	std::cout << "\n\nВведите кол-во рабочих: ";
	std::cin >> workers;
	std::cout << "\n\nВведите шанс проигрыша: ";
	std::cin >> ch_to_lose;
	std::cout << "\n\nВведите кол-во денег: ";
	std::cin >> money;
	std::cout << "\n\nВведите шанс выигрыша: ";
	std::cin >> ch_to_win;
	std::cout << "\n\nВведите кол-во игровых площадок: ";
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