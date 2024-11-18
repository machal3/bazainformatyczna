#include <iostream>
#include <vector>

using namespace std;

// Funkcja do wyświetlania planszy
void print_board (const vector<vector<int>>& board)
{
    for (const auto& row : board)
    {
        for (int cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Funkcja do sprawdzania, czy dana pozycja jest na planszy
bool is_valid (int x , int y , int n)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

// Funkcja do rozwiązywania łamigłówki Signpost
bool solve_signpost (vector<vector<int>>& board , const vector<vector<char>>& directions , int x , int y , int current_number)
{
    int n = board.size ();

    // Warunek zakończenia rekurencji: wszystkie liczby zostały umieszczone
    if (current_number == n * n + 1)
    {
        return true;
    }

    // Sprawdzenie, czy aktualna pozycja jest poprawna i czy nie została jeszcze wypełniona
    if (!is_valid (x , y , n) || board[x][y] != 0)
    {
        return false;
    }

    // Ustawienie aktualnej liczby na planszy
    board[x][y] = current_number;

    // Rekurencyjne wywołanie funkcji dla wszystkich możliwych kierunków
    switch (directions[x][y])
    {
        case 'N':
            if (solve_signpost (board , directions , x - 1 , y , current_number + 1)) return true;
            break;
        case 'NE':
            if (solve_signpost (board , directions , x - 1 , y + 1 , current_number + 1)) return true;
            break;
        case 'E':
            if (solve_signpost (board , directions , x , y + 1 , current_number + 1)) return true;
            break;
        case 'SE':
            if (solve_signpost (board , directions , x + 1 , y + 1 , current_number + 1)) return true;
            break;
        case 'S':
            if (solve_signpost (board , directions , x + 1 , y , current_number + 1)) return true;
            break;
        case 'SW':
            if (solve_signpost (board , directions , x + 1 , y - 1 , current_number + 1)) return true;
            break;
        case 'W':
            if (solve_signpost (board , directions , x , y - 1 , current_number + 1)) return true;
            break;
        case 'NW':
            if (solve_signpost (board , directions , x - 1 , y - 1 , current_number + 1)) return true;
            break;
    }

    // Cofnięcie aktualnego kroku (backtrack)
    board[x][y] = 0;
    return false;
}

int main ()
{
    int n;
    int case_number = 1;

    while (cin >> n)
    {
        // Wczytanie kierunków strzałek
        vector<vector<char>> directions (n , vector<char> (n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> directions[i][j];
            }
        }

        vector<vector<int>> board (n , vector<int> (n , 0));
        board[0][0] = 1;

        solve_signpost (board , directions , 0 , 0 , 2);

        cout << "Case #" << case_number++ << ":" << endl;
        print_board (board);
    }

    return 0;
}