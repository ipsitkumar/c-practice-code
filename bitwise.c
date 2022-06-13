#include <stdio.h>

// findParity:
//      returns 1: for odd parity
//              0: for even parity.
int findParity(int n) {

} 

// getRightMostSetBitPos:
//      returns: position of right most set bit in n
//      -1: otherwise
int getRightMostSetBitPos(int n) {
    int pcount = 0;

    if (!n) {
        return -1;
    }
    while (!(n & (1 << pcount))) {
        pcount++;
    }
    return pcount;
}

// checkIfPowOf2:
//      returns: 1 if n is positive and power of 2
//               0 if n is positive but not power of 2
//              -1 if n is negative.
int checkIfPowOf2(int n) {
    if ( n < 0) {
        return -1;
    }
    if(!(n & (n -1))) {
        return 1;
    }
    return 0;

}

// clearRightMostSetBit
//  returns n clearing the right most set bit.
int clearRightMostSetBit(int n) {
   return n & ( n - 1);
}

// printBits:
// printf all significants bits of n.
void printBits(int n) {
    
    int i, p, sp = 0;
    for (i = (sizeof(n) * 8) - 1; i >= 0; i--) {
        p = ( n & (0x1 << i));
        if(!sp) {
            if(!p)
                continue;
            else
                sp = 1;
        }
        printf("%d ", p ? 1 : 0); 
    } 
    printf("\n");
    return;
}

// checkNthBit:
//      returns n with position bit toggled.
//              -1: if pos supplied is more than 32
int toggleBit(int n, int pos) {
    if (pos > (sizeof(int) * 8) - 1) {
        return -1;
    }
    n = n ^ (1 << pos);
    return n;
}


// checkNthBit:
//      returns 1: if pos bit in n is set
//              0: if pos bit in n is clear
//              -1: if pos supplied is more than 32
int checkNthBit(int n, int pos) {
    if (pos > (sizeof(int) * 8) - 1) {
        return -1;
    }
    if(n & (1 << pos))
        return 1;
    return 0;
}

// clearNthBit:
//      returns n with position bit set.
//              -1: if pos supplied is more than 32
int clearNthBit(int n, int pos) {
    if (pos > (sizeof(int) * 8) - 1) {
        return -1;
    }
    return n &= ~( 1 << pos);
}

// setNthBit:
//      returns n with position bit set.
//              -1: if pos supplied is more than 32
int setNthBit(int n, int pos) {
    if (pos > (sizeof(int) * 8) - 1) {
        return -1;
    }
    return n |= ( 1 << pos);
}

// swapBits:
//      n: returns the number after swapping the bits at positions passed
//      -1: if no swaps to be done.
int swapBits(int n, int p1, int p2) {
    if ((n & (0x1 << p1) >> p1) ^ ((n & ( 0x1 << p2)) >> p2)) {
        n = n ^ (1 << p1);
        n = n ^ (1 << p2);
        return n;
    }
    return -1;
}

// swap: swaps values passed in the parameters.
void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

// signMatch: 
// returns 1: sign matches.
//         0: doesn't match.
int signMatch(int num1, int num2) {
    if ((num1 ^ num2) < 0)
        return 0;
    return 1;
}

// oddEven: 1: n is odd
//          0: n is even.
int oddEven(int n) {
    if ( n & 0x1)
        return 1;
    return 0;
}

int main() {
    //int num = 536870912;
    int num = -88;
    printBits(num);
    printf("Right most bit of %d is %d\n", num, getRightMostSetBitPos(num));
    return 0;
}
