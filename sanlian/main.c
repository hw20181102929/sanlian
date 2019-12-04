bool Delete( HashTable H, ElementType Key )
{
    int index,tmp;
    index=tmp=Hash(Key,H->TableSize);
    if(H->Heads[index].Next==NULL)
    {
        return false;
    }
    struct LNode * p;
    p=H->Heads[index].Next;
    if(strcmp(Key,p->Data)==0)
    {
        struct LNode * p1;
        p1=p->Next;
        H->Heads[index].Next=p1;
        free(p1);
    }
    while(p->Next&&strcmp(p->Next->Data,Key)!=0)
    {
        p=p->Next;
    }
    if(p->Next==NULL)
    {
        return false;
    }
    else{
        struct LNode * p1;
        p1=p->Next;printf("%s is deleted from list Heads[%d]",p1->Data,index);
        p->Next=p1->Next;
        free(p1);
        return true;
    }
}
