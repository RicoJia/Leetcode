#include "solution.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <unordered_set>

class Friend
{
public:
    std::vector<Friend*> friends;

    Friend(std::string email)
    {
        this->email = email;
    }
    
    void addFriendship(Friend* target)
    {
        friends.push_back(target);
        target->friends.push_back(this);
    }
    
    bool dfs(Friend* current, unordered_set<Friend*>& visited, Friend*& target){
        if (visited.find(current) != visited.end()){
            return false; 
        }
        if (current == target){
            return true;
        }
        visited.insert(current); 
        for (const auto& next: current->friends){
            if(dfs(next, visited, target)){
                return true; 
            }
        }
        return false; 
    }

    bool canBeConnected(Friend* target)
    {
        unordered_set<Friend*> visited{}; 
        if (dfs(this, visited, target)){
            return true;
        }
        return false;
    }

private:
    std::string email;
    bool visited_ = false; 
};

#ifndef RunTests
int main()
{
    Friend a("A");
    Friend b("B");
    Friend c("C");
    
    a.addFriendship(&b);
    b.addFriendship(&c);
    
    std::cout << a.canBeConnected(&c);
}
#endif
