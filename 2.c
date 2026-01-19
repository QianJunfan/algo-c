/* leetcode 2 - add tow numbers
 * Jan 19, 2026
 */

/* failed */
#define N ListNode
#define ll long long 

ll cal(struct N *n)
{
        ll s = 0;
        ll f = 1;
        while (n != NULL) {
                s += (ll)n->val * f;
                f *= 10;
                n = n->next;
        }

        return s;
}

struct N *addTwoNumbers(struct N *l1, struct N *l2)
{
        ll s = cal(l1) + cal(l2);
        
        struct N h;
        struct N *p = &h;

        if (s == 0) {
                struct N *n = malloc(sizeof(struct N));
                n->next = NULL;
                n->val = 0;
                return n;
        }

        while (s != 0) {
                int t = s % 10;
                s /= 10;
                struct N *n = malloc(sizeof(struct N));
                n->val = t;
                p->next = n;
                p = n;
        }
        p->next = NULL;
        return h.next;
}


/* bf */
#define N ListNode

struct N *addTwoNumbers(struct N *l1, struct N *l2)
{
        struct N h;
        struct N *p = &h;

        int f = 0;
        while (l1 && l2 ) {
                int s = l1->val + l2->val;
                if (f) {
                        ++s;
                        f = 0;
                }

                if (s >= 10) {
                        f = 1;
                        s = s % 10;
                }
                
                struct N *n = malloc(sizeof(struct N));
                n->val = s;
                n->next = NULL;

                p->next = n;
                p = n;

                l1 = l1->next;
                l2 = l2->next;
        }

        struct N *t = l1 ? l1 : l2;

        while (t) {
                int s = t->val;
                if (f) {
                        ++s;
                        f = 0;
                }

                if (s >= 10) {
                        f = 1;
                        s = s % 10;
                }

                struct N *n = malloc(sizeof(struct N));
                n->val = s;
                n->next = NULL;
                p->next = n;
                p = n;
                t = t->next;
        }

        if (f) {
                struct N *n = malloc(sizeof(struct N));
                n->val  = 1;
                n->next = NULL;
                p->next = n;
                p = n;
        }
        return h.next;
}

/* better */
#define N ListNode

struct N *addTwoNumbers(struct N *l1, struct N *l2)
{
        struct N h;
        struct N *p = &h;
        int f = 0;

        while (l1 || l2 || f) {
                int s = f;

                if (l1) {
                        s += l1->val;
                        l1 = l1->next;
                }

                if (l2) {
                        s += l2->val;
                        l2 = l2->next;
                }

                f = s / 10;

                struct N *n = malloc(sizeof(struct N));
                n->val = s % 10;
                n->next = NULL;

                p->next = n;
                p = n;
        }

        return h.next;
}
