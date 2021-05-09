#ifndef RATING_H
#define RATING_H
#include <string>

using namespace std;

class Rating
{
    public:
        void AddNumberOfReviews();				//review�`�ƥ[�@
        void AddSumOfTheRatings(int rate);		//�[�J�����`�M
        int GetNumberOfReviews();				//�����@���X��review
        int GetSumOfTheRatings();				//���������`�M
        double GetAverage();					//���o�����æ^��

    private:
        int _numberOfReviews;
        int _sumOfTheRatings;
};

#endif
