#include "logger.h"

#include "linkedList.h"
#include "linkedList.cpp"
using namespace std;
int main(int argc,char ** argv)
{
   logStartLine("start testing!");
    linkedList<int> lst1;
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    // int a[11] = {1,2,3,4,5,6,7,8,9,10};
    // for(int i = 0 ; i < 11 ; ++i)
        // lst1.push_front(a[0]);
    int a = 50;
    lst1.push_front(a);
    cout << "size: " << lst1.size() << endl;

    cout << lst1[0]<<endl;

}
