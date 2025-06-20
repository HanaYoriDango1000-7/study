#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct location{
	int number;
	string name;
	string discription;
	vector<int> portal;

};

struct portal_ {
	string name;
	string target;
};

struct Player {
	int current_loc = 0;
};

location room[4];
Player hero;

//

void InitGame() {

	room[0].name = "one";
	room[1].name = "two";
	room[2].name = "three";
	room[3].name = "four";
	room[0].portal.push_back(1);
	room[0].portal.push_back(3);
	room[1].portal.push_back(0);
	room[0].discription = "Тут все заебались, куда пойдем?";
	room[1].discription = "Тут круто";
	room[2].discription = "Тут плохо"; 
}

//МЫ ВЫВОДИМ ИМЯ ЛОКАЦИИ В КОТОРОЙ НАХОДИТЬСЯ ИГРОК.


void StartGame() {

	cout << "Мы находимся здесь: " << room[0].name << "\n";//НЕ ПРАВИЛЬНО!!
	cout << "Описание: " << room[0].discription << "\n";

	bool exit = false;
	string temp;

	while (exit = true) {
		// МЫ ВВОДИМ go и нам должно выдавать двери/порталы в ТЕКУЩЕЙ локции игрока
		// Выбираем портал, и ТЕКУЩАЯ локация игрока меняется на локацию выбранную нами

		cin >> temp;
		
		if (temp == "go") {
			
			
		}
		
	}

}

int main() {
	setlocale(LC_ALL, "RU");
	InitGame();
	StartGame();

	int x[4]{ 7 , -2 , 9 , 5 };
	for (int i = 0; i < 4; i++ ) {
	
		x[0] = 1;


		//cout << x[i];
	}
}