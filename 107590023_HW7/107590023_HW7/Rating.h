#ifndef RATING_H
#define RATING_H
#include <string>

using namespace std;

class Rating
{
    public:
        void AddNumberOfReviews();				//review總數加一
        void AddSumOfTheRatings(int rate);		//加入評價總和
        int GetNumberOfReviews();				//紀錄共有幾個review
        int GetSumOfTheRatings();				//紀錄評價總和
        double GetAverage();					//取得平均並回傳

    private:
        int _numberOfReviews;
        int _sumOfTheRatings;
};

#endif
