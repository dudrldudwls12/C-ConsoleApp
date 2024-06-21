#include <iostream>

using namespace std;
#define SIZE 6
template<typename KEY, typename VALUE>
class HashTable
{
private:
    struct Node
    {
        KEY key;
        VALUE value;
        Node * next;
    };
    struct Bucket
    {
        int count;
        Node* head;
    };
public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            bucket[i].count = 0;
            bucket[i].head = nullptr;
        }
    }
};
int main()
{
 
    return 0;
}