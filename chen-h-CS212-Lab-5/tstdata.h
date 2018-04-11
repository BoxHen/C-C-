typedef char itemType;

typedef struct stackNodeTag{
	itemType item;
	struct stackNodeTag *next;
}stackNode;

stackNode *anchor;