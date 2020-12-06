#include <iostream>
#include <string>
using namespace std;
char mat[6][7] = { {'1','1','1','1','1','1','1'},
				  {'1','1','1','1','1','1','1'},
				  {'1','1','1','1','1','1','1'},
				  {'1','1','1','1','1','1','1'},
				  {'1','1','1','1','1','1','1'},
				  {'1','1','1','1','1','1','1'} };

char player = 'x';
void print()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << mat[i][j] << "  ";
		}
		cout << endl;
	}
}
char winer()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (mat[i][j] == 'x' && mat[i][j] == mat[i][j + 1] && mat[i][j] == mat[i][j + 2] && mat[i][j] == mat[i][j + 3])
			{
				return 'x';
				
			}
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (mat[i][j] == mat[i][j + 1] && mat[i][j] == mat[i][j + 2] && mat[i][j] == mat[i][j + 3] && mat[i][j] == 'o')
			{
				return'o';
				
			}
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (mat[j][i] == mat[j + 1][i] && mat[j][i] == mat[j + 2][i] && mat[j][i] == mat[j + 3][i] && mat[j][i] == 'x')
			{
				return 'x';
			}
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (mat[j][i] == mat[j + 1][i] && mat[j][i] == mat[j + 2][i] && mat[j][i] == mat[j + 3][i] && mat[j][i] == 'o')
			{
				return'o';
			}
		}
	}

	int counter = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (mat[i][j] == '1')
			{
				counter += 1;
			}
		}
	}
	if (counter == 0)
	{
		return 'z';
	
	}

}
bool finsh(char m[6][7])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; i < 7; i++)
		{
			if (m[i][j] == '1')
			{
				return false;
			}
		}
	}

	return true;
}

void play()
{
	while (!finsh(mat))
	{
		int position;
		cout << "enter the position (from 1 to 7) player " << player << " : ";
		cin >> position;

		if (position > 0 && position < 8)
		{
			int s = 0;
			for (int i = 0; i < 6; i++)
			{
				if (mat[i][position - 1] == 'x' || mat[i][position - 1] == 'o')
				{
					s += 1;

				}
			}
			if (mat[0][position - 1] == 'x' || mat[0][position - 1] == 'o')
			{
				cout << "Invalid place" << endl;
				cout << "try agin" << endl;
				play();
			}
			else
			{
				mat[5 - s][position - 1] = player;
			}
			print();

			if (winer() == 'x')
			{
				cout << "player x is the winer "<<endl;
				cout << "END GAME " << endl;
			}
			else if (winer() == 'o')
			{
				cout << "player O is the winer " << endl;
				cout << "END GAME "<<endl;
			}
			else if (winer() == 'z')
			{
				cout << "NO WINER" << endl;
				cout << "END GAME" << endl;
			}


			if (player == 'x')
			{
				player = 'o';
			}
			else
			{
				player = 'x';
			}

			

			play();
		}
		else
		{
			cout << "Invalid place" << endl;
			cout << "try agin" << endl;
			play();
		}

	}
	
}


int main()
{

	play();


	return 0;
}
