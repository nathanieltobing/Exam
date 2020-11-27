struct Data{
    char name[255],month[255];
    int day,year;
};



struct Node{
    Data biodata;
    Node *next,*prev;
} *head, *tail , *curr;



