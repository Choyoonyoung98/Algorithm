//
//  main.cpp
//  JustThatSong17683
//
//  Created by 조윤영 on 2021/03/16.
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;
string transferToSimple(string song) {
    string result = "";
    for(int i=0; i<song.size(); i++) {
        if(i != song.size()-1 && song[i+1] =='#') {
            result += tolower(song[i]); //소문자로 대체해서 넣는다!
            i++;
        } else result += song[i];
    }
    
    return result;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int time = 0;
    for(string music: musicinfos) {
        vector<string> infos;
        string temp = "";
        for(char m: music) {
            if(m == ',') {
                infos.push_back(temp);
                temp = "";
            } else temp += m;
        }
        infos.push_back(temp);
        
        string startTime = infos[0];
        string endTime = infos[1];
        string title = infos[2];
        string song = infos[3];
        string startH = "";
        string endH = "";
        string startM = "";
        string endM = "";
        bool findH = false;
        for(int i=0; i<5; i++) {
            if(startTime[i] == ':') findH = true;
            else if(findH) {
                startM += startTime[i];
                endM += endTime[i];
            } else {
                startH += startTime[i];
                endH += endTime[i];
            }
        }
        
        string simpleSong = transferToSimple(song);
        int playTime = (stoi(endH) - stoi(startH)) * 60 + (stoi(endM) - stoi(startM));
        string playList = "";
        for(int i=0; i <playTime / simpleSong.size(); i++) playList += simpleSong;
        playList += simpleSong.substr(0, playTime % simpleSong.size());
        
        string simpleM = transferToSimple(m);
        for(int i=0; i<playList.size(); i++) {
            int idx = 0;
            bool findAnswer = true;
            if(playList[i] == simpleM[0]) {
                for(int j=i; j<i+simpleM.size(); j++) {
                    char A = simpleM[idx++];
                    char B = playList[j];
                    if(A != B) {
                        findAnswer = false;
                        break;
                    }
                }
                if(findAnswer && playTime > time) {
                    time = playTime;
                    answer = title;
                }
            }
        }
    }
    return answer;
}
    
int main(int argc, const char * argv[]) {
    string m = "ABC";
    vector<string> musicincos = {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"};
    cout<< solution(m, musicincos);
    return 0;
}
