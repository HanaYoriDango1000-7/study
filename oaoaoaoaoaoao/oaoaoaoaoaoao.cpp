#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Ñîçäàåì øàáëîí ìàãàçèíà
struct product {
	string name;
	int count;
	short price;
//дажпдпжвжв
};
 
// Ñîçäàåì þçåðà 
struct info {
	int money = 5000;
	string basket;
	int choice;
	vector<product> box;
};

// Ñîçäàåì âåêòîðíûé ìàññèâ  
vector<product> shop;
info user;

int main() {
	setlocale(LC_ALL, "RU");

	// Äîáàâëÿåì ïðîäóêò, èõ êîë-âî è öåíó â ìàññèâ
	shop.push_back({ "potato", 15, 150 });
	shop.push_back({ "tomato", 3, 100 });
	shop.push_back({ "chips", 10, 240 });
	shop.push_back({ "orange", 5, 80 });
	shop.push_back({ "cucumber", 100, 50 });

	while (user.money >= 0) {

		// Çàïóñêàåì öèêë äëÿ äåìîíñòðàöèè àññîðòèìåíòà 
		cout << "Ñïèñîê ïðîäóêòîâ â ìàãàçèíå: \n";
		for (int i = 0; i < shop.size(); i++) {
			cout << shop[i].name << "\t" << shop[i].count << "\t" << shop[i].price << "\n";
		}

		//
		std::cout << "Âàø òåêóùèé ñ÷åò: " << user.money << "\n";
		std::cout << "Ââåäèòå æåëàåìûé ïðîäóêò: ";
		std::cin >> user.basket;
		//

		for (int i = 0; i < shop.size(); i++) {

			if (user.basket == shop[i].name) {

				std::cout << "Ââåäèòå êîëè÷åñòâî: ";
				std::cin >> user.choice;

				if (user.choice <= shop[i].count ) {

					if (user.choice * shop[i].price <= user.money) {
						
						shop[i].count -= user.choice;
						user.money -= user.choice * shop[i].price;
						
						user.box.push_back({ user.basket, user.choice });
					}

				} else {

					cout << "Error \n";

				}
			}

		}


		if (user.basket == "info") {

			cout << "Âàø ñ÷åò: " << user.money << "\n";

			for (int i = 0; i < user.box.size(); i++) {

				cout << user.box[i].name << "\t" << user.box[i].count << "\n";

			}

		}

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
//
//	Tree birch;
//	birch.name = "Áåðåçà\n";
//	birch.ages = 24;
//	birch.place.x = 100;
//	birch.place.y = 50;
//
//	Tree yelka;
//	yelka.name = "Åëêà\n";
//	yelka.ages = 5;
//
//	birch.get_info();
//
//	return 0;
//}


// DZZZZZZZZZZZZZZZZZZZZZZZZ-------------------------------------















//void game() {
//
//	// Îáüÿâëåíèå ìàññèâ 
//	std::string x[3]{ "stone","sissors","paper" };
//
//	// Ñîçäàåì ïåðåìåííóþ äëÿ ðàíäîìà
//	//int r = x[];
//	srand(time(0));
//
//	int bot = rand() % 3;
//	std::string temp = x[bot];
//	std::string player;
//
//
//	// Îáúÿâëåì íà÷àëî öèêëà 
//	for (int i = 0; i < 5; i++) {
//
//		// Èãðîê ââîäèò ñâîé âàðèàíò
//		std::cin >> player;
//
//		// Âûâîäèì õîä áîòà 
//		std::cout << x[bot] << std::endl;
//
//		// Ñðàâíèâàåì è âûâîäèì win/lose/draw
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
// Ïðî÷èòàòü ïðî ñòðóêòóðû, ìàññèâû â ïîðÿäêå âîçðàñòàíèÿ - ïóçûðüêîâûé ìåòîä, 1.5 - ñèìóëÿòîð ìàãàçèíà.


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
