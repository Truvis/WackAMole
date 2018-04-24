#ifndef KEEP_H
#define KEEP_H
#include <string>

class Keep
{
    public:
        Keep();
        virtual ~Keep();
        int getScore();
        void SaveScore(int NewScore);
        void ShowScore();

    protected:

    private:
         std::string name;
         int score;
         static std::string filename;
};

#endif // KEEP_H
