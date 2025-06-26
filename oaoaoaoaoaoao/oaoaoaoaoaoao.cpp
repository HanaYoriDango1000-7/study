#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Локации, имя, описание, порталы (двери)
struct location{
	string name;
	string discription;
	vector<int> portal;

};

// СОЗДАЛ СТРУКТУРУ для ПОРТАЛОВ portal_, в ней имя портала, и цель куда она ведет.
struct portal_ {
	string name;
	string target;
};

// Игрок, текущее местоположение 
struct Player {
	int current_loc = 0;
};

location room[4];
Player hero;
vector <portal_> doors;

//

void InitGame() {

	room[0].name = "one";
	room[1].name = "two";
	room[2].name = "three";
	room[3].name = "four";
	room[0].portal.push_back(1);
	room[0].portal.push_back(3);
	room[1].portal.push_back(0);
	room[0].discription = "Тут все заебались";
	room[1].discription = "Тут круто";
	room[2].discription = "Тут плохо"; 
	doors.push_back({"red", "blue"}); // дверь с ONE в TWO / 1 --> 2
	doors.push_back({ "orange", "green" }); // дверь с ONE в FOUR / 1 --> 4
	doors.push_back({ "indigo", "yellow" }); // с THREE в TWO / 3 --> 2
	doors.push_back({ "pink", "grey" }); // с FOUR в THREE / 4 --> 3
	doors.push_back({ "black", "violet" }); // с THREE в ONE / 3 --> 1

}

void StartGame() {

	bool exit = false;
	string temp;
	string temp2;

	int choice;

	while (exit = true) {
		
		// Текущее местоположение игрока
		cout << "Вы в локации \t" << room[hero.current_loc].name << std::endl;

		cin >> temp;
		
		if (temp == "go") {
			for (int i = 0; i < room[hero.current_loc].portal.size();i++) {

				cout << room[hero.current_loc].portal[i] << doors[hero.current_loc].name << std::endl;

			}
	
		// Выбираем портал, и ТЕКУЩАЯ локация игрока меняется на локацию выбранную нами
		cout << "Куда идем?\n";
		cin >> temp2;
		hero.current_loc = choice;

		//Перебираем двери с ввода пользователя
		for (int i = 0; i < doors.size(); i++) {\

			if (temp2 == doors[i].name) {



			 }
		
		}

		}
		
	}

}


int main() {
	setlocale(LC_ALL, "RU");
	InitGame();
	StartGame();

	/*int x[4]{ 7 , -2 , 9 , 5 };
	for (int i = 0; i < 4; i++ ) {
	
		x[i];


		cout << x[i];
	}*/
}