
//Libraries needed
#include<iostream>
#include<ctime>
#include<stdlib.h>

using namespace std;

//Declare variables
int dist = 10, phealth = 10, chealth = 10;
char player[10] = { '*', '*', '*', '*', '*', '*', '*', '*', '*', '*' };
char computer[10] = { '*', '*', '*', '*', '*', '*', '*', '*', '*', '*' };

//Getting random value into defendCritical
int defendCritical()
{
    //Generate random number
    srand(time(0));
    if ((rand() % 10) + 1 == 10) return 1;
    return 0;
}

//If user choose defend, this is the output
void defend(int x)
{
    //Defend choice

    //If distance is 0, if defendCritical is 1 which mean  it reach that 10% of making the defence useless
    if (dist == 0)
    {
        //Player
        if (x == 1)
        {
            if (defendCritical() == 1)
            {
                player[phealth - 1] = ' ';
                phealth--;
            }
        }

        //Computer
        else
        {
            if (defendCritical() == 1)
            {
                computer[chealth - 1] = ' ';
                chealth--;
            }
        }
    }
    // else defend is successful meaning nothing happened
}

//If user choose surrender, this is the output
void surrender()
{
    //Clear all that before it
    system("cls");
    //Surrender Output
    cout << "I====================v=====================II" << endl;
    cout << "I                You've lost               II" << endl;
    cout << "I                 Game over                II" << endl;
    cout << "I====================v=====================II" << endl;
    //Stop and Finish
    system("pause");
    exit(0);
}

//Getting random value into critical
int critical()
{
    //Generate random number
    srand(time(0));
    if ((rand() % 10) + 1 == 10) return 2;
    return 0;
}

//If user choose attack this is the output
void attack(int x)
{
    //if distance = 0, attack minus 1 point of health
    if (dist == 0)
    {

        //Player
        if (x == 1)
        {
            computer[chealth - 1] = ' ';
            chealth--;
        }

        //Computer
        else
        {
            player[phealth - 1] = ' ';
            phealth--;
        }

        //If int critical output is 2, critical chance is successful
        //Minus 2 point of health (1 minus due to above condtion, 1 minus due to below condition)
        if (critical() == 2)
        {
            //Player
            if (x == 1)
            {
                computer[chealth - 1] = ' ';
                chealth--;
            }

            //Computer
            else {
                player[phealth - 1] = ' ';
                phealth--;
            }
        }
    }

    //If distance = 1, attack minus 1 point of health
    else if (dist == 1)
    {
        //Player
        if (x == 1)
        {
            computer[chealth - 1] = ' ';
            chealth--;
        }

        //Computer
        else
        {
            player[phealth - 1] = ' ';
            phealth--;
        }
    }
}

//If player choose to move forward, run this
void moveForward()
{
    (dist - 1 < 0) ? dist -= 0 : dist--;
}

//If player choose to move backward, run this
void moveBackward()
{
    (dist + 1 > 10) ? dist += 0 : dist++;
}

//Update every time player choose an option
void updateStatus()
{
    //Generate random number goes into pc choice
    srand(time(0));
    int pcchoice;
    pcchoice = (rand() % 4) + 1;

    //Declare Action
    char action;

    //Clear screen every output
    system("cls");

    //Game Display Screen
    cout << "I====================v=====================II" << endl;
    cout << "I Level: 1                                 II" << endl;
    cout << "I====================v=====================II" << endl;
    cout << "I Player 1           v Computer            II" << endl;
    cout << "I HP: ";

    //Player health bar
    for (int i = 0;i < 10;i++)
        cout << player[i];

    //Display health in this [ ]
    cout << " [";
    if (phealth == 10)
    {
        cout << phealth;
    }
    else
    {
        cout << " " << phealth;
    }
    cout << "]v HP: ";

    //Computer health bar
    for (int i = 0;i < 10;i++)
        cout << computer[i];

    //Display health in this [ ]
    cout << " [";
    if (chealth == 10)
    {
        cout << chealth;
    }
    else
    {
        cout << " " << chealth;
    }
    cout << "] II" << endl;

    //Display current distance
    cout << "I====================v=====================II" << endl;
    cout << "I Distance between fighters : ";
    if (dist == 10)
    {
        cout << "10";
    }
    else
    {
        cout << " " << dist;
    }
    cout << "           II" << endl;

    //Input Selection
    cout << "I====================v=====================II" << endl;
    cout << endl << "Command: " << endl;
    cout << "[1] Move Forward" << endl << "[2] Move Backward" << endl << "[3] Attack" << endl << "[4] Defend" << endl << "[0] Surrender";
    cout << endl << endl;

    //Choice goes into Action
    cout << "Choose an action: ";
    cin >> action;

    //Using Ascii value, If input is between not 1 2 3 4, loop if still not 1 2 3 4
    while (action < 48 || action>52)
    {

        //Clear screen after every input
        system("cls");
        cin.clear();
        cin.ignore(10, '\n');

        //Game Display Screen
    cout << "I====================v=====================II" << endl;
    cout << "I Level: 1                                 II" << endl;
    cout << "I====================v=====================II" << endl;
    cout << "I Player 1           v Computer            II" << endl;
    cout << "I HP: ";

    //Player health bar
    for (int i = 0;i < 10;i++)
        cout << player[i];

    //Display health in this [ ]
    cout << " [";
    if (phealth == 10)
    {
        cout << phealth;
    }
    else
    {
        cout << " " << phealth;
    }
    cout << "]v HP: ";

    //Computer health bar
    for (int i = 0;i < 10;i++)
        cout << computer[i];

    //Display health in this [ ]
    cout << " [";
    if (chealth == 10)
    {
        cout << chealth;
    }
    else
    {
        cout << " " << chealth;
    }
    cout << "] II" << endl;

    //Display current distance
    cout << "I====================v=====================II" << endl;
    cout << "I Distance between fighters : ";
    if (dist == 10)
    {
        cout << "10";
    }
    else
    {
        cout << " " << dist;
    }
    cout << "           II" << endl;

    //Input Selection
    cout << "I====================v=====================II" << endl;
    cout << endl << "Command: " << endl;
    cout << "[1] Move Forward" << endl << "[2] Move Backward" << endl << "[3] Attack" << endl << "[4] Defend" << endl << "[0] Surrender";
    cout << endl << endl;

    //Choice goes into Action
    cout << "Please choose within the specific range: ";
    cin >> action;
    }

    //If player choose to surrender 0
    if (action == 48) surrender();
    cout << "\nI====================v=====================II" << endl;
    cout << "I     Player choose to ";

    //if computer choice is number 1
    if (pcchoice == 1)
    {
        //If player choice is 1
        if (action == 49)
        {
            cout << "move forward        II" << endl;
            cout << "I====================v=====================II" << endl;
            if (dist >= 2)
            {
                moveForward();
                moveForward();
            }
        }

        //If player choice is number 2
        else if (action == 50)
        {
            cout << "move backward       II" << endl;
            cout << "I====================v=====================II" << endl;
        }

        //If player choice is number 3
        else if (action == 51)
        {
            cout << "attack              II" << endl;
            cout << "I====================v=====================II" << endl;
            if (dist == 0)
            {
                attack(1);
                moveBackward();
                moveBackward();
            }
            else
            {
                moveForward();
                attack(1);
            }
        }

        //If user choice is number 4
        else
        {
            cout << "defend              II" << endl;
            cout << "I====================v=====================II" << endl;
            if (dist == 0)
            {
                moveBackward();
                moveBackward();
            }
            else
            {
                moveForward();
            }
        }

        //Output of computer choice 1
        cout << "I====================v=====================II" << endl;
        cout << "I     Computer choose to move forward      II" << endl;
        cout << "I====================v=====================II" << endl;
    }

    //if computer choice is number 2
    else if (pcchoice == 2)
    {

        //If player choice is number 1
        if (action == 49) {
            cout << "move forward        II" << endl;
            cout << "I====================v=====================II" << endl;
        }


        //If player choice is number 2
        else if (action == 50)
        {
            cout << "move backward       II" << endl;
            cout << "I====================v=====================II" << endl;
            if (dist < 9) {
                moveBackward();
                moveBackward();
            }
        }


        //If player choice is number 3
        else if (action == 51)
        {
            cout << "attack              II" << endl;
            cout << "I====================v=====================II" << endl;
            moveBackward();
            attack(1);
        }


        //If player choice is number 4
        else
        {
            cout << "defend              II" << endl;
            cout << "I====================v=====================II" << endl;
            moveBackward();
        }

        //Output if computer choose choice 3
        cout << "I====================v=====================II" << endl;
        cout << "I     Computer choose to move backward     II" << endl;
        cout << "I====================v=====================II" << endl;
    }

    //If computer choice is number 3
    else if (pcchoice == 3)
    {

        //If player choice is number 1
        if (action == 49) {
            cout << "move forward        II" << endl;
            cout << "I====================v=====================II" << endl;
            if (dist == 0)
            {
                attack(0);
                moveBackward();
                moveBackward();
            }
            else {
                moveForward();
                attack(0);
            }
        }


        //If player choice is number 2
        else if (action == 50)
        {
            cout << "move backward       II" << endl;
            cout << "I====================v=====================II" << endl;
            moveBackward();
            attack(0);
        }


        //If player choice is number 3
        else if (action == 51)
        {
            cout << "attack              II" << endl;
            cout << "I====================v=====================II" << endl;
            attack(1);
            attack(0);
        }


        //If player choice is number 4
        else {
            cout << "defend              II" << endl;
            cout << "I====================v=====================II" << endl;
            if (dist == 0)
            {
                defend(1);
                attack(0);
            }
            else if (dist == 1)
            {

            }
        }

        //Output if computer choose choice 3
        cout << "I====================v=====================II" << endl;
        cout << "I     Computer choose to attack            II" << endl;
        cout << "I====================v=====================II" << endl;
    }

    //If computer choose choice 4
    else
    {

        //If player choice is number 1
        if (action == 49)
        {
            cout << "move forward        II" << endl;
            cout << "I====================v=====================II" << endl;
            if (dist == 0)
            {
                moveBackward();
                moveBackward();
            }
            else
            {
                moveForward();
            }
        }

        //If player choice is number 2
        else if (action == 50)
        {
            cout << "move backward       II" << endl;
            cout << "I====================v=====================II" << endl;
            moveBackward();
        }


        //If player choice is number 3
        else if (action == 51)
        {
            cout << "attack              II" << endl;
            cout << "I====================v=====================II" << endl;
        }


        //If player choice is number 4
        else
        {
            cout << "defend              II" << endl;
            cout << "I====================v=====================II" << endl;
        }

        //Output if computer choose choice 4
        cout << "I====================v=====================II" << endl;
        cout << "I     Computer choose to defend            II" << endl;
        cout << "I====================v=====================II" << endl;
    }

    //Loop until surrender or one loss
    cout << endl << "Press any key to continue: ";
    system("pause");
    system("cls");

    //If both player and computer health are 0
    if (phealth == 0 && chealth == 0)
    {
        cout << "I====================v=====================II" << endl;
        cout << "I                 Game over                II" << endl;
        cout << "I                It's a draw               II" << endl;
        cout << "I====================v=====================II" << endl;
        cout << endl << "Press any key to continue: ";
        system("pause");
        exit(0);
    }

    //If player health are 0
    else if (phealth == 0)
    {
        cout << "I====================v=====================II" << endl;
        cout << "I                You've lost               II" << endl;
        cout << "I                 Game over                II" << endl;
        cout << "I====================v=====================II" << endl;
        cout << endl << "Press any key to continue: ";
        system("pause");
        exit(0);
    }

    //If computer health are 0
    else if (chealth == 0)
    {
        cout << "I====================v=====================II" << endl;
        cout << "I                 You've won               II" << endl;
        cout << "I                Well played               II" << endl;
        cout << "I====================v=====================II" << endl;
        cout << endl << "Press any key to continue: ";
        system("pause");
        exit(0);
    }
}

//Main Output to run
int main()
{
    while (true)
    {
        updateStatus();
        system("cls");
    }

}

