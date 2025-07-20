// Verify Preorder Serialization of a Binary Tree
// Input: preorder string like "9,3,4,#,#,1,#,#,2,#,6,#,#"
// Output: true if it's a valid binary tree preorder serialization

#include <stdio.h>
#include <stdbool.h>

// Function to verify the serialization
bool isValidSerialization(char* preorder) {
    int slots = 1;

    for (int i = 0; preorder[i]; ) {
        if (slots == 0) return false;

        if (preorder[i] == ',') {
            i++;
            continue;
        }

        if (preorder[i] == '#') {
            slots--;   // null node uses one slot
            i++;
        } else {
            // skip over the number
            while (preorder[i] && preorder[i] != ',') i++;
            slots++;   // non-null node: -1 + 2 = +1 slot
        }
    }

    return slots == 0;
}

int main() {
    char input1[] = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    char input2[] = "1,#";

    printf("Input: %s => %s\n", input1, isValidSerialization(input1) ? "true" : "false");
    printf("Input: %s => %s\n", input2, isValidSerialization(input2) ? "true" : "false");

    return 0;
}
