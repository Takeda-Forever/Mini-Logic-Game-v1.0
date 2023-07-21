#pragma	once
#include "lib.h"
#define cls system("cls") //������� �������
#define milis(x) sleep_for(milliseconds(x)) //�������� � ������������
#define second(x) sleep_for(seconds(x)) //�������� � ��������
#define cin_fail cin.clear(); cin.ignore(numeric_limits<std::streamsize>::max(), '\n') //������� �����
#define jump cout << endl //������� ������
#define next cout << "������� ������ ���-�� ����������:"

enum choice { start, error, option, edit };
class game {
public:
	game(uint16_t _num = 25) :num(_num){}
	void menu();
	void game_start();
	void game_option();
	void test();
	void game_error();
	void option_edit();
private:
	uint16_t num;
	bool turn = true;
	choice select;
	int winner(bool&);
	int correct_choice(uint16_t&);
	string menu_list = "1.������ ����\n2.���������\n3.�����\n";
};

