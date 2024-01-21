#include <iostream>
#include <memory>

using namespace std;

class Song {
public:
    string title;
    Song(string _title): title{_title} {};
};

void fn(shared_ptr<Song> sp) {
    cout << "in fn: " << sp.use_count() << "\n";    //3
}

int main() {
    unique_ptr<Song> ps1 = make_unique<Song>("a");
    cout << ps1->title << "\n";
    cout << (*ps1).title << "\n";

    unique_ptr<Song> ps2 = std::move(ps1);
    cout << ps2->title << "\n";
    cout << std::boolalpha << (ps1 == nullptr) << "\n";

    shared_ptr<Song> ps3 = make_shared<Song>("b");
    cout << ps3.use_count() << "\n";    //1
    shared_ptr<Song> ps4 = ps3;
    cout << ps3.use_count() << "\n";    //2
    cout << ps4.use_count() << "\n";    //2
    shared_ptr<Song> ps5(nullptr);
    ps5.swap(ps4);
    cout << "---\n";
    cout << ps3.use_count() << "\n";    //2
    cout << ps4.use_count() << "\n";    //0
    cout << ps5.use_count() << "\n";    //2
    fn(ps5);
    cout << ps5.use_count() << "\n";    //2
    
    // // bad code - will delete obj after ps6 dies
    // // and ps5 etc will become invalid and fail
    // shared_ptr<Song> ps6(ps5.get());
    // cout << ps6.use_count() << "\n";    // 1

    shared_ptr<Song> ps7(new Song("c"));
    cout << ps7->title << " | " << ps7.use_count() << "\n"; // c | 1

    return 0;
}