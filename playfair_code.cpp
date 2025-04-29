#include<iostream>
#include<string>
#include<math.h>
#include<fstream>
using namespace std;
string encryption(string ans, string text, char map[5][5])
{
	// xử lý văn bản đầu vào
	for (int i = 0; i < text.size(); i += 2)
	{
		if (text[i] == text[i + 1])
		{
			if (text[i] == 'X')
			{
				text.insert(text.begin() + i + 1, 'Y');
			}
			else
			{
				text.insert(text.begin() + i + 1, 'X');
			}
		}
	}
	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] == 'J')
		{
			text[i] = 'I';
		}
	}
	if (text.size() % 2 == 1)
	{
		if (text[text.size() - 1] == 'X') text += 'Y';
		else text += 'X';
	}

	int check[500]; int u = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			check[map[i][j]] = u++;
		}
	}


	for (int i = 0; i < text.size(); i += 2)
	{
		int x1, x2, y1, y2 = 0;
		//phần tìm vị trí
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (map[j][k] == text[i])
				{
					x1 = j;
					y1 = k;
				}
				if (map[j][k] == text[i + 1])
				{
					x2 = j;
					y2 = k;
				}
			}
		}

		// phần xử lý 3 trường hợp
		if (x1 == x2) {
			// Cùng hàng: dịch phải 1 (vòng quanh nếu cần)
			ans += map[x1][(y1 + 1) % 5];
			ans += map[x2][(y2 + 1) % 5];
		}
		else if (y1 == y2) {
			// Cùng cột: dịch xuống 1 (vòng quanh nếu cần)
			ans += map[(x1 + 1) % 5][y1];
			ans += map[(x2 + 1) % 5][y2];
		}
		else {
			// Hình chữ nhật: hoán đổi cột
			ans += map[x1][y2];
			ans += map[x2][y1];
		}

		ans += " "; // Giữ nguyên khoảng trắng giữa các cặp
	}

	return ans;
}
string decryption(string ans, string text, char map[5][5])
{
	int check[500]; int u = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			check[map[i][j]] = u++;
		}
	}

	for (int i = 0; i < text.size(); i += 2)
	{
		int x1, x2, y1, y2 = 0;
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (map[j][k] == text[i])
				{
					x1 = j;
					y1 = k;
				}
				if (map[j][k] == text[i + 1])
				{
					x2 = j;
					y2 = k;
				}
			}
		}

		if (x1 == x2)
		{
			ans += map[x1][(y1 - 1 + 5) % 5];
			ans += map[x2][(y2 - 1 + 5) % 5];
		}
		else if (y1 == y2)
		{
			ans += map[(x1 - 1 + 5) % 5][y1];
			ans += map[(x2 - 1 + 5) % 5][y2];
		}
		else
		{
			ans += map[x1][y2];
			ans += map[x2][y1];
		}
	}
	return ans;
} 
int main()
{
	//ofstream ot("output.txt");
	//ifstream in("input.txt");
	string apb = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
	int act;
	string key;
	string text;
	int sign[500]; // mảng dùng để đánh dấu các ký tự để in matrix
	string keyTable="";
	cout << "Your key: "; cin >> key;
	cout << "Your text (without ' '): ";cin >> text;
	cout << "Choose your action (1-Encryption || 2-Decryption): ";cin >> act;
	cout << endl;
	// tạo ma trận khóa từ key nhập sẵn
	for (int i = 0; i < key.size(); i++)
	{
		if (key[i] == 'J') key[i] = 'I'; //I và J là giống nhau trong playfair
		sign[key[i]] = 0;
	}

	for (int i = 0; i < apb.size(); i++)
	{
		sign[apb[i]] = 0;
	}
	int index = 0; int inAp = 0;
	while(index<key.size())
	{
		if (sign[key[index]] == 0)
		{
			keyTable += key[index];
			sign[key[index]] = 1;
		}
		index++;
	}
	while (inAp < apb.size())
	{
		if (sign[apb[inAp]] == 0)
		{
			keyTable += apb[inAp];
			sign[apb[inAp]] = 1;
		}
		inAp++;
	}
	int out = 0; char map[5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			map[i][j] = keyTable[out];
			out++;
		}
	}
	cout << "Key matrix: " << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	int check[500]; int u = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			check[map[i][j]] = u++;
		}
	}
	string ans = "";
	if (act == 1) cout << encryption(ans, text, map);
	else cout << decryption(ans, text, map);
}
