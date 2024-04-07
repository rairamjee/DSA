#include<stdio.h>
#include<stdlib.h>

typedef struct nodes
{
    int data;
    struct nodes *left;
    struct nodes *right;
}node;

node*root=NULL;

node*create(node*);
void insert(node*,node*);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *search(node*,int );
node *max(node*);
node *min(node*);
node *del(node*,int);



int main()
{
    int ch,sno,n;
    node*newnode,*temp1,*max_val,*min_val,*temp2;
    do
    {
        printf("\n1.CREATE AND INSERT \n2.ORDERS OF TREE \n3.SEARCH ANY DATA \n4.MAX AND MIN DATA IN THE TREE \n5.DELETE \n6.EXIT");
        printf("\n\n\tEnter Your Choice  :: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            newnode=(node*)malloc(sizeof(node));
            printf("\nEnter the data which is to be added in the tree :: \n");
            scanf("%d",&newnode->data);
            newnode->left=NULL;
            newnode->right=NULL;
            if(root ==NULL )
            create(newnode);
            else
            insert(root,newnode);
            break;

            case 2:
            printf("\n\t -- The Orders of the tree are as follows --\n");
            
            printf("\nINORDER ::\n");
            inorder(root);

            printf("\nPREORDER ::\n");
            preorder(root);

            printf("\nPOSTORDER ::\n");
            postorder(root);
            break;

            case 3:
            printf("\nEnter The Data To Be Searched \n");
            scanf("%d",&sno);
            temp1=search(root,sno);
            if(temp1==NULL)
            printf("\nData Is Not Found In The List \n");
            else
            printf("\nData Is Found In The List \n");
            break;

            case 4:
            max_val=max(root);
            min_val=min(root);
            if(max_val==NULL || min_val==NULL)
            printf("\nNo Data Is Found in the Tree\n");
            else
            {
            printf("The Maximum Value In The Tree Is :: %d\n",max_val->data);
            printf("The Minimum Value In The Tree Is :: %d\n",min_val->data);
            }
            break;

            case 5:
            printf("\nEnter the Data To Be Deleted ::\n");
            scanf("%d",&n);
            temp2=del(root,n);
            printf("\nElement Deletd = %d",temp2->data);
            break;

            case 6:
            exit(0);

            default:
            printf("\nINVALID CHOICE\n");

        }
    }while(ch!=6);
    return 0;
}

node * create(node*newnode)
{
    root=newnode;
    return newnode;;
}

void insert(node*root,node*newnode)
{
    if(newnode->data<root->data)
    {
        if(root->left==NULL)
        {
            root->left=newnode;
        }
        else
        {
            insert(root->left,newnode);
        }
    }
    else if(newnode->data>root->data)
    {
        if(root->right==NULL)
        {
            root->right=newnode;
        }
        else
        {
            insert(root->right,newnode);
        }
    }
}

void inorder(node *temp)
{
    if(temp != NULL)
    {
        inorder(temp->left);
        printf("%d ",temp->data);
        inorder(temp->right);
    }
}

void preorder(node *temp)
{
    if(temp != NULL)
    {
        printf("%d ",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(node *temp)
{
    if(temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->data);
    }
}

node *search(node*temp,int sno)
{
    if(temp==NULL || temp->data == sno)
    return temp;

    else if(sno<temp->data)
    return search(temp->left,sno);

    else if(sno>temp->data)
    return search(temp->right,sno);
}

node *max(node*temp)
{
    if(temp==NULL)
    return NULL;

    else if(temp->right==NULL)
    return temp;

    else
    return max(temp->right);
}

node *min(node*temp)
{
    if(temp==NULL)
    return NULL;

    else if(temp->left==NULL)
    return temp;

    else
    return min(temp->left);
}

node *del(node*temp,int no)
{
    node *temp1;

    if(temp==NULL)
    return NULL;

    else if( no < temp->data)
    temp->left=del(temp->left,no);

    else if(no > temp->data)
    temp->right=del(temp->right,no);

    else
    {
        // 0 child
        if(temp->left==NULL && temp->right==NULL)
        {
            free(temp);
            temp=NULL;
        }

        // 1 child i.e. either left or right
        else if(temp->left==NULL)
        {
            temp1=temp;
            temp=temp->right;
            free(temp1);
        }

        else if(temp->right==NULL)
        {
            temp1=temp;
            temp=temp->left;
            free(temp1);
        }

        // 2 child

        else if(temp->left != NULL && temp->right !=NULL)
        {
            temp1=min(temp->right);
            temp->data=temp1->data;
            temp->right=del(temp->right,temp1->data);
        }
    }
    return temp;
}