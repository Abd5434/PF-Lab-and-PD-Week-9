#include <iostream>
using namespace std;

const int num = 20;
const int clubPlayers = 25;
const int clubCoaches = 3;
const int achievements = 5;
const int scheduleNumber = 10;

int usersCount = 0;
string userArrName[num];
string userArrPassword[num];
string userArrRole[num];
string clubPlayersName[clubPlayers];
int clubPlayersAge[clubPlayers];
string clubPlayersRole[clubPlayers];
string clubPlayersBattingStyle[clubPlayers];
string clubPlayersBowlingStyle[clubPlayers];
int clubPlayersSalary[clubPlayers];
string clubCoachesName[clubCoaches];
int clubCoachesAge[clubCoaches];
string clubCoachesRole[clubCoaches];
int clubCoachesSalary[clubCoaches];
string showAchievements[achievements];
string opposition[scheduleNumber];
string date[scheduleNumber];
string time[scheduleNumber];
string ground[scheduleNumber];
int clubPlayerInnings[clubPlayers];
int clubPlayerRuns[clubPlayers];
int clubPlayerWickets[clubPlayers];
int clubPlayerHighScore[clubPlayers];
float clubPlayerAverage[clubPlayers];
string trainingDate[scheduleNumber];
string trainingTime[scheduleNumber];

string clubName = "Diamond Cricket Club";
int newTicketPrices = 200;
int currentPlayers = 0;
int currentCoaches = 0;

void header();
string login();
void subMenu(string subMenu);
string adminMenu();
string playerMenu();
string coachMenu();
string fanMenu();
string signIn(string name, string password);
bool signUp(string name, string password, string role);
void adminInterface();
void playerInterface();
void coachInterface();
void fanInterface();
void addPlayer();
void removePlayer();
void searchPlayer();
void checkFinances();
void addCoach();
void removeCoach();
void addAchievements();
void setTicketPrices();
void checkTeam();
void checkMgmtStaff();
void changePlayerName();
void scheduleMatch();
void checkSchedule();
void changePlayingX1();
void addPlayerPerformance();
void checkStats();
void scheduleTraining();
void checkAchievements();
void checkPlayingXI();
void checkTrainingSchedule();

main()
{
    string option = "0";
    while (option != "3")
    {
        header();
        subMenu("Login");
        option = login();

        if (option == "1")
        {
            system("cls");
            header();
            subMenu("Signin");
            string name;
            string password;
            string role;

            cout << "Name: ";
            cin >> name;
            cout << "Password: ";
            cin >> password;

            role = signIn(name, password);

            if (role == "Admin")
            {
                system("cls");
                adminInterface();
            }

            else if (role == "Player")
            {
                system("cls");
                playerInterface();
            }

            else if (role == "Coach")
            {
                system("cls");
                coachInterface();
            }

            else if (role == "Fans")
            {
                system("cls");
                fanInterface();
            }
            else if (role == "nothing")
            {
                cout << "You have entered invalid credentials..." << endl;
                string anykey;
                cout << "Enter any key to continue...";
                cin >> anykey;
            }
        }

        else if (option == "2")
        {
            system("cls");
            string name, password, role;
            header();
            subMenu("Sign up");
            cout << "Username: ";
            cin >> name;
            cout << "Password: ";
            cin >> password;
            cout << "Role (Admin / Coach / Player / Fans): ";
            cin >> role;

            bool ok = signUp(name, password, role);
            if (ok == true)
            {
                cout << "Signed up successfully." << endl;
            }

            else if (ok == false)
            {
                cout << "User capacity have been filled." << endl;
            }

            cout << "Enter any key to continue...";
            string userEnter;
            cin >> userEnter;
        }
    }
}

void header()
{
    system("cls");
    cout << "*********************************************************************************************************************" << endl;
    cout << "*******************************************Cricket Club Management System********************************************" << endl;
    cout << "*********************************************************************************************************************" << endl;
    cout << endl
         << endl;
}

string login()
{
    cout << "1. Sign in" << endl;
    cout << "2. Sign Up" << endl;
    cout << "3. Exit" << endl;
    string option;
    cout << "Enter an option...";
    cin >> option;
    return option;
}

void subMenu(string subMenu)
{
    string message = subMenu + " Menu";
    cout << message << endl;
    cout << "-------------------" << endl;
}

string adminMenu()
{
    cout << "1. Add a player." << endl;
    cout << "2. Remove a player." << endl;
    cout << "3. Check Finances." << endl;
    cout << "4. Search a player." << endl;
    cout << "5. Add a coach." << endl;
    cout << "6. Remove a coach." << endl;
    cout << "7. Add Achievements." << endl;
    cout << "8. Set Ticket Prices." << endl;
    cout << "9. Check Team." << endl;
    cout << "10. Check Management Staff." << endl;
    cout << "11. Change a player's name." << endl;
    cout << "12. Schedule a match." << endl;
    cout << "13. Exit." << endl;
    cout << "Enter an option...";
    string option;
    cin >> option;
    return option;
}

string playerMenu()
{
    cout << "1. Check Schedule." << endl;
    cout << "2. Check Playing XI." << endl;
    cout << "3. Check Statistics." << endl;
    cout << "4. Check Achievements." << endl;
    cout << "5. Check Training Schedule." << endl;
    cout << "6. Exit." << endl;
    string option;
    cout << "Enter an option...";
    cin >> option;
    return option;
}

string coachMenu()
{
    cout << "1. Add a player." << endl;
    cout << "2. Remove a player." << endl;
    cout << "3. Search a player." << endl;
    cout << "4. Check Schedule." << endl;
    cout << "5. Check Team." << endl;
    cout << "6. Change playing XI." << endl;
    cout << "7. Check statistics of players." << endl;
    cout << "8. Schedule Training Session." << endl;
    cout << "9. Check Achievements." << endl;
    cout << "10. Add Player Statistics." << endl;
    cout << "11. Exit." << endl;
    string option;
    cout << "Enter your option...";
    cin >> option;
    return option;
}

string fanMenu()
{
    cout << "1. Check Schedule." << endl;
    cout << "2. Check Statistics of players" << endl;
    cout << "3. Check Achievements" << endl;
    cout << "4. Exit" << endl;
    string option;
    cout << "Enter your option...";
    cin >> option;
    return option;
}

string signIn(string name, string password)
{
    for (int idx = 0; idx < num; idx++)
    {
        if ((name == userArrName[idx]) && (password == userArrPassword[idx]))
        {
            return userArrRole[idx];
        }
    }
    return "nothing";
}

bool signUp(string name, string password, string role)
{
    if (usersCount < num)
    {
        userArrName[usersCount] = name;
        userArrPassword[usersCount] = password;
        userArrRole[usersCount] = role;
        usersCount++;
        return true;
    }

    else
    {
        return false;
    }
}

void adminInterface()
{
    string adminOption = "0";
    while (adminOption != "13")
    {
        system("cls");
        header();
        adminOption = adminMenu();
        system("cls");
        if (adminOption == "1")
        {

            header();
            addPlayer();
        }
        else if (adminOption == "2")
        {
            header();
            removePlayer();
        }
        else if (adminOption == "3")
        {
            header();
            checkFinances();
        }
        else if (adminOption == "4")
        {
            header();
            searchPlayer();
        }
        else if (adminOption == "5")
        {
            header();
            addCoach();
        }
        else if (adminOption == "6")
        {
            header();
            removeCoach();
        }
        else if (adminOption == "7")
        {
            header();
            addAchievements();
        }
        else if (adminOption == "8")
        {
            header();
            setTicketPrices();
        }
        else if (adminOption == "9")
        {
            header();
            checkTeam();
        }
        else if (adminOption == "10")
        {
            header();
            checkMgmtStaff();
        }
        else if (adminOption == "11")
        {
            header();
            changePlayerName();
        }
        else if (adminOption == "12")
        {
            header();
            scheduleMatch();
        }
    }
}

void playerInterface()
{
    string playerOption = "0";
    while (playerOption != "6")
    {
        system("cls");
        header();
        playerOption = playerMenu();
        system("cls");

        if (playerOption == "1")
        {
            header();
            checkSchedule();
        }

        else if (playerOption == "2")
        {
            header();
            checkPlayingXI();
        }

        else if (playerOption == "3")
        {
            header();
            checkStats();
        }

        else if (playerOption == "4")
        {
            header();
            checkAchievements();
        }

        else if (playerOption == "5")
        {
            header();
            checkTrainingSchedule();
        }
    }
}

void coachInterface()
{
    string coachOption = "0";
    while (coachOption != "11")
    {
        system("cls");
        header();
        coachOption = coachMenu();
        system("cls");

        if (coachOption == "1")
        {
            header();
            addPlayer();
        }

        else if (coachOption == "2")
        {
            header();
            removePlayer();
        }

        else if (coachOption == "3")
        {
            header();
            searchPlayer();
        }

        else if (coachOption == "4")
        {
            header();
            checkSchedule();
        }

        else if (coachOption == "5")
        {
            header();
            checkTeam();
        }

        else if (coachOption == "6")
        {
            header();
            changePlayingX1();
        }

        else if (coachOption == "7")
        {
            header();
            checkStats();
        }

        else if (coachOption == "8")
        {
            header();
            scheduleTraining();
        }

        else if (coachOption == "9")
        {
            header();
            checkAchievements();
        }

        else if (coachOption == "10")
        {
            header();
            addPlayerPerformance();
        }
    }
}

void fanInterface()
{
    string fanOption = "0";
    while (fanOption != "4")
    {
        system("cls");
        header();
        fanOption = fanMenu();
        system("cls");

        if (fanOption == "1")
        {
            header();
            checkSchedule();
        }

        else if (fanOption == "2")
        {
            header();
            checkStats();
        }

        else if (fanOption == "3")
        {
            header();
            checkAchievements();
        }
    }
}

void addPlayer()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        system("cls");
        header();
        string a;
        getline(cin,a);
        cout << "Enter the player's name: ";
        getline(cin,clubPlayersName[currentPlayers]);
        cout << "Enter the age of player: ";
        cin >> clubPlayersAge[currentPlayers];
        cout << "Role(Batsmen / Bowler / WK / All-Rounder): ";
        getline(cin,a);
        getline(cin,clubPlayersRole[currentPlayers]);
        cout << "Batting style(Left / Right): ";
        getline(cin,clubPlayersBattingStyle[currentPlayers]);
        cout << "Bowling style(Left / Right / No): ";
        getline(cin,clubPlayersBowlingStyle[currentPlayers]);
        cout << "Enter his salary: ";
        cin >> clubPlayersSalary[currentPlayers];
        currentPlayers++;
        cout << "Do you want to continue?" << endl
             << "Enter 0 to exit. " << endl
             << "Enter any other key to continue...";
        cin >> userEnter;
    }
}

void removePlayer()
{
    string nameToRemove;
    string userEnter = "1";
    int ageRemove;
    while (userEnter != "0")
    {
        string a;
        getline(cin,a);
        cout << "Enter the name of player you want to remove: ";
        getline(cin,nameToRemove);
        cout << "Enter his age: ";
        cin >> ageRemove;

        for (int idx = 0; idx < currentPlayers; idx++)
        {
            if ((nameToRemove == clubPlayersName[idx]) && (ageRemove == clubPlayersAge[idx]))
            {
                clubPlayersName[idx] = "";
                clubPlayersAge[idx] = 0;
                clubPlayersBattingStyle[idx] = "";
                clubPlayersBowlingStyle[idx] = "";
                clubPlayersRole[idx] = "";
                clubPlayersSalary[idx] = 0;
                currentPlayers--;
            }
        }
        cout << "Do you want to continue?" << endl
             << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        cin >> userEnter;
    }
}

void checkFinances()
{
    int sumPlayer = 0;
    int sumCoach = 0;
    string userEnter = "1";
    while (userEnter != "0")
    {
        for (int idx = 0; idx < currentPlayers; idx++)
        {
            sumPlayer = sumPlayer + clubPlayersSalary[idx];
        }
        for (int idx = 0; idx < currentPlayers; idx++)
        {
            sumCoach = sumCoach + clubCoachesSalary[idx];
        }
        cout << "1. Player's Salary: " << sumPlayer << endl;
        cout << "2. Coach's Salary: " << sumCoach << endl;

        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        cin >> userEnter;
    }
}

void addCoach()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        string a;
        getline(cin,a); 
        cout << "Enter the coach's name: ";
        getline(cin,clubCoachesName[currentCoaches]);
        cout << "Role(Head / Batting / Bowling / WK / Fielding): ";
        getline(cin,clubCoachesRole[currentCoaches]);
        cout << "Enter the age of coach: ";
        cin >> clubCoachesAge[currentCoaches];
        cout << "Enter his salary: ";
        cin >> clubCoachesSalary[currentCoaches];
        currentCoaches++;
        cout << "Do you want to continue?" << endl
             << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        cin >> userEnter;
    }
}

void removeCoach()
{
    string nameToRemove;
    string userEnter = "1";
    int ageRemove;
    while (userEnter != "0")
    {
        string a;
        getline(cin,a);
        cout << "Enter the name of coach you want to remove: ";
        getline(cin,nameToRemove);
        cout << "Enter his age: ";
        cin >> ageRemove;

        for (int idx = 0; idx < currentPlayers; idx++)
        {
            if ((nameToRemove == clubCoachesName[idx]) && (ageRemove == clubCoachesAge[idx]))
            {
                clubCoachesName[idx] = "";
                clubCoachesAge[idx] = 0;
                clubCoachesRole[idx] = "";
                clubCoachesSalary[idx] = 0;
                currentCoaches--;
            }
        }
        cout << "Do you want to continue?" << endl
             << "Press 0 to exit." << endl
             << "Enter any other number to continue...";
        cin >> userEnter;
    }
}

void addAchievements()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        string a; 
        getline(cin,a);
        cout << "Enter Achievements:-" << endl;
        for (int idx = 0; idx < achievements; idx++)
        {
            getline(cin,showAchievements[idx]);
        }
        cout << "Do you want to continue?" << endl
             << "Press 0 to exit." << endl
             << "Enter any other number to continue...";
        cin >> userEnter;
    }
}

void setTicketPrices()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        cout << "Set New Ticket Prices: ";
        cin >> newTicketPrices;
        cout << "Do you want to continue?" << endl
             << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        cin >> userEnter;
    }
}

void checkTeam()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        cout << "     "
             << "Name"
             << "    "
             << "    Age"
             << "    "
             << "    Role"
             << "    "
             << "    Batting Style"
             << "    "
             << "    Bowling Style"
             << "    "
             << "    Salary" << endl;
        for (int idx = 0; idx < currentPlayers; idx++)
        {
            cout << idx + 1 << ".    " << clubPlayersName[idx] << "    " << clubPlayersAge[idx] << "    " << clubPlayersRole[idx] << "    " << clubPlayersBattingStyle[idx] << "    " << clubPlayersBowlingStyle[idx] << "    " << clubPlayersSalary[idx] << endl;
        }
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        cin >> userEnter;
    }
}

void checkMgmtStaff()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        cout << "     "
             << "Name"
             << "    "
             << "Age"
             << "    "
             << "Role"
             << "    "
             << "Salary" << endl;
        for (int idx = 0; idx < currentCoaches; idx++)
        {
            cout << idx + 1 << ".   " << clubCoachesName[idx] << "   " << clubCoachesAge[idx] << "    " << clubCoachesRole[idx] << "   " << clubCoachesSalary[idx] << endl;
        }
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        cin >> userEnter;
    }
}

void searchPlayer()
{
    string search;
    bool flag = false;
    string userEnter = "1";
    while (userEnter != "0")
    {
        string a;
        getline(cin,a);
        cout << "Enter the player's name: ";
        getline(cin,search);

        for (int idx = 0; idx < currentPlayers; idx++)
        {
            if (search == clubPlayersName[idx])
            {
                flag = true;
                cout << "The player is at index " << idx << endl;
                cout << "Player's Role: " << clubPlayersRole[idx] << endl;
                cout << "Player's Batting Style: " << clubPlayersBattingStyle[idx] << endl;
                cout << "Player's Bowling Style: " << clubPlayersBowlingStyle[idx] << endl;
                cout << "Player's Salary: " << clubPlayersSalary[idx] << endl;
            }
        }
        if (flag == false)
        {
            cout << "There is no such player in the team." << endl;
        }
        cout << "Do you want to continue?" << endl;
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        cin >> userEnter;
    }
}

void scheduleMatch()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        for (int idx = 0; idx < scheduleNumber; idx++)
        {
            cout << "Match " << idx + 1 << endl;
            string a;
            getline(cin,a);
            cout << "Enter the opposite club name: ";
            getline(cin,opposition[idx]);
            cout << "Date: ";
            getline(cin,date[idx]);
            cout << "Time: ";
            getline(cin,time[idx]);
            cout << "Ground: ";
            getline(cin,ground[idx]);

            cout << "Do you want to continue?" << endl
                 << "Press 0 to exit." << endl;
            string anykey = "2";
            cin >> anykey;
            if (anykey == "0")
            {
                break;
            }
        }
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        cin >> userEnter;
    }
}

void checkSchedule()
{
    string userEnter = "1";

    for (int idx = 0; idx < scheduleNumber; idx++)
    {
        cout << clubName << " vs " << opposition[idx] << "       " << date[idx] << "       " << time[idx] << "       " << ground[idx] << endl;
    }

    cout << "Enter any key to exit.";
    cin >> userEnter;
}

void changePlayingX1()
{
    string userEnter = "1";
    int idx1, idx2, temp;
    string temp1;
    while (userEnter != "0")
    {
        cout << "Enter Player in playing XI(index): ";
        cin >> idx1;
        idx1 = idx1 - 1;
        cout << "Enter substitution player(index): ";
        cin >> idx2;
        idx2 = idx2 - 1;
        temp1 = clubPlayersName[idx1];
        clubPlayersName[idx1] = clubPlayersName[idx2];
        clubPlayersName[idx2] = temp1;

        temp = clubPlayersAge[idx1];
        clubPlayersAge[idx1] = clubPlayersAge[idx2];
        clubPlayersAge[idx2] = temp;

        temp1 = clubPlayersRole[idx1];
        clubPlayersRole[idx1] = clubPlayersRole[idx2];
        clubPlayersRole[idx2] = temp1;

        temp1 = clubPlayersBattingStyle[idx1];
        clubPlayersBattingStyle[idx1] = clubPlayersBattingStyle[idx2];
        clubPlayersBattingStyle[idx2] = temp1;

        temp1 = clubPlayersBowlingStyle[idx1];
        clubPlayersBowlingStyle[idx1] = clubPlayersBowlingStyle[idx2];
        clubPlayersBowlingStyle[idx2] = temp1;

        temp = clubPlayersSalary[idx1];
        clubPlayersSalary[idx1] = clubPlayersSalary[idx2];
        clubPlayersSalary[idx2] = temp;

        cout << "Do you want to continue?" << endl;
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        ;
        cin >> userEnter;
    }
}

void changePlayerName()
{
    string userEnter = "1";
    string name, role;
    while (userEnter != "0")
    {
        string a;
        getline(cin,a);

        cout << "Name of player which was recorded previously: ";
        getline(cin,name);
        cout << "His Role: ";
        getline(cin,role);

        for (int idx = 0; idx < currentPlayers; idx++)
        {
            if ((name == clubPlayersName[idx]) && (role == clubCoachesRole[idx]))
            {
                string a;
                getline(cin,a);
                cout << "Write the corrected version: ";
                getline(cin,clubPlayersName[idx]);
            }
        }

        cout << "Do you want to continue?" << endl;
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        cin >> userEnter;
    }
}

void addPlayerPerformance()
{
    string userEnter = "1";
    string name, role;
    float average;
    while (userEnter != "0")
    {
        string a;
        getline(cin,a);
        cout << "Player's name: ";
        getline(cin,name);
        cout << "Player's Role: ";
        getline(cin,role);

        for (int idx = 0; idx < currentPlayers; idx++)
        {
            if ((clubPlayersName[idx] == name) && (clubPlayersRole[idx] == role))
            {
                cout << "Enter his runs: ";
                cin >> clubPlayerRuns[idx];
                cout << "Nummber of innings: ";
                cin >> clubPlayerInnings[idx];
                cout << "Number of wickets: ";
                cin >> clubPlayerWickets[idx];
                cout << "Highest Score: ";
                cin >> clubPlayerHighScore[idx];
                average = clubPlayerRuns[idx] / clubPlayerInnings[idx];
                cout << "Average: " << average << endl;
                clubPlayerAverage[idx] = average;
            }
        }

        cout << "Do you want to continue?" << endl;
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        cin >> userEnter;
    }
}

void checkStats()
{
    string userEnter = "1";
    string name, role;
    while (userEnter != "0")
    {
        string a;
        getline(cin,a);
        cout << "Player's Name: ";
        getline(cin,name);
        cout << "Player's Role: ";
        getline(cin,role);

        for (int idx = 0; idx < currentPlayers; idx++)
        {
            if ((name == clubPlayersName[idx]) && (role == clubPlayersRole[idx]))
            {
                cout << "Player Name: " << name << endl;
                cout << "Player's Role: " << role << endl;
                cout << "Innings: " << clubPlayerInnings[idx] << endl;
                cout << "Runs: " << clubPlayerRuns[idx] << endl;
                cout << "Wickets: " << clubPlayerWickets[idx] << endl;
                cout << "Highest Score: " << clubPlayerHighScore[idx] << endl;
                cout << "Average: " << clubPlayerAverage[idx] << endl;
            }
        }

        cout << "Do you want to continue?" << endl;
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        cin >> userEnter;
    }
}

void scheduleTraining()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        for (int idx = 0; idx < scheduleNumber - 5; idx++)
        {
            cout << "Enter Date: ";
            cin >> trainingDate[idx];
            cout << "Enter Time: ";
            cin >> trainingTime[idx];
        }

        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        cin >> userEnter;
    }
}

void checkAchievements()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        for (int idx = 0; idx < achievements; idx++)
        {
            cout << idx + 1 << ". " << showAchievements[idx] << endl;
        }
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        cin >> userEnter;
    }
}

void checkPlayingXI()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        for (int idx = 0; idx < 11; idx++)
        {
            cout << idx + 1 << ". " << clubPlayersName[idx] << endl;
        }
        cout << "Enter 0 to exit.";
        cin >> userEnter;
    }
}

void checkTrainingSchedule()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        cout << "                       Date"
             << "        Time" << endl;
        for (int idx = 0; idx < scheduleNumber - 5; idx++)
        {
            cout << "Training Session " << idx + 1 << ". " << trainingDate[idx] << "    " << trainingTime[idx] << endl;
        }
        cout << "Enter 0 to exit.";
        cin >> userEnter;
    }
}
