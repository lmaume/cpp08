#include "easyfind.hpp"


#include <vector>
#include <list>
#include <deque>

int main(void)
{
	try
	{
		std::vector<int>	victor;
		std::deque<int>		detail;
		std::list<int>		ouais;

		//? toutes les listes de nombres sont 48295,
		//? l'on trouvera l'index du nombre que l'on cherche via easyfind s'il en fait partie, sinon, une exception est renvoyee

		ouais.push_back(4);
		ouais.push_back(8);
		ouais.push_back(2);
		ouais.push_back(9);
		ouais.push_back(5);

		detail.push_back(4);
		detail.push_back(8);
		detail.push_back(2);
		detail.push_back(9);
		detail.push_back(5);

		victor.push_back(4);
		victor.push_back(8);
		victor.push_back(2);
		victor.push_back(9);
		victor.push_back(5);

		//? on cherche 9 :
		int find = ::easyfind(victor, 9);
		std::cout << "number 9's pos in victor is : " << find << '\n';

		find = ::easyfind(detail, 9);
		std::cout << "number 9's pos in detail is : " << find << '\n';

		find = ::easyfind(ouais, 9);
		std::cout << "number 9's pos in ouais is : " << find << '\n';


		//? on cherche 8 :
		find = ::easyfind(victor, 8);
		std::cout << "number 8's pos in victor is : " << find << '\n';

		find = ::easyfind(detail, 8);
		std::cout << "number 8's pos in detail is : " << find << '\n';

		find = ::easyfind(ouais, 8);
		std::cout << "number 8's pos in ouais is : " << find << '\n';


		find = ::easyfind(victor, 6);
		std::cout << "number 6's pos in victor is : " << find << '\n';
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << " number not found.\n";
	}
}
