#include <iostream>
#include <string>
#include <vector>

using namespace std;



// Создаем шаблон магазина
struct product {
	string name;
	int count;
	short price;

};

// Создаем юзера 
struct info {
	int money = 5000;
	string basket;
	int choice;
	vector<product> box;

	void fix() {
		if (user.basket == shop[i].name) {
			if () {



			}

		}
	}

};

// Создаем векторный массив  
vector<product> shop;
info user;

//

int main() {
	setlocale(LC_ALL, "RU");

	// Добавляем продукт, их кол-во и цену в массив
	shop.push_back({ "potato", 15, 150 });
	shop.push_back({ "tomato", 3, 100 });
	shop.push_back({ "chips", 10, 240 });
	shop.push_back({ "orange", 5, 80 });
	shop.push_back({ "cucumber", 100, 50 });

	while (user.money >= 0) {

		// Запускаем цикл для демонстрации ассортимента 
		cout << "Список продуктов в магазине: \n";
		for (int i = 0; i < shop.size(); i++) {
			cout << shop[i].name << "\t" << shop[i].count << "\t" << shop[i].price << "\n";
		}

		//
		std::cout << "Ваш текущий счет: " << user.money << "\n";
		std::cout << "Введите желаемый продукт: ";
		/*std::cin >> user.basket;*/
		/*fix();*/
		//

		for (int i = 0; i < shop.size(); i++) {

			if (user.basket == shop[i].name) {

				std::cout << "Введите количество: ";
				std::cin >> user.choice;


				if (user.choice <= shop[i].count && user.choice > 0) {

					if (user.choice * shop[i].price <= user.money) {

						shop[i].count -= user.choice;
						user.money -= user.choice * shop[i].price;

						user.box.push_back({ user.basket, user.choice });
					}

				}
				else {

					cout << "Error: товар кончился, либо введено неверное количество \n";

				}
			}
			else {
				cout << "Error \n";
			}

		}


		if (user.basket == "info") {

			cout << "Ваш счет: " << user.money << "\n";

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
//	birch.name = "Береза\n";
//	birch.ages = 24;
//	birch.place.x = 100;
//	birch.place.y = 50;
//
//	Tree yelka;
//	yelka.name = "Елка\n";
//	yelka.ages = 5;
//
//	birch.get_info();
//
//	return 0;
//}


// DZZZZZZZZZZZZZZZZZZZZZZZZ-------------------------------------















//void game() {
//
//	// Обьявление массив 
//	std::string x[3]{ "stone","sissors","paper" };
//
//	// Создаем переменную для рандома
//	//int r = x[];
//	srand(time(0));
//
//	int bot = rand() % 3;
//	std::string temp = x[bot];
//	std::string player;
//
//
//	// Объявлем начало цикла 
//	for (int i = 0; i < 5; i++) {
//
//		// Игрок вводит свой вариант
//		std::cin >> player;
//
//		// Выводим ход бота 
//		std::cout << x[bot] << std::endl;
//
//		// Сравниваем и выводим win/lose/draw
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
// Прочитать про структуры, массивы в порядке возрастания - пузырьковый метод, 1.5 - симулятор магазина.


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
