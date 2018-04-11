typedef char itemType;

typedef struct queueNodeTag{
	itemType item;
	struct queueNodeTag *next;
}queueNode;

queueNode *anchor; // front
queueNode *rear;