#include "asteroids.h"

// Main function for moving the ship
struct ship_action move_ship(int field[][FIELD_WIDTH], void *ship_state){
    // Your code should go here
    struct ship_action action;

    // Initialize the state if it's the first call
    if (ship_state == NULL) {
        // TODO: Allocate and initialize state here if needed
    }

    // TODO: Implement your algorithm here to decide on the ship's next action
    // You can use the state variable to maintain information between function calls

    // Example: Move the ship down if the first asteroid in the ship's column is below the ship
    int ship_col = 0;  // The ship is always in column 0
    int first_asteroid_row = find_first_asteroid(ship_col, field);
    if (first_asteroid_row > 2) {
        action.move = 1;  // Move down
    } else if (first_asteroid_row < 2) {
        action.move = -1;  // Move up
    } else {
        action.move = 0;  // Stay in place
    }

    // Set the state variable if needed
    action.state = ship_state;

    return action;
}

// Helper function to find the index of the first asteroid in a column
int find_first_asteroid(int col, int field[FIELD_HEIGHT][FIELD_WIDTH]) {
    int row;
    for (row = 0; row < FIELD_HEIGHT; row++) {
        if (field[row][col] == 1) {
            return row;
        }
    }
    return FIELD_HEIGHT;
}
