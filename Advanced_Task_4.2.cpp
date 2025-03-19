#include<iostream>
#include<string>
#include<math.h>
#include<fstream>
using namespace std;
string encryption(string ans, string text, char map[5][5])
{
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
		if (x1 == x2 || y1 == y2)
		{
			for (int j = 0; j < 5; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					if (check[text[i]] - check[text[i + 1]] == 5)
					{
						if (map[j][k] == text[i])
						{
							ans += map[j + 1][k];
							ans += text[i];
						}
					}
					if (check[text[i]] - check[text[i + 1]] == -5)
					{
						if (map[j][k] == text[i + 1])
						{
							ans += text[i + 1];
							ans += map[j + 1][k];

						}
					}
					if (check[text[i]] - check[text[i + 1]] == 10)
					{
						if (map[j][k] == text[i])
						{
							if (j == 4)
							{
								ans += map[0][k];
								ans += map[j - 1][k];
							}
							else
							{
								ans += map[j + 1][k];
								ans += map[j - 1][k];
							}

						}
					}
					if (check[text[i]] - check[text[i + 1]] == -10)
					{
						if (map[j][k] == text[i])
						{
							if (j + 3 == 4)
							{
								ans += map[j + 1][k];
								ans += map[0][k];
							}
							else
							{
								ans += map[j + 1][k];
								ans += map[j + 2][k];
							}

						}
					}
					if (check[text[i]] - check[text[i + 1]] == -15)
					{
						if (map[j][k] == text[i])
						{
							if (j + 3 == 4)
							{
								ans += map[j + 1][k];
								ans += map[0][k];
							}
							else
							{
								ans += map[j + 1][k];
								ans += map[j + 3][k];
							}

						}
					}
					if (check[text[i]] - check[text[i + 1]] == 15)
					{
						if (map[j][k] == text[i])
						{
							if (j == 4)
							{

								ans += map[0][k];
								ans += map[j - 2][k];
							}
							else
							{
								ans += map[j + 1][k];
								ans += map[j - 2][k];
							}

						}
					}
					if (check[text[i]] - check[text[i + 1]] == 20)
					{
						if (map[j][k] == text[i])
						{
							ans += map[0][k];
							ans += map[1][k];
						}
					}
					if (check[text[i]] - check[text[i + 1]] == -20)
					{
						if (map[j][k] == text[i])
						{
							ans += map[1][k];
							ans += map[0][k];
						}
					}
					if (check[text[i]] - check[text[i + 1]] == 1)
					{
						if (map[j][k] == text[i])
						{
							if (k == 4)
							{
								ans += map[j][0];
								ans += map[j][k];
							}
							else
							{
								ans += map[j][k + 1];
								ans += text[i];
							}

						}
					}
					if (check[text[i]] - check[text[i + 1]] == -1)
					{
						if (map[j][k] == text[i])
						{
							if (k + 1 == 4)
							{
								ans += map[j][k + 1];
								ans += map[j][0];
							}
							else
							{
								ans += map[j][k + 1];
								ans += map[j][k + 2];
							}
						}
					}
					if (check[text[i]] - check[text[i + 1]] == 2)
					{
						if (map[j][k] == text[i])
						{
							if (k == 4)
							{
								ans += map[j][0];
								ans += map[j][k - 1];
							}
							else
							{
								ans += map[j][k + 1];
								ans += map[j][k - 1];
							}
						}
					}
					if (check[text[i]] - check[text[i + 1]] == -2)
					{
						if (map[j][k] == text[i])
						{
							if (k + 2 == 4)
							{
								ans += map[j][k + 1];
								ans += map[j][0];
							}
							else
							{
								ans += map[j][k + 1];
								ans += map[j][k + 3];
							}
						}
					}
					if (check[text[i]] - check[text[i + 1]] == 3)
					{
						if (map[j][k] == text[i])
						{
							if (k == 4)
							{
								ans += map[j][0];
								ans += map[j][k - 2];
							}
							else
							{
								ans += map[j][k + 1];
								ans += map[j][k - 2];
							}
						}
					}
					if (check[text[i]] - check[text[i + 1]] == -3)
					{
						if (map[j][k] == text[i])
						{
							if (k + 3 == 4)
							{
								ans += map[j][k + 1];
								ans += map[j][0];
							}
							else
							{
								ans += map[j][k + 1];
								ans += map[j][k + 4];
							}
						}
					}
					if (check[text[i]] - check[text[i + 1]] == 4)
					{
						if (map[j][k] == text[i])
						{
							ans += map[j][0];
							ans += map[j][k - 3];
						}
					}
					if (check[text[i]] - check[text[i + 1]] == -4)
					{
						if (map[j][k] == text[i])
						{
							ans += map[j][k + 1];
							ans += map[j][k];
						}
					}
				}
			}
		}
		else
		{
			for (int j = 0; j < 5; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					if (map[j][k] == text[i])
					{
						if (y1 - y2 < 0)
						{
							ans += map[j][k + abs(y1 - y2)];
						}
						else ans += map[j][k - abs(y1 - y2)];
					}

				}
			}
			for (int j = 0; j < 5; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					if (map[j][k] == text[i + 1])
					{
						if (y1 - y2 < 0)
						{
							ans += map[j][k - abs(y1 - y2)];
						}
						else ans += map[j][k + abs(y1 - y2)];

					}
				}
			}
		}
		ans += " ";
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

	if (ans.size() > 0 && ans[ans.size() - 1] == 'X' || ans[ans.size() - 1] == 'Y')
	{
		if (ans.size() % 2 == 1)
		{
			ans.pop_back();
		}
	}

	return ans;
} 
int main()
{
	string apb = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
	int act;
	string key;
	string text;
	int sign[500];
	string keyTable="";
	cout << "Your key (without ' '): "; cin >> key;
	cout << "Your text (without ' '): ";cin >> text;
	cout << "Choose your action (1-Encryption || 2-Decryption): ";cin >> act;
	cout << endl;
	for (int i = 0; i < key.size(); i++)
	{
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
	string ans = "";
	cout << "Result: " << endl;
	if (act == 1) cout <<encryption(ans, text, map);
	else cout << decryption(ans, text, map);
}