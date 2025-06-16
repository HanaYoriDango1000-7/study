#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct product {
	string name;
	int count;
	short price;

};

// Создаем векторный массив  
vector<product> shop;

int main() {
	setlocale(LC_ALL, "RU");

// Создаем переменную в которой будем хранить денюги и результаты трат
	short money, result;
	money = 5000;
// Создаем переменную для временного хранения инфы о выбранной покупке
	string basket;

// Добавляем продукт, их кол-во и цену в массив
shop.push_back({ "tomato", 3, 100 });
shop.push_back({ "potato", 15, 150 });
shop.push_back({ "chips", 10, 240 });
shop.push_back({ "orange", 5, 80 });
shop.push_back({ "cucumber", 100, 50 });

//Счетчик покупок для вывода списка 
short tomato = 0;
short potato = 0;
short chips = 0;
short orange = 0;
short cucumber = 0;

// Выводим список продуктов, количество и цену
cout << "Список продуктов в магазине: \n";
for (int i = 0; i < shop.size(); i++) {
	cout << shop[i].name << "\t" << shop[i].count << "\t" << shop[i].price << "\n";
}

// Даем покупателю выбрать продукты
for (short money2 = 5000; money2 > 0; money2 = result) {

	// Вновь запускаем цикл для демонстрации ассортимента 
	for (int i = 0; i < shop.size(); i++) {
		cout << shop[i].name << "\t" << shop[i].count << "\t" << shop[i].price << "\n";
	}

	//
	std::cout << "Ваш текущий счет: " << money << "\n";
	std::cout << "Введите желаемый продукт: ";
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
			cout << "Томатов больше нет в наличии\n";
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
			cout << "Картошки больше нет в наличии\n";
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
			cout << "Чипсов больше нет в наличии\n";
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
			cout << "Апельсинов больше нет в наличии\n";
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
			cout << "Огурцов больше нет в наличии\n";
		}
	}
	if (basket == "complete") {
		cout << "Ваш список купленных продуктов: \n";
		if (tomato > 0) {
			cout << "Томаты: " << tomato << "Шт.\n";
		}
		if (chips > 0) {
			cout << "Чипсы: " << chips << "Шт.\n";
		}
		if (orange > 0) {
			cout << "Апельсины: " << orange << "Шт.\n";
		}
		if (potato > 0) {
			cout << "Картошка: " << potato << "Шт.\n";
		}
		if (cucumber > 0) {
			cout << "Огурцы: " << cucumber << "Шт.\n";
		}
		cout << "Общая сумма: " << 5000 - money;
	//Завершение кода
		result = 0;

	}
	}

	// Избавляемся от мусора
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
