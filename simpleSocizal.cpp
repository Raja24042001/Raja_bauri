#include <iostream>
#include <vector>
#include <string>

using namespace std;

class User {
public:
    string name;
    vector<User*> friends;

    User(const string& name) : name(name) {}

    void addFriend(User* newFriend) {
        friends.push_back(newFriend);
    }

    void displayFriends() const {
        cout << name << "'s friends: ";
        for (const auto& friendPtr : friends) {
            cout << friendPtr->name << " ";
        }
        cout << endl;
    }
};

class SocialNetwork {
private:
    vector<User> users;

public:
    void addUser(const string& name) {
        users.emplace_back(name);
        cout << name << " has been added to the network.\n";
    }

    User* findUser(const string& name) {
        for (auto& user : users) {
            if (user.name == name) {
                return &user;
            }
        }
        return nullptr;
    }

    void addFriendship(const string& name1, const string& name2) {
        User* user1 = findUser(name1);
        User* user2 = findUser(name2);
        if (user1 && user2) {
            user1->addFriend(user2);
            user2->addFriend(user1);
            cout << name1 << " and " << name2 << " are now friends.\n";
        } else {
            cout << "One or both users do not exist in the network.\n";
        }
    }

    void displayUser(const string& name) const {
        for (const auto& user : users) {
            if (user.name == name) {
                user.displayFriends();
                return;
            }
        }
        cout << name << " does not exist in the network.\n";
    }
};

int main() {
    SocialNetwork network;

    network.addUser("Alice");
    network.addUser("Bob");
    network.addUser("Charlie");

    network.addFriendship("Alice", "Bob");
    network.addFriendship("Alice", "Charlie");

    network.displayUser("Alice");
    network.displayUser("Bob");

    return 0;
}