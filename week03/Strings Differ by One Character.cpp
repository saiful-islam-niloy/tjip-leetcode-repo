#include <bits/stdc++.h>
using namespace std;

class StringProblem {
   public:
    bool isDifferbyOneChar(vector<string> &lst) {
        int size = lst.size();
        for (int i = 0; i<size; i++){
            string first = lst[i];
            for (int j = i+1; j < size; j++) {
                string second = lst[j];

                int diff = 0;

                for (int k = 0; k<first.size(); k++)
                    if (first[k] != second[k]) diff++;
                if (diff == 1) return true;
            }
        }
      return false;
    }
};

int main(){
  vector<vector<string>> arr ={
     { "abcd", "acbd", "aacd"},
     {"ab", "ac", "aa"},
     {"ab","cd","yz"}};
  StringProblem sp;
  for(int i=0; i<arr.size(); i++)
    cout << sp.isDifferbyOneChar(arr[i]) << endl;
  return 0;
}