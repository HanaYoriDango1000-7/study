#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Сделать инвентарь через класс и прописать все взаимодействия + проверка на правильностьт каждого ввода 
// предметы можно брать выбирая их с локации 
// + реализация этих предметов и бота

enum class items_ {
	key,
	torch,
	gold

};

struct bots {
	string name;
	string discription;

};

vector<string> discription_items{"Открывает розовый портал", "Осветит темноту на твоем пути", "Оно дорого стоит..."};
string word[3]{ "key", "torch", "gold" };
int count_items[3]{1, 1, 3};

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
	vector<items_> item;

};

// Игрок, текущее местоположение 
struct Player {
	int current_loc = 0;
	vector<items_> item;
};

// Создаем обькты с типом данных наших структур
location room[4];
Player hero;
string temp;
bool check;

// 
void check_items() {

	vector<string> items{ "key", "torch", "gold" };

	check = true;

	while (check) {

		for (int i = 0; i < items.size(); i++) {

			if (temp == items[i]) {
				
				check = false;
				break;

			}
			if (temp != items[i] && (i == items.size() - 1)) {

				cout << "Введите имя предмета правильно";

			}
		}

	}
}


// 
void check_portal() {

	check = true;

	while (check) {

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

	vector<string> action{"go", "check", "get", "list", "use", "drop"};

	check = true;

	while (check) {

		for (int i = 0; i < action.size(); i++ ) {

			if (temp == action[i]) {

				check = false;
				break;
			}
			if (temp != action[i] && (i == action.size() - 1)) {

				cout << "Введите одно из действий: go, check, get, list, use, drop \n";
				 
				cin >> temp;
				
			}
		}
	}
}

// Инициализируем составляющие игры
void InitGame() {

	// Добавляем имена локаций, чтобы в дальньйшем сравниватьт их с вводом пользователя
	room[0].name = "Дом";

	room[0].item.push_back(items_::key);
	room[0].item.push_back(items_::torch);
	room[0].discription = "Мой уютный домик где я всегда могу хорошенько отдохнуть";
	room[0].portal.push_back({ "red", 1 }); // дверь с ONE в TWO / 1 --> 2
	room[0].portal.push_back({ "blue", 3 }); // дверь с ONE в FOUR / 1 --> 4

	////////////////////////////////////////////////////////////////////////
	room[1].name = "Таверна";

	room[1].discription = "Отличное место чтобы расслабиться после тяжелого дня в шахте";
	room[1].portal.push_back({ "black", 0 }); // с THREE в ONE / 3 --> 1

	////////////////////////////////////////////////////////////////////////
	room[2].name = "Шахта";

	room[2].item.push_back(items_::gold);
	room[2].discription = "Здесь наверняка можно найти что-то интересное";
	room[2].portal.push_back({ "violet", 1 }); // с THREE в TWO / 3 --> 25
	room[2].portal.push_back({ "green", 0 }); // с TWO в ONE / 2 --> 1

	///////////////////////////////////////////////////////////////////////
	room[3].name = "Пещера";

	room[3].discription = "Тут слишком темно...";
	room[3].portal.push_back({ "pink", 2 }); // с FOUR в THREE / 4 --> 3

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

			for (int i = 0; i < room[hero.current_loc].item.size(); i++) {

				cout << word[(int)room[hero.current_loc].item[i]] << endl;

			}

		}
		// Осматриваем комнату и что-то находим / не находим
		if (temp == "get") {

			cout << "Напишите название предмета, который хотите подобрать";
			cin >> temp;

			for (int i = 0; i < room[hero.current_loc].item.size(); i++) {

				if (temp == word[(int)room[hero.current_loc].item[i]]) {

					// Количество предметов в текущей комнате больше нуля и не равно нулю
					if (count_items[i] > 0 &&  count_items[i] != 0) {

						// Добавляем предметы выбранный предмет в инвентарь игрока
						hero.item.emplace_back(word[(int)room[hero.current_loc].item[i]]);
						
						// Удаляем единицу с количества в локации и выводим что нашли 
						cout << "Вы нашли: " << word[(int)room[hero.current_loc].item[i]] << "\n";
					
						count_items;
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


}