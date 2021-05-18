struct listNode
{
    /* data */
    int val;
    listNode *next;
    listNode() : val(0), next(nullptr) {}
    listNode(int x) : val(x), next(nullptr) {}
    listNode(int x, listNode *after) : val(x), next(after) {}
};

class solution
{
public:
    listNode *add_two_numbers(listNode *l1, listNode *l2)
    {
        listNode *l3 = nullptr;
        // listNode **node=&l3;
        listNode prehead(0), *p = &prehead;
        int count = 0;
        while (l1 != nullptr || l2 != nullptr || count > 0)
        {
            /* code */
            if (l1 != nullptr)
            {
                count += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                count += l2->val;
                l2 = l2->next;
            }
            // (*node) = new listNode(count % 10);
            // count = count / 10;
            p->next = new listNode(count % 10);
            count = count / 10;
            p = p->next;
        }
        return prehead.next;
    }
};
