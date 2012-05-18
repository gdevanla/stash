/*
 *
 * This program accepts a input from STDIN with following format
 *
 * n
 * name integer
 * name integer
 * .
 * .
 * .
 * .
 * .
 * 
 *
 * where n=no of items to use while findig the set that sums to zero.
 * name = name of item
 * integer = the value of item.
 *
 * Here the program has been written for a interview challenge that
 * asks to calculate a combinations of items whose total calorie value sums to
 * zero.
 *
 * The program can be generalized to any subset sum problem.
 *
 *


#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <functional>

#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=b;--i)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
 
#define debug(x) //cerr<< #x << " = " << (x) << "\n";
#define debuga(x,l) cerr<< #x << " = " << for(int i=0 ; i < l; i++ ) { cerr << x[i] << " "; } cout << "\n";
#define debugv(v) cerr << #v << " = "; FOREACH(it,v) cerr << *it <<","; cerr << "\n";
#define SIZE(a)  (int(a.size()))
#define SIZEOFA( a ) (sizeof( a ) / sizeof( a[ 0 ] )) 


#define MAX_ITEMS 50
#define MAX_CALORIES 100000 //assumes each item has calories value between -2000 and 2000 calories

using namespace std;

int n=0;
string names[MAX_ITEMS];
int calories[MAX_ITEMS];
bool take[MAX_ITEMS];

int caltable[MAX_ITEMS+1][MAX_CALORIES+1];

int main()
{

  //get input
  cin >> n;
  int total=0;
  int shift=0;

  //populate names and calories
  for (int i = 1; i <= n; i++) {
    cin >> names[i] >> calories[i];
    if ( calories[i] < 0 )
    {
      shift = shift + calories[i];
    }
    else
    {
      total = total + calories[i];
    }

  }

  // If sum of calories of all items sums up to zero
  // just take everything and have fun!
  if ( total+shift == 0 )
  {
    cout << "Take All" << endl;
    return 0;
  }

  //the most negative value possible would be the 0 index in the array.Hence
  //shift
  shift = (-shift);
  //This is always possible. No item, no calorie.
  caltable[0][shift]=1;  
  for (int i = 1; i <= n; i++) {
    {
      for ( int j = 0 ; j <= total+shift ; j++ )
      {
        int value = j - shift;
        int remaining = value-calories[i];
        
        if ( remaining < -shift || remaining > total 
            || caltable[i-1][remaining+shift] == 0 ) 
        {
          // in case taking item does not produce j,
          // copy over the value form previous item that us [i-1,j]
          caltable[i][j]= (caltable[i-1][j] == 1)?2:caltable[i-1][j];
          continue;
        }
        else
        {
          caltable[i][j] = 1;
        }
      }
    }
  }

    /*
    cout << " " << endl;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= total+shift; j++) {
        cout  << caltable[i][j] << "" ;
      }
      cout << endl;
    }*/

    int temp = shift; //this would be the index of j that equivalent to 0.
    //cout << temp << endl; 
    // walk through the array and mark all the items
    // that can be taken so that sum equals 0.
    for ( int i=n;i>=0;i--)
    {
      if ( caltable[i][temp] == 0 ) { cout << "No solution"; break; }
      else if ( caltable[i][temp] == 1 ) 
      {
        //cout << names[i] << " " << temp << " " << i << " "  << caltable[i][temp] << " " << endl;
        take[i]=true;
        temp = temp - calories[i];
      }
      else if ( caltable[i][temp] == 2 ) 
      {
        continue;
      }
    }

    for (int i = 0; i <= n; i++) {
      if ( take[i] == true ) cout << names[i] << endl;
    }
}
