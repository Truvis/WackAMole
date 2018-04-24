#include "Keep.h"
#include <fstream>
#include <iostream>

using namespace std;
string Keep::filename = "scores.txt";

Keep::Keep()
{
    name = "TT";
    score = 0;
    getScore();
    ShowScore();
}

Keep::~Keep()
{
    //dtor
}

int Keep::getScore(){
    /// load the file
    ifstream ScoreFile;
    ScoreFile.open(filename);
    // open file
    if (ScoreFile.is_open()){
        ScoreFile >> score >> name;
        ScoreFile.close();
        return score;
    }
    // safety net if file is missing
    else {
        ofstream outfile(filename);
        outfile <<score<<" "<<name<<endl;
        outfile.close();
    }
    return 0;
}

void Keep::ShowScore(){
    cout<<"CURRENT HIGH PLAYER:"<<endl;
    cout<<score<<" "<<name<<endl;
    cout << "Press Enter to Play";
    cin.ignore();
}


void Keep::SaveScore(int NewScore){
    /// load the file
    if(NewScore>score){
        cout<<"NEW HIGH SCORE"<<endl;
        cout<<"Enter your name:"<<endl;
        cin>>name;
        ofstream ScoreFile;
        ScoreFile.open(filename);
            if (ScoreFile.is_open())
            {
                ScoreFile<<NewScore<<" "<<name<<endl;
                ScoreFile.close();
            }
    }
    // prevent the window from closing auto matically
    else {
        cout<<"No new score"<<endl;
        cout<<"Try again"<<endl;
        cin.ignore();
    }
}
