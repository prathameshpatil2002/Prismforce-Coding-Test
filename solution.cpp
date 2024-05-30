#include <bits/stdc++.h>
using namespace std;

// For Recharge Purpose
int AbhimanyuPowerGlobal;

/**
 * enemies : vector of power of enemy in circles
 * i : current circle / enemy index
 * a : available skips
 * b : available recharges
 * dp : dp vector to store state
 * @return maximum power corresponding state
 **/
int canAbhimanyuCrossChakravyuh(vector<int> &enemies, int i, int p, int a, int b, vector<vector<vector<int>>> &dp)
{
   // Abhimanyu covered all circles
   if (i == 11)
   {
      return p;
   }

   // memo of recursive state
   if (dp[i][a][b] != -1)
   {
      return dp[i][a][b];
   }
   if (enemies[i] > p)
   {
      // recharging
      if (b)
      {
         dp[i][a][b] = max(dp[i][a][b], canAbhimanyuCrossChakravyuh(enemies, i, AbhimanyuPowerGlobal, a, b - 1, dp));
      }
      // skipping
      if (a)
      {
         // special condition of circle k3 and k7 enemies of regenrate
         if (i == 2 || i == 6)
         {
            enemies[i + 1] += (enemies[i] + enemies[i] / 2);
         }
         dp[i + 1][a][b] = max(dp[i + 1][a][b], canAbhimanyuCrossChakravyuh(enemies, i + 1, p, a - 1, b, dp));
      }
   }
   // fighting enemy
   else
   {
      dp[i + 1][a][b] = max(dp[i + 1][a][b], canAbhimanyuCrossChakravyuh(enemies, i + 1, p - enemies[i], a, b, dp));
   }
   return dp[i][a][b];
}

int main()
{
   int a; // Allowed Number of Skips
   int b; // Allowed Number of Recharges

   cin >> AbhimanyuPowerGlobal >> a >> b;
   vector<int> enemies(11);
   for (int i = 0; i < 11; i++)
   {
      cin >> enemies[i];
   }

   vector<vector<vector<int>>> dp(12, vector<vector<int>>(a + 1, vector<int>(b + 1, -1)));

   int ans = canAbhimanyuCrossChakravyuh(enemies, 0, AbhimanyuPowerGlobal, a, b, dp);

   // checking is there any combination of a and b leading to non negative power
   int nonNegativePower = 0;

   for (int i = 0; i <= a; i++)
   {
      for (int j = 0; j <= b; j++)
      {
         if (dp[11][i][j] >= 0)
         {
            nonNegativePower++;
         }
      }
   }
   if (nonNegativePower)
   {
      cout << "YES";
   }
   else
   {
      cout << "NO";
   }
   return 0;
}
