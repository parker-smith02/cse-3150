#include "ECTrendingNews.h"

// Your code goes here
// pay-per click subscriber
void ECPayPerClickSubscriber::Update()
{
    news.ReceivePayment(1);
}

ECContractSubscriber::ECContractSubscriber(ECTrendingNews &news) : news(news)
{
    news.ReceivePayment(100);
}

// Contract subscriber


// This is the subject


// add a subscriber

// remove a subscriber

// Notify news is available for view
void ECTrendingNews :: Notify()
{
    for (auto x : listObs) {
        x->Update();
    }
}
// receive payment (assume in whole dollar)

// Get total revenue received
        
