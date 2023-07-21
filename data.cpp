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
		cout << "���������� ������� " << num << "\n";
		if (turn)
			cout << "��� ������ 1\n";
		else
			cout << "��� ������ 2\n";
		cout << "������� ����� �� 1 �� 4:";
		correct_choice(_num);
		if (_num < 5 && _num > 0 && (num - _num) >= 0)
		{
			num -= _num;
			turn = !turn;
		}
		else
			cout << "������� ������\n";
		milis(300);
		cls;
	} while (num > 0);
	cls;
	cout << "������� ����� " << winner(turn);
	jump;
	second(2);
}
void game::game_option() //���� ��������� ��������� ����
{
	cls;
	uint16_t sel;
	cout << "1.�������� ���������� �������\n"
		<< "2.� ����\n"
		<< "����:";
	correct_choice(sel); //���������� ����
	if (sel == 1)
		select = edit; //������� ��������� ����
	else if (sel == 2)
		menu();
	test();
}
void game::menu() //���� ����
{
	cls;
	uint16_t sel;
	cout << menu_list; //������� ��������� ������
	cout << "����:";
	correct_choice(sel);
	switch (sel)
	{
	case 1:
		select = start; //������ ����
		break;
	case 2:
		select = option; //������� � ���������
		break;
	case 3: //�����
		exit('\n');
		break;
	default:
		select = error; //���� ������
		break;
	}
	cls;
	test();
}

void game::option_edit() //�������� ��������� ����
{
	cls;
	uint16_t m_num; //���������� ��� ��������� ���. ������
	cout << "�������� ���������� �����: " << num;
	cout << "\n������� ���������� �����: ";
	correct_choice(m_num);
	if (m_num > num && m_num > 10 && m_num < 40) //����������
	{
		num = m_num;
		cout << "���������� ����� �������� �� " << num << endl;
	}
	else if (m_num < num && m_num > 10) //�����������
	{
		num = m_num;
		cout << "���������� ����� ����� �� " << num << endl;
	}
	else
		cout << "����������� ����� �� ����� ���� ���� 10 � ���� 40.\n"; //���� ������� ���. ������ ���� 10 ��� ���� 40
	milis(600);
}
void game::game_error() //���� ��������� ������
{
	cout << "�� �������� � �������! � ���� ���������� � ����!\n";
	milis(600);
	menu();
}

int game::correct_choice(uint16_t & n) //���������� ���� �����
{
	while (true) {
		cin >> n;
		// ��������� ��������� cin � ��� ������, ��������� �������������
		if (cin.fail()) {
			cout << "�������� �����. ���������� ��� ���:";
			// ���������� ���� ������ � ������� ����� �����
			cin_fail;
		}
		else {
			// ���������, ��� ����� ����� ������ ����� ��� ������ ��������
			char c;
			if (cin.get(c) && c == '\n') {
				break; // ���� ���������, ������� �� �����
			}
			else {
				cout << "�������� �����. ���������� ��� ���:";
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			}
		}
	}
	return n;
}

void game::test() //���������� ����� ��������
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