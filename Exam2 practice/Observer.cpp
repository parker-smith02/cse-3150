#include <iostream>
#include <vector>
#include <string>

class Observer {
    public:
        virtual void Update(const std::string &newMessage) = 0;
};

class Subject {
    public:
        virtual void Attach(Observer *observer) = 0;

        virtual void Detach(Observer *observer) = 0;

        virtual void Notify() = 0;
};


class NewsSource : public Subject {
    public:
        NewsSource() : numSubs(0) {}

        virtual void Attach(Observer *observer) {
            subList.push_back(observer);
            numSubs++;
        }

        virtual void Detach(Observer *observer) {
            subList.erase(std::remove(subList.begin(), subList.end(), observer), subList.end());
            numSubs--;
        }

        virtual void Notify() {
            for (auto x : subList) {
                x->Update(curMessage);
            }
        }

        virtual void SetMessage(const std::string &newMessage) {
            curMessage = newMessage;
            Notify();
        }
        
    private:
        std::vector<Observer *> subList;
        int numSubs;
        std::string curMessage;
};

class Subscriber : public Observer {
    public:
        Subscriber() : news(NULL) {}

        virtual void SubscribeToNews(NewsSource *newsSource) {
            news = newsSource;
            news->Attach(this);
        }

        virtual void UnsubscribeToNews() {
            news->Detach(this);
        }

        virtual void Update(const std::string &message) {
            std::cout << "New message: " << message << std::endl;
        }
    private:
        NewsSource *news;
};


int main() {

    NewsSource news;
    Subscriber sub1, sub2, sub3;

    sub1.SubscribeToNews(&news);
    news.SetMessage("Hello World!");
    sub2.SubscribeToNews(&news);
    news.SetMessage("Hello World Again!");
    sub3.SubscribeToNews(&news);
    news.SetMessage("Hello World Again Again!");
    sub3.UnsubscribeToNews();
    news.SetMessage("Hello World Again Again Again!");
    




}