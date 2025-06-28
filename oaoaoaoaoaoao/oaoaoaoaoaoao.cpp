#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct bots {
	string name;
	string discription;



};

// Создал структуру для предметов 
struct items {
	string name;
	string discription;
	int count;
	string item_target;
	string item_location;
};

// СОЗДАЛ СТРУКТУРУ для ПОРТАЛОВ portal_, в ней имя портала, и цель куда она ведет.
struct portal_ {
	string name;
	int target;
};

// Локации, имя, описание, векьторный массив с порталами, откуда мы будем записывать таргет в текущее положение игрока
struct location{
	string name;
	string discription;
	vector<portal_> portal;
	vector<items> loot;

};

// Игрок, текущее местоположение 
struct Player {
	int current_loc = 0;
	vector<items> inventory;
};

// Создаем обькты с типом данных наших структур
location room[4];
Player hero;
string temp;

// 
void check_items() {

	bool check = true;

	while (check = true) {

		if (temp == "Ключ") {

			check = false;

		}
		else if (temp == "Факел") {
			 
			check = false;

		}
		else if (temp == "Золото") {

			check = false;

		}
	}

}

// 
void check_portal() {

	bool check = true;

	while (check == true) {

		if (temp == "red") {
			check = false;
		}
		else if (temp == "blue") {
			check = false;
		}
		else if (temp == "violet") {
			check = false;
		}
		else if (temp == "pink") {
			check = false;
		}
		else if (temp == "black") {
			check = false;
		}
		else if (temp == "green") {
			check = false;
		}
		else {
			cout << "Введите имя одного из доступных порталов: \n";
			for (int i = 0; i < room[hero.current_loc].portal.size(); i++) {

				cout << room[hero.current_loc].portal[i].name << std::endl;

			}
			cin >> temp;
		}
	}

}


// Проверка на неправильность ввода 
void check_action(){

	//
	bool check = true;

	// 
	while (check == true) {

		if (temp == "go") {
			check = false;
		}
		else if (temp == "check") {
			check = false;
		}
		else if (temp == "list") {
			check = false;
		}
		else if (temp == "use") {
			check = false;
		}
		else {
			cout << "Выберите одно из действий: go, check room, list, use \n";
			cin >> temp;
		}
	}


}

// Инициализируем составляющие игры
void InitGame() {

	// Добавляем имена локаций, чтобы в дальньйшем сравниватьт их с вводом пользователя
	room[0].name = "Дом";
	room[1].name = "Таверна";
	room[2].name = "Шахта";
	room[3].name = "Пещера";

	// Добавляем описание локаций
	room[0].discription = "Мой уютный домик где я всегда могу хорошенько отдохнуть";
	room[1].discription = "Отличное место чтобы расслабиться после тяжелого дня в шахте";
	room[2].discription = "Здесь наверняка можно найти что-то интересное";
	room[3].discription = "Тут слишком темно...";

	// Создаем порталы с именами и таргетом
	room[0].portal.push_back({ "red", 1 }); // дверь с ONE в TWO / 1 --> 2
	room[0].portal.push_back({ "blue", 3 }); // дверь с ONE в FOUR / 1 --> 4
	room[3].portal.push_back({ "pink", 2 }); // с FOUR в THREE / 4 --> 3
	room[2].portal.push_back({ "violet", 1 }); // с THREE в TWO / 3 --> 2
	room[1].portal.push_back({ "black", 0 }); // с THREE в ONE / 3 --> 1
	room[2].portal.push_back({ "green", 0 }); // с TWO в ONE / 2 --> 1

	// Создаем пул предметов которые игрок может найти 
	// 1 room
	room[0].loot.push_back({ "Ключ", "Открывает розовый портал", 1, "пещера", "Дом"});
	room[0].loot.push_back({"Факел", "Осветит темноту на твоем пути", 1, "пещера", "Дом"});
	// 3 room
	room[2].loot.push_back({ "Золото", "Оно дорого стоит...", 2, "bot", "Шахта"});
}


// Начинаем игру
void StartGame() {

	// Создаем переменную для завершения цикла игры
	bool exit = false;

	// начало игрового цикла 
	while (exit == false) {
		
		// Показываем текущее местоположение игрока
		cout << "Вы в: \t" << room[hero.current_loc].name << "\n" << room[hero.current_loc].discription << std::endl;

		// Ожидаем ввода go
		cin >> temp;
		check_action();
		
		// При go выводим все доступные порталы для игрока в его текущем положении
		if (temp == "go") {
			
			for (int i = 0; i < room[hero.current_loc].portal.size(); i++) {

				cout << room[hero.current_loc].portal[i].name << std::endl;

			}
			// Вводим ИМЯ портала 
			cout << "Введите имя портала, в который хотите войти\n";
			cin >> temp;
			check_portal();

			//Перебираем порталы с ввода пользователя
			for (int i = 0; i < room[hero.current_loc].portal.size(); i++) {

				// Сравниваем ввод пользователя с именами порталов
				if (temp == room[hero.current_loc].portal[i].name) {

					// Присваиваем игроку новое текущее местоположение с таргета 
					hero.current_loc = room[hero.current_loc].portal[i].target;
				}

			}

		}
		// Осматриваем комнату и что-то находим / не находим
		else if (temp == "check") {

			for (int i = 0; i < room[hero.current_loc].loot.size(); i++) {

				if (room[hero.current_loc].name == room[hero.current_loc].loot[i].item_location) {

					if (room[hero.current_loc].loot[i].count > 0) {

						hero.inventory.push_back({room[hero.current_loc].loot[hero.current_loc]});
						cout << "Вы нашли: " << hero.inventory[i].name << "\n";
					} 

				}

			}

		}
		// Смотрим инвентарь
		else if (temp == "list") {

			for (int i = 0; i < hero.inventory.size(); i++) {

				cout << hero.inventory[i].name << "\n" << "Описание: " << hero.inventory[i].discription << std::endl;

			}
			cin >> temp; 

			// Используем предмет если он есть в инвентаре 
			if (temp == "use") {

				cout << "Введите имя предмета, который хотите использовать" << std::endl;
				cin >> temp;
				check_items();

				for (int i = 0; i < hero.inventory.size(); i++) {

					if (temp == hero.inventory[i].name) {

						if (room[hero.current_loc].name == hero.inventory[i].item_target) {

						}


				    }

				}
			}
		}

	}
		
}

int main() {
	setlocale(LC_ALL, "RU");
	InitGame();
	StartGame();

}