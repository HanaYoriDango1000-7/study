#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// + реализация этих предметов и бота

enum class items_ {
	key,
	torch,
	gold

};

struct sale {
	string name;
	string discription;
	int price;


};

struct peaceful_bots_ {
	string name;
	string discription;
	vector<sale> item;

};

struct evil_bots_ {
	string name;
	string discription;
	vector<items_> item;
	int hp;
	int attack;

};
vector<string> discription_items{"Открывает розовый портал", "Осветит темноту на твоем пути", "Оно дорого стоит..."};
string word[3]{ "key", "torch", "gold" };

struct portal_ { // имя портала, и цель куда он ведет, открыт/закрыт
	string name;
	int target;
	bool open = true;
	
};

struct location{ // у локаций есть имя, описание, порталы, предметы, мирные/враждебные мобы и уровень освещения (true - светло)
	string name;
	string discription;
	vector<portal_> portal;
	vector<items_> item;
	vector<peaceful_bots_> p_bot;
	vector<evil_bots_> e_bot;
	bool lvl_light = true;
};

struct Player { // у игрока есть текущее местоположение, инвентарь и кошелек
	int current_loc = 0;
	vector<items_> item;
	int wallet = 200;
};

// Создаем обькты с типом данных наших структур
location room[5];
Player hero;
string temp;
bool check;
 
void check_items() { // проверка на ввод предметов

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

void check_portal() { // проверка на ввод порталов

	check = true;

	while (check) {

		for (int i = 0; i < room[hero.current_loc].portal.size(); i++) {
			
			if (temp == room[hero.current_loc].portal[i].name) {

				check = false;
				break;
			}

			 if(temp != room[hero.current_loc].portal[i].name && (i == room[hero.current_loc].portal.size() - 1)) {
				

					cout << "Введите название одного из доступных порталов: " << endl;

					for (int i = 0; i < room[hero.current_loc].portal.size(); i++) {

						cout << room[hero.current_loc].portal[i].name << endl;
						check = false;

					

					}

				
			 }

		}
	
	}

}

void check_action(){ // Проверка на неправильность ввода

	vector<string> action{"go", "pick", "list", "use", "drop", "trunk", "help", "speak"};

	check = true;

	while (check) {

		for (int i = 0; i < action.size(); i++ ) {

			if (temp == action[i]) {

				check = false;
				break;
			}
			if (temp != action[i] && (i == action.size() - 1)) {

				cout << "Введите одно из действий: help, go, pick, list, trunk, use, drop, speak \n";
				 
				cin >> temp;
				
			}
		}
	}
}

void InitGame() { // Инициализируем составляющие игры

	room[0].name = "Дом";

	room[0].item.push_back(items_::key);
	room[0].item.push_back(items_::torch);
	room[0].discription = "Мой уютный домик, где я всегда могу хорошенько отдохнуть";
	room[0].portal.push_back({ "red", 1 }); // 1 --> 2
	room[0].portal.push_back({ "blue", 3 }); // 1 --> 4

	////////////////////////////////////////////////////////////////////////
	room[1].name = "Таверна";

	room[1].p_bot.push_back({ "Хозяин таверны", "Помимо хорошей выпивки может продать и редкие предметы" });
	room[1].discription = "Поговаривают, что хозяин этой таверны продает редкие предметы. Он сидит за одним из столов. Может стоит поговорить с ним?";
	room[1].portal.push_back({ "black", 0 }); // 3 --> 1

	////////////////////////////////////////////////////////////////////////
	room[2].name = "Шахта";

	room[2].item.push_back(items_::gold);
	room[2].discription = "Здесь наверняка можно найти что-то интересное";
	room[2].portal.push_back({ "violet", 1 }); // 3 --> 2
	room[2].portal.push_back({ "green", 0 }); // 3 --> 1

	///////////////////////////////////////////////////////////////////////
	room[3].name = "Пещера";

	room[3].lvl_light = false;
	room[3].discription = "Тут слишком темно...";
	room[3].portal.push_back({ "pink", 2, false}); // 4 --> 3

	/////////////////////////////////////////////////////////////////////////
	room[4].name = "Усыпальница";

	room[4].discription = "В воздухе веет опасностью...";
	room[4].portal.push_back({ "yellow", 3 }); // 5 --> 4

}

void StartGame() { // Начинаем игру

	bool life = true; 	// Создаем переменную для завершения цикла игры
	cout << "Вы в: \t" << room[hero.current_loc].name << "\n" << room[hero.current_loc].discription << endl; // Показываем текущее местоположение игрока

	while (life == true) { // начало игрового цикла

		cin >> temp; // Ожидаем ввода go/pick/list/use/
		check_action();
		
		if (temp == "go") { // При go выводим все доступные порталы для игрока в его текущем положении
			
			for (int i = 0; i < room[hero.current_loc].portal.size(); i++) {

				cout << room[hero.current_loc].portal[i].name << "\t" << (room[hero.current_loc].portal[i].open ? "Открыто" : "Закрыто") << endl;

			}
			cout << "Введите имя портала, в который хотите войти\n";
			cin >> temp;
			check_portal(); // ввод и проверка на неправильность ввода

			for (int i = 0; i < room[hero.current_loc].portal.size(); i++) { //Перебираем порталы с ввода пользователя

				if (temp == room[hero.current_loc].portal[i].name && room[hero.current_loc].portal[i].open == true) { // Сравниваем ввод пользователя с именами порталов

					hero.current_loc = room[hero.current_loc].portal[i].target; // Присваиваем игроку новое текущее местоположение с таргета 
					cout << "Вы переместились в: \t" << room[hero.current_loc].name << "\n" << room[hero.current_loc].discription << endl; // Показываем текущее местоположение игрока
				
				}

			}

		}
		if (temp == "speak") {




		}
		if (temp == "help") { // выводим игроку все команды и описание к ним

			vector<string> action{ "go", "pick", "list", "use", "drop", "trunk", "speak"}; // список команд
			vector<string> discription_commands{  // описания команд
				"Перемещение", 
				"Подобрать предмет", 
				"Посмотреть предметы на локации", 
				"Использовать предметы",
				"Выкинуть предмет", 
				"Багажник лол",
			    "Взаимодействие с дружественным ботом"};
				

			cout << "Вы можете ввести следующие команды: \n";

			for (int i = 0; i < action.size(); i++) {

				cout << left << setw(25) << discription_commands[i] << "\t" << "\t" << action[i] << endl;

			}

		}
		if (temp == "trunk") { // Выводим инвентарь игрока

			for (int i = 0; i < hero.item.size(); i++) {

				cout << word[(int)hero.item[i]] << "\n" << discription_items[i] << endl;

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

				cout << word[(int)room[hero.current_loc].item[i]] << "\n" << "Описание: " << discription_items[i] << endl;

			}
		}
		if (temp == "drop") { // дропаем предметы в комнату

			cout << "Напишите имя предмета, который хотите выбросить \n";
			cin >> temp;
			check_items(); // Проверка на неправильность ввода

			for (int i = 0; i < hero.item.size(); i++) {
			
				if (temp == word[(int)hero.item[i]]) {
				
					cout << "Вы выбросили: " << word[(int)hero.item[i]] << endl;
					room[hero.current_loc].item.emplace_back(hero.item[i]);
					hero.item.erase(hero.item.cbegin() + i);

				}
			
			}

		}
		if (temp == "use") { // Используем предмет

				cout << "Введите имя предмета, который хотите использовать \n";
				cin >> temp; 
				check_items(); // Ввод и его проверка
				for (int i = 0; i < hero.item.size(); i++) { // Перебираем инвентарь

					if (temp == word[(int)hero.item[i]]) { // Проверяем на имя предмета

						if (temp == "key") {

							cout << "Введите имя портала, который желаете открыть или закрыть \n";
							cin >> temp;
							check_portal();

							if (temp == room[hero.current_loc].portal[i].name) {

								room[hero.current_loc].portal[i].open ? room[hero.current_loc].portal[i].open = false : room[hero.current_loc].portal[i].open = true;
								cout << room[hero.current_loc].portal[i].name << "\t" << (room[hero.current_loc].portal[i].open ? " теперь открыт" : "теперь закрыт") << endl;
								hero.item.erase(hero.item.cbegin() + i);

							}

						}
						if (temp == "torch") {

							if (!room[hero.current_loc].lvl_light) {

								cout << "Вы поставили факел на держатель. Теперь в комнате светло и вашему взору открылся новый портал \n";
								cout << "Интересно, куда же он ведет? \n";
								room[hero.current_loc].lvl_light = true;
								room[3].discription = "Теперь тут светло";
								room[3].portal.push_back({ "purple", 4, true }); // 4 --> 5 он скрыт
								hero.item.erase(hero.item.cbegin() + i);
							}
							else {

								cout << "В комнате итак светло \n";

							}

						}
						if (temp == "gold") {

							cout << "efgef";

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