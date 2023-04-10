#ifndef EC_TRANDING_NEWS_H
#define EC_TRANDING_NEWS_H
#include <vector>
#include <algorithm>
class ECTrendingNews;


// Subscriber interface. DON'T CHANGE THIS
class ECSubscriber
{
public:
	virtual ~ECSubscriber() {}
    virtual void Update() = 0;
    virtual int ContractCost() const = 0;
};

// pay-per click subscriber
class ECPayPerClickSubscriber : public ECSubscriber
{
public:
	ECPayPerClickSubscriber(ECTrendingNews &news) : news(news) {}
	virtual void Update();
	virtual int ContractCost() const { return 0; }
private:
	ECTrendingNews &news;
};

// Contract subscriber
class ECContractSubscriber : public ECSubscriber
{
public:
	ECContractSubscriber(ECTrendingNews &news);
	virtual void Update();
	virtual int ContractCost() const { return 100; }
private:
	ECTrendingNews &news;
};

// This is the subject
class ECTrendingNews
{
public:
	ECTrendingNews() : balance(0) {}
	~ECTrendingNews();
	// add a subscriber
	void Subscribe(ECSubscriber *pSub)
	{
		listObs.push_back(pSub);
	}
	// remove a subscriber
	void UnSubscribe(ECSubscriber *pSub)
	{
		listObs.erase(std::remove(listObs.begin(), listObs.end(), pSub), listObs.end());
	}
	// Notify news is available for view
	void Notify();
	// receive payment (assume in whole dollar)
	void ReceivePayment(int amount)
	{
		balance += amount;
	}
	// Get total revenue received
	int GetTotRevenue() const {return balance;}
	
private:
	std::vector<ECSubscriber *> listObs;
	int balance;
};


#endif
