#include <iostream>
#include <vector>

using namespace std;

struct Disk{
    int size;
    int start;
};

int main(){

    vector<Disk> disks;

    /*
    //test
    disks.push_back({5,4});
    disks.push_back({2,1});
    */
    //input
    disks.push_back({13, 11});
    disks.push_back({5, 0});
    disks.push_back({17, 11});
    disks.push_back({3, 0});
    disks.push_back({7, 2});
    disks.push_back({19, 17});
    disks.push_back({11, 0});

    int t = 0;

    while(true){
        bool bounced = false;
        for(int i = 0; i < disks.size(); i++){
            Disk d = disks[i];
            if((d.start + i + 1 + t) % d.size){
                bounced = true;
            }
        }
        if(!bounced){
            cout << t << endl;
            return 0;
        }
        t++;
    }
    return 0;
}
