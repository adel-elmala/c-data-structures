#include "logger.h"

#include "linkedList.h"
#include "linkedList.cpp"
using namespace std;
int main(int argc,char ** argv)
{
   logStartLine("start testing!");
    linkedList<int> lst1;
    // linkedList<int> lst2 = lst1;
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;

    
    
    logStartLine("test (push_front)");
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i = 0 ; i < 10 ; ++i)
        lst1.push_front(a[i]);
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    lst1.prettyPrint();
    
    logStartLine("test (operator[])");
    cout << "read first element:"<<lst1[0]<<endl;
    lst1[0] = 999;
    cout << "change first element\n";
    lst1.prettyPrint();

    // cout << lst1[1]<<endl;
    logEndLine();
    logStartLine("test (pop_front)");
    cout << "pop first element:"<< lst1.pop_front() << endl;
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    lst1.prettyPrint();
    
    logStartLine("test (push_back");
    
    int ll = 123;
    lst1.push_back(ll);
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    int l2 = 456;
    lst1.push_back(l2);
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    logEndLine();
    logStartLine("test (pop_back)");
    
    lst1.pop_back();
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    lst1.pop_back();
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    logEndLine();

    logStartLine("test (erase)");
    
    lst1.erase(0);
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    lst1.erase(5);
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
  
    lst1.erase(6);
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    

    lst1.erase(1);
    lst1.prettyPrint();
    cout << "size: " << lst1.size() << endl;
    cout << "empty?: " << lst1.empty() << endl;
    
    logEndLine();

    

    // lst2.prettyPrint();
}
