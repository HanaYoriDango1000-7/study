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

	vector<string> action{"go", "pick", "list", "use", "drop", "inventory"};

	check = true;

	while (check) {

		for (int i = 0; i < action.size(); i++ ) {

			if (temp == action[i]) {

				check = false;
				break;
			}
			if (temp != action[i] && (i == action.size() - 1)) {

				cout << "Введите одно из действий: go, pick, list, inventory, use, drop \n";
				 
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
	room[0].discription = "Мой уютный домик, где я всегда могу хорошенько отдохнуть";
	room[0].portal.push_back({ "red", 1 }); // дверь с ONE в TWO / 1 --> 2
	room[0].portal.push_back({ "blue", 3 }); // дверь с ONE в FOUR / 1 --> 4

	////////////////////////////////////////////////////////////////////////
	room[1].name = "Таверна";

	room[1].discription = "Отличное место, чтобы расслабиться после тяжелого дня в шахте";
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

	bool exit = false; 	// Создаем переменную для завершения цикла игры
	cout << "Вы в: \t" << room[hero.current_loc].name << "\n" << room[hero.current_loc].discription << std::endl; // Показываем текущее местоположение игрока

	while (exit == false) { // начало игрового цикла

		cin >> temp; // Ожидаем ввода go/pick/list/use/
		check_action();
		
		if (temp == "go") { // При go выводим все доступные порталы для игрока в его текущем положении
			
			for (int i = 0; i < room[hero.current_loc].portal.size(); i++) {

				cout << room[hero.current_loc].portal[i].name << std::endl;

			}
			cout << "Введите имя портала, в который хотите войти\n";
			cin >> temp;
			check_portal(); // ввод и проверка на неправильность ввода

			for (int i = 0; i < room[hero.current_loc].portal.size(); i++) { //Перебираем порталы с ввода пользователя

				if (temp == room[hero.current_loc].portal[i].name) { // Сравниваем ввод пользователя с именами порталов

					hero.current_loc = room[hero.current_loc].portal[i].target; // Присваиваем игроку новое текущее местоположение с таргета 
					cout << "Вы переместились в: \t" << room[hero.current_loc].name << "\n" << room[hero.current_loc].discription << std::endl; // Показываем текущее местоположение игрока
				}

			}

		}
		if (temp == "inventory") { // Выводим инвентарь игрока

			for (int i = 0; i < hero.item.size(); i++) {

				cout << word[(int)hero.item[i]] << endl;

			}

		}
		if (temp == "pick") { // Подбираем предмет

			cout << "Напишите название предмета, который хотите подобрать \n";
			cin >> temp;
			check_items(); // Проверка на неправильность ввода

			for (int i = 0; i < room[hero.current_loc].item.size(); i++) {

				if (temp == word[(int)room[hero.current_loc].item[i]]) {

						cout << "Вы подобрали: " << word[(int)room[hero.current_loc].item[i]] << endl; // выводим что нашли
						hero.item.emplace_back(room[hero.current_loc].item[i]); // Добавляем в инвентарь игрока
						room[hero.current_loc].item.erase(room[hero.current_loc].item.cbegin() + i);// Удаляем с локации 

				}
			}

		}   
		if (temp == "list") { // Смотрим предметы в комнате
		
			for (int i = 0; i < room[hero.current_loc].item.size(); i++) {

				cout << word[(int)room[hero.current_loc].item[i]] << "\n" << "Описание: " << discription_items[i] << std::endl;

			}
		}
		if (temp == "drop") { // дропаем предметы в комнату

			cout << "Напишите имя предмета, который хотите выбросить \n";
			cin >> temp;
			check_items();

			for (int i = 0; i < hero.item.size(); i++) {
			
				if (temp == word[(int)hero.item[i]]) {
				
					hero.item.erase(hero.item.cbegin() + i);

					room[hero.current_loc].item.emplace_back(hero.item[i]);

				
				}
			
			}

		}
		if (temp == "use") { // Используем предмет

				cout << "Введите имя предмета, который хотите использовать \n";
				cin >> temp; // Ввод и его проверка
				check_items();

				for (int i = 0; i < hero.item.size(); i++) { // Перебираем инвентарь

					if (temp == word[(int)hero.item[i]]) { // Проверяем на имя предмета

						cout << "efwsef";

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