#include "Rating.h"

int Rating::GetNumberOfReviews()
{
    return _numberOfReviews;
}

int Rating::GetSumOfTheRatings()
{
    return _sumOfTheRatings;
}

double  Rating::GetAverage()
{
    return (double)_sumOfTheRatings / (double)_numberOfReviews;		//­pºâ¥­§¡
}

void Rating::AddNumberOfReviews()
{
    _numberOfReviews++;
}
void Rating::AddSumOfTheRatings(int rate)
{
    _sumOfTheRatings += rate;
}