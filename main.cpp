#include <iostream>
#include <string>
using namespace std;

//Initial Rock-Paper-Scissors CLI game in C++ with player vs computer logic

enum enchoice { Stone = 1, Paper = 2, Scissor = 3 };

struct stGameResults
{
    short GameRound = 0;
    short Player1WinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;

};

string GetChoiceName(enchoice choice)
{
    switch (choice)
    {
    case Stone:return "Stone";
    case Paper:return "Paper";
    case Scissor:return "Scissor";
    default:return "Unknown";
    }
}

enchoice GetRandomChoice()
{
    return (enchoice)(rand() % 3 + 1);
}

enchoice ReadChoicePlayer()
{
    int ch_player;
    do
    {
        cout << "Your choice: [1]Stone,[2]Paper,[3]Scissor ?";
        cin >> ch_player;
    } while (ch_player < 1 || ch_player > 3);
    return (enchoice)ch_player;
}

int WhoWonTheRound(enchoice player, enchoice computer)
{
    // ترجع 0 = تعادل، 1 = لاعب فاز، 2 = كمبيوتر فاز
    if (player == computer)
    {
        cout << "Round winner = [No winner]\n";
        system("color 6f");//Windows only
        return 0;
    }

    else if ((player == Stone && computer == Scissor) ||
        (player == Paper && computer == Stone) ||
        (player == Scissor && computer == Paper))
    {
        cout << "Round winner = [Player]\n";
        system("color 2f");//Windows only
        return 1;
    }

    else
    {
        cout << "Round winner = [Computer]\n";
        cout << "\a";
        system("color 4f");//Windows only
        return 2;
    }
}

int ReadNumberOfRounds(int& number)
{
    cout << "Enter the number Rounds:";
    cin >> number;
    return number;
}

void PlayGameRounds(int number, stGameResults& GameResults)
{

    for (int i = 1; i <= number; i++)
    {
        cout << "\n\nRound " << i << " begins:\n\n";
        enchoice player = ReadChoicePlayer();
        enchoice computer = GetRandomChoice();

        cout << "--------Round[" << i << "]---------\n\n";
        cout << "Player1 Choice:" << GetChoiceName(player) << endl;
        cout << "computer choice:" << GetChoiceName(computer) << endl;

        int result = WhoWonTheRound(player, computer);
        if (result == 0)
            GameResults.DrawTimes++;
        else if (result == 1)
            GameResults.Player1WinTimes++;
        else if (result == 2)
            GameResults.ComputerWinTimes++;
        cout << "\n\n-----------------------------\n\n";
        GameResults.GameRound++;
    }
}

void ShowFinalResults(stGameResults GameResults)
{
    //Final result
    cout << "\t\t\t--------------------------------\n\n";
    cout << "\t\t\t\t+++Game Over+++\t\t\n\n";
    cout << "\t\t\t--------------------------------\n\n";
    cout << "\t\t\t-------- [Game results] -------- \n\n";

    cout << "\t\t\tGame Rounds\t  :" << GameResults.GameRound << endl;
    cout << "\t\t\tPlayer won times  :" << GameResults.Player1WinTimes << endl;
    cout << "\t\t\tComputer won times:" << GameResults.ComputerWinTimes << endl;
    cout << "\t\t\tDraw times        :" << GameResults.DrawTimes << endl;
    if (GameResults.Player1WinTimes > GameResults.ComputerWinTimes)
        cout << "\t\t\tFinal wineer      :Player\n";
    else if (GameResults.ComputerWinTimes > GameResults.Player1WinTimes)
        cout << "\t\t\tFinal winner      :Computer\n";
    else
        cout << "\t\t\tFinal winner      :No winner\n";

}

void ResetScreen()
{
    system("cls");//Windows only
    system("color 0f");// Reset color
}

void StartGame()
{
    int num;
    char playagain;
    stGameResults GameResults;
    do
    {
        ResetScreen();
        PlayGameRounds(ReadNumberOfRounds(num), GameResults);
        ShowFinalResults(GameResults);
        cout << "\nDo you play again?(y,n)";
        cin >> playagain;
    } while (playagain == 'Y' || playagain == 'y');

    cout << "\nThanks for playing\n";
}



int main()
{
    srand((unsigned)time(NULL));
    StartGame();
}

