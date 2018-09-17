
typedef struct NodeTag{
	char item;
	struct NodeTag *next;
	struct NodeTag *previous;
}Node;

Node *tracker;
Node *rear;
Node *anchor;

Node *tracker2;
Node *rear2;
Node *anchor2;
