#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct location{
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

	bool exit = false;
	string temp;

	int choice;

	while (exit = true) {
		
		cout << "Вы в локации \t" << room[hero.current_loc].name << std::endl;

		// МЫ ВВОДИМ go и нам должно выдавать двери/порталы в ТЕКУЩЕЙ локции игрока
		// Выбираем портал, и ТЕКУЩАЯ локация игрока меняется на локацию выбранную нами

		cin >> temp;
		
		if (temp == "go") {
			for (int i = 0; i < room[hero.current_loc].portal.size();i++) {

				cout  << room[hero.current_loc].portal[i] << std::endl;

			}

		cout << "Куда идем?\n";
		cin >> choice;

		hero.current_loc = choice ;

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