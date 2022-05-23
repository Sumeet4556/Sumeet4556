#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *l,*r;
};
node *root;
class bst
{
    public:
    void create(node * root)
    {
        int a;
        do
        {
            node *ne,*temp;
            ne = new node;
            cout<<"Enter value";
            cin>>ne->data;
            ne->l=NULL;
            ne->r=NULL;
            temp=root;
            while(1)
            {
                if(ne->data < temp->data)
                {
                    if(temp->l==NULL)
                    {
                        temp->l=ne;
                        cout<<"CREATED SUCCESFULLY";
                        break;
                    }
                    else
                    {
                        temp=temp->l;
                    }
                }
                else
                {
                    if(temp->r==NULL)
                    {
                        temp->r=ne;
                        cout<<"CREATED SUCCESFULLY";
                        break;                
                    }
                    else
                    {
                        temp=temp->r;
                    }
                }
            }
            cout<<"\n WANT TO CONTINUE? \n1.YES \n 2.NO";
            cin>>a;
         }while(a==1);
    }
    void min(node * root)
    {
        node *temp;
        temp=root;
        while(temp->l != NULL)
        {
            temp=temp->l;
        }
        cout<<"SMALLETS ELEMENT"<<temp->data<<endl;
    }
    void search(node *root,int a)
    {
        int x;
        while (root!=NULL)
        {
            if(x==root->data)
            {
                if(x<root->data)
                {
                    cout<<"NUMBER PRESENT"<<endl;
                    break;
                }
                else
                {
                    root = root->l;

                }
            }
            else
            {
                if(x==root->data)
                {
                    cout<<"NUMBER IS PRESENT"<<endl;
                    break;
                    
                }
                else
                {
                    root=root->r;
                }
            }
        }
        if(root==NULL)
        cout<<"NUMBER IS NOT PRESENT"<<endl;
    }
};

int main()
{
    bst b;
    int ch;
    while(1)
    {
        cout<<"ENTER YOUR CHOICE"<<endl;
        cout<<"\n1)INSERT\n2)minimum\n3)search";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnterthedataforrootnode:";
            root = new node();
            cin >> root->data;
            cout << "Rootnodecreatedsuccessfully." << endl;
            root->l = NULL;
            root->r = NULL;
            b.create(root);
            break;
        case 2:
        b.min(root);
        break;
        case 3:
        int c;
        cout<<"ELEMENT TO BE SEARCHED";
        cin>>c;
        b.search(root,c);
        default:exit(0);

        }
    }
}
