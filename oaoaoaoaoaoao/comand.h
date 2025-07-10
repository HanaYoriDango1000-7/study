#pragma once

#include "object.h"

void drop() {

	for (int i = 0; i < hero.item.size(); i++) {

		if (temp == word[(int)hero.item[i]]) {

			cout << "Вы выбросили: " << word[(int)hero.item[i]] << endl;
			room[hero.current_loc].item.emplace_back(hero.item[i]);
			hero.item.erase(hero.item.cbegin() + i);

		}
	}
}

void list() {

	for (int i = 0; i < room[hero.current_loc].item.size(); i++) {

		cout << word[(int)room[hero.current_loc].item[i]] << "\n" << "Описание: " 
			<< discription_items[(int)room[hero.current_loc].item[i]] << endl;

	}
}

void trunk() {

	for (int i = 0; i < hero.item.size(); i++) {

		cout << left << setw(10) << word[(int)hero.item[i]] 
			<< "\t" << discription_items[(int)hero.item[i]] << endl;

	}
}

void pick() {

	for (int i = 0; i < room[hero.current_loc].item.size(); i++) {

		if (temp == word[(int)room[hero.current_loc].item[i]]) {

			cout << "Вы подобрали: " << word[(int)room[hero.current_loc].item[i]] << endl; // выводим что нашли

			hero.item.emplace_back(room[hero.current_loc].item[i]); // Добавляем в инвентарь игрока

			room[hero.current_loc].item.erase(room[hero.current_loc].item.cbegin() + i);// Удаляем с локации 

		}
	}
}

void help() {

	vector<string> action{ "go", "pick", "list", "use", "drop", "trunk", "speak" }; // список команд

	vector<string> discription_commands{  // описания команд

		"Перемещение",
		"Подобрать предмет",
		"Посмотреть предметы на локации",
		"Использовать предметы",
		"Выкинуть предмет",
		"Багажник лол",
		"Взаимодействие с мирным ботом" };

	cout << "Вы можете ввести следующие команды: \n";

	for (int i = 0; i < action.size(); i++) {

		cout << left << setw(35) << discription_commands[i] << "\t" << action[i] << endl;

	}
}

void traid() {

	if (hero.current_loc == trader.current_loc) {

		int num;
		trader.active = true;

		while (trader.active) {

			if (!trader.item.empty()) {

				if (hero.wallet > 0 && hero.wallet != 0) {

					cout << "Хозяин таверны: скажи, если что пригляделось \n";
					cout << "Вот все что у меня есть: \n";
					cout << "Наименование" << "\t" << "Цена" << endl;
					for (int i = 0; i < trader.item.size(); i++) {

						cout << trader.item[i].num << ". " << left << setw(10) << trader.item[i].name 
							<< "\t" << trader.item[i].price << "\n" << trader.item[i].discription << endl;

					}
					cout << "Ваш бюджет: " << hero.wallet << endl;
					cout << "Для покупки введите номер товара (0 - выйти)" << endl;
					cin >> num;
					for (int i = 0; i < trader.item.size(); i++) {

						if (num == trader.item[i].num) {
							if (trader.item[i].price <= hero.wallet) {

								switch (num) {
								case(1):
									hero.wallet -= 1 * trader.item[i].price;
									hero.item.emplace_back(trader.item_[i]);
									trader.item.erase(trader.item.cbegin() + i);
									trader.item_.erase(trader.item_.cbegin() + i);
									cout << "Без понятия зачем тебе этот ключ, но с тобой приятно иметь дело \n";
									break;
								case(2):
									hero.wallet -= 1 * trader.item[i].price;
									hero.item.emplace_back(trader.item_[i]);
									trader.item.erase(trader.item.cbegin() + i);
									trader.item_.erase(trader.item_.cbegin() + i);
									cout << "Хороший выбор \n";
									break;
								case(3):
									hero.wallet -= 1 * trader.item[i].price;
									hero.item.emplace_back(trader.item_[i]);
									trader.item.erase(trader.item.cbegin() + i);
									trader.item_.erase(trader.item_.cbegin() + i);
									cout << "Спасибо за покупку! \n";
									break;

								}
							}
						}
						if (num == 0 && (i == trader.item.size() - 1)) {

							cout << "Вы вышли из магазина \n";
							trader.active = false;

						}
						if (num != 0 && (i == trader.item.size() - 1)) {

							cout << "Введите корректный выбор \n";

						}
					}
				}
				else {
					cout << "Хозяин таверны: нет денег - нет товаров, уж прости \n";
					trader.active = false;

				}
			}
			else {
				cout << "Хозяин таверны: прости, но у меня больше ничего нет. Приходи в другой раз\n";
				trader.active = false;

			}
		}
	}
	else {
		cout << "Здесь не с кем разговаривать \n";

	}
}
void check_items() { // проверка на ввод предметов

	vector<string> items{ "key", "torch", "gold", "dark key", "axe", "shield" };

	check = true;

	while (check) {

		for (int i = 0; i < items.size(); i++) {

			if (temp == items[i]) {

				check = false;
				break;

			}
			if (temp != items[i] && (i == items.size() - 1)) {

				cout << "Введите имя предмета правильно \n";
				cin >> temp;
			}
		}

	}
}

void check_portal(string temp) { // проверка на ввод порталов

	check = true;

	while (check) {

		for (int i = 0; i < room[hero.current_loc].portal.size(); i++) {

			if (temp == room[hero.current_loc].portal[i].name) {

				check = false;
				break;
			}

			if (temp != room[hero.current_loc].portal[i].name && (i == room[hero.current_loc].portal.size() - 1)) {


				cout << "Введите название одного из доступных порталов: " << endl;

				for (int i = 0; i < room[hero.current_loc].portal.size(); i++) {

					cout << room[hero.current_loc].portal[i].name << endl;
					check = false;
				}
				cin >> temp;
			}
		}
	}
}

void check_action() { // Проверка на неправильность ввода

	vector<string> action{ "go", "pick", "list", "use", "drop", "trunk", "help", "speak" };

	check = true;

	while (check) {

		for (int i = 0; i < action.size(); i++) {

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

void use_items() {
	if (!hero.item.empty()) {

		for (int i = 0; i < hero.item.size(); i++) { // Перебираем инвентарь

			if (temp == word[(int)hero.item[i]]) { // Проверяем на имя предмета

				if (temp == "key") {

					cout << "Введите имя портала, который желаете открыть или закрыть \n";
					cin >> temp;
					check_portal(temp);

					for (int j = 0; j < room[hero.current_loc].portal.size(); j++) {

						if (temp == room[hero.current_loc].portal[j].name) {

							auto& p = room[hero.current_loc].portal[j];

							p.open ? p.open = false : p.open = true;
							cout << p.name << "\t" << (room[hero.current_loc].portal[j].open ? " теперь открыт \n" : "теперь закрыт \n");
							

						}

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

			}
			else if (temp != word[(int)hero.item[i]] && hero.item.empty() ||
				temp != word[(int)hero.item[i]] && (i == hero.item.size() - 1)) {

				cout << "ERROR NOT FOUND \n";
				
			}
		}
	}
	else {

		cout << "У тебя ничего нет \n";

	}
}

void go() {

	for (int i = 0; i < room[hero.current_loc].portal.size(); i++) {

		cout << room[hero.current_loc].portal[i].name << "\t" << (room[hero.current_loc].portal[i].open ? "Открыто" : "Закрыто") << endl;

	}
	cout << "Введите имя портала, в который хотите войти\n";
	cin >> temp;
	check_portal(temp); // ввод и проверка на неправильность ввода

	for (int i = 0; i < room[hero.current_loc].portal.size(); i++) { //Перебираем порталы с ввода пользователя

		if (temp == room[hero.current_loc].portal[i].name && room[hero.current_loc].portal[i].open == true) { // Сравниваем ввод пользователя с именами порталов

			hero.current_loc = room[hero.current_loc].portal[i].target; // Присваиваем игроку новое текущее местоположение с таргета 
			cout << "Вы переместились в: \t" << room[hero.current_loc].name << "\n" << room[hero.current_loc].discription << endl; // Показываем текущее местоположение игрока

		}
	}
}