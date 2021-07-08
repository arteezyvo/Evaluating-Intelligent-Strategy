// Van Quoc Thinh Vo
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
using namespace std;

class candidate
{
	public:
		string name;
		int vote;
};

struct strategy
{
   char type;
   double x;
   double y;
};

// voter class
   // voter preference
   // voter strategy
struct voter
{
   string name;
   strategy strat;
   vector<int> preference;
   vector<int> ballot;
};

void currentStanding(candidate* arr, int n)
{
	int total_vote = 0;
	for (int i = 0; i < n; i++)
   {
		total_vote += arr[i].vote; 
	}

	cout<< "Current standing of the election............." << endl;
	cout<< "Name of candidate" << "\t" <<"vote received" << endl;
	for (int i = 0; i < n; i++)
   {
		cout << arr[i].name << "\t\t\t";
		cout << arr[i].vote << endl;
	}

	int max = INT_MIN, count = 0;
	int index[n] = {0};

	for (int i = 0; i < n; i++)
   {
		if (arr[i].vote > max)
      {
			max = arr[i].vote;
		}
	}
	
	for (int i = 0; i < n; i++)
   {
		if (arr[i].vote == max)
      {
			index[count] = i;
			count++;
		}
	}
	
	if (count == 1)
		cout << "The current leader is " << arr[index[count-1]].name << endl;
	else
   {
		cout << "There is tie between:" << endl;
      
		for(int i = 0; i < count - 1; i++)
      {
			cout << arr[index[i]].name << ", ";
      }
		cout << arr[index[count-1]].name << endl;
	}
	return ;
}

//CS 4318 rps.cpp
int randomInt(int n)
{
   // Return a random nonnegative integer less than n.
   int r;
   if (n <= 0)
   {
      return 0;
   }
   do
   {
      r = random();
   }
   while (r >= INT_MAX / n * n);
   return r / (INT_MAX / n);
}

// candidates with highest random will be voter's favorite
// random number -> candidate
/*Preferences function*/
void voterPreference(voter* arrVoter, int numVoter, int numCandidate)
{
   //int r;
   vector<int> rand;
   //int max;
   for (int j = 0; j < numCandidate; j++)
   {
      rand.push_back(j);
   }
   for (int i = 0; i < numVoter; i++)
   {
      //cout << "Voter number " << i+1 << " 's preference" << endl;
      random_shuffle(rand.begin(), rand.end(), randomInt);
      //reset voter preference, reset the preference string
      arrVoter[i].preference.clear();
      for (int k = 0; k < numCandidate; k++)
      {
         arrVoter[i].preference.push_back(rand[k]);
         //cout << arrVoter[i].preference[k] << endl;
      }
      //cout << endl;   
   }
}

// for all strategy
// switch
// index breaks tie
// return a ballot
vector<int> strategyBallot(const candidate* arrCandidate, voter v, int numCandidate)
{
   int firstPlacer, secondPlacer;
   vector<int> ballot;
   for (int i = 0; i < numCandidate; i++)
   {
      ballot.push_back(0);
   }
   firstPlacer = 0;
   for (int i = 0; i < numCandidate; i += 1)
   {
      if (arrCandidate[i].vote > arrCandidate[firstPlacer].vote ||
          (arrCandidate[i].vote == arrCandidate[firstPlacer].vote && i < firstPlacer))
      {
         firstPlacer = i;
      }
   }
   secondPlacer = firstPlacer == 0 ? 1 : 0;
   for (int i = 0; i < numCandidate; i += 1)
   {
      if (i != firstPlacer &&
          (arrCandidate[i].vote > arrCandidate[secondPlacer].vote ||
           (arrCandidate[i].vote == arrCandidate[secondPlacer].vote && i < secondPlacer)))
      {
         secondPlacer = i;
      }
   }
   switch(v.strat.type)
   {
      // successful
      case 'F':
      case 'f':
         // use number for candidates and voters
         int firstPrefF;
         firstPrefF = 0;
         for (int i = 0; i < numCandidate; i++)
         {
            if (v.preference[i] > v.preference[firstPrefF])
            {
               firstPrefF = i;
            }
         }
         ballot.at(firstPrefF) = 1;
         break;

      // successful
      case 'H':
         for (int i = 0; i < numCandidate; i++)
         {
            if (v.preference[i] >= (numCandidate / 2))
            {
               ballot.at(i) = 1;
            }
         }
         break;

      // successful
      case 'U':
         for (int i = 0; i < numCandidate; i++)
         {
            if (v.preference[i] != 0)
            {
               ballot.at(i) = 1;
            }
         }
         break;

      // successful
      case 'D':
      {
         ballot.at(firstPlacer) = 1;

         for (int i = 0; i < numCandidate; i++)
         {
            if (v.preference[i] > v.preference[firstPlacer])
            {
               ballot.at(i) = 1;
            }
         }
         break;
      }

      // successful
      case 'Q':
      {
         for (int i = 0; i < numCandidate; i++)
         {
            if (v.preference[i] > v.preference[firstPlacer])
            {
               ballot.at(i) = 1;
            }
         }
         break;
      }

      // successful
      case 'T':
      {
         for (int j = 0; j < numCandidate; j++)
         {
            if (v.preference[j] >= v.preference[firstPlacer] && v.preference[j] >= v.preference[secondPlacer])
            {
               ballot.at(j) = 1;
            }
         }

         break;
      }

      // successful
      case 'Y':
      {
         for (int j = 0; j < numCandidate; j++)
         {
            if (v.preference[j] > v.preference[firstPlacer] || v.preference[j] > v.preference[secondPlacer])
            {
               ballot.at(j) = 1;
            }
         }
         break;
      }

      // successful
      case 'A':
      {
         for (int j = 0; j < numCandidate; j++)
         {
            if (v.preference[j] > v.preference[firstPlacer])
            {
               ballot.at(j) = 1;
            }
         }
         if (v.preference[firstPlacer] > v.preference[secondPlacer])
         {
            ballot.at(firstPlacer) = 1;
         }
         break;
      }

      // successful
      case 'd':
         ballot.at(firstPlacer) = 1;
         break;

      // successful
      case 'q':
         int preferred;
         preferred = 0;
         for (int i = 0; i < numCandidate; i++)
         {
            if (v.preference[i] > v.preference[firstPlacer] &&
                (v.preference[preferred] <= v.preference[firstPlacer] || arrCandidate[i].vote > arrCandidate[preferred].vote))
            {
               preferred = i;
            }
         }
         if (v.preference[preferred] > v.preference[firstPlacer])
         {
            ballot.at(preferred) = 1;
         }
         break;

      // successful
      case 'a':
         //vote between firstPlacer and secondPlacer
         if (v.preference[firstPlacer] > v.preference[secondPlacer])
         {
            ballot.at(firstPlacer) = 1;
         }
         else
         {
            ballot.at(secondPlacer) = 1;
         }
         break;

      case 'E':
      {
         vector<double> v1;
         vector<double> v2;
         vector<double> v3;
         vector<double> prefVal;
         double expVal;
         double total;
         for (int i = 0; i < numCandidate; i++)
         {
            v1.push_back(arrCandidate[i].vote + v.strat.y);
            v2.push_back(pow(v1[i], v.strat.x));
         }
         total =  accumulate(v2.begin(), v2.end(), 0);
         expVal = 0.0;
         for (int i = 0; i < numCandidate; i++)
         {
            v3.push_back(v2[i] / total);
            prefVal.push_back(v.preference[i] + 1);
            expVal += v3[i] * prefVal[i];
         }

         for (int i = 0; i < numCandidate; i++)
         {
            if (prefVal[i] > expVal)
            {
               ballot.at(i) = 1;
            }
         }
         break;
      }
         
      case 'W': // Warren Smith's moving-average strategy
      {
         vector<int> leaders = vector<int>(numCandidate);
         for (int i = 0; i < numCandidate; i += 1)
         {
            leaders.at(i) = i;
         }
         for (int i = 0; i < numCandidate; i += 1)
         {
            for (int j = i + 1; j < numCandidate; j += 1)
            {
               if (arrCandidate[i].vote < arrCandidate[j].vote ||
                   (arrCandidate[i].vote == arrCandidate[j].vote && i > j))
               {
                  int temp = leaders.at(i);
                  leaders.at(i) = leaders.at(j);
                  leaders.at(j) = temp;
               }
            }
         }
         int totalPref = v.preference[leaders.at(0)] + v.preference[leaders.at(1)];
         int numPrefs = 2;
         for (int j = 0; j < numCandidate; j += 1)
         {
            if (v.preference[j] * numPrefs > totalPref)
            {
               ballot.at(j) = 1;
            }
            if (j > 1)
            {
               totalPref += v.preference[leaders.at(j)];
               numPrefs += 1;
            }
         }
         break;
      }
   }
   return ballot;
}

//function to run an election with these voters and these candidates using different strategies
// dont use cout and cin
void runElection(candidate* arrCandidate, voter* arrVoter, int numCandidate, int numVoter, int roundLimit)
{
   //vector<int> temp;
   int round;
   for (int i = 0; i < numCandidate; i++)
   {
      arrCandidate[i].vote = 0;
   }
   for (int j = 0; j < numVoter; j++)
   {
      arrVoter[j].ballot = vector<int>(numCandidate, 0);
      //temp = vector<int>(numCandidate, 0);
   }
   for (round = 0; round < roundLimit; round++)
   {
      for (int j = 0; j < numVoter; j++)
      {
         //ballot = strategy(arrCandidate, arrVoter[j], numCandidate);
         arrVoter[j].ballot = strategyBallot(arrCandidate, arrVoter[j], numCandidate);
         //temp = arrVoter[j].ballot;
         for (int i = 0; i < numCandidate; i++)
         {
            arrCandidate[i].vote = 0;
            for (int k = 0; k < numVoter; k++)
            {
               arrCandidate[i].vote += arrVoter[k].ballot.at(i);
            }
         }
         
      }
      
      /*for (int j = 0; j < numVoter; j++)
      {
         if (arrVoter[j].ballot == temp)
         {
            round = roundLimit - 1;
         }
      }*/
   }
}

// function to compare between 2 strategies by running many elections
// return a number that show which strategy is better and by how much
// positive: strat1 better, negative: strat2 better
int compareStrategy(candidate* arrCandidate, voter* arrVoter, int numCandidate, int numVoter, int numElection, int roundLimit, strategy strat1, strategy strat2)
{
   int first1, first2;
   
   int stratPoint = 0;
   for (int i = 0; i < numElection; i++)
   {
      voterPreference(arrVoter, numVoter, numCandidate);
      for (int j = 0; j < numVoter; j++)
      {
         arrVoter[j].strat.type = strat1.type;
         arrVoter[j].strat.x = strat1.x;
         arrVoter[j].strat.y = strat1.y;
      }
      runElection(arrCandidate, arrVoter, numCandidate, numVoter, roundLimit);
      first1 = 0;
      for (int k = 0; k < numCandidate; k++)
      {
         
         if (arrCandidate[k].vote > arrCandidate[first1].vote)
         {
            first1 = k;
         }
      }
      
      for (int j = 0; j < numVoter; j++)
      {
         arrVoter[j].strat.type = strat2.type;
         arrVoter[j].strat.x = strat2.x;
         arrVoter[j].strat.y = strat2.y;
         runElection(arrCandidate, arrVoter, numCandidate, numVoter, roundLimit);
         first2 = 0;
         for (int k = 0; k < numCandidate; k++)
         {
            if (arrCandidate[k].vote > arrCandidate[first2].vote)
            {
               first2 = k;
            }
         }
         // stratPoint[j] 
         stratPoint += arrVoter[j].preference[first1] - arrVoter[j].preference[first2];
         arrVoter[j].strat.type = strat1.type;
         arrVoter[j].strat.x = strat1.x;
         arrVoter[j].strat.y = strat1.y;
      }
   }
   
   return stratPoint;
}

int main()
{
	string s;
	//int v;
   int numCandidate, numVoter, numElection;
   int stratPoint, roundLimit;
   vector<int> preference;
   vector<char> strategies = {'F', 'H', 'U', 'D', 'Q', 'T', 'Y', 'A', 'f', 'd', 'q', 'a', 'E', 'W'};
   srandom(time(0));
   cout << "Enter number of candidates" << endl;
   cin >> numCandidate;
   cout << "Enter number of voters" << endl;
   cin >> numVoter;
   cout << "Enter number of elections" << endl;
   cin >> numElection;
   candidate arrCandidate[numCandidate];
   voter arrVoter[numVoter];
   voter v;
   strategy strat1, strat2;
   
   voterPreference(arrVoter, numVoter, numCandidate);
   for (int j = 0; j < numVoter; j++)
   {
      cout << "Voter number " << j+1 << " 's preference" << endl;
      for (int k = 0; k < numCandidate; k++)
      {
         cout << arrVoter[j].preference[k] << endl;
      }
      cout << endl;
   }
   
   cout << "Enter 2 values of x and y for the strategies " << endl;
   cin >> strat1.x;
   cin >> strat1.y;
   cin >> strat2.x;
   cin >> strat2.y;
   cout << "Enter the limit number of rounds " << endl;
   cin >> roundLimit;

      for (int j = 0; j < static_cast<int>(strategies.size()); j++)
      {
         strat1.type = strategies.at(j);
         cout << "When everyone else uses strategy " << strat1.type << "(" << strat1.x << ", " << strat1.y << "), ";
         for (int k = 0; k < static_cast<int>(strategies.size()); k++)
         {
            strat2.type = strategies.at(k);
            stratPoint = compareStrategy(arrCandidate, arrVoter, numCandidate, numVoter, numElection, roundLimit, strat1, strat2);
            if (stratPoint > 0)
            {
              cout << "strategy " << strat1.type << "(" << strat1.x << ", " << strat1.y << ") seems better than strategy " << strat2.type << "(" << strat2.x << ", " << strat2.y << ").\n";
              cout << stratPoint << ").\n";
            }
            else if (stratPoint < 0)
            {
              cout << "strategy " << strat2.type << "(" << strat2.x << ", " << strat2.y << ") seems better than strategy " << strat1.type << "(" << strat1.x << ", " << strat1.y << ").\n";
              cout << stratPoint << ").\n"; 
            }
            else
            {
              cout << "strategies " << strat1.type << " and " << strat2.type << " seem the same.\n";
            }
         }
      }
	return 0;
}

/*
strategy A

    A B C   round1   round2   round3
v0: 0 1 2   BC       BC       BC
v1: 0 2 1   B        B        B
v2: 2 1 0   AB       A        A

B2, A1, C1

*/
