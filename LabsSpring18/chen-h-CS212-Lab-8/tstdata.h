typedef char itemType;

typedef struct NodeTag{
	itemType item;
	struct NodeTag *next;
	struct NodeTag *previous;
}Node;

Node *tracker;
Node *rear;
Node *anchor;