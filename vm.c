#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define getPosition(x, y, z) (x + (y * space->edgeLength) + (z * space->edgeLength * space->edgeLength))
#define currentPosition getPosition(space->tracker->vectors[0][0], space->tracker->vectors[0][1], space->tracker->vectors[0][2])
#define setVector(head, vect, x_, y_, z_)  \
                                        head->vectors[vect][0] = x_;\
                                        head->vectors[vect][1] = y_;\
                                        head->vectors[vect][2] = z_

#define combineTriple(t1, op, t2) t1[0] op t2[0]; t1[1] op t2[1]; t1[2] op t2[2]
#define forEachVect(op) op(0); op(1); op(2)

typedef struct Space Space;
typedef struct Head {
    unsigned int** vectors;
    char op;
    char value;
} Head;
typedef struct Space {
    Head** space;
    Head* tracker;
    int edgeLength;
    int size;
} Space;
typedef int (*opCode)(Space*);

int runInstruction(Space* space, opCode* codes){
    int out = codes[space->space[currentPosition]->op](space);
    combineTriple(space->tracker->vectors[0], +=, space->tracker->vectors[1]);
    combineTriple(space->tracker->vectors[1], +=, space->tracker->vectors[2]);
    return out;
}

void printHead(Head* head, int c){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (c) {
                printf("%c ", head->vectors[i][j]);
            }
            else {
                printf("%d ", head->vectors[i][j]);
            }
        }
    }
}

#define makeTrackerAndCurrent(op, var1, var2) \
int op ##Tracker (Space* space){return op(space, var1, var2);}\
int op ##Current (Space* space){return op(space, var2, var1);}

int set0Tracker (Space* space) {combineTriple(space->tracker->vectors[0],  =, space->space[currentPosition]->vectors[0]); return 0;}
int set0Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[0],  =, space->tracker->vectors[0]); return 0;}
int add0Tracker (Space* space) {combineTriple(space->tracker->vectors[0], +=, space->space[currentPosition]->vectors[0]); return 0;}
int add0Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[0], +=, space->tracker->vectors[0]); return 0;}
int sub0Tracker (Space* space) {combineTriple(space->tracker->vectors[0], -=, space->space[currentPosition]->vectors[0]); return 0;}
int sub0Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[0], -=, space->tracker->vectors[0]); return 0;}
int div0Tracker (Space* space) {combineTriple(space->tracker->vectors[0], /=, space->space[currentPosition]->vectors[0]); return 0;}
int div0Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[0], /=, space->tracker->vectors[0]); return 0;}
int mul0Tracker (Space* space) {combineTriple(space->tracker->vectors[0], *=, space->space[currentPosition]->vectors[0]); return 0;}
int mul0Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[0], *=, space->tracker->vectors[0]); return 0;}
int mod0Tracker (Space* space) {combineTriple(space->tracker->vectors[0], %=, space->space[currentPosition]->vectors[0]); return 0;}
int mod0Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[0], %=, space->tracker->vectors[0]); return 0;}
int set1Tracker (Space* space) {combineTriple(space->tracker->vectors[1],  =, space->space[currentPosition]->vectors[1]); return 0;}
int set1Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[1],  =, space->tracker->vectors[1]); return 0;}
int add1Tracker (Space* space) {combineTriple(space->tracker->vectors[1], +=, space->space[currentPosition]->vectors[1]); return 0;}
int add1Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[1], +=, space->tracker->vectors[1]); return 0;}
int sub1Tracker (Space* space) {combineTriple(space->tracker->vectors[1], -=, space->space[currentPosition]->vectors[1]); return 0;}
int sub1Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[1], -=, space->tracker->vectors[1]); return 0;}
int div1Tracker (Space* space) {combineTriple(space->tracker->vectors[1], /=, space->space[currentPosition]->vectors[1]); return 0;}
int div1Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[1], /=, space->tracker->vectors[1]); return 0;}
int mul1Tracker (Space* space) {combineTriple(space->tracker->vectors[1], *=, space->space[currentPosition]->vectors[1]); return 0;}
int mul1Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[1], *=, space->tracker->vectors[1]); return 0;}
int mod1Tracker (Space* space) {combineTriple(space->tracker->vectors[1], %=, space->space[currentPosition]->vectors[1]); return 0;}
int mod1Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[1], %=, space->tracker->vectors[1]); return 0;}
int set2Tracker (Space* space) {combineTriple(space->tracker->vectors[2],  =, space->space[currentPosition]->vectors[2]); return 0;}
int set2Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[2],  =, space->tracker->vectors[2]); return 0;}
int add2Tracker (Space* space) {combineTriple(space->tracker->vectors[2], +=, space->space[currentPosition]->vectors[2]); return 0;}
int add2Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[2], +=, space->tracker->vectors[2]); return 0;}
int sub2Tracker (Space* space) {combineTriple(space->tracker->vectors[2], -=, space->space[currentPosition]->vectors[2]); return 0;}
int sub2Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[2], -=, space->tracker->vectors[2]); return 0;}
int div2Tracker (Space* space) {combineTriple(space->tracker->vectors[2], /=, space->space[currentPosition]->vectors[2]); return 0;}
int div2Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[2], /=, space->tracker->vectors[2]); return 0;}
int mul2Tracker (Space* space) {combineTriple(space->tracker->vectors[2], *=, space->space[currentPosition]->vectors[2]); return 0;}
int mul2Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[2], *=, space->tracker->vectors[2]); return 0;}
int mod2Tracker (Space* space) {combineTriple(space->tracker->vectors[2], %=, space->space[currentPosition]->vectors[2]); return 0;}
int mod2Current (Space* space) {combineTriple(space->space[currentPosition]->vectors[2], %=, space->tracker->vectors[2]); return 0;}
int show(Space* space, Head* head1, Head* head2){
    printHead(head1, head2->value % 2);
    printf(" | %d |>%d<|\n", head1->value, head1->op); return 0;
} makeTrackerAndCurrent(show, space->tracker, space->space[currentPosition])

// Runs the provided function on all heads in space.
int globalOp(Space* space, int (*op)(Space*, int)){
    int i = 0;
    while (op(space, i++)){}
    return i;
}

// Initializes the head at the given index of space
// by setting all its vectors to 0, and its operation
// to noOp.
// Returns 0 when index == space->size
int initHead(Space* space, int index){
    space->space[index] = (Head*) calloc(1, sizeof(Head));
    space->space[index]->vectors = (unsigned int**) calloc(3, sizeof(unsigned int*));
    space->space[index]->op = 36;
    for (int i = 0; i < 3; i++){
        space->space[index]->vectors[i] = (unsigned int*) calloc(3, sizeof(unsigned int));
    }
    return space->size - index - 1;
}

// allocates space for (size) heads
Space* newSpace(int size){
    Space* space = (Space*) calloc(1, sizeof(Space));
    space->edgeLength = size;
    space->size = size * size * size;
    space->space = (Head**) calloc(space->size, sizeof(Head*));

    space->tracker = (Head*) calloc(1, sizeof(Head));
    space->tracker->vectors = (unsigned int**) calloc(3, sizeof(unsigned int*));
    for (int i = 0; i < 3; i++){
        space->tracker->vectors[i] = (unsigned int*) calloc(3, sizeof(unsigned int));
    }

    globalOp(space, initHead);
    return space;
}

int main(int argc, char** argv){
    opCode codes[] = {
        set0Tracker, // 0
        set0Current, // 1
        add0Tracker, // 2
        add0Current, // 3
        sub0Tracker, // 4
        sub0Current, // 5
        div0Tracker, // 6
        div0Current, // 6
        mul0Tracker, // 7
        mul0Current, // 8
        mod0Tracker, // 9
        mod0Current, //10
        set1Tracker, //11
        set1Current, //12
        add1Tracker, //13
        add1Current, //14
        sub1Tracker, //15
        sub1Current, //16
        div1Tracker, //17
        div1Current, //18
        mul1Tracker, //19
        mul1Current, //20
        mod1Tracker, //21
        mod1Current, //22
        set2Tracker, //23
        set2Current, //24
        add2Tracker, //25
        add2Current, //26
        sub2Tracker, //27
        sub2Current, //28
        div2Tracker, //29
        div2Current, //30
        mul2Tracker, //31
        mul2Current, //32
        mod2Tracker, //33
        mod2Current, //34
        showTracker, //35
        showCurrent, //36
    };
    int size = 9;
    Space* space = newSpace(size);
    setVector(space->space[currentPosition], 2, 1, 0, 0);
    space->space[currentPosition]->op = 24;
    runInstruction(space, codes);
    runInstruction(space, codes);
    runInstruction(space, codes);
    runInstruction(space, codes);
    runInstruction(space, codes);
    runInstruction(space, codes);
}