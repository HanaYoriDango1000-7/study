#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Сделать инвентарь через класс и прописать все взаимодействия + проверка на правильностьт каждого ввода 
// предметы можно брать выбирая их с локации 
// + реализация этих предметов и бота

enum class p {
	axe,
	sword,
	hemlet

};

struct bots {
	string name;
	string discription;

};

struct commands {
	string name;
	
};

vector<string> a{"UGA BUGA", "OBAMA SOSAT", "LOX"};
string word[3]{ "axe", "sword", "hemlet" };
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
	vector<p> items;

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
bool check;
vector<commands> action;

// 
void check_items() {

	check = true;

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

	check = true;

	while (check == true) {

		for (int i = 0; i < room[hero.current_loc].portal.size(); i++) {
			
			if (temp == room[hero.current_loc].portal[i].name) {

				check = false;
				break;
			}

			 if(temp != room[hero.current_loc].portal[i].name && (i == room[hero.current_loc].portal.size() - 1)) {
				

					cout << "Введите название одного из доступных порталов: " << std::endl;

					for (int i = 0; i < room[hero.current_loc].portal.size(); i++) {

						cout << room[hero.current_loc].portal[i].name << std::endl;
						check = false;

					

					}

				
			 }

		}
	
	}

}


// Проверка на неправильность ввода 
void check_action(){

	string action[6]{"go", "check", "get", "list", "use", "drop"};

	check = true;

	while (check == true) {

		for (int i = 0; i < action[i].size(); i++ ) {

			if (temp == action[i]) {

				check = false;
				break;
			}
			if (temp != action[i] && (i == action[i].size() + 1)) {

				cout << "Введите одно из действий: go, check, get, list, use, drop";
				 

			}
		}
	}
}

// Инициализируем составляющие игры
void InitGame() {

	// Добавляем имена команд для проверок 
	action[0].name.push_back({"go"});


	// Добавляем имена локаций, чтобы в дальньйшем сравниватьт их с вводом пользователя
	room[0].name = "Дом";
	room[1].name = "Таверна";
	room[2].name = "Шахта";
	room[3].name = "Пещера";

	room[0].items.push_back(p::sword);
	// Добавляем описание локаций
	room[0].discription = "Мой уютный домик где я всегда могу хорошенько отдохнуть";
	room[1].discription = "Отличное место чтобы расслабиться после тяжелого дня в шахте";
	room[2].discription = "Здесь наверняка можно найти что-то интересное";
	room[3].discription = "Тут слишком темно...";

	// Создаем порталы с именами и таргетом
	room[0].portal.push_back({ "red", 1 }); // дверь с ONE в TWO / 1 --> 2
	room[0].portal.push_back({ "blue", 3 }); // дверь с ONE в FOUR / 1 --> 4
	room[3].portal.push_back({ "pink", 2 }); // с FOUR в THREE / 4 --> 3
	room[2].portal.push_back({ "violet", 1 }); // с THREE в TWO / 3 --> 25
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

	// Показываем текущее местоположение игрока
	cout << "Вы в: \t" << room[hero.current_loc].name << "\n" << room[hero.current_loc].discription << std::endl;

	// начало игрового цикла 
	while (exit == false) {

		// Ожидаем ввода go/check/list/use/
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
					// Показываем текущее местоположение игрока
					cout << "Вы переместились в: \t" << room[hero.current_loc].name << "\n" << room[hero.current_loc].discription << std::endl;
				}

			}

		}

		if (temp == "check") {

			cout << "Здесь есть следующий лут: \n";

			for (int i = 0; i < room[hero.current_loc].loot.size(); i++) {

				cout << room[hero.current_loc].loot[i].name << "\t" << room[hero.current_loc].loot[i].count << "\n";

			}

		}
		// Осматриваем комнату и что-то находим / не находим
		if (temp == "get") {

			for (int i = 0; i < room[hero.current_loc].loot.size(); i++) {

				// Сравниваю ИМЯ ТЕКУЩЕЙ ЛОКАЦИИ с именем локации которой принадлежит предмет
				if (room[hero.current_loc].name == room[hero.current_loc].loot[i].item_location) {

					// Количество предметов в текущей комнате больше нуля и не равно нулю
					if (room[hero.current_loc].loot[i].count > 0 && room[hero.current_loc].loot[i].count != 0) {

						// Добавляем предметы с текущей комнаты в инвентарь игрока
						hero.inventory.push_back({room[hero.current_loc].loot[i]});
						
						// Удаляем единицу с количества в локации и выводим что нашли 
						cout << "Вы нашли: " << room[hero.current_loc].loot[i].name << "\n";
						/*for (room[hero.current_loc]) {

						}*/
						room[hero.current_loc].loot[i].count--;
					} 
					else {
						break;
						// cout << "здесь больше ничего нет";
						// нужно решить проблему с двойным выводом текста здесь 
						// нужно разобраться с методом erase() который поможет удалит предметы с массива после его поднятия в ивнентарь
					}
				}

			}
		
		}

		// Смотрим инвентарь
		if (temp == "list") {

			for (int i = 0; i < hero.inventory.size(); i++) {

				cout << hero.inventory[i].name << "\t" << hero.inventory[i].count << "\n" << "Описание: " << hero.inventory[i].discription << std::endl;

			}
		}

		//
		if (temp == "drop") {

			cout << "void";

		}

		// Используем предмет если он есть в инвентаре 
		if (temp == "use") {

				// Ввод и его проверка
				cout << "Введите имя предмета, который хотите использовать" << std::endl;
				cin >> temp;
				check_items();

				// Перебираем инвентарь
				for (int i = 0; i < hero.inventory.size(); i++) {

					// Проверяем на имя предмета
					if (temp == hero.inventory[i].name) {

						// Проверяем чтобы количество предмета не было меньше или равно нулю
						if (hero.inventory[i].count > 0 && hero.inventory[i].count != 0) {

							//Сравниваем имя текущей локации с целью предмета
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

	cout << (int)room[0].items[0];
	cout << a[0];
}