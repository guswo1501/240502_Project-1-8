#include <iostream>
#include <string>


using namespace std;

int main()
{
	// 1. �� �� �Է��� ������ ����
	int num;

	cout << "�� �� �з��� �Է��Ͻðڽ��ϱ�?  ";
	cin >> num;

	// 2. �л� ����ŭ "�̸�, ����, ����" ������ �ѹ��� �Է¹ޱ� (�������� ������ ����)
	string** inputArr = new string * [num];			//2���� �迭 ���� (�ϴ� ���� ����)

	for (int i = 0; i < num; i++)
	{
		cout << i + 1 << "��° �л��� �����͸� �̸�, ����, ���� ������ �Է����ּ��� ";

		inputArr[i] = new string[3];				// �̸�,����,���� �� 3���� �����͸� �����״�, �� ��� 3���� ���� �����ϰڴٴ� ��

		for (int j = 0; j < 3; j++)
		{
			cin >> inputArr[i][j];
		}
	}

	// 3. �л� ���� ���

	for (int i = 0; i < num; i++)
	{
		cout << endl;
		cout << inputArr[i][0] << " ���� " << inputArr[i][1] << " ���̰�, ������ " << inputArr[i][2] << "�Դϴ�." << endl;

	}
	// 4. ��� ����
	// inputArr[i][1]�� �ִ� ���� ���� ���õ� ���̹Ƿ�, �̰� �̿�����.

	int sum_age = 0;
	float avg_age = 0;

	for (int i = 0; i < num; i++)
	{
		sum_age += stoi(inputArr[i][1]);
	}

	avg_age = sum_age / num;

	cout << endl;
	cout << "��� ���̴� " << avg_age << "�� �Դϴ�." << endl;
	cout << endl;

	// 5. ���� ���� ���� ���
	// inputArr[i][2]�� �ִ� ���� ���ϰ� ���õ� ���̹Ƿ�, �̰� �̿�����.


	int* temp = new int[num];
	int fast_birth = 0;

	for (int i = 0; i < num; i++)
	{
		temp[i] = stoi(inputArr[i][2]);		// temp��� �迭�� ���� �ű⿡ ������� ���� ���� ����

	}

	for (int i = 0; i < num; i++)
	{
		if (temp[i] <= temp[num - 1])
		{
			fast_birth = temp[i];
		}

		if (temp[i] > temp[num - 1])
		{
			fast_birth = temp[num - 1];
		}

		else break;
	}

	if (fast_birth < 1000)
	{
		cout << "���� ���� ������ " << '0' << fast_birth << "�Դϴ�." << endl;
	}

	else
	{
		cout << "���� ���� ������ " << fast_birth << "�Դϴ�." << endl;
	}

	for (int i = 0; i < 3; i++)			// ���� �迭, �� ����
		delete[] inputArr[i];

	delete[] inputArr;					// ���� �迭, �� ����
	delete[] temp;
}

