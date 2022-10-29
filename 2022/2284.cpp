#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <climits>
#include <unordered_map>
#include "algorithm"
#include "cstring"

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

string largestWordCount(vector<string> &messages, vector<string> &senders)
{

  unordered_map<string, int> m1;

  for (int i = 0; i < messages.size(); i++)
  {
    int words = count(begin(messages[i]), end(messages[i]), ' ');
    m1[senders[i]] += words;
  }
  string name = "";
  int maxval = INT_MIN;

  for (auto [key, val] : m1)
  {
    cout << key << " " << val << "\n";
  }

  int itr = 0;
  for (auto [key, val] : m1)
  {
    cout << "here key is " << key << " name is " << name << " val is " << val << " maxval is " << maxval << "\n";
    if ((maxval < val) || (maxval == val && key > name))
    {
      if (key > name)
        cout << "true\n";
      maxval = val;
      name = key;
    }
  }
  return name;
}

int main()
{
  if ("RclslxNRo" < "ofcOzZ")
    cout << "o is bigger than r\n";
  vector<string> messages = {"Wq Hb Iw HAq WhX PXj XC o ll",
                             "ELw L mgN K qn yEP TmJ HGC TRK",
                             "q kYO E dF l js q",
                             "HV Mg Oic MT Rj yx CcO",
                             "G Br d tTw S Rbt",
                             "D",
                             "bN y P LDX yq h Dg h",
                             "caB J VDr du UD Ddp",
                             "b DJI bR F Xjt",
                             "m vyD Kfq qw",
                             "aH",
                             "i G SiF tk uzO LK JdE sO",
                             "Fk lS H wW uq TmP TyY ZhN",
                             "X",
                             "iE bXc tf dZV",
                             "G QYVc",
                             "ydA VPV",
                             "pei k zY dXi",
                             "OAS rLN H h w Lhd aj lj RxR xf"};

  vector<string> senders = {"yHfc",
                            "ek",
                            "aMatAkNUHm",
                            "Bz",
                            "RclslxNRo",
                            "oD",
                            "cRRZX",
                            "HMzf",
                            "RclslxNRo",
                            "gUcyyFXiqc",
                            "cRRZX",
                            "ICUHL",
                            "Bn",
                            "OTBiDoT",
                            "iE",
                            "xPjhTIV",
                            "gUcyyFXiqc",
                            "Cmfa",
                            "ofcOzZ"};
  cout << "ans is " << largestWordCount(messages, senders);
  return 0;
}
