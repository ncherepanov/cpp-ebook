
#include <array>
#include <iomanip>
#include <iostream>

using namespace std;

const int MAX_USER = 100000;
const int MAX_PAGES = 1000;

struct Book {
    double Part(int user) const;
    void Print(int user) const; 
    void AddUserPage(int user, int page);
    void Commander();
    std::array<int, MAX_USER> user_page_{};
    std::array<int, MAX_PAGES> page_num_{};
};

int main() {
    Book book;
    book.Commander();
    return 0;
}

void Book::Commander() {
    int query_count;
    cin >> query_count;
    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        int user;
        cin >> query_type >> user;
        if (query_type == "READ") {
            int page;
            cin >> page;
            AddUserPage(user, page);
        } 
        else
            Print(user);
    }
}

void Book::AddUserPage(int user, int page) {
    for (int i = user_page_[user-1]; i < page; ++i)
        ++page_num_[i];
    user_page_[user-1] = page;
}

void Book::Print(int user) const {
    cout << setprecision(6) << Part(user) << '\n';
}

double Book::Part(int user) const {
    if(user_page_[user-1] == 0)
        return 0.;
    else if(page_num_[0] == 1)
        return 1.;
    return (page_num_[0] - page_num_[user_page_[user - 1] - 1]) * 1.0/(page_num_[0] - 1);
}

/*
//input
12
CHEER 5
READ 1 10
CHEER 1
READ 2 5
READ 3 7
CHEER 2
CHEER 3
READ 3 10
CHEER 3
READ 3 11
CHEER 3
CHEER 1

//output
0
1
0
0.5
0.5
1
0.5
*/
