#include <iostream>


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
// ��������� ��� ���������, 1.5 - ��������� ��������, ������� � ����� ��������
int main() {

	int x[5]{ 7, -1, 4, -9, 5 };

	int p = -5;
	p *= -1;
	


	for (int i = 0; i < 5 ; i++) {
		
		if (x[i] < 0) {

			x[i] *= -1;

		}
		
		std::cout << x[i];

	}
}

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





