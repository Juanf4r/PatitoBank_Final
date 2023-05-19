#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime> 
#include <vector>
#include <algorithm>
#include <cmath>

class Clients //Class Clients
{
protected:
	std::string ownerName = "";
	std::string RFC = "";
	std::string password = "";
	std::string deposit = "";
	std::string withdraw = "";

	std::vector<std::string> vector_titularName;
	std::vector<std::string> vector_RFC;
	std::vector<std::string> vector_passWord;
	std::vector<std::string> vector_history;
	std::vector<std::string> vector_deposit;
	std::vector<std::string> vector_withdraw;
	std::vector<int> vector_balance;
	std::vector<long long> vector_id;

	int totalOutcomes = 0, totalIncomes = 0;
	int balance = 0;
	int id = 0;

public:
	Clients()//Client generic constructor
	{
		std::string titularName = "";
		std::string RFC = "";
		std::string password = "";
		int balance = 0;
		long long id = 1000000000;
	}//Client Specific Constructor
	Clients(std::string Nombre, std::string rfc, std::string passWord, int bal, int ID) //Client specific constructor  
	{
		ownerName = Nombre;
		RFC = rfc;
		password = passWord;
		balance = bal;
		id = ID;
	}

	~Clients() //Destroys Clients
	{}

	//Method to Create an Account
	void createAccount()
	{
		bool check = 0;
		do {
			std::cout << "\n" << "Please enter your Full Name : ";
			std::cin.ignore();
			std::getline(std::cin, ownerName); vector_titularName.push_back(ownerName);

			std::cout << "\n" << "Please enter your RFC : ";
			std::getline(std::cin, RFC); vector_RFC.push_back(RFC);

			std::cout << "\n" << "Your Balance now is: " << balance << " Dollars\n\n"; vector_balance.push_back(balance);
			Sleep(777);

			srand(time(0)); //Number Random = 0

			id = 1000000000 + rand() % 9999999999; //Random Number Between 1000000000 & 9999999999

			std::cout << "Your New ID is : " << id << "\n\n";  vector_id.push_back(id); Sleep(777);

			std::cout << "Please enter your new password : ";
			std::getline(std::cin, password); vector_passWord.push_back(password);

			std::cout << "\nCongratulations, You've made a New Account!" << "\n"; Sleep(1440);

			std::cout << "\nWould you like to create another account?\n\n"; Sleep(1440);
			std::cout << "0) Yes, 1) No" << "\n\n";
			std::cin >> check;
			system("CLS");
		} while (check == 0);
		
	}
	//Show Information about a Specific Account
	void showClient()
	{
		bool stop = false, flag = false;
		int counter = 0;
		long long aux = 0;
		long long buscar = 0;
		std::string password_buscar;

		if (vector_id.size() == 0) //Protection from Bug
		{
			std::cout << "\nYou must create an Account First\n\n"; Sleep(1500);
			system("CLS");
		}
		else
		{
			do
			{
				std::cout << "Introduce the Account ID to see: "; std::cin >> buscar;
				counter++;

				auto it = std::find(vector_id.begin(), vector_id.end(), buscar);

				if (aux <= counter)
				{
					system("CLS");

					aux = it - vector_id.begin();

					std::cout << "Introduce the password: "; std::cin >> password_buscar;
					if (password_buscar == vector_passWord[aux])
					{
						flag = true;
					}
					else
					{
						std::cout << "The password is incorrect\n";
						std::cout << "Would  you like try again?\n";
						std::cout << "0) Yes, 1) No" << "\n";
						std::cin >> stop;
						flag = false;
					}
					do
					{
						std::cout << "--------------------------------------" << "\n";
						std::cout << "||       Client Information         ||" << "\n";
						std::cout << "||                                  ||" << "\n";
						std::cout << "|| Account owner name: " << vector_titularName[aux] << "\n";
						std::cout << "|| Owner RFC: " << vector_RFC[aux] << "\n";
						std::cout << "|| Balance: " << vector_balance[aux] << "\n";
						std::cout << "|| Account ID : " << vector_id[aux] << "\n\n";

						std::cout << "Do you want to see other Account?\n\n";
						std::cout << "0) Yes, 1) No" << "\n\n";
						std::cin >> stop;
						flag = false;
					} while (flag == true);
				}
				else
				{
					std::cout << "The account you are looking for does not exist \n";
					std::cout << "Do you want to try again?\n";
					std::cout << "0) Yes, 1) No" << "\n";
					std::cin >> stop;
					counter--; flag = false;
				}
			} while (stop == false); Sleep(1440);
			system("CLS");
		}
	}
	//Deposit Money to a Selected Account
	void depositMoney()
	{
		bool stop = false, flag = false;
		int deposit = 0;
		int counter = -1;
		int aux = 0;
		long long buscar = 0;
		std::string password_buscar;

		if (vector_balance.size() == 0) //Protection from Bug
		{
			std::cout << "\nYou must create an Account First\n\n"; Sleep(1500);
			system("CLS");
		}
		else
		{
			do
			{
				std::cout << "Introduce the Account ID to deposit: "; std::cin >> buscar;
				counter++;

				auto it = std::find(vector_id.begin(), vector_id.end(), buscar);

				if (aux <= counter)
				{
					system("CLS");

					aux = it - vector_id.begin();

					do 
					{
						std::cout << "Introduce the password: "; std::cin >> password_buscar;
						if (password_buscar == vector_passWord[aux])
						{
							flag = true;
						}
						else
						{
							std::cout << "The password is incorrect\n";
							std::cout << "Would  you like try again?\n";
							std::cout << "0) Yes, 1) No" << "\n";
							std::cin >> stop;
						}
					} while (!flag && stop == false);

					while (flag == true)
					{
						std::cout << "---------------------------------------" << "\n";
						std::cout << "||       Deposit Information         ||" << "\n";
						std::cout << "||                                   ||" << "\n";
						std::cout << "|| Account owner name: " << vector_titularName[aux] << "\n";
						std::cout << "|| Balance: " << vector_balance[aux] << "\n";
						std::cout << "|| Account ID : " << vector_id[aux] << "\n\n";

						std::cout << "How much do you wish to deposit: "; std::cin >> deposit;
						system("CLS");
						
						totalIncomes += deposit;
						vector_balance[aux] += deposit;

						std::string holder = "\n"+ vector_titularName[aux] + " deposit: " + std::to_string(deposit);
						vector_history.push_back(holder);

						std::cout << "Loading"; std::cout << "."; Sleep(500); std::cout << "."; Sleep(500); std::cout << "."; Sleep(500);
						std::cout << "\nYou deposit has been completed\n\n";

						std::cout << "---------------------------------------" << "\n";
						std::cout << "||       Deposit Information         ||" << "\n";
						std::cout << "||                                   ||" << "\n";
						std::cout << "|| Account owner name: " << vector_titularName[aux] << "\n";
						std::cout << "|| Balance: " << vector_balance[aux] << "\n";
						std::cout << "|| Account ID : " << vector_id[aux] << "\n\n";

						std::cout << "Do you want to deposit again?\n";
						std::cout << "0) Yes, 1) No" << "\n";
						std::cin >> stop; flag = false;

					} 
				}
				else
				{
					std::cout << "The account you are looking for does not exist \n";
					std::cout << "Do you want to try again?\n";
					std::cout << "0) Yes, 1) No" << "\n";
					std::cin >> stop;
					counter--;
				}
				if (aux >= vector_id.size())
				{
					std::cout << "There are no more accounts to show\n";
				}
			} while (stop == false); Sleep(1440);
			system("CLS");
		}
	}
	//Retire Money of a Selected Account
	void retireMoney()
	{
		bool stop = false, flag = false;
		int withdraw = 0;
		int invert = 0;
		int counter = -1;
		int aux = 0;
		long long buscar = 0;
		std::string password_buscar;

		if (vector_balance.size() == 0) //Protection from Bug
		{
			std::cout << "\nYou must create an Account First\n\n"; Sleep(1500);
			system("CLS");
		}
		else
		{
			do
			{
				std::cout << "Introduce the Account ID to withdraw: "; std::cin >> buscar;
				counter++;

				auto it = std::find(vector_id.begin(), vector_id.end(), buscar);

				if (aux <= counter)
				{
					system("CLS");

					aux = it - vector_id.begin();
					do
					{
						std::cout << "Introduce the password: "; std::cin >> password_buscar;
						if (password_buscar == vector_passWord[aux])
						{
							flag = true;
						}
						else
						{
							std::cout << "The password is incorrect\n";
							std::cout << "Would  you like try again?\n";
							std::cout << "0) Yes, 1) No" << "\n";
							std::cin >> stop;
						}
					}while (!flag && stop == false);
					while (flag == true)
					{
						std::cout << "----------------------------------------" << "\n";
						std::cout << "||       Withdraw Information         ||" << "\n";
						std::cout << "||                                    ||" << "\n";
						std::cout << "|| Account owner name: " << vector_titularName[aux] << "\n";
						std::cout << "|| Balance: " << vector_balance[aux] << "\n";
						std::cout << "|| Account ID : " << vector_id[aux] << "\n\n";

						std::cout << "How much do you want to Withdraw: "; std::cin >> withdraw;

						totalOutcomes += withdraw;
						vector_balance[aux] -= withdraw;

						std::string holder = "\n" + vector_titularName[aux] + " withdraw: " + std::to_string(withdraw);
						vector_history.push_back(holder);

						std::cout << "Loading"; std::cout << "."; Sleep(500); std::cout << "."; Sleep(500); std::cout << "."; Sleep(500); std::cout << "\n";

						if (vector_balance[aux] < 0)
						{
							std::cout << "You have insuficient founds" << std::endl;
							vector_balance[aux] += withdraw;
							std::cout << "\n\nDo you want to withdraw again?\n";
							std::cout << "0) Yes, 1) No" << "\n";
							std::cin >> stop;
						}
						else
						{
							std::cout << "Your withdraw has been completed\n\n";

							std::cout << "----------------------------------------" << "\n";
							std::cout << "||       Withdraw Information         ||" << "\n";
							std::cout << "||                                    ||" << "\n";
							std::cout << "|| Account owner name: " << vector_titularName[aux] << "\n";
							std::cout << "|| Balance: " << vector_balance[aux] << "\n";
							std::cout << "|| Account ID : " << vector_id[aux] << "\n\n";

							std::cout << "Do you want to withdraw again?\n";
							std::cout << "0) Yes, 1) No" << "\n";
							std::cin >> stop;
						}
						flag = false;
					}
				}
				else
				{
					std::cout << "The account you are looking for does not exist \n";
					std::cout << "Do you want to try again?\n";
					std::cout << "0) Yes, 1) No" << "\n";
					std::cin >> stop;
					counter--;
				}

				if (aux >= vector_id.size())
				{
					std::cout << "There are no more accounts to show\n";
				}

			} while (stop == false); Sleep(1440);
			system("CLS");
		}
	}
	//Show Money of Each Account
	void showBalance()
	{
		bool stop = false, flag = false;
		int counter = 0;
		int aux = 0;
		long long buscar = 0;
		std::string password_buscar;

		if (vector_balance.size() == 0) //Protection from Bug
		{
			std::cout << "\nYou must create an Account First\n\n"; Sleep(1500);
			system("CLS");
		}
		else
		{
			do
			{
				std::cout << "Introduce the Account ID to see: "; std::cin >> buscar;
				counter++;

				auto it = std::find(vector_id.begin(), vector_id.end(), buscar);


				if (aux <= counter)
				{
					system("CLS");

					aux = it - vector_id.begin();

					std::cout << "Introduce the password: "; std::cin >> password_buscar;
					if (password_buscar == vector_passWord[aux])
					{
						flag = true;
					}
					else
					{
						std::cout << "The password is incorrect\n";
						std::cout << "Would  you like try again?\n";
						std::cout << "0) Yes, 1) No" << "\n";
						std::cin >> stop;
					}
					do
					{
						std::cout << "---------------------------------------" << "\n";
						std::cout << "||       Account Information         ||" << "\n";
						std::cout << "||                                   ||" << "\n";
						std::cout << "|| Account owner name: " << vector_titularName[aux] << "\n";
						std::cout << "|| Balance: " << vector_balance[aux] << "\n";

						std::cout << "Do you want to see other Account?\n";
						std::cout << "0) Yes, 1) No" << "\n";
						std::cin >> stop;
						flag = false;
					} while (flag == true);
				}
				else
				{
					std::cout << "The account you are looking for does not exist \n";
					std::cout << "Do you want to try again?\n";
					std::cout << "0) Yes, 1) No" << "\n";
					std::cin >> stop;
					counter--;
				}
			} while (stop == false); Sleep(1440);
			system("CLS");
		}
	}

	void transactionsAccounts()
	{
		bool stop = false, flag = false, flag2 = false;
		int counter = 0, counter2 = 0, aux = 0, aux2 = 0, transfer = 0;
		long long buscar = 0, buscar2 = 0;
		std::string password_buscar;

		if (vector_balance.size() == 0) //Protection from Bug
		{
			std::cout << "\nYou must create an Account First\n\n"; Sleep(1500);
		}
		else
		{
			do
			{
				std::cout << "Introduce your ID Account: "; std::cin >> buscar;
				counter++;

				auto it = std::find(vector_id.begin(), vector_id.end(), buscar);

				if (aux <= counter)
				{
					aux = it - vector_id.begin();

					std::cout << "Introduce the password: "; std::cin >> password_buscar;
					if (password_buscar == vector_passWord[aux])
					{
						flag = true;
					}
					else
					{
						std::cout << "The password is incorrect\n";
						std::cout << "Would  you like try again?\n";
						std::cout << "0) Yes, 1) No" << "\n";
						std::cin >> stop;
					}
					do
					{
						system("CLS");
						std::cout << "---------------------------------------" << "\n";
						std::cout << "||       Account Information         ||" << "\n";
						std::cout << "||                                   ||" << "\n";
						std::cout << "|| Account owner name: " << vector_titularName[aux] << "\n";
						std::cout << "|| Balance: " << vector_balance[aux] << "\n\n";

						std::cout << "Introduce the ID Account to Transfer: "; std::cin >> buscar2;
						counter2++;

						auto it = std::find(vector_id.begin(), vector_id.end(), buscar2);

						if (aux2 <= counter2)
						{
							aux2 = it - vector_id.begin();
							flag2 = true;
							do
							{
								system("CLS");
								std::cout << "\n---------------------------------------" << "\n";
								std::cout << "||       Account Information         ||" << "\n";
								std::cout << "||                                   ||" << "\n";
								std::cout << "|| Account owner name: " << vector_titularName[aux2] << "\n";

								std::cout << "Introduce the amount of money to transfer: "; std::cin >> transfer;
								vector_balance[aux] -= transfer;
								vector_balance[aux2] += transfer;
								std::cout << "Loading"; std::cout << "."; Sleep(500); std::cout << "."; Sleep(500); std::cout << "."; Sleep(500); std::cout << "\n";
								std::cout << "\nYour transfer has been completed\n\n";

								std::cout << "---------------------------------------" << "\n";
								std::cout << "||       Transfer Information         ||" << "\n";
								std::cout << "||                                   ||" << "\n";
								std::cout << "|| Account owner name: " << vector_titularName[aux] << "\n";
								std::cout << "|| Balance: " << vector_balance[aux] << "\n";
								std::cout << "|| Account ID : " << vector_id[aux] << "\n\n";

								std::cout << "Do you want to see other Account?\n";
								std::cout << "0) Yes, 1) No" << "\n";
								std::cin >> stop;
								flag2 = false;
							} while (flag2 == true);
						}
						else
						{
							std::cout << "The account you are looking for does not exist \n";
							std::cout << "Do you want to try again?\n";
							std::cout << "0) Yes, 1) No" << "\n";
							std::cin >> stop;
							counter2--;
						}
						flag = false;
					} while (flag == true);
				}
				else
				{
					std::cout << "The account you are looking for does not exist \n";
					std::cout << "Do you want to try again?\n";
					std::cout << "0) Yes, 1) No" << "\n";
					std::cin >> stop;
					counter--;
				}
			} while (stop == false); Sleep(1440);
		}
		system("CLS");
	}

	void transHistory()
	{
		system("CLS");

		for (int i = 0; i < vector_history.size(); i++)
		{
			std::cout << vector_history[i];
		}
		std::cout << std::endl;
				
		Sleep(1440);
		
		system("CLS");
	}

	void adminAcess()
	{
		system("CLS");

		int pin = 1234, aux = 0;
		std::string options;

		std::cout << "Introduce the Pin: "; std::cin >> aux; 

		if (aux == pin) //The pin is 1234
		{
			system("CLS");

			std::cout << "------------------------------------------" << "\n";
			std::cout << "||         Welcome to Admin Acess       ||" << "\n";
			std::cout << "||                                      ||" << "\n";
			std::cout << "||          Select an Option:           ||" << "\n";
			std::cout << "||                                      ||" << "\n";
			std::cout << "||       0) Show Total of Income        ||" << "\n";
			std::cout << "||       1) Show Total of Outcomes      ||" << "\n";
			std::cout << "||                                      ||" << "\n";
			std::cout << "------------------------------------------" << "\n\n";
			std::cin >> options;

			int options_num = ((int)options[0]) - 48; //This let read any letter and makes it a Number

			switch (options_num)
			{
			case 0:
				
				std::cout << "Total Incomes: " << totalIncomes << "\n";
				Sleep(2110);
				break;

			case 1:
				std::cout << "Total Outcomes: " << totalOutcomes << "\n";
				Sleep(2110);
				break;

			default:
				std::cin.ignore();
				std::cout << "\nYour Selected option is not valid :c\n\n" << "Please Try Again" << std::endl;
				Sleep(2000); system("CLS");
			}
		}
		else
		{
			system("CLS");
			std::cout << "THe Pin you digited is incorrect\n";
			std::cout << "Try another time :)\n"; Sleep(1440);
		}
	}

	//Getters & setters
	std::string getownerName()
	{
		return ownerName;
	}
	void settitularName(std::string ownerName)
	{
		ownerName = ownerName;
	}
	std::string getRFC()
	{
		return RFC;
	}
	void setRFC(std::string rfc)
	{
		RFC = rfc;
	}
	int getbalance()
	{
		return balance;
	}
	void setBalance(int bal)
	{
		balance = bal;
	}
	int getID()
	{
		return id;
	}
	void setID(int ID)
	{
		id = ID;
	}
	std::string getDeposit()
	{
		return deposit;
	}
	void setDeposit(std::string Deposit)
	{
		deposit = Deposit;
	}
};

class Start :public Clients
{
protected:
	std::string options;

public:
	Start()
	{
		options = "";
	}

	Start(int Options)
	{
		options = Options;
	}

	void Menu() //Main Menu on Console
	{
		system("CLS");
		std::cout << "------------------------------------------" << "\n";
		std::cout << "||         Welcome to Patito Bank       ||" << "\n";
		std::cout << "||                                      ||" << "\n";
		std::cout << "||          Select an Option:           ||" << "\n";
		std::cout << "||                                      ||" << "\n";
		std::cout << "||       0) Create an Account           ||" << "\n";
		std::cout << "||       1) Make a Deposit              ||" << "\n";
		std::cout << "||       2) Withdraw Money              ||" << "\n";
		std::cout << "||       3) Show Balance                ||" << "\n";
		std::cout << "||       4) Transfer to other Account   ||" << "\n";
		std::cout << "||       5) Transacctions history       ||" << "\n";
		std::cout << "||       6) Show an Account             ||" << "\n";
		std::cout << "||       7) Admin Access                ||" << "\n";
		std::cout << "||                                      ||" << "\n";
		std::cout << "------------------------------------------" << "\n\n";

		std::cin >> options;

		int options_num = ((int)options[0]) - 48; //This let read any letter and makes it a Number

		switch (options_num)
		{
		case 0:
			createAccount();
			Menu();
			break;

		case 1:
			depositMoney();
			Menu();
			break;

		case 2:
			retireMoney();
			Menu();
			break;

		case 3:
			showBalance();
			Menu();
			break;

		case 4:
			transactionsAccounts();
			Menu();
			break;

		case 5:
			transHistory();
			Menu();
			break;

		case 6:
			showClient();
			Menu();
			break;
		case 7:
			adminAcess();
			Menu();
			break;

		default:
			std::cin.ignore();
			std::cout << "\nYour Selected option is not valid :c\n\n" << "Please Try Again" << std::endl;
			Sleep(2110);
			Menu();
		}
	}
};

int main()
{
	system("CLS");

	Start menu;

	menu.Menu();

	std::cout << "\n\n";
	return 0;
}