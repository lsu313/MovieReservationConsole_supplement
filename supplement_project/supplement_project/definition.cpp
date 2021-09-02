#include "definition.h"

void Movie::Movie_choice()
{
	cout << "======================" << endl;
	cout << "���� ������ ��ȭ��" << endl;
	cout << "!.�θ��� ����" << endl;
	cout << "2.Ƽ�ĴϿ��� ��ħ��" << endl;
	cout << "3.ī����ī" << endl;
	cout << "4.�ٶ��� �Բ� �������" << endl;
	cout << "======================" << endl;
	cout << "�����Ͻ� ��ȭ�� ��ȣ�� �Է����ּ���: ";
	cin >> movie_choice;
	while (1) {
		if (movie_choice < 1 && movie_choice > 4)
		{
			cout << "�߸� �Էµ� ���Դϴ�." << endl;
			cout << "�����Ͻ� ��ȭ�� ��ȣ�� �Է����ּ���: ";
		}
		else break;
		cin >> movie_choice;
	}
	cout << endl;
	cout << "�ش� ��ȭ�� �󿵰��� ";
	switch (movie_choice)
	{

	case 1:
		cout << "1��, 2�� �Դϴ�." << endl << endl;
		cout << "1�� �󿵽ð�" << endl;
		for (int i = 0; i < 3; i++)
			cout << time[0][i] << endl;
		cout << "2�� �󿵽ð�" << endl;
		for (int i = 0; i < 3; i++)
			cout << time[1][i] << endl;
		break;
	case 2:
		cout << "3��, 4�� �Դϴ�." << endl << endl;
		cout << "3�� �󿵽ð�" << endl;
		for (int i = 0; i < 3; i++)
			cout << time[2][i] << endl;
		cout << "4�� �󿵽ð�" << endl;
		for (int i = 0; i < 3; i++)
			cout << time[3][i] << endl;

		break;
	case 3:
		cout << "5��, 6�� �Դϴ�." << endl << endl;
		cout << "5�� �󿵽ð�" << endl;
		for (int i = 0; i < 3; i++)
			cout << time[4][i] << endl;
		cout << "6�� �󿵽ð�" << endl;
		for (int i = 0; i < 3; i++)
			cout << time[5][i] << endl;
		break;
	case 4:
		cout << "7��, 8�� �Դϴ�." << endl << endl;
		cout << "7�� �󿵽ð�" << endl;
		for (int i = 0; i < 3; i++)
			cout << time[6][i] << endl;
		cout << "8�� �󿵽ð�" << endl;
		for (int i = 0; i < 3; i++)
			cout << time[7][i] << endl;
		break;

	}
	cout << "���Ͻô� �󿵰��� ���ڸ� �Է��� �ּ��� : "; cin >> theater;
	cout << endl;
	cout << "���Ͻô� �󿵽ð��� ��ȣ�� �Է��� �ּ���: "; cin >> time_idx;    //m1.theater, m1,time_dix���� ���� �󿵽ð� ���
	//��½� idx - 1 ���� �־����
}

void Movie::Delete() //���� �ʱ�ȭ �Լ�
{
	movie_choice = 0;
	theater = -1;
	time_idx = -1;

}

void Seat_info::Update_seatInfo(string name, int gender, string phone_num, int seat_row, int seat_col)
{
	this->name = name;
	this->gender = gender;
	this->phone_num = phone_num;
	this->seat_row = seat_row;
	this->seat_col = seat_col;
}

void Seat_info::Delete_seatInfo(string name, int gender, string phone_num, int seat_row, int seat_col)  //������� ��
{
	this->name = "";
	this->gender = 0;
	this->phone_num = "";
	this->seat_row = 0;
	this->seat_col = 0;
}

bool Seat_info::Compare(string name, string phone_num)
{
	if (this->name == name && this->phone_num == phone_num)
		return true;
	else
		return false;
}

Seat::Seat()
{

	char temp1 = '1'; //�ƽ�Ű�ڵ� 49: 1 ���� �ֱ�����
	char temp2 = 'A';
	seat_ui[0][0] = 'x';
	for (int i = 1; i < 6; i++) {
		seat_ui[0][i] = temp1;
		seat_ui[i][0] = temp2;
		temp1++; temp2++;

		for (int j = 1; j < 6; j++)
			seat_ui[i][j] = 'o';
	}
}

void Seat::Reset()
{
	temp_x = 0;
	temp_y = 0;
	input_seat[0] = 0;
	input_seat[1] = 0;

	char temp1 = '1'; //�ƽ�Ű�ڵ� 49: 1 ���� �ֱ�����
	char temp2 = 'A';
	seat_ui[0][0] = 'x';
	for (int i = 1; i < 6; i++) {
		seat_ui[0][i] = temp1;
		seat_ui[i][0] = temp2;
		temp1++; temp2++;

		for (int j = 1; j < 6; j++) {
			seat_ui[i][j] = 'o';
			cnt_seat[i][j] = 0;
			cnt_gender_seat[0][i][j] = 0;
			cnt_gender_seat[1][i][j] = 0;
		}

	}
}

void Seat::Seat_cancle(string name, int gender, string phone_num)
{
	Seat_output();
	for (int i = 1; i < 6; i++)
	{
		bool check = false;
		for (int j = 1; j < 6; j++)
		{
			if (info[i][j].Compare(name, phone_num)) {
				temp_x = info[i][j].seat_row;
				temp_y = info[i][j].seat_col;
				check = true;
				break;
			}
		}
		if (check)
			break;
	}
	cout << "�����Ͻ� �¼��� " << seat_ui[temp_x][0] << "��" << seat_ui[0][temp_y] << "�� �ڸ� �Դϴ�." << endl;
	cout << "�ش� �¼��� ���Ű� ��� �Ǿ����ϴ�." << endl;
	cnt_seat[temp_x][temp_y] -= 1;
	if (gender == 1) // ����
		cnt_gender_seat[0][temp_x][temp_y] -= 1;
	else//����
		cnt_gender_seat[1][temp_x][temp_y] -= 1;
	info[temp_x][temp_y].Delete_seatInfo(name, gender, phone_num, temp_x, temp_y);
	Seat_check_for_cancle();
	cout << endl;
	Seat_output();
}

void Seat::Seat_output()
{
	cout << endl;
	cout << "�¼� ��Ȳ" << endl;
	cout << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
			cout << seat_ui[i][j] << " ";
		cout << endl;
	}
	cout << endl;

}

void Seat::Seat_check()
{

	if (temp_x == 1)
	{
		if (temp_y == 1)
		{
			seat_ui[temp_x][temp_y] = 'x';
			seat_ui[temp_x + 1][temp_y] = 'x';
			seat_ui[temp_x][temp_y + 1] = 'x';
		}
		else if (temp_y == 5)
		{
			seat_ui[temp_x][temp_y] = 'x';
			seat_ui[temp_x + 1][temp_y] = 'x';
			seat_ui[temp_x][temp_y - 1] = 'x';
		}
		else
		{
			seat_ui[temp_x][temp_y] = 'x';
			seat_ui[temp_x + 1][temp_y] = 'x';
			seat_ui[temp_x][temp_y - 1] = 'x';
			seat_ui[temp_x][temp_y + 1] = 'x';
		}
	}
	else if (temp_x == 5)
	{
		if (temp_y == 1)
		{
			seat_ui[temp_x][temp_y] = 'x';
			seat_ui[temp_x - 1][temp_y] = 'x';
			seat_ui[temp_x][temp_y + 1] = 'x';
		}
		else if (temp_y == 5)
		{
			seat_ui[temp_x][temp_y] = 'x';
			seat_ui[temp_x - 1][temp_y] = 'x';
			seat_ui[temp_x][temp_y - 1] = 'x';
		}
		else
		{
			seat_ui[temp_x][temp_y] = 'x';
			seat_ui[temp_x - 1][temp_y] = 'x';
			seat_ui[temp_x][temp_y + 1] = 'x';
			seat_ui[temp_x][temp_y - 1] = 'x';
		}
	}
	else if (temp_y == 1)
	{
		seat_ui[temp_x][temp_y] = 'x';
		seat_ui[temp_x - 1][temp_y] = 'x';
		seat_ui[temp_x][temp_y + 1] = 'x';
		seat_ui[temp_x + 1][temp_y] = 'x';
	}
	else if (temp_y == 5)
	{
		seat_ui[temp_x][temp_y] = 'x';
		seat_ui[temp_x - 1][temp_y] = 'x';
		seat_ui[temp_x][temp_y - 1] = 'x';
		seat_ui[temp_x + 1][temp_y] = 'x';
	}
	else
	{
		seat_ui[temp_x][temp_y] = 'x';
		seat_ui[temp_x - 1][temp_y] = 'x';
		seat_ui[temp_x][temp_y - 1] = 'x';
		seat_ui[temp_x + 1][temp_y] = 'x';
		seat_ui[temp_x][temp_y + 1] = 'x';
	}

}

void Seat::Seat_check_for_cancle()
{

	if (temp_x == 1)
	{
		if (temp_y == 1)
		{
			seat_ui[temp_x][temp_y] = 'o';
			seat_ui[temp_x + 1][temp_y] = 'o';
			seat_ui[temp_x][temp_y + 1] = 'o';
		}
		else if (temp_y == 5)
		{
			seat_ui[temp_x][temp_y] = 'o';
			seat_ui[temp_x + 1][temp_y] = 'o';
			seat_ui[temp_x][temp_y - 1] = 'o';
		}
		else
		{
			seat_ui[temp_x][temp_y] = 'o';
			seat_ui[temp_x + 1][temp_y] = 'o';
			seat_ui[temp_x][temp_y - 1] = 'o';
			seat_ui[temp_x][temp_y + 1] = 'o';
		}

	}
	else if (temp_x == 5)
	{
		if (temp_y == 1)
		{
			seat_ui[temp_x][temp_y] = 'o';
			seat_ui[temp_x - 1][temp_y] = 'o';
			seat_ui[temp_x][temp_y + 1] = 'o';
		}
		else if (temp_y == 5)
		{
			seat_ui[temp_x][temp_y] = 'o';
			seat_ui[temp_x - 1][temp_y] = 'o';
			seat_ui[temp_x][temp_y - 1] = 'o';
		}
		else
		{
			seat_ui[temp_x][temp_y] = 'o';
			seat_ui[temp_x - 1][temp_y] = 'o';
			seat_ui[temp_x][temp_y + 1] = 'o';
			seat_ui[temp_x][temp_y - 1] = 'o';
		}
	}
	else if (temp_y == 1)
	{
		seat_ui[temp_x][temp_y] = 'o';
		seat_ui[temp_x - 1][temp_y] = 'o';
		seat_ui[temp_x][temp_y + 1] = 'o';
		seat_ui[temp_x + 1][temp_y] = 'o';
	}
	else if (temp_y == 5)
	{
		seat_ui[temp_x][temp_y] = 'o';
		seat_ui[temp_x - 1][temp_y] = 'o';
		seat_ui[temp_x][temp_y - 1] = 'o';
		seat_ui[temp_x + 1][temp_y] = 'o';
	}
	else
	{
		seat_ui[temp_x][temp_y] = 'o';
		seat_ui[temp_x - 1][temp_y] = 'o';
		seat_ui[temp_x][temp_y - 1] = 'o';
		seat_ui[temp_x + 1][temp_y] = 'o';
		seat_ui[temp_x][temp_y + 1] = 'o';
	}

}

void Seat::Seat_input_hard(char x, char y, int gender, string name, string phone_num)
{
	input_seat[0] = x;
	input_seat[1] = y;
	for (int i = 1; i < 6; i++)
	{
		if (seat_ui[i][0] == input_seat[0])
			temp_x = i;
		if (seat_ui[0][i] == input_seat[1])
			temp_y = i;
	}
	info[temp_x][temp_y].Update_seatInfo(name, gender, phone_num, temp_x, temp_y);
	cnt_seat[temp_x][temp_y] += 1;
	if (gender == 1) // ����
		cnt_gender_seat[0][temp_x][temp_y] += 1;
	else//����
		cnt_gender_seat[1][temp_x][temp_y] += 1;
	Seat_check();
}

void Seat::Seat_input(string name, int gender, string phone_num)
{
	while (1) {
		cout << "���Ͻô� �¼� ��ȣ�� �Է����ּ���. EX)A�� 3�� �ڸ� -> a3 or A3" << endl;
		cin >> input_seat[0] >> input_seat[1];
		if (input_seat[0] >= 97 && input_seat[0] <= 122)
			input_seat[0] -= 32;
		for (int i = 1; i < 6; i++)
		{
			if (seat_ui[i][0] == input_seat[0])
				temp_x = i;
			if (seat_ui[0][i] == input_seat[1])
				temp_y = i;
		}
		cout << "�����Ͻ� �¼��� " << seat_ui[temp_x][0] << "��" << seat_ui[0][temp_y] << "�� �ڸ� �Դϴ�." << endl;
		info[temp_x][temp_y].Update_seatInfo(name, gender, phone_num, temp_x, temp_y);
		cnt_seat[temp_x][temp_y] += 1;
		if (gender == 1) // ����
			cnt_gender_seat[0][temp_x][temp_y] += 1;
		else//����
			cnt_gender_seat[1][temp_x][temp_y] += 1;

		if (seat_ui[temp_x][temp_y] == 'x')
		{
			cout << "�ش� �¼��� �Ұ��մϴ�." << endl;
			Seat_output();
			continue;
		}
		Seat_check();
		break;
	}

}

Point::Point()
{
	charge_money = 20000;
	charge_point = 0;
}

void Point::Payment(int price)
{
	charge_money = charge_money - price;
	cout << "�ܿ����� " << charge_money << "�� �Դϴ�." << endl;
	cout << endl;
}

void Point::Save(string name)
{
	charge_point += 100;
	cout << name << "���� ����Ʈ�� " << charge_point << "P �Դϴ�. " << endl;
}

void Point::Cancle_payment(int price)
{
	charge_money += price;
	cout << "�ܿ����� " << charge_money << "�� �Դϴ�." << endl;
}

void Point::Cacle_save(string name)
{
	charge_point -= 100;
	cout << name << "���� ����Ʈ�� " << charge_point << "P �Դϴ�. " << endl;
}

bool Person::Check_info(string name, string phone_num) // ������� �� ����Ȯ�� ���� �Լ�
{
	if ((this->name) == name && (this->phone_num) == phone_num)
		return true;
	else
		return false;
}

void Person::Set_hard(string name, int gender, string phone_num, int movie_choice, int theater, int time_idx)
{
	this->name = name;
	this->gender = gender;
	this->phone_num = phone_num;
	m1.movie_choice = movie_choice;
	m1.theater = theater;
	m1.time_idx = time_idx;
}

void Person::personal_information()
{
	cout << "�Ʒ� ������ �Է����ּ���." << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "������ �Է����ּ��� : ";
	cin >> name;
	cout << endl;
	cout << "����(��ȣ)�� �������ּ��� : 1.���� 2.���� " << endl;
	cin >> gender;
	cout << endl;
	while (1) {
		if (gender < 1 && gender > 2)
		{
			cout << "�߸� �Էµ� ���Դϴ�." << endl;
			cout << "������ �������ּ��� : 1.���� 2.���� ";
		}
		else break;
		cin >> gender;
	}
	cout << "�޴���ȭ ��ȣ�� �Է��� �ּ��� .(����x)" << endl;
	cin >> phone_num;
	cout << endl;
}

void Person::Reservation()
{
	personal_information();
	m1.Movie_choice();
	seat[m1.theater - 1][m1.time_idx - 1].Seat_output();
	seat[m1.theater - 1][m1.time_idx - 1].Seat_input(name, gender, phone_num);
	seat[m1.theater - 1][m1.time_idx - 1].Seat_output();
	PayandSave();
	a = seat[m1.theater - 1][m1.time_idx - 1].input_seat[0];
	b = seat[m1.theater - 1][m1.time_idx - 1].input_seat[1];               
}

void Person::Reservation_hard(char x, char y)
{
	seat[m1.theater - 1][m1.time_idx - 1].Seat_input_hard(x, y, gender, name, phone_num);
}

void Person::PayandSave()
{
	string temp_phone;
	cout << "��ȭ ������ " << m1.price << "�� �Դϴ�." << endl;
	pnt.Payment(m1.price);
	while (1) {
		cout << "����Ʈ ������ ���� �޴���ȭ ��ȣ�� �Է����ּ��� (����x)" << endl;
		cin >> temp_phone;
		if (phone_num != temp_phone)
		{
			cout << name << "���� ��ϵ� ��ȣ�� ��ġ���� �ʽ��ϴ�" << endl;
			continue;
		}
		break;
	}
	pnt.Save(name);
}

void Person::Reservation_cancel()
{
	cout << "��ȭ ���Ÿ� ����Ͻðڽ��ϱ�?" << endl;
	cout << "1. Yes 2. No " << endl;
	int n;
	cin >> n;
	cout << endl;
	if (n == 2)
		return;
	Refund();
	seat[m1.theater - 1][m1.time_idx - 1].Seat_cancle(name, gender, phone_num);
	gender = 0;
	name = "";
	phone_num = "";
	m1.Delete();
}

void Person::Refund()
{
	string temp_phone;
	cout << m1.price << "�� ȯ�ҵ˴ϴ�." << endl;
	pnt.Cancle_payment(m1.price);
	cout << endl;
	while (1) {
		cout << "����Ʈ ������ ���� �޴���ȭ ��ȣ�� �Է����ּ���.(����x)" << endl;
		cin >> temp_phone;
		if (phone_num != temp_phone)
		{
			cout << name << "���� ��ϵ� ��ȣ�� ��ġ���� �ʽ��ϴ�" << endl;
			continue;
		}
		break;
	}
	pnt.Cacle_save(name);
	cout << endl;

}

Cnt::~Cnt() { delete m; delete s1; }

void Cnt::Sum_seats()
{
	//Set_movie, Set_most ���� Sum_seat_most
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int z = 1; z < 6; z++)
			{
				for (int w = 1; w < 6; w++) {
					s2[i][j].cnt_seat[z][w] += Person::seat[i][j].cnt_seat[z][w];
					s2[i][j].cnt_gender_seat[0][z][w] += Person::seat[i][j].cnt_gender_seat[0][z][w];
					s2[i][j].cnt_gender_seat[1][z][w] += Person::seat[i][j].cnt_gender_seat[1][z][w];
				}
			}
		}
	}
}

void Cnt::ChartoInt()
{

	cout << "���Ͻô� �¼� ��ȣ�� �Է����ּ���. EX)A�� 3�� �ڸ� -> a3 or A3" << endl;

	cin >> x >> y;
	if (x >= 97 && y <= 122)
		x -= 32;
	for (int i = 1; i < 6; i++)
	{
		if (s1->seat_ui[i][0] == x)
			row = i;
		if (s1->seat_ui[0][i] == y)
			col = i;
	}
}
void Cnt::Cnt_ratio()
{
	if ((s2[theater - 1][time_idx - 1].cnt_gender_seat[0][row][col] + s2[theater - 1][time_idx - 1].cnt_gender_seat[1][row][col]) == 0)
		return;
	man_ratio = 100 * s2[theater - 1][time_idx - 1].cnt_gender_seat[0][row][col] / (s2[theater - 1][time_idx - 1].cnt_gender_seat[0][row][col] + s2[theater - 1][time_idx - 1].cnt_gender_seat[1][row][col]);
	woman_ratio = 100 * s2[theater - 1][time_idx - 1].cnt_gender_seat[1][row][col] / (s2[theater - 1][time_idx - 1].cnt_gender_seat[1][row][col] + s2[theater - 1][time_idx - 1].cnt_gender_seat[0][row][col]);
}
void Cnt::Out_sum()
{
	cout << endl;
	cout << "==================" << endl;
	cout << "1. ��ȭ�� ����Ƚ��" << endl;
	cout << "2. ���� ���� ����" << endl;
	cout << "3. �󿵴뺰 ���� Ƚ��" << endl;
	cout << "==================" << endl;
	cout << endl;
	cout << "��ȣ: ";
	cin >> n;
	value[0] = value[1] = value[2] = value[3] = 0;
	switch (n)
	{
	case 1:
		ChartoInt();
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i < 2)
					value[0] += s2[i][j].cnt_seat[row][col];
				else if (i < 4)
					value[1] += s2[i][j].cnt_seat[row][col];
				else if (i < 6)
					value[2] += s2[i][j].cnt_seat[row][col];
				else
					value[3] += s2[i][j].cnt_seat[row][col];
			}
		}
		cout << endl;
		cout << x << "��" << y << "��° �ڸ��� ��ȭ�� ����Ƚ��" << endl;
		cout << "�θ��� ���� " << value[0] << "ȸ" << endl;
		cout << "Ƽ�ĴϿ��� ��ħ�� " << value[1] << "ȸ" << endl;
		cout << "ī����ī " << value[2] << "ȸ" << endl;
		cout << "�ٶ��� �Բ� �������. " << value[3] << "ȸ" << endl;
		cout << endl;
		break;
	case 2:
		cout << endl;
		cout << "���Ͻô� �󿵰��� �Է��� �ּ���(1��~8��): "; cin >> theater;
		for (int i = 0; i < 3; i++)
			cout << m->time[theater - 1][i] << endl;
		cout << "���Ͻô� �ð��븦 �Է��� �ּ���(1Ÿ��~3Ÿ��): "; cin >> time_idx;
		cout << endl;
		ChartoInt();
		cout << theater << "�� " << time_idx << "Ÿ�� " << x << "��" << y << "��° �ڸ��� ���ະ ����Ƚ��" << endl;
		cout << endl;
		Cnt_ratio();
		cout << "���� " << s2[theater - 1][time_idx - 1].cnt_gender_seat[0][row][col] << "ȸ" << " " << man_ratio << "%" << endl;
		cout << "���� " << s2[theater - 1][time_idx - 1].cnt_gender_seat[1][row][col] << "ȸ" << " " << woman_ratio << "%" << endl;
		man_ratio = woman_ratio = 0;
		cout << endl;
		break;
	case 3:
		cout << endl;
		cout << "���Ͻô� �󿵰��� �Է��� �ּ���(1��~8��): "; cin >> theater;
		cout << endl;
		ChartoInt();
		cout << endl;
		cout << theater << "�� " << x << "��" << y << "��° �ڸ��� �󿵴뺰 ����Ƚ��" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << m->time[theater - 1][i] << " Ÿ��" << s2[theater - 1][i].cnt_seat[row][col] << "ȸ" << endl;
		}

		break;
	default: cout << "Unknown number" << endl;
		cout << endl;
		break;
	}
}

void Cnt::Set_gender()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			for (int z = 1; z < 6; z++)
			{
				for (int w = 1; w < 6; w++) {
					Sum_seat_gender[0][z][w] += Person::seat[i][j].cnt_gender_seat[0][z][w];
					Sum_seat_gender[1][z][w] += Person::seat[i][j].cnt_gender_seat[1][z][w];
				}
			}
		}
	}
}

void Cnt::Cnt_gender()
{
	for (int idx = 0; idx < 2; idx++)
	{
		gt1[idx] = 0; gt2[idx] = 0; gt3[idx] = 0;
		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 6; j++)
			{
				if (gt1[idx] < Sum_seat_gender[idx][i][j])
				{
					gt1[idx] = Sum_seat_gender[idx][i][j];
					gtop1[idx][0] = i;
					gtop1[idx][1] = j;
				}
			}
		}
		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 6; j++)
			{
				if (gt2[idx] < Sum_seat_gender[idx][i][j] && Sum_seat_gender[idx][i][j] < gt1[idx])
				{
					gt2[idx] = Sum_seat_gender[idx][i][j];
					gtop2[idx][0] = i;
					gtop2[idx][1] = j;
				}
			}
		}
		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 6; j++)
			{
				if (gt3[idx] < Sum_seat_gender[idx][i][j] && Sum_seat_gender[idx][i][j] < gt2[idx])
				{
					gt3[idx] = Sum_seat_gender[idx][i][j];
					gtop3[idx][0] = i;
					gtop3[idx][1] = j;
				}
			}
		}
	}
}

void Cnt::Set_movie() {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++)
		{
			for (int z = 1; z < 6; z++) {
				for (int w = 1; w < 6; w++) {

					if (i < 2)
						Sum_seat_movie[0][z][w] += Person::seat[i][j].cnt_seat[z][w];
					if (i < 4)
						Sum_seat_movie[1][z][w] += Person::seat[i][j].cnt_seat[z][w];
					if (i < 6)
						Sum_seat_movie[2][z][w] += Person::seat[i][j].cnt_seat[z][w];
					if (i < 8)
						Sum_seat_movie[3][z][w] += Person::seat[i][j].cnt_seat[z][w];
				}
			}
		}
	}
}

void Cnt::Cnt_movie()
{

	for (int idx = 0; idx < 4; idx++)   //��ȭ�� top1,2,3�� ���ϱ� ���� ��ȭidx(Person class�� theater ����)
	{

		mt1[idx] = 0; mt2[idx] = 0; mt3[idx] = 0;
		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 6; j++)
			{
				if (mt1[idx] < Sum_seat_movie[idx][i][j])
				{
					mt1[idx] = Sum_seat_movie[idx][i][j];
					mtop1[idx][0] = i;
					mtop1[idx][1] = j;
				}
			}
		}
		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 6; j++)
			{
				if (mt2[idx] < Sum_seat_movie[idx][i][j] && Sum_seat_movie[idx][i][j] < mt1[idx])
				{
					mt2[idx] = Sum_seat_movie[idx][i][j];
					mtop2[idx][0] = i;
					mtop2[idx][1] = j;
				}
			}
		}
		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 6; j++)
			{
				if (mt3[idx] < Sum_seat_movie[idx][i][j] && Sum_seat_movie[idx][i][j] < mt2[idx])
				{
					mt3[idx] = Sum_seat_movie[idx][i][j];
					mtop3[idx][0] = i;
					mtop3[idx][1] = j;
				}
			}
		}

	}
}

void Cnt::Set_most()
{
	//�Ϸ�� ���� ���� ������ �¼��� ���ϱ� ���� ������
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++)
		{
			for (int z = 1; z < 6; z++) {
				for (int w = 1; w < 6; w++) {

					Sum_seat_most[i][z][w] += Person::seat[i][j].cnt_seat[z][w];
				}
			}
		}
	}
}

 void Cnt::Cnt_most() {
	//���� ���� ������ �¼��� ���ϴ� �Լ�
	for (int idx = 0; idx < 8; idx++) {
		t1[idx] = 0;
		t2[idx] = 0;
		t3[idx] = 0;


		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 6; j++)
			{
				if (t1[idx] < Sum_seat_most[idx][i][j])
				{
					t1[idx] = Sum_seat_most[idx][i][j];
					top1[idx][0] = i;
					top1[idx][1] = j;
				}
			}
		}
		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 6; j++)
			{
				if (t2[idx] < Sum_seat_most[idx][i][j] && Sum_seat_most[idx][i][j] < t1[idx])
				{
					t2[idx] = Sum_seat_most[idx][i][j];
					top2[idx][0] = i;
					top2[idx][1] = j;
				}
			}
		}
		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 6; j++)
			{
				if (t3[idx] < Sum_seat_most[idx][i][j] && Sum_seat_most[idx][i][j] < t2[idx])
				{
					t3[idx] = Sum_seat_most[idx][i][j];
					top3[idx][0] = i;
					top3[idx][1] = j;
				}
			}
		}
	}

}

void Cnt::Out_gender()
{
	for (int idx = 0; idx < 2; idx++)
	{
		if (idx == 0)
		{
			cout << endl;
			cout << "���ڰ��� ���� ���� ������ �¼�" << endl;
			cout << "=================================" << endl;
			cout << "���� ���� ���ŵ� �¼� Top1�� ��" << gt1[idx] << "������ " << s1->seat_ui[gtop1[idx][0]][0] << "��" << s1->seat_ui[0][gtop1[idx][1]] << "�� �ڸ� �Դϴ�." << endl;
			cout << "���� ���� ���ŵ� �¼� Top2�� ��" << gt2[idx] << "������ " << s1->seat_ui[gtop2[idx][0]][0] << "��" << s1->seat_ui[0][gtop2[idx][1]] << "�� �ڸ� �Դϴ�." << endl;
			cout << "���� ���� ���ŵ� �¼� Top3�� ��" << gt3[idx] << "������ " << s1->seat_ui[gtop3[idx][0]][0] << "��" << s1->seat_ui[0][gtop3[idx][1]] << "�� �ڸ� �Դϴ�." << endl;
			cout << "=================================" << endl;
		}
		else
		{
			cout << endl;
			cout << "���ڰ��� ���� ���� ������ �¼�" << endl;
			cout << "=================================" << endl;
			cout << "���� ���� ���ŵ� �¼� Top1�� ��" << gt1[idx] << "������ " << s1->seat_ui[gtop1[idx][0]][0] << "��" << s1->seat_ui[0][gtop1[idx][1]] << "�� �ڸ� �Դϴ�." << endl;
			cout << "���� ���� ���ŵ� �¼� Top2�� ��" << gt2[idx] << "������ " << s1->seat_ui[gtop2[idx][0]][0] << "��" << s1->seat_ui[0][gtop2[idx][1]] << "�� �ڸ� �Դϴ�." << endl;
			cout << "���� ���� ���ŵ� �¼� Top3�� ��" << gt3[idx] << "������ " << s1->seat_ui[gtop3[idx][0]][0] << "��" << s1->seat_ui[0][gtop3[idx][1]] << "�� �ڸ� �Դϴ�." << endl;
			cout << "=================================" << endl;
		}
	}
}

 void Cnt::Out_most()
{
	for (int idx = 0; idx < 8; idx++) {
		cout << endl;
		cout << "=================================" << endl;
		cout << idx + 1 << "������ " << "���� ���� ���ŵ� �¼� Top1�� ��" << t1[idx] << "������ " << s1->seat_ui[top1[idx][0]][0] << "��" << s1->seat_ui[0][top1[idx][1]] << "�� �ڸ� �Դϴ�." << endl;
		cout << idx + 1 << "������ " << "���� ���� ���ŵ� �¼� Top2�� ��" << t2[idx] << "������ " << s1->seat_ui[top2[idx][0]][0] << "��" << s1->seat_ui[0][top2[idx][1]] << "�� �ڸ� �Դϴ�." << endl;
		cout << idx + 1 << "������ " << "���� ���� ���ŵ� �¼� Top3�� ��" << t3[idx] << "������ " << s1->seat_ui[top3[idx][0]][0] << "��" << s1->seat_ui[0][top3[idx][1]] << "�� �ڸ� �Դϴ�." << endl;
		cout << "=================================" << endl;
	}
}

void Cnt::Out_movie()
{
	cout << "=================================" << endl;
	cout << "��ȭ�� ���� ���� ���ŵ� �¼�" << endl;
	cout << endl;
	cout << "!.�θ��� ����" << endl;
	cout << "���� ���� ���ŵ� �¼� Top1�� ��" << mt1[0] << "������ " << s1->seat_ui[mtop1[0][0]][0] << "��" << s1->seat_ui[0][mtop1[0][1]] << "�� �ڸ� �Դϴ�." << endl;
	cout << "���� ���� ���ŵ� �¼� Top2�� ��" << mt2[0] << "������ " << s1->seat_ui[mtop2[0][0]][0] << "��" << s1->seat_ui[0][mtop2[0][1]] << "�� �ڸ� �Դϴ�." << endl;
	cout << "���� ���� ���ŵ� �¼� Top3�� ��" << mt3[0] << "������ " << s1->seat_ui[mtop3[0][0]][0] << "��" << s1->seat_ui[0][mtop3[0][1]] << "�� �ڸ� �Դϴ�." << endl;
	cout << endl;
	cout << "2.Ƽ�ĴϿ��� ��ħ��" << endl;
	cout << "���� ���� ���ŵ� �¼� Top1�� ��" << mt1[1] << "������ " << s1->seat_ui[mtop1[1][0]][0] << "��" << s1->seat_ui[0][mtop1[1][1]] << "�� �ڸ� �Դϴ�." << endl;
	cout << "���� ���� ���ŵ� �¼� Top2�� ��" << mt2[1] << "������ " << s1->seat_ui[mtop2[1][0]][0] << "��" << s1->seat_ui[0][mtop2[1][1]] << "�� �ڸ� �Դϴ�." << endl;
	cout << "���� ���� ���ŵ� �¼� Top3�� ��" << mt3[1] << "������ " << s1->seat_ui[mtop3[1][0]][0] << "��" << s1->seat_ui[0][mtop3[1][1]] << "�� �ڸ� �Դϴ�." << endl;
	cout << endl;
	cout << "3.ī����ī" << endl;
	cout << "���� ���� ���ŵ� �¼� Top1�� ��" << mt1[2] << "������ " << s1->seat_ui[mtop1[2][0]][0] << "��" << s1->seat_ui[0][mtop1[2][1]] << "�� �ڸ� �Դϴ�." << endl;
	cout << "���� ���� ���ŵ� �¼� Top2�� ��" << mt2[2] << "������ " << s1->seat_ui[mtop2[2][0]][0] << "��" << s1->seat_ui[0][mtop2[2][1]] << "�� �ڸ� �Դϴ�." << endl;
	cout << "���� ���� ���ŵ� �¼� Top3�� ��" << mt3[2] << "������ " << s1->seat_ui[mtop3[2][0]][0] << "��" << s1->seat_ui[0][mtop3[2][1]] << "�� �ڸ� �Դϴ�." << endl;
	cout << endl;
	cout << "4.�ٶ��� �Բ� �������" << endl;
	cout << "���� ���� ���ŵ� �¼� Top1�� ��" << mt1[3] << "������ " << s1->seat_ui[mtop1[3][0]][0] << "��" << s1->seat_ui[0][mtop1[3][1]] << "�� �ڸ� �Դϴ�." << endl;
	cout << "���� ���� ���ŵ� �¼� Top2�� ��" << mt2[3] << "������ " << s1->seat_ui[mtop2[3][0]][0] << "��" << s1->seat_ui[0][mtop2[3][1]] << "�� �ڸ� �Դϴ�." << endl;
	cout << "���� ���� ���ŵ� �¼� Top3�� ��" << mt3[3] << "������ " << s1->seat_ui[mtop3[3][0]][0] << "��" << s1->seat_ui[0][mtop3[3][1]] << "�� �ڸ� �Դϴ�." << endl;
	cout << "=================================" << endl;
}


void Sort_Cnt::Reset_vector()  //vector �ʱ�ȭ
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		v[i] = 0;
	}
}

void Sort_Cnt::Cnt_most()
{
	/* �� ���α׷������� ��ȭ���� �󿵰� �¼��� 3���� �迭�� counting �Ѵ�.
	�װ��� 1���� vector�� �����ϱ� ����  ���� �� index���� 10�� ������ �� index�� �״�� �Ͽ�
	��� �� ���Ѱ��� vector�� index�� Ȱ���Ұ��̴�.
	*/
	v.resize(56);          //56�� �ǹ̴� (������ ��: 1~5)*10 + (������ ��: 1~5) �� 11~ 55 ������ vector �ε����� ���� �����̴�.

	/* �󿵰��� ���ϴ� idx�� ���� 8�󿵰��� �ݺ��Ͽ� counting �Ѵ�.*/
	for (int i = 0; i < 8; i++) {
		Reset_vector();
		
			for (int z = 1; z < 6; z++) {
				for (int w = 1; w < 6; w++) {

					//temp_v[(100 * i) + (10 * z) + w] += Sum_seat_most[i][z][w];
					v[(10 * z) + w] += Sum_seat_most[i][z][w];
				}
			}
		
		sort(v.rbegin(), v.rend()); //�������� ����
		int tmp = 0;
		
		/*top3�� ���� ���� ������������ ���ĵ� Vector�� ���� ������ ����*/
		t1[i] = v[tmp++];
		while (1) {
			if (v[tmp] == 0 || v[tmp] != v[tmp - 1]) {
				break;
			}
			tmp++;
		}
		t2[i] = v[tmp++];
		while (1) {
			if (v[tmp] == 0 || v[tmp] != v[tmp - 1]) {
				break;
			}
			tmp++;
		}
		t3[i] = v[tmp];
		
	}
	
}
 void Sort_Cnt::Cnt_movie()
{
	v.resize(56);
	for (int idx = 0; idx < 4; idx++) {
		Reset_vector();
		for (int z = 1; z < 6; z++) {
			for (int w = 1; w < 6; w++) {

				v[(10 * z) + w] += Sum_seat_movie[idx][z][w];

			}
		}
		sort(v.rbegin(), v.rend());
		int tmp = 0;

		mt1[idx] = v[tmp++];
		while (1) {
			if (v[tmp] == 0 || v[tmp] != v[tmp - 1]) {
				break;
			}
			tmp++;
		}
		mt2[idx] = v[tmp++];
		while (1) {
			if (v[tmp] == 0 || v[tmp] != v[tmp - 1]) {
				break;
			}
			tmp++;
		}
		mt3[idx] = v[tmp];
	}

}
  
   void Sort_Cnt::Cnt_gender()
  {
	  v.resize(56);
	  for (int i = 0; i < 2; i++) {
		  Reset_vector();
		  for (int z = 1; z < 6; z++)
		  {
			  for (int w = 1; w < 6; w++) {
				  v[(10 * z) + w] += Sum_seat_gender[i][z][w];
			  }
		  }
		  sort(v.rbegin(), v.rend());
		  int tmp = 0;

		  gt1[i] = v[tmp++];
		  while (1) {
			  if (v[tmp] == 0 || v[tmp] != v[tmp - 1]) {
				  break;
			  }
			  tmp++;
		  }
		  gt2[i] = v[tmp++];
		  while (1) {
			  if (v[tmp] == 0 || v[tmp] != v[tmp - 1]) {
				  break;
			  }
			  tmp++;
		  }
		  gt3[i] = v[tmp];

	  }
  }
void Reset_Seat()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Person::seat[i][j].Reset();
		}
	}
}

 PastStatistics::PastStatistics() {
	input.open("input.txt");
	if (!input.is_open()) {
		cout << "�ؽ�Ʈ ������ �������� �ʽ��ϴ�." << endl;
		return;
	}
	
	
}

  PastStatistics::~PastStatistics() {

	 output.close();
 }
 

  void PastStatistics::InputData()
 {
	 int people_num;
	 input >> people_num;
	 Person* p1 = new Person[people_num];
	 string name, phone_num;
	 int gender, movie_choice, theater, time_idx;
	 char x, y;
	 for (int i = 0; i < people_num; i++) {
		 input >> name >> gender >> phone_num >> movie_choice >> theater >> time_idx >> x >> y;
		 p1[i].Set_hard(name, gender, phone_num, movie_choice, theater, time_idx);  p1[i].Reservation_hard(x, y);

	 }
	 delete[] p1;
 }

void PastStatistics::Day1()
{
	//1����
	InputData();
}

void  PastStatistics::Day2()
{
	//2����
	InputData();
}

void PastStatistics::Day3()
{
	InputData();
	//3����
	
}

void PastStatistics::Day4()
{
	InputData();
	//4����
	
}

void PastStatistics::Day5()
{
	InputData();
	//5����

}

void PastStatistics::Day6()
{
	InputData();
	//6����
}

 Execution::~Execution() { delete[] temp_p; }

void Execution::OutputData()
{
	output.open("input.txt", ios::app);
	if (!output.is_open()) {
		cout << "�ؽ�Ʈ ������ �������� �ʽ��ϴ�." << endl;
		return;
	}
	output << endl;
	output << people_number;
	for (int i = 0; i < count; i++)
	{
		if (temp_p[i].name == "" && temp_p[i].gender == 0) {       //�ش� ��ü�� ���������� ��ҵǾ����� Ȯ���ϱ� ����
			continue;
		}
		output << endl;
		output << temp_p[i].name << " " << temp_p[i].gender << " " << temp_p[i].phone_num << " " << temp_p[i].m1.movie_choice << " " << temp_p[i].m1.theater << " " << temp_p[i].m1.time_idx << " " << temp_p[i].a << " " << temp_p[i].b;

	}
}

void Execution::Day1To7_Execution() {

	Day1();
	c1->Set_most();
	c1->Set_movie();
	c1->Set_gender();
	c8->Sum_seats();
	c1->Cnt::Cnt_most();
	c1->Cnt::Cnt_movie();
	c1->Cnt::Cnt_gender();
	c1->Cnt_most();
	c1->Cnt_movie();
	c1->Cnt_gender();
	Reset_Seat();

	Day2();

	c2->Set_most();
	c2->Set_movie();
	c2->Set_gender();
	c8->Sum_seats();
	c2->Cnt::Cnt_most();
	c2->Cnt::Cnt_movie();
	c2->Cnt::Cnt_gender();
	c2->Cnt_most();
	c2->Cnt_movie();
	c2->Cnt_gender();

	Reset_Seat();

	Day3();

	c3->Set_most();
	c3->Set_movie();
	c3->Set_gender();
	c8->Sum_seats();
	c3->Cnt::Cnt_most();
	c3->Cnt::Cnt_movie();
	c3->Cnt::Cnt_gender();
	c3->Cnt_most();
	c3->Cnt_movie();
	c3->Cnt_gender();

	Reset_Seat();

	Day4();

	c4->Set_most();
	c4->Set_movie();
	c4->Set_gender();
	c8->Sum_seats();
	c4->Cnt::Cnt_most();
	c4->Cnt::Cnt_movie();
	c4->Cnt::Cnt_gender();
	c4->Cnt_most();
	c4->Cnt_movie();
	c4->Cnt_gender();

	Reset_Seat();

	Day5();


	c5->Set_most();
	c5->Set_movie();
	c5->Set_gender();
	c8->Sum_seats();
	c5->Cnt::Cnt_most();
	c5->Cnt::Cnt_movie();
	c5->Cnt::Cnt_gender();
	c5->Cnt_most();
	c5->Cnt_movie();
	c5->Cnt_gender();

	Reset_Seat();

	Day6();

	c6->Set_most();
	c6->Set_movie();
	c6->Set_gender();
	c8->Sum_seats();
	c6->Cnt::Cnt_most();
	c6->Cnt::Cnt_movie();
	c6->Cnt::Cnt_gender();
	c6->Cnt_most();
	c6->Cnt_movie();
	c6->Cnt_gender();

	Reset_Seat();




	
	int brk = 0;   //����ڿ��� ������ �Է¹޾� ���ǹ� ����
	while (1) {
		cout << "================================" << endl;
		cout << "ȫ�ͱ��忡 ���� ���� ȯ���մϴ�!" << endl;
		cout << "================================" << endl;
		cout << endl;
		cout << "================================" << endl;
		cout << "�Ʒ� ��ȣ�� �Է��� �ּ���." << endl;
		cout << endl;
		cout << "1. ��ȭ �����ϱ�" << endl;
		cout << endl;
		cout << "2. ��ȭ ���� ���" << endl;
		cout << endl;
		cout << "3. ������ ����(�¼� ��� Ȯ���ϱ�)" << endl;
		cout << endl;
		cout << "4. ���α׷� ����" << endl;
		cout << "================================" << endl;
		cout << endl;
		cout << "��ȣ: ";
		cin >> brk;
		if (brk == 4) {
			input.close();
			OutputData();
			return;
		}
		else if (brk == 2)
		{
			string name;
			string phone_num;
			cout << "������ �Է��� �ּ���:";
			cin >> name;
			cout << "�޴���ȭ ��ȣ�� �Է��� �ּ���:";
			cin >> phone_num;
			if (count == 0) cout << "��ϵǽ� ������ �����ϴ�." << endl;
			else {
				for (int k = 0; k < count; k++)
				{
					if (temp_p[k].Check_info(name, phone_num))
					{
						temp_p[k].Reservation_cancel();
						people_number--;
						break;
					}
					if (k == count - 1)
						cout << "��ϵǽ� ������ �����ϴ�." << endl;
				}
			}
		}
		else if (brk == 1) {
			temp_p[count].Reservation();
			count++;
			people_number++;
		}
		else if (brk == 3) break;
		else {
			cout << "�߸��� �Է� ��ȣ �Դϴ�." << endl;
			return;
		}
	}
	input.close();
	OutputData();

	c7->Set_most();
	c7->Set_movie();
	c7->Set_gender();
	c8->Sum_seats();
	c7->Cnt::Cnt_most();
	c7->Cnt::Cnt_movie();
	c7->Cnt::Cnt_gender();
	c7->Cnt_most();
	c7->Cnt_movie();
	c7->Cnt_gender();

	//statistics
	int n;
	while (1) {
		cout << "������ ���� �Դϴ�." << endl;
		cout << "���Ͻô� ��� �����Ϳ� �ش��ϴ� ��ȣ�� �Է����ּ���." << endl;
		for (int i = 1; i <= 9; i++) {
			if (i < 7)
				cout << i << ". " << i << "����" << endl;
			else if (i == 7)
				cout << i << ". " << i << "����(���� ������ �����)" << endl;
			else if (i == 8)
				cout << i << ". " << "�¼��� ��������" << endl;
			else
				cout << i << ". " << "������ ���� ����" << endl;
		}
		cout << endl;
		cout << "��ȣ: "; cin >> n;
		cout << endl;
		switch (n)
		{
		case 1:
			c1->Out_most();
			c1->Out_movie();
			c1->Out_gender();
			break;
		case 2:
			c2->Out_most();
			c2->Out_movie();
			c2->Out_gender();
			break;
		case 3:
			c3->Out_most();
			c3->Out_movie();
			c3->Out_gender();
			break;
		case 4:
			c4->Out_most();
			c4->Out_movie();
			c4->Out_gender();
			break;
		case 5:
			c5->Out_most();
			c5->Out_movie();
			c5->Out_gender();
			break;
		case 6:
			c6->Out_most();
			c6->Out_movie();
			c6->Out_gender();
			break;

		case 7:
			// ���� ���� ���ŵ� �¼�
			for (int idx = 0; idx < 8; idx++) {
				for (int i = 1; i < 6; i++)
				{
					for (int j = 1; j < 6; j++)
					{
						c8->Sum_seat_most[idx][i][j] = c1->Sum_seat_most[idx][i][j] + c2->Sum_seat_most[idx][i][j] + c3->Sum_seat_most[idx][i][j] + c4->Sum_seat_most[idx][i][j] + c5->Sum_seat_most[idx][i][j] + c6->Sum_seat_most[idx][i][j] + c7->Sum_seat_most[idx][i][j];
					}
				}
			}
			c8->Cnt::Cnt_most();
			c8->Cnt_most();
			c8->Out_most();

			//��ȭ�� ���� ���ŵ� �¼�
			for (int idx = 0; idx < 4; idx++) {
				for (int i = 1; i < 6; i++)
				{
					for (int j = 1; j < 6; j++)
					{
						c8->Sum_seat_movie[idx][i][j] = c6->Sum_seat_movie[idx][i][j] + c5->Sum_seat_movie[idx][i][j] + c4->Sum_seat_movie[idx][i][j] + c3->Sum_seat_movie[idx][i][j] + c2->Sum_seat_movie[idx][i][j] + c1->Sum_seat_movie[idx][i][j] + c7->Sum_seat_movie[idx][i][j];
					}
				}
			}
			c8->Cnt::Cnt_movie();
			c8->Cnt_movie();
			c8->Out_movie();

			//���� ���� ���ŵ� �¼�
			for (int idx = 0; idx < 2; idx++) {
				for (int i = 1; i < 6; i++)
				{
					for (int j = 1; j < 6; j++)
					{
						c8->Sum_seat_gender[idx][i][j] = c6->Sum_seat_gender[idx][i][j] + c5->Sum_seat_gender[idx][i][j] + c4->Sum_seat_gender[idx][i][j] + c3->Sum_seat_gender[idx][i][j] + c2->Sum_seat_gender[idx][i][j] + c1->Sum_seat_gender[idx][i][j] + c7->Sum_seat_gender[idx][i][j];
					}
				}
			}
			c8->Cnt::Cnt_gender();
			c8->Cnt_gender();
			c8->Out_gender();

			break;
		case 8:
			c8->Out_sum();
			break;
		case 9:
			break;
		default: cout << "Unknown number" << endl;
			break;

		}
		if (n == 9)
			break;
	}
	
}


