#include <iostream>

using namespace std;

char matrix[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player = 'X';
int n;

void Draw()
{
	system("cls");
	cout << "Simple Tic Tac Toe" << endl;
	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Input()
{
	int a;
	cout << "It's " << player << "'s turn. " <<"Press the number of the box you want to occupy: ";
	cin >> a;
	
	if (a > 9 || a < 1)
	{
		cout << "Sorry that is not one of the numbers on the boxes. Try again!" << endl;
		Input();
	}
			
	if(a == 1 && matrix[0][0] == '1'){matrix[0][0] = player;}
	else if(a == 2 && matrix[0][1] == '2'){matrix[0][1] = player;}
	else if(a == 3 && matrix[0][2] == '3'){matrix[0][2] = player;}
	else if(a == 4 && matrix[1][0] == '4'){matrix[1][0] = player;}
	else if(a == 5 && matrix[1][1] == '5'){matrix[1][1] = player;}
	else if(a == 6 && matrix[1][2] == '6'){matrix[1][2] = player;}
	else if(a == 7 && matrix[2][0] == '7'){matrix[2][0] = player;}
	else if(a == 8 && matrix[2][1] == '8'){matrix[2][1] = player;}
	else if(a == 9 && matrix[2][2] == '9'){matrix[2][2] = player;}
	
	else
	{
		cout << "That box is already occupied. Try again!" << endl;
		Input();
	}
}

void SwitchPlayer()
{
	if (player == 'X'){player = 'O';}
	else{player = 'X';}
}

char Victory()
{
	//checks the rows
	if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X'){return 'X';}
	if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X'){return 'X';}
	if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X'){return 'X';}
	
	if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O'){return 'O';}
	if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O'){return 'O';}
	if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O'){return 'O';}
	
	//checks the columns
	if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X'){return 'X';}
	if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X'){return 'X';}
	if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X'){return 'X';}
	
	if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O'){return 'O';}
	if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O'){return 'O';}
	if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O'){return 'O';}
	
	//checks the diagonals
	if(matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X'){return 'X';}
	if(matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X'){return 'X';}
	
	if(matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O'){return 'O';}
	if(matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O'){return 'O';}
	
	//no player has won yet
	return '/';
}

int main()
{
	n = 0;
	Draw();
	while(1)
	{
		n++;
		Input();
		Draw();
		if (Victory() == 'X')
		{
			cout << "X wins!";
			break;
		}
		else if (Victory() == 'O')
		{
			cout << "O wins!";
			break;	
		}
		else if (Victory() == '/' && n == 9)
		{
			cout << "It's a draw!" << endl;
			break;
		}
		SwitchPlayer();
	}
	system("pause");
	return 0;	
}
