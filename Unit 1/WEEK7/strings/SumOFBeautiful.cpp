#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int sumOfBaeautu(string s){
    int answer = 0,n =s.length();
    for(int len =2;len<=n;len++ ){
        vector<int> freq(26,0);
        for(int i =0;i <len;i++){
             freq[s[i]-'a']++;
        }
        int maxFrequency = 0,minFrequecncy=INT_MAX;
        for(int i = 0;i<26;i++){
            maxFrequency = max(maxFrequency,freq[i]);
            if(freq[i]){
                minFrequecncy=min(minFrequecncy,freq[i]);
            }
        }

        answer +=maxFrequency-minFrequecncy;

        for(int i=len;i< n;i++){
            freq[s[i-len]-'a']--;
            freq[s[i]-'a']++;

            int maxFrequency = 0,minFrequency=INT_MAX;
            for(int ch = 0;i<26;ch++){
            maxFrequency = max(maxFrequency,freq[ch]);
            if(freq[ch]){
                minFrequecncy=min(minFrequecncy,freq[ch]);
            }
        }

        answer +=maxFrequency-minFrequecncy;


        }
    }
    return answer;
}