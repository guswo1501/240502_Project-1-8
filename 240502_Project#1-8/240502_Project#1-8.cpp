#include <iostream>
#include <string>


using namespace std;

int main()
{
	// 1. 몇 명 입력할 것인지 묻기
	int num;

	cout << "몇 명 분량을 입력하시겠습니까?  ";
	cin >> num;

	// 2. 학생 수만큼 "이름, 나이, 생일" 순서로 한번에 입력받기 (공백으로 데이터 구분)
	string** inputArr = new string * [num];			//2차원 배열 선언 (일단 행을 생성)

	for (int i = 0; i < num; i++)
	{
		cout << i + 1 << "번째 학생의 데이터를 이름, 나이, 생일 순서로 입력해주세요 ";

		inputArr[i] = new string[3];				// 이름,나이,생일 총 3개의 데이터를 받을테니, 한 행당 3개의 열을 생성하겠다는 뜻

		for (int j = 0; j < 3; j++)
		{
			cin >> inputArr[i][j];
		}
	}

	// 3. 학생 정보 출력

	for (int i = 0; i < num; i++)
	{
		cout << endl;
		cout << inputArr[i][0] << " 님은 " << inputArr[i][1] << " 세이고, 생일은 " << inputArr[i][2] << "입니다." << endl;

	}
	// 4. 평균 나이
	// inputArr[i][1]에 있는 값이 나이 관련된 값이므로, 이걸 이용하자.

	int sum_age = 0;
	float avg_age = 0;

	for (int i = 0; i < num; i++)
	{
		sum_age += stoi(inputArr[i][1]);
	}

	avg_age = sum_age / num;

	cout << endl;
	cout << "평균 나이는 " << avg_age << "세 입니다." << endl;
	cout << endl;

	// 5. 가장 빠른 생일 출력
	// inputArr[i][2]에 있는 값이 생일과 관련된 값이므로, 이걸 이용하자.


	int* temp = new int[num];
	int fast_birth = 0;

	for (int i = 0; i < num; i++)
	{
		temp[i] = stoi(inputArr[i][2]);		// temp라는 배열을 만들어서 거기에 사람들의 생일 정보 저장

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
		cout << "가장 빠른 생일은 " << '0' << fast_birth << "입니다." << endl;
	}

	else
	{
		cout << "가장 빠른 생일은 " << fast_birth << "입니다." << endl;
	}

	for (int i = 0; i < 3; i++)			// 동적 배열, 열 해제
		delete[] inputArr[i];

	delete[] inputArr;					// 동적 배열, 행 해제
	delete[] temp;
}

