#include <cstdio>
#include "DynamicArray.h"

int main(int argc, const char *argv[])
{
    AlgoAdel::DynamicArray<int> arr;
    fprintf(stdout, "size:[%lu]\n", arr.size());
    fprintf(stdout, "capacity:[%lu]\n", arr.capacity());
    fprintf(stdout, "is_empty:[%d]\n", arr.is_empty());
    arr.prettyPrint();

    logStartLine("INSERTING!!");
    arr.insert(0, 9);
    arr.prettyPrint();
    arr.insert(1, 99);
    arr.insert(2, 999);
    arr.prettyPrint();
    arr.insert(12, 9999);
    arr.prettyPrint();
    fprintf(stdout, "size:[%lu]\n", arr.size());
    fprintf(stdout, "capacity:[%lu]\n", arr.capacity());
    fprintf(stdout, "is_empty:[%d]\n", arr.is_empty());

    logStartLine("PUSH !!");
    arr.push(123);
    arr.prettyPrint();
    arr.push(456);
    arr.prettyPrint();
    fprintf(stdout, "size:[%lu]\n", arr.size());
    fprintf(stdout, "capacity:[%lu]\n", arr.capacity());
    fprintf(stdout, "is_empty:[%d]\n", arr.is_empty());

    logStartLine("PREPEND !!");
    arr.prepend(147);
    arr.prepend(985);
    arr.prettyPrint();
    fprintf(stdout, "size:[%lu]\n", arr.size());
    fprintf(stdout, "capacity:[%lu]\n", arr.capacity());
    fprintf(stdout, "is_empty:[%d]\n", arr.is_empty());

    logStartLine("POP !!");
    arr.pop();
    arr.prettyPrint();
    arr.pop();
    arr.prettyPrint();
    fprintf(stdout, "size:[%lu]\n", arr.size());
    fprintf(stdout, "capacity:[%lu]\n", arr.capacity());
    fprintf(stdout, "is_empty:[%d]\n", arr.is_empty());

    logStartLine("DELETEITEM !!");
    arr.deleteItem(5);
    arr.prettyPrint();

    arr.deleteItem(0);
    arr.prettyPrint();
    fprintf(stdout, "size:[%lu]\n", arr.size());
    fprintf(stdout, "capacity:[%lu]\n", arr.capacity());
    fprintf(stdout, "is_empty:[%d]\n", arr.is_empty());

    return 0;
}