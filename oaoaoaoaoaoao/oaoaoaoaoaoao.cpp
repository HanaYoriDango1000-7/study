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
	
};

// Создаем векторный массив  
vector<product> shop;
info user;










void fix() {

	bool proverka = false;


	while (proverka == false) {

		std::cin >> user.basket;

		if (user.basket == "tomato" ||
			user.basket == "potato" ||
			user.basket == "chips" ||
			user.basket == "orange" ||
			user.basket == "apple") {

			proverka = true;

		}
		else {
			cout << "Введите корректное название: ";
			//std::cin >> user.basket;
		}
	}
}

int main() {
	setlocale(LC_ALL, "RU");

	// Добавляем продукт, их кол-во и цену в массив
	shop.push_back({ "tomato", 3, 100 });
	shop.push_back({ "potato", 15, 150 });
	shop.push_back({ "chips", 10, 240 });
	shop.push_back({ "orange", 5, 80 });
	shop.push_back({ "apple", 10, 50 });

	while (user.money >= 0) {

		// Запускаем цикл для демонстрации ассортимента 
		cout << "Список продуктов в магазине: \n";
		cout << "Name\t" << "Count\t" << "Price" << std::endl;
		for (int i = 0; i < shop.size(); i++) {
			cout << shop[i].name << "\t" << shop[i].count << "\t" << shop[i].price << "\n";
		}

		// ввод
		std::cout << "Ваш текущий счет: " << user.money << "\n";
		std::cout << "Введите желаемый продукт: ";
		
		fix();

		for (int i = 0; i < shop.size(); i++) {

		// Проверка ввода пользователя на соответствие списку продуктов

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

					cout << "Error 1 \n";

				}
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
