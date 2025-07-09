#include "comand.h"

void StartGame() { // Начинаем игру

	bool life = true; 	// Создаем переменную для завершения цикла игры
	cout << "Вы в: \t" << room[hero.current_loc].name << "\n" << room[hero.current_loc].discription << endl; // Показываем текущее местоположение игрока
	cout << "Для навигации воспользуйтесь командой help \n";

	while (life == true) { // начало игрового цикла

		cin >> temp; // Ожидаем ввода go/pick/list/use/
		check_action();
		
		if (temp == "go") { // При go выводим все доступные порталы для игрока в его текущем положении
			
			go();

		}
		if (temp == "speak") {// взаимодействие с дружественным ботом

			traid();

		}
		if (temp == "help") { // выводим игроку все команды и описание к ним

			help();

		}
		if (temp == "trunk") { // Выводим инвентарь игрока

			trunk();
			
		}
		if (temp == "pick") { // Подбираем предмет

			cout << "Напишите название предмета, который хотите подобрать \n";
			cin >> temp;
			check_items(); // Проверка на неправильность ввода
			pick(); // поднятие предмета

		}   
		if (temp == "list") { // Смотрим предметы в комнате
		
			list();

		}
		if (temp == "drop") { // дропаем предметы в комнату

			cout << "Напишите имя предмета, который хотите выбросить \n";
			cin >> temp;
			check_items(); // Проверка на неправильность ввода
			drop();
			
		}
		if (temp == "use") { // Используем предмет

			cout << "Введите имя предмета, который хотите использовать \n";
			cin >> temp; 
			check_items(); // Ввод и его проверка
			use_items();

		}   
	}
}
		
int main() {
	setlocale(LC_ALL, "RU");
	InitGame();
	StartGame();

}
/*///////
emplace_back мне ломает команды мудила((  dqdhtrhrtert
cdcdcdc



*/