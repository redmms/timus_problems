#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <algorithm>
 
using namespace std;
 
 
template <int delta> struct ManacherBase{
private:
        vector<int> rad;
        vector<char> text;
        int i, n;
 
public:
        ManacherBase()
        {
                text.push_back('$');
                rad.push_back(0);
                text.push_back('$');
                rad.push_back(0);
                i = 2;
                n = 1;
        }
 
        void addLetter(char c)
        {
                text.push_back(0);
                rad.push_back(0);
 
                int s = i - rad[i] + delta;
                text[n + 1] = c;
                while(i + rad[i] <= n)
                {
                        rad[i] = min(rad[s + n - i - delta], n - i);
                        if(text[i - rad[i] - 1 + delta] == text[i + rad[i] + 1])
                        {
                                rad[i]++;
                                break;
                        }
                        i++;
                }
                n++;
        }
 
        int maxPal()
        {
                return (n - i) * 2 + 1 - delta;
        }
 
} ;
 
struct Manacher{
private:
        ManacherBase<0> manacherEven;
        ManacherBase<1> manacherOdd;
 
public:
        void addLetter(char c)
        {
                manacherEven.addLetter(c);
                manacherOdd.addLetter(c);
        }
 
        int maxPal()
        {
                return max(manacherEven.maxPal(), manacherOdd.maxPal());
        }
 
};
 
 
class Ukkonen
{
private:
        int _minUniqueSuffix;
        struct node
        {
                node *suff, *parent;
                map<char, node *> sons;
                int begpos;
                int *endpos;
                int depth;
                int len() {return *endpos - begpos;}
                node(node *p, int b, int *e, int d=0) : parent(p), begpos(b), endpos(e), depth(d) {}
        };
        struct inode
        {
                node *rnode;
                int off;
                inode(node *rnode, int off) : rnode(rnode), off(off) {}
        };
 
        vector<char> src;
        int *src_end;
        node *root;
        inode x;
        inode son(inode z, char c)
        {
                if (z.off != z.rnode->len() && src[z.rnode->begpos + z.off] == c)
                        return inode(z.rnode, z.off + 1);
                if (z.off == z.rnode->len() && z.rnode->sons.find(c) != z.rnode->sons.end())
                        return inode(z.rnode->sons[c], 1);
                return inode(0, 0);
        }
 
public:
 
        Ukkonen() : x(0, 0), src_end(new int(0))
        {
                x.rnode = root = new node(new node(0, -1, new int(0)), 0, new int(0));
                root->parent->suff = root;
                root->suff = root->parent;
        }
        ~Ukkonen() {}
 
        void addLetter(char c)
        {
                node *zprev = 0;
                src.push_back(c);
                (*src_end)++;
                root->parent->sons[c] = root;
                while (!son(x, c).rnode)
                {
                        if (x.off != x.rnode->len())
                        {
                                node *z = new node(x.rnode->parent, x.rnode->begpos, new int(x.rnode->begpos + x.off));
                                z->depth = z->parent->depth + z->len();
                                x.rnode->parent = x.rnode->parent->sons[src[x.rnode->begpos]] = z;
                                x.rnode->begpos = *z->endpos;
                                z->sons[src[*z->endpos]] = x.rnode;
                                x = inode(z, z->len());
                        }
                        if (zprev)
                                zprev->suff = x.rnode;
                        zprev = x.rnode;
                        x.rnode->sons[c] = new node(x.rnode, *src_end - 1, src_end);
 
                        node *p = x.rnode->parent->suff;
                        int off;
                        for (off = 0; off < x.off; off += max(p->len(), 1))
                                p = p->sons[src[x.rnode->begpos + off]];
                        x = inode(p, p->len() + x.off - off);
                }
                if (zprev && zprev != root)
                        zprev->suff = x.rnode;
                if (zprev != root)
                        x = son(x, c);
                _minUniqueSuffix = x.rnode->parent->depth + x.off + 1;
        }
 
        int minUniqueSuffix()
        {
                return _minUniqueSuffix;
        }
 
};
 
 
 
struct Me{
 
private:
        int n, res;
        Ukkonen ukkonen;
        Manacher manacher;
 
public:
        Me() : n(0), res(0) {}
 
        void addLetter(char c)
        {
                manacher.addLetter(c);
                ukkonen.addLetter(c);
                if( ukkonen.minUniqueSuffix() <= manacher.maxPal() ) res++;
        }
 
        void print()
        {
                printf("%d\n", res);
        }
 
} me;
 
 
char s[100500];
 
 
int main()
{
        scanf("%s", s);
        int n = strlen(s);
        for(int i = 0; i < n; i++)
        {
                me.addLetter(s[i]);
                me.print();
        }
        return 0;
}