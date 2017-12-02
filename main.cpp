#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int searchForNum(int start, int end, int & count)
{
    if (start <= end)
    {
        count++;
        int mid = (start + end) / 2;
        
        cout << endl << "Is the number " << mid << "?" << endl
             << "Enter (Y)es, (L)ower, or (H)igher: ";

        string answer = "";
        cin >> answer;

        if (answer == "Y" || answer == "y")
            return mid;
        else if (answer == "L" || answer == "l")
            return searchForNum(start, mid - 1, count);
        else if (answer == "H" || answer == "h")
            return searchForNum(mid + 1, end, count);
        else
        {
            cout << endl << "Please enter a valid response" << endl;
            return searchForNum(start, end, count);
        }
    }
    else
    {
        cout << endl << "You are lying to me :(" << endl;
        return -1;
    }
        
}

int main()
{
    int min = 0, max = 0;
    
    cout << "I will guess a number that you're thinking of BETWEEN a "
            "minimum and maximum value..." << endl << endl;
    
    cout << "Please enter your minimum bound: ";
    cin >> min;
    cout << endl << "Please enter your maximum bound: ";
    cin >> max;
    
    if (max > min)
    {
        int count = 0;
        int answer = searchForNum(min, max, count);
        
        if (count == 1 && answer != -1)
            cout << endl << "I guessed your answer to be " << answer << " in only " << count << " try!";
        else if (count > 1 && answer != -1)
            cout << endl << "I guessed your answer to be " << answer << " in only " << count << " tries!";
    }
    else
        cout << endl << "Your maximum is less than (or equal to) your minimum" << endl;
    
    return EXIT_SUCCESS;
}

/*TEST CODE: THINKING OF 52

I will guess a number that you're thinking of BETWEEN a minimum and maximum value...

Please enter your minimum bound: -348 

Please enter your maximum bound: 911

Is the number 281?
Enter (Y)es, (L)ower, or (H)igher: l

Is the number -34?
Enter (Y)es, (L)ower, or (H)igher: h

Is the number 123?
Enter (Y)es, (L)ower, or (H)igher: l

Is the number 44?
Enter (Y)es, (L)ower, or (H)igher: h

Is the number 83?
Enter (Y)es, (L)ower, or (H)igher: l

Is the number 63?
Enter (Y)es, (L)ower, or (H)igher: l

Is the number 53?
Enter (Y)es, (L)ower, or (H)igher: l

Is the number 48?
Enter (Y)es, (L)ower, or (H)igher: h

Is the number 50?
Enter (Y)es, (L)ower, or (H)igher: h

Is the number 51?
Enter (Y)es, (L)ower, or (H)igher: h

Is the number 52?
Enter (Y)es, (L)ower, or (H)igher: y

I guessed your answer to be 52 in only 11 tries!

RUN FINISHED; exit value 0; real time: 1m 10s; user: 0ms; system: 0ms
 */



/*TEST 2: THINKING OF -18

I will guess a number that you're thinking of BETWEEN a minimum and maximum value...

Please enter your minimum bound: -123

Please enter your maximum bound: 55

Is the number -34?
Enter (Y)es, (L)ower, or (H)igher: h

Is the number 11?
Enter (Y)es, (L)ower, or (H)igher: l

Is the number -11?
Enter (Y)es, (L)ower, or (H)igher: l

Is the number -22?
Enter (Y)es, (L)ower, or (H)igher: h

Is the number -16?
Enter (Y)es, (L)ower, or (H)igher: l

Is the number -19?
Enter (Y)es, (L)ower, or (H)igher: h

Is the number -17?
Enter (Y)es, (L)ower, or (H)igher: l

Is the number -18?
Enter (Y)es, (L)ower, or (H)igher: l

You are lying to me :(

RUN FINISHED; exit value 0; real time: 30s; user: 0ms; system: 0ms
*/