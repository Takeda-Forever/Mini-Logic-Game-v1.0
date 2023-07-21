#include "data.h"

int game::winner(bool& _winner)
{
	if (!_winner)
		return 1;
	else
		return 0;
}

void game::game_start()
{
	cls;
	uint16_t _num;
	do
	{
		cout << "Количество палочек " << num << "\n";
		if (turn)
			cout << "Ход игрока 1\n";
		else
			cout << "Ход игрока 2\n";
		cout << "Введите число от 1 до 4:";
		correct_choice(_num);
		if (_num < 5 && _num > 0 && (num - _num) >= 0)
		{
			num -= _num;
			turn = !turn;
		}
		else
			cout << "Введите заново\n";
		milis(300);
		cls;
	} while (num > 0);
	cls;
	cout << "Победил игрок " << winner(turn);
	jump;
	second(2);
}
void game::game_option() //Меню изминений настройки игры
{
	cls;
	uint16_t sel;
	cout << "1.Изменить количество палочек\n"
		<< "2.В меню\n"
		<< "Ввод:";
	correct_choice(sel); //Правильный ввод
	if (sel == 1)
		select = edit; //Изменит настройки игры
	else if (sel == 2)
		menu();
	test();
}
void game::menu() //Меню игры
{
	cls;
	uint16_t sel;
	cout << menu_list; //Вывести возможные выборы
	cout << "Ввод:";
	correct_choice(sel);
	switch (sel)
	{
	case 1:
		select = start; //Начать игру
		break;
	case 2:
		select = option; //Переход в настройки
		break;
	case 3: //Выход
		exit('\n');
		break;
	default:
		select = error; //Итог ошибка
		break;
	}
	cls;
	test();
}

void game::option_edit() //Изменить настройки игры
{
	cls;
	uint16_t m_num; //Переменное для изминение кол. спичек
	cout << "Нынешный количество палок: " << num;
	cout << "\nВведите количество палок: ";
	correct_choice(m_num);
	if (m_num > num && m_num > 10 && m_num < 40) //Увиличение
	{
		num = m_num;
		cout << "Количество палок поднялся до " << num << endl;
	}
	else if (m_num < num && m_num > 10) //Уменшьшение
	{
		num = m_num;
		cout << "Количество палок упала до " << num << endl;
	}
	else
		cout << "Колочиество палок не может быть ниже 10 и выше 40.\n"; //Если входное кол. спичек ниже 10 или выше 40
	milis(600);
}
void game::game_error() //Если пройзошло ошибка
{
	cout << "Вы ошиблись с выбором! И были возвращены в меню!\n";
	milis(600);
	menu();
}

int game::correct_choice(uint16_t & n) //Корректный ввод числа
{
	while (true) {
		cin >> n;
		// Проверяем состояние cin и тип данных, введенных пользователем
		if (cin.fail()) {
			cout << "Неверный выбор. Попробуйте еще раз:";
			// Сбрасываем флаг ошибки и очищаем буфер ввода
			cin_fail;
		}
		else {
			// Проверяем, что после ввода целого числа нет других символов
			char c;
			if (cin.get(c) && c == '\n') {
				break; // Ввод корректен, выходим из цикла
			}
			else {
				cout << "Неверный выбор. Попробуйте еще раз:";
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			}
		}
	}
	return n;
}

void game::test() //Выполнения итога проверки
{
	if (select == start)
		game_start();
	else if (select == option)
		game_option();
	else if (select == error)
		game_error();
	else if (select == edit)
		option_edit();
}