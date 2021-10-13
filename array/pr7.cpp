#include <bits/stdc++.h>
using namespace std;
void print_vector(vector<auto> v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << v[i] << ", ";
   }
   cout << "]"<<endl;
}
class Solution {
   public:
   vector<int> beautifulArray(int N) {
      vector <int> ret;
      ret.push_back(1);
      while(ret.size() < N){
         vector <int> temp;
         for(int i = 0; i < ret.size(); i++){
            if(ret[i] * 2 - 1 <= N) temp.push_back(ret[i] * 2 - 1);
         }
         for(int i = 0; i < ret.size(); i++){
            if(ret[i] * 2 <= N)temp.push_back(ret[i] * 2 );
         }
         ret = temp;
      }
      return ret;
   }
};
main(){
   Solution ob;
   print_vector(ob.beautifulArray(6));
}
