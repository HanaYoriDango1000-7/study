#include <iostream>
#include <string>
#include <vector>

using namespace std;


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

};

// Игрок, текущее местоположение 
struct Player {
	int current_loc = 0;
};

// Создаем обькты с типом данных наших структур
location room[4];
Player hero;


// Инициализируем составляющие игры
void InitGame() {

	// Добавляем имена локаций, чтобы в дальньйшем сравниватьт их с вводом пользователя
	room[0].name = "one";
	room[1].name = "two";
	room[2].name = "three";
	room[3].name = "four";

	// Добавляем описание локаций
	room[0].discription = "Тут все заебались";
	room[1].discription = "Тут круто";
	room[2].discription = "Тут плохо"; 
	room[3].discription = "Тут тупик";

	// Создаем порталы с именами и таргетом
	room[0].portal.push_back({"red", 1}); // дверь с ONE в TWO / 1 --> 2
	room[0].portal.push_back({"blue", 3}); // дверь с ONE в FOUR / 1 --> 4
	room[3].portal.push_back({"pink", 2}); // с FOUR в THREE / 4 --> 3
	room[2].portal.push_back({"violet", 1}); // с THREE в TWO / 3 --> 2
	room[1].portal.push_back({"black", 0}); // с THREE в ONE / 3 --> 1
	room[2].portal.push_back({"green", 0}); // с TWO в ONE / 2 --> 1
}

// Начинаем игру
void StartGame() {

	// Создаем переменную для завершения цикла игры
	bool exit = false;

	// Создаем переменные для временного хранения ввода от пользователя
	string temp;
	string temp2;

	// начало игрового цикла 
	while (exit = true) {
		
		// Показываем текущее местоположение игрока
		cout << "Вы в локации \t" << room[hero.current_loc].name << "\n" << room[hero.current_loc].discription << std::endl;

		// Ожидаем ввода go
		cin >> temp;
		
		// При go выводим все доступные порталы для игрока в его текущем положении
		if (temp == "go") {
			for (int i = 0; i < room[hero.current_loc].portal.size();i++) {

				cout << room[hero.current_loc].portal[i].name << std::endl;

			}
	
		// Вводим ИМЯ портала 
		cout << "Куда идем?\n";
		cin >> temp2;
	
		//Перебираем двери с ввода пользователя
		for (int i = 0; i < room[hero.current_loc].portal.size(); i++) { \

			// Сравниваем ввод пользователя с именами порталов
			if (temp2 == room[hero.current_loc].portal[i].name) {
					
				// Присваиваем игроку новое текущее местоположение с таргета 
				hero.current_loc = room[hero.current_loc].portal[i].target;
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