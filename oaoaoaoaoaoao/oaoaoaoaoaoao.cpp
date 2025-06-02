#include <iostream>





int main()
{

	srand(time(0));
	int inp;
	int bot = 1 + rand()%5;
	int count = 0;
	

	while (count < 3) {

		std::cin >> inp;	

		if (inp == bot) {

			std::cout << "win\n";
			bot = 1 + rand() % 5;
			count++;

		}
		else {

			std::cout << "lose\n";
			
		}

		std::cout << bot << std::endl;

	}



}

