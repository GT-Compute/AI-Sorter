//Block Sorting
//There are 3 stacks L1, L2, L3
//First enter the starting position
//After that give  

#include <iostream>
#include <vector>

using namespace std;

void printVector(string s, vector<char> v)
{
    cout << s;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    cout << endl;
}

void printStates(string s, vector<char> v)
{
    if (v.size() > 0)
    {
        cout << s << " Table ( " << v[0] << " )" << endl;
        cout << s << " Hat   ( " << v[v.size()-1] << " )" << endl;
        cout << s << " On-top{ ";
        for (int i = 1; i < v.size(); i++)
        {
            cout << "(" << v[i] << "," << v[i-1] << ")";
        }
        cout << " }" << endl;

    }

}

void setVector(vector<char> &v)
{
    char add = '-';
    cout << "Please enter a character or press period to end: ";
    while (add!='.')
    {
        cin >> add;

        if (add!='.')
        {
            v.push_back(add);
        }
    }
    cout << endl;
}



bool checkVecMatch(vector<char> &var1, vector<char> &var2)
{
    if (var1.size() == var2.size())
    {
        for (int i = 0; i < var1.size(); i++)
        {
            if (var1[i] != var2[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool seek(char c, vector<char> &var)
{
    for (int i = var.size()-1; i>=0;i--)
    {
        if (var[i]==c)
        {
            return true;
        }
    }
    return false;
}

int countVecMatch(vector<char> &var1, vector<char> &var2)
{
    int num = 0;
    if (var1.size() <= 0 && var2.size() <=0)
        return 0;
    for (int i = 0; i < var1.size() && i < var2.size(); i++)
    {
        if (var1[i] == var2[i])
        {
            num = num+1;
        }
        else break;
    }
    return num;
}

bool moveArm(int &armLocation, int newLocation, int &number)
{
    if (armLocation == newLocation)
    {
        return false;
    }
    else
    {
        cout << "Moving arm from " << armLocation << " to " << newLocation << endl;
        armLocation = newLocation;
        number = number + 1;
        return true;
    }
}

void pickUp(char &armHolds, vector<char> &vecStack, int &number)
{
    int error;
    if (vecStack.size() > 0)
    {

        armHolds = vecStack[vecStack.size()-1];
        cout << "Arm picked up " << armHolds << endl;
        vecStack.pop_back();
        number += 1;
        return;
    }
    else
    {
        cout << "Error can not be moved pile is empty" << endl;
        cout << "test" << endl;
        cin >> error;
        return;
    }
}

void printAll(char armHolds, int armLocation, vector<char>stack1, vector<char>stack2,vector<char>stack3)
{
    if (armHolds != '-')
    {
        cout << "Arm is over stack " << armLocation << " holding :" << armHolds << endl;
    }
    else
    {
        cout << "Arm is over stack " << armLocation << " arm is currently empty" << endl;
    }
    printVector("L1 :", stack1);
    printVector("L2 :", stack2);
    printVector("L3 :", stack3);

}

void putDown(char &armHolds, vector<char> &vecStack, int &number)
{
    int error;
    if (armHolds != '-')
    {
        cout << "Arm put down : " << armHolds << endl;
        vecStack.push_back(armHolds);
        armHolds = '-';
        number += 1;
        return;
    }
    else
    {
        cout << "Arm is empty" << endl;
        cout << "test" << endl;
        cin >> error;
        return;
    }
}

void printArm(char armHolds, int armLocation)
{
    cout << "Arm is over pile number " << armLocation << " holding " <<armHolds << endl;
}

int main()
{
    //This is the starting position/current position
    vector <char> L1 = {};
    vector <char> L2 = {};
    vector <char> L3 = {};

    //This is the goal i want to get the vectors to match
    vector <char> eL1 = {};
    vector <char> eL2 = {};
    vector <char> eL3 = {};

    int number = 0;

    int armLocation = 1;
    char armHolds = '-';

    int sortedL1 = 0;
    int sortedL2 = 0;
    int sortedL3 = 0;

    int position = 0;

    int pile = 1;
    cout << "Now entering L1 starting position" << endl;
    setVector(L1);
    cout << "Now entering L2 starting position" << endl;
    setVector(L2);
    cout << "Now entering L3 Starting position" << endl;
    setVector(L3);
    cout << "Now entering L1 end position" << endl;
    setVector(eL1);
    cout << "Now entering L2 end position" << endl;
    setVector(eL2);
    cout << "Now entering L3 end position" << endl;
    setVector(eL3);

    bool solved = false;
    //Precounting
    printVector("L1 :", L1);
    printVector("L2 :", L2);
    printVector("L3 :", L3);
    printVector("eL1:", eL1);
    printVector("eL2:", eL2);
    printVector("eL3:", eL3);

    sortedL1 = countVecMatch(L1,eL1);
    cout << "Presorted L1 :" << sortedL1 << endl;
    sortedL2 = countVecMatch(L2,eL2);
    cout << "Presorted L2 :" << sortedL2 << endl;
    sortedL3 = countVecMatch(L3,eL3);
    cout << "Presorted L3 :" << sortedL3 << endl;

    cout << "Test" << endl;
    printVector("L1 :", L1);
    printVector("L2 :", L2);
    printVector("L3 :", L3);
    printVector("eL1:", eL1);
    printVector("eL2:", eL2);
    printVector("eL3:", eL3);

    //This lets the computer know that is is currently destacking
    bool destacking = true;

    //starts the sorting loop
    while(!solved)
    {
        if (destacking)
        {
            cout << endl << "start unstack" << endl;
            if (position == 0)
            {
                cout << "Unstacking Location 1" << endl;
                while (L1.size() > sortedL1)
                {
                    if (eL1.size() >= 1)
                    {
                        if (L1[L1.size()-1] != eL1[sortedL1])
                        {
                            cout << "Moving from L1 to L2" << endl;
                            if (moveArm(armLocation ,1, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            pickUp(armHolds, L1, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                            if (moveArm(armLocation, 2, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            putDown(armHolds, L2, number);
                            printAll(armHolds,armLocation,L1,L2,L3);

                        }
                        else{
                            cout << "Moving from L1 to L3" << endl;
                            if (moveArm(armLocation ,1, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            pickUp(armHolds, L1, number);
                            if (moveArm(armLocation, 3, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            putDown(armHolds, L3, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                        }
                    }
                    else{
                        cout << "Moving from L1 to L3" << endl;
                        if (moveArm(armLocation ,1, number))
                            printAll(armHolds,armLocation,L1,L2,L3);
                        pickUp(armHolds, L1, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                        if (moveArm(armLocation, 3, number))
                            printAll(armHolds,armLocation,L1,L2,L3);
                        putDown(armHolds, L3, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                    }
                }
                destacking = false;
            }
            if (position == 1)
            {
                cout << "Unstacking Location 2" << endl;
                while (L2.size() > sortedL2)
                {
                    if (eL2.size() >= 1)
                    {
                        if (L2[L2.size()-1] != eL2[sortedL2])
                        {
                            cout << "Moving from L2 to L3" << endl;
                            if (moveArm(armLocation ,2, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            pickUp(armHolds, L2, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                            if (moveArm(armLocation, 3, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            putDown(armHolds, L3, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                        }
                        else{
                            cout << "Moving from L2 to L1" << endl;
                            if (moveArm(armLocation ,2, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            pickUp(armHolds, L2, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                            if (moveArm(armLocation, 1, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            putDown(armHolds, L1, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                        }
                    }
                    else{
                        cout << "Moving from L2 to L1" << endl;
                        if (moveArm(armLocation ,2, number))
                            printAll(armHolds,armLocation,L1,L2,L3);
                        pickUp(armHolds, L2, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                        if (moveArm(armLocation, 1, number))
                            printAll(armHolds,armLocation,L1,L2,L3);
                        putDown(armHolds, L1, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                    }
                }
                destacking = false;
            }
            if (position == 2)
            {
            cout << "Unstacking Location 3" << endl;
                while (L3.size() > sortedL3)
                {
                    if (eL3.size() >= 1)
                    {
                        if (L3[L3.size()-1] != eL3[sortedL3])
                        {
                            cout << "Moving from L3 to L2" << endl;
                            if (moveArm(armLocation ,3, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            pickUp(armHolds, L3, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                            if (moveArm(armLocation, 2, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            putDown(armHolds, L2, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                        }
                        else{
                            cout << "Moving from L3 to L1" << endl;
                            if (moveArm(armLocation ,3, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            pickUp(armHolds, L3, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                            if (moveArm(armLocation, 1, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            putDown(armHolds, L1, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                        }
                    }
                    else{
                        cout << "Moving from L3 to L1" << endl;
                        if (moveArm(armLocation ,3, number))
                            printAll(armHolds,armLocation,L1,L2,L3);
                        pickUp(armHolds, L3, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                        if (moveArm(armLocation, 1, number))
                            printAll(armHolds,armLocation,L1,L2,L3);
                        putDown(armHolds, L1, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                    }
                }
                destacking = false;
            }
            destacking = true;
        }
        //solve stack

        if (position == 0)
        {
            cout << "Starting to restack location 1" << endl;
            //Check if they already match then skip
            if (checkVecMatch(L1,eL1))
            {
                position = 1;
            }
            //If they do not match start to solve
            else
            {
                //While they do not match
                while(!checkVecMatch(L1,eL1))
                {
                    cout << endl << "Not matching yet" << endl;
                    //Look for what is needed in L2
                    if (seek(eL1[sortedL1],L2) )
                    {
                        cout << eL1[sortedL1] << " Found in line 2" << endl;
                        //If you find it in L2 move blocks until you uncover it
                        while (L2[L2.size()-1] != eL1[sortedL1])
                        {
                            cout << "Moving from L2 to L3" << endl;
                            if (moveArm(armLocation ,2, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            pickUp(armHolds, L2, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                            if (moveArm(armLocation, 3, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            putDown(armHolds, L3, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                        }
                        //Them move it to L1
                        cout << "Moving from L2 to L1 for final placement" << endl;
                        if (moveArm(armLocation ,2, number))
                            printAll(armHolds,armLocation,L1,L2,L3);
                        pickUp(armHolds, L2, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                        if (moveArm(armLocation, 1, number))
                            printAll(armHolds,armLocation,L1,L2,L3);;
                        putDown(armHolds, L1, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                        sortedL1++;

                    }
                    //Otherwise do it with L3
                    else
                    {
                        cout << eL1[sortedL1] << " Found in line 3" << endl;
                        while (L3[L3.size()-1] != eL1[sortedL1])
                        {
                            cout << "Moving from L3 to L2" << endl;
                            if (moveArm(armLocation ,3, number))
                                printAll(armHolds,armLocation,L1,L2,L3);;
                            pickUp(armHolds, L3, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                            if (moveArm(armLocation, 2, number))
                                printAll(armHolds,armLocation,L1,L2,L3);;
                            putDown(armHolds, L2, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                        }
                        cout << "Moving from L3 to L1" << endl;
                        if (moveArm(armLocation ,3, number))
                            printAll(armHolds,armLocation,L1,L2,L3);
                        pickUp(armHolds, L3, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                        if (moveArm(armLocation, 1, number))
                            printAll(armHolds,armLocation,L1,L2,L3);
                        putDown(armHolds, L1, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                        sortedL1++;
                    }

                }
                position = 1;
            }
        }
        //Else if position checked is 1 solve
        else if (position == 1)
        {
            cout << "Starting to restack location 2" << endl;
            //If the stack is already solved skip
            if (checkVecMatch(L2,eL2))
            {
                position = 2;
            }
            //Otherwise solve
            else
            {
                //So long as it is not solved
                while(!checkVecMatch(L2,eL2))
                {
                    cout << endl << "Not matching yet" << endl;
                    //Look for next item needed in L1
                    if (seek(eL2[sortedL2],L1) )
                    {
                        cout << eL2[sortedL2] << " Found in line 1" << endl;
                        //while move from L1 to L3 until you uncover what you need
                        while (L1[L1.size()-1] != eL2[sortedL2])
                        {
                            cout << "Moving from L1 to L3" << endl;
                            if (moveArm(armLocation ,1, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            pickUp(armHolds, L1, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                            if (moveArm(armLocation, 3, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            putDown(armHolds, L3, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                        }
                        //Place it from L1 onto L2
                        cout << "Moving from L1 to L2" << endl;
                        if (moveArm(armLocation ,1, number))
                            printAll(armHolds,armLocation,L1,L2,L3);
                        pickUp(armHolds, L1, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                        if (moveArm(armLocation, 2, number))
                            printAll(armHolds,armLocation,L1,L2,L3);
                        putDown(armHolds, L2, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                        sortedL2++;
                    }
                    //Otherwise do the inverse
                    else
                    {
                        cout << eL2[sortedL2] << " Found in line 3" << endl;
                        while (L3[L3.size()-1] != eL2[sortedL2])
                        {
                            cout << "Moving from L3 to L1" << endl;
                            if (moveArm(armLocation ,3, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            pickUp(armHolds, L3, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                            if (moveArm(armLocation, 1, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            putDown(armHolds, L1, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                        }
                        cout << "Moving from L3 to L2" << endl;
                        if (moveArm(armLocation ,3, number))
                            printAll(armHolds,armLocation,L1,L2,L3);
                        pickUp(armHolds, L3, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                        if (moveArm(armLocation, 2, number))
                            printAll(armHolds,armLocation,L1,L2,L3);
                        putDown(armHolds, L2, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                        sortedL2++;
                    }
                }
                position = 2;
            }
        }
        else if (position == 2)
        {
            cout << "Starting to restack location 3" << endl;
            if (checkVecMatch(L3,eL3))
            {
                solved = true;
            }
            else
            {
                while(!checkVecMatch(L3,eL3))
                {
                    cout << endl << "Not matching yet" << endl;
                    //Look for the needed item in L1
                    if (seek(eL3[sortedL3],L1) )
                    {
                        cout << eL3[sortedL3] << " Found in line 1" << endl;
                        //If found move from L1 to L2 until you get the right item
                        while (L1[L1.size()-1] != eL3[sortedL3])
                        {
                            cout << "Moving from L1 to L2" << endl;
                            if (moveArm(armLocation ,1, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            pickUp(armHolds, L1, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                            if (moveArm(armLocation, 2, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            putDown(armHolds, L2, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                        }
                        cout << "Moving from L1 to L3" << endl;
                        if (moveArm(armLocation ,1, number))
                            printAll(armHolds,armLocation,L1,L2,L3);
                        pickUp(armHolds, L1, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                        if (moveArm(armLocation, 3, number))
                            printAll(armHolds,armLocation,L1,L2,L3);
                        putDown(armHolds, L3, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                        sortedL3++;
                    }
                    //else do the inverse
                    else
                    {
                        cout << eL3[sortedL3] << " Found in line 2" << endl;
                        while (L2[L2.size()-1] != eL3[sortedL3])
                        {
                            cout << "Moving from L2 to L1" << endl;
                            if (moveArm(armLocation ,2, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            pickUp(armHolds, L2, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                            if (moveArm(armLocation, 1, number))
                                printAll(armHolds,armLocation,L1,L2,L3);
                            putDown(armHolds, L1, number);
                            printAll(armHolds,armLocation,L1,L2,L3);
                        }
                        cout << "Moving from L2 to L3" << endl;
                        if (moveArm(armLocation ,2, number))
                            printAll(armHolds,armLocation,L1,L2,L3);
                        pickUp(armHolds, L2, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                        if (moveArm(armLocation, 3, number))
                            printAll(armHolds,armLocation,L1,L2,L3);
                        putDown(armHolds, L3, number);
                        printAll(armHolds,armLocation,L1,L2,L3);
                        sortedL3++;
                    }
                }
            }
            solved = true;
        }
    }

    cout << "Number of steps: " << number << endl;
    printStates("State of L1 ", L1);
    printStates("State of L2 ", L2);
    printStates("State of L3 ", L3);
    cout << endl << endl;
    printVector("L1 :", L1);
    printVector("L2 :", L2);
    printVector("L3 :", L3);




    return 0;
}
