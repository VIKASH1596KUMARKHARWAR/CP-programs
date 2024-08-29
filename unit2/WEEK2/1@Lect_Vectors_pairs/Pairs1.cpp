#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    /*pair<int ,int>p;
    p.first=5;
    p.second=6;
    cout<<p.first<<" "<<p.second;
    */

   /*pair<int ,int>p(5,6) ;//initialisation and declaration
    cout<<p.first<<" "<<p.second;*/

   /*pair<int ,int>p={6,12} ;
    cout<<p.first<<" "<<p.second;*/

   /*pair<int ,int>p=make_pair(61,12) ;
    cout<<p.first<<" "<<p.second;*/


/*sort wrt to marks
9 varun
56 garima
79 vikash
13 anu
13 kamini ==> {tie breaker} when first values is equal, check with the second values*/

     int n;
     cin>>n;

    vector<pair<int,string>>studentList;

    for(int i =0;i <n; i++){
        int score;
        string name;

        cin>>score>>name;
        studentList.push_back({score,name});
    }


    sort(studentList.begin(),studentList.end());

    for(int i = 0; i<n; i++){
        cout<< studentList[i].first <<" " << studentList[i].second<<endl;
    }
    
}
