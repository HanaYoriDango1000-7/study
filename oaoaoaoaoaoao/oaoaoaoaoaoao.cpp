#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct product {
	string name;
	int count;
	short price;

};

// ������� ��������� ������  
vector<product> shop;

int main() {
	setlocale(LC_ALL, "RU");

// ������� ���������� � ������� ����� ������� ������ � ���������� ����
	short money, result;
	money = 5000;
// ������� ���������� ��� ���������� �������� ���� � ��������� �������
	string basket;

// ��������� �������, �� ���-�� � ���� � ������
shop.push_back({ "tomato", 3, 100 });
shop.push_back({ "potato", 15, 150 });
shop.push_back({ "chips", 10, 240 });
shop.push_back({ "orange", 5, 80 });
shop.push_back({ "cucumber", 100, 50 });

//������� ������� ��� ������ ������ 
short tomato = 0;
short potato = 0;
short chips = 0;
short orange = 0;
short cucumber = 0;

// ������� ������ ���������, ���������� � ����
cout << "������ ��������� � ��������: \n";
for (int i = 0; i < shop.size(); i++) {
	cout << shop[i].name << "\t" << shop[i].count << "\t" << shop[i].price << "\n";
}

// ���� ���������� ������� ��������
for (short money2 = 5000; money2 > 0; money2 = result) {

	// ����� ��������� ���� ��� ������������ ������������ 
	for (int i = 0; i < shop.size(); i++) {
		cout << shop[i].name << "\t" << shop[i].count << "\t" << shop[i].price << "\n";
	}

	//
	std::cout << "��� ������� ����: " << money << "\n";
	std::cout << "������� �������� �������: ";
	std::cin >> basket;

	//
	if (basket == "tomato") {
		if (shop[0].count > 0) {

			shop[0].count--;
			result = money - 100;
			money = result;
			tomato++;
		}
		else if (shop[0].count == 0) {
			cout << "������� ������ ��� � �������\n";
		}
	}
	if (basket == "potato") {
		if (shop[1].count > 0) {

			shop[1].count--;
			result = money - 150;
			money = result;
			potato++;
		}
		else if (shop[1].count == 0) {
			cout << "�������� ������ ��� � �������\n";
		}
	}
	if (basket == "chips") {
		if (shop[2].count > 0) {
			shop[2].count--;
			result = money - 240;
			money = result;
			chips++;
		}
		else if (shop[2].count == 0) {
			cout << "������ ������ ��� � �������\n";
		}
	}
	if (basket == "orange") {
		if (shop[3].count > 0) {
			shop[3].count--;
			result = money - 80;
			money = result;
			orange++;
		}
		else if (shop[3].count == 0) {
			cout << "���������� ������ ��� � �������\n";
		}
	}
	if (basket == "cucumber") {
		if (shop[4].count > 0) {
			shop[4].count--;
			result = money - 50;
			money = result;
			cucumber++;
		}
		else if (shop[4].count == 0) {
			cout << "������� ������ ��� � �������\n";
		}
	}
	if (basket == "complete") {
		cout << "��� ������ ��������� ���������: \n";
		if (tomato > 0) {
			cout << "������: " << tomato << "��.\n";
		}
		if (chips > 0) {
			cout << "�����: " << chips << "��.\n";
		}
		if (orange > 0) {
			cout << "���������: " << orange << "��.\n";
		}
		if (potato > 0) {
			cout << "��������: " << potato << "��.\n";
		}
		if (cucumber > 0) {
			cout << "������: " << cucumber << "��.\n";
		}
		cout << "����� �����: " << 5000 - money;
	//���������� ����
		result = 0;

	}
	}

	// ����������� �� ������
	shop.clear();
}


		

//using  namespace std;
//
//struct Point {
//	int x, y;
//
//};
//
//struct Tree {
//	string name;
//	int ages;
//	bool is_alive;
//	float height;
//	Point place;
//
//	void get_info() {
//		std::cout << "Name: " << name << "Age: " << ages;
//	}
//};
//
//int main() {
//
//	Tree birch;
//	birch.name = "������\n";
//	birch.ages = 24;
//	birch.place.x = 100;
//	birch.place.y = 50;
//
//	Tree yelka;
//	yelka.name = "����\n";
//	yelka.ages = 5;
//
//	birch.get_info();
//
//	return 0;
//}


// DZZZZZZZZZZZZZZZZZZZZZZZZ-------------------------------------















//void game() {
//
//	// ���������� ������ 
//	std::string x[3]{ "stone","sissors","paper" };
//
//	// ������� ���������� ��� �������
//	//int r = x[];
//	srand(time(0));
//
//	int bot = rand() % 3;
//	std::string temp = x[bot];
//	std::string player;
//
//
//	// �������� ������ ����� 
//	for (int i = 0; i < 5; i++) {
//
//		// ����� ������ ���� �������
//		std::cin >> player;
//
//		// ������� ��� ���� 
//		std::cout << x[bot] << std::endl;
//
//		// ���������� � ������� win/lose/draw
//		if (player == x[0] && x[bot] == x[1] ||
//			player == x[1] && x[bot] == x[2] ||
//			player == x[2] && x[bot] == x[0]) {
//
//			std::cout << "You win\n";
//
//		}
//		else if (player == x[bot]) {
//
//			std::cout << "Draw\n";
//
//		}
//		else {
//			std::cout << "You lose\n";
//		}
//	}
// ��������� ��� ���������, ������� � ������� ����������� - ����������� �����, 1.5 - ��������� ��������.


	//std::cout << temp; 

	//char word[4]{ 't','e','s','t' };

	//for (int i = 0; i < 4; i++) {
	//	std::cout << temp[i];
	//}

	//while (count < 3) {

	//	std::cin >> inp;	
	//	//
	//	if (inp == bot) {

	//		std::cout << "win\n";
	//		bot = 1 + rand() % 5;
	//		count++;

	//	}
	//	else {

	//		std::cout << "lose\n";
	//		
	//	}

	//	std::cout << bot << std::endl;

	//}
