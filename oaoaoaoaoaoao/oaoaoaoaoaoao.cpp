#include <iostream>
#include <string>


// DZZZZZZZZZZZZZZZZZZZZZZZZ----------------------------------
// ��������� ��� ���������, ������� � ������� ����������� - ����������� �����, 1.5 - ��������� ��������.

int main() {

	int x[5]{ 7, -1, 4, -9, 5 };

	for (int i = 0; i < 5 ; i++) {
		
		if (x[i - 1] > x[i]) {

			std::swap(x[i - 1], x[i]);
			
		}
		
		std::cout << x[i];

	}
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
//	setlocale(LC_ALL, "RU");
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
