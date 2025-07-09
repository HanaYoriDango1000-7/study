#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

enum class items_ {
	key,
	torch,
	gold,
	d_key,
	axe,
	shield

};

struct sale {
	string name;
	string discription;
	int price;
	int num;

};

struct peaceful_bots_ {
	string name;
	int current_loc;
	vector<sale> item;
	vector<items_> item_;
	bool active = true;

};

struct evil_bots_ {
	string name;
	vector<items_> item;
	int hp = 100;
	int attack = 10;

};
vector<string> discription_items{ "Открывает розовый портал",
								"Осветит темноту на твоем пути",
								"Оно дорого стоит...",
								"Ключ от усыпальницы",
								"Боевой топор",
								"Отличный щит" };

string word[6]{ "key", "torch", "gold", "dark key", "axe", "shield" };

struct portal_ { // имя портала, и цель куда он ведет, открыт/закрыт 
	string name;
	int target;
	bool open = true;

};

struct location { // у локаций есть имя, описание, порталы, предметы, мирные/враждебные мобы и уровень освещения (true - светло)
	string name;
	string discription;
	vector<portal_> portal;
	vector<items_> item;
	bool lvl_light = true;
};

struct Player { // у игрока есть текущее местоположение, инвентарь и кошелек
	int current_loc = 0;
	vector<items_> item;
	int wallet;
	int hp;
	int attack;
};

// Создаем обькты с типом данных наших структур
location room[5];
Player hero;
peaceful_bots_ trader;
evil_bots_ skeleton;
string temp;
bool check;



void InitGame() { // Инициализируем составляющие игры
	//player
	hero.attack = 5;
	hero.hp = 100;
	hero.wallet = 300;

	//bots
	trader.name = "Хозяин таверны";
	trader.current_loc = 1;
	trader.active = true;
	trader.item_.push_back(items_::d_key);
	trader.item_.push_back(items_::axe);
	trader.item_.push_back(items_::shield);
	trader.item.push_back({ "dark key", "Ключ от чьей-то усыпальницы", 100, 1 });
	trader.item.push_back({ "axe", "Боевой топор", 100, 2 });
	trader.item.push_back({ "shield", "Поможет защититься от атаки противника", 100, 3 });

	//location 1
	room[0].name = "Дом";

	room[0].item.push_back(items_::key);
	room[0].item.push_back(items_::torch);
	room[0].discription = "Мой уютный домик, где я всегда могу хорошенько отдохнуть";
	room[0].portal.push_back({ "red", 1 }); // 1 --> 2
	room[0].portal.push_back({ "blue", 3 }); // 1 --> 4

	//location 2
	room[1].name = "Таверна";


	room[1].discription = "Поговаривают, что хозяин этой таверны продает редкие предметы. Может стоит поговорить с ним?";
	room[1].portal.push_back({ "black", 0 }); // 3 --> 1f

	//location 3
	room[2].name = "Шахта";

	room[2].item.push_back(items_::gold);
	room[2].discription = "Здесь наверняка можно найти что-то интересное";
	room[2].portal.push_back({ "violet", 1 }); // 3 --> 2
	room[2].portal.push_back({ "green", 0 }); // 3 --> 1

	//location 4
	room[3].name = "Пещера";

	room[3].lvl_light = false;
	room[3].discription = "Тут слишком темно...";
	room[3].portal.push_back({ "pink", 2, false }); // 4 --> 3

	//location 5
	room[4].name = "Усыпальница";

	room[4].discription = "В воздухе веет опасностью...";
	room[4].portal.push_back({ "yellow", 3 }); // 5 --> 4

}